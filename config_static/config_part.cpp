#include "config_part.h"

#include <string>
using std::getline;
#include <fstream>
using std::ifstream;

#include "utils.h"

config_value *read_config_file(const string &);

config_part::config_part(const string &title, config_part *prev) {
    _title = title;
    set_prev(prev);
    if (prev) {
        prev->set_next(this);
    }
}

config_part::config_part(const string &path) {
    _type = CONFIG_PART_READ_FILE;
    _title = path;
}

config_part::config_part(const char *path) {
    _type = CONFIG_PART_READ_FILE;
    _title = path;
}

string config_part::get_title() {
    return _title;
}

void config_part::set_prev(config_part *prev) {
    _prev = prev;
}

void config_part::set_next(config_part *next) {
    _next = next;
}

config_part *config_part::get_prev() {
    return _prev;
}

config_part *config_part::get_next() {
    return _next;
}

void config_part::add_value(const string &title, const string &value) {
    _values = get_head(new config_value(title, value, get_last(_values)));
}

config_value *config_part::get_values() {
    return _values;
}

string *config_part::get_value(const string &name) {
    auto ptr = _values;
    while (ptr) {
        if (*ptr->get_title() == name) {
            return ptr->get_value();
        }
        ptr = ptr->get_next();
    }
    return nullptr;
}

string *config_part::get_value(const int &index) {
    if (index >= cal_config_value_size(_values)) {
        return nullptr;
    }
    auto *ptr = _values;
    for (int i = 0; i < index; ++i) {
        ptr = ptr->get_next();
    }
    return ptr->get_value();
}

config_value *config_part::read() {
    if (_type != CONFIG_PART_READ_FILE) {
        return nullptr;
    }
    return read_config_file(_title);
}

void config_part::read_file() {
    read();
}

config_part *get_head(config_part *part) {
    if (!part) {
        return nullptr;
    }
    auto *tmp = part;
    while (tmp->get_prev()) {
        tmp = tmp->get_prev();
    }
    return tmp;
}

bool is_config_value(const string &str) {
    return !str.empty() && str.find('=') != -1;
}

config_value *read_config_file(const string &str) {
    ifstream stream(str);
    if (!stream) {
        return nullptr;
    }
    string line;
    config_value *current = nullptr;
    while (stream.peek() != EOF && getline(stream, line)) {
        if (!is_config_value(line)) {
            continue;
        }
        current = new config_value(get_config_part_value_title(line), get_config_part_value_value(line), current);
    }
    return get_head(current);
}