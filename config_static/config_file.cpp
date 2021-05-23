#include "config_file.h"

#include <iostream>
using std::ios;
using std::getline;
#include <fstream>
using std::ifstream;

// Static .cpp internal functions prototypes
config_part *analysis_line(const string &str, config_part *part);
bool is_new_part(const string &);
string get_config_part_name(const string &);
string get_config_part_value_title(const string &);
string get_config_part_value_value(const string &);
string cut_value(const string &);
const int &count_config_parts(config_part *);

// Constructors
config_file::config_file(const bool &read) { if (read) read_file(); }

config_file::config_file(): config_file(false) {}

config_file::config_file(const string &str): config_file(str, true) {}

config_file::config_file(const char *c_str): config_file(c_str, true) {}

config_file::config_file(const string &str, const bool &read): config_file(read) { set_path(str); }

config_file::config_file(const char *c_str, const bool &read): config_file(read) { set_path(c_str); }

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
    ifstream file_stream(*_path, ios::in);
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

string *config_file::get_config_part_titles() {
    auto current = _config_parts;
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
    return str.starts_with('[') && str.ends_with(']');
}

string get_config_part_name(const string &str) {
    return str.substr(str.find('['), str.find(']') - str.find('['));
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
    return cut_value(str.substr(str.find('=')));
}

string cut_value(const string &str) {
    auto tmp = string(str);
    if (str.starts_with(' ')) {
        int i = 1;
        while (i < tmp.length()) {
            if (tmp[i] != ' ') {
                tmp = tmp.substr(i);
                break;
            }
            i++;
        }
    }
    if (str.ends_with(' ')) {
        int i = (int) tmp.length();
        while (i > 0) {
            if (str[i] != ' ') {
                tmp = str.substr(0, i);
                break;
            }
            i--;
        }
    }
    return tmp;
}

const int &count_config_parts(config_part *part) {

}