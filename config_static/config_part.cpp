#include "config_part.h"

config_part::config_part(const string &title, config_part *prev) {
    _title = title;
    set_prev(prev);
    if (prev) {
        prev->set_next(this);
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