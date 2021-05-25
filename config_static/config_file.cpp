#include "config_file.h"

#include <iostream>
using std::ios;
using std::getline;
#include <fstream>
using std::ifstream;
#include "utils.h"

// Static .cpp internal functions prototypes
config_part *analysis_line(const string &str, config_part *part);
bool is_new_part(const string &);
string get_config_part_name(const string &);
string get_config_part_value_title(const string &);
string get_config_part_value_value(const string &);
string cut_value(const string &);
int count_config_parts(config_part *);

// Constructors
config_file::config_file() = default;

config_file::config_file(const string &str) {
    set_path(str);
    read_file();
}

config_file::config_file(const char *c_str) {
    set_path(c_str);
    read_file();
}

/** Class defined functions **/
void config_file::set_path(const string &str) {
    _path = new string(str);
}

void config_file::set_path(const char *c_str) {
    _path = new string(c_str);
}

config_part *config_file::read() {
    if (!_path) {
        return nullptr;
    }
    ifstream file_stream(*_path);
    if (!file_stream) {
        return nullptr;
    }

    string line;
    config_part *current = nullptr;
    while (file_stream.peek() != EOF && getline(file_stream, line)) {
        current = analysis_line(line, current);
    }
    _config_parts = get_head(current);
    return _config_parts;
}

void config_file::read_file() {
    read();
}

config_part *config_file::get_config_part(const string &title) {
    auto *current = _config_parts;
    while (current) {
        if (current->get_title() == title) {
            return current;
        }
        current = current->get_next();
    }
    return nullptr;
}

int config_file::get_config_part_size() {
    return count_config_parts(_config_parts);
}

// Static .cpp internal functions
config_part *analysis_line(const string &str, config_part *part) {
    if (str.empty()) {
        return part;
    }
    if (is_new_part(str)) {
        return new config_part(get_config_part_name(str), part);
    }
    part->add_value(get_config_part_value_title(str), get_config_part_value_value(str));
    return part;
}

bool is_new_part(const string &str) {
    return str_starts_with(str, '[') && str_ends_with(str, ']');
}

string get_config_part_name(const string &str) {
    return str.substr(str.find('[') + 1, str.find(']') - str.find('[') - 1);
}

string get_config_part_value_title(const string &str) {
    if (str.find('=') == -1) {
        return "";
    }
    return cut_value(str.substr(0, str.find('=')));
}

string get_config_part_value_value(const string &str) {
    if (str.find('=') == -1) {
        return "";
    }
    return cut_value(str.substr(str.find('=') + 1));
}

string cut_value(const string &str) {
    auto tmp = string(str);
    if (str_starts_with(str, ' ')) {
        for (int i = 0; i < tmp.length(); ++i) {
            if (tmp[i] != ' '){
                tmp = tmp.substr(i);
                break;
            }
        }
    }
    if (str_ends_with(tmp, ' ')) {
        for (int i = tmp.length(); i > -1 ; --i) {
            if (tmp[i] != ' ') {
                return tmp.substr(0, i + 1);
            }
        }
    }
    return tmp;
}

int count_config_parts(config_part *part) {
    auto count = 0;
    auto *current = part;
    while (current) {
        count++;
        current = current->get_next();
    }
    return count;
}