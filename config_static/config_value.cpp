#include "config_value.h"

config_value::config_value(const string &title, const string &value, config_value *prev) {
    set_title(title);
    set_value(value);
    if (prev) {
        set_prev(prev);
        prev->set_next(this);
    }
}

string *config_value::get_title() {
    return &_title;
}

void config_value::set_title(const string &title) {
    _title = title;
}

string *config_value::get_value() {
    return &_value;
}

void config_value::set_value(const string &value) {
    _value = value;
}

config_value *config_value::get_prev() {
    return _prev;
}

void config_value::set_prev(config_value *prev) {
    _prev = prev;
}

config_value *config_value::get_next() {
    return _next;
}

void config_value::set_next(config_value *next) {
    _next = next;
}

config_value *get_last(config_value *value) {
    if (!value) {
        return nullptr;
    }
    auto *ptr = value;
    while (ptr->get_next()) {
        ptr = ptr->get_next();
    }
    return ptr;
}

config_value *get_head(config_value *value) {
    if (!value) {
        return nullptr;
    }
    auto *ptr = value;
    while (ptr->get_prev()) {
        ptr = ptr->get_prev();
    }
    return ptr;
}

int cal_config_value_size(config_value *head) {
    auto ptr = head;
    int count = 0;
    while (ptr) {
        count++;
        ptr = ptr->get_next();
    }
    return count;
}