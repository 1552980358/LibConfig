#include "config_part.h"

config_part::config_part(const string &title, config_part *prev) {
    _title = title;
    set_prev(prev);
    if (prev) {
        prev->set_next(prev);
    }
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
    _titles = (string *) realloc(_titles, ++_number * sizeof(string));
    _values = (string *) realloc(_values, _number * sizeof(string));
    _titles[_number - 1] = title;
    _values[_number - 1] = value;
}

string *config_part::get_value(const string &name) {
    for (int i = 0; i < _number; ++i) {
        if (_titles[i] == name) {
            return get_value(i);
        }
    }
    return nullptr;
}

string *config_part::get_value(const int &index) {
    return index >= _number || index < 0 ? nullptr : &_values[index];
}

config_part *get_head(config_part *part) {
    auto *tmp = part;
    while (tmp && tmp->get_prev()) {
        tmp = tmp->get_prev();
    }
    return tmp;
}