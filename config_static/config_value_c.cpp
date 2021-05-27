extern "C" {
#include "config_value_c.h"
}
#include "config_value.h"
#include <cstring>

int config_value_get_title_length(void *ptr) {
    return (int) ((config_value *) ptr)->get_title()->size() + 1;
}

void config_value_get_title(void *ptr, char *title) {
    strcpy(title, ((config_value *) ptr)->get_title()->c_str());
}

void config_value_set_title(void *ptr, const char *title) {
    ((config_value *) ptr)->set_title(title);
}

int config_value_get_value_length(void *ptr) {
    return (int) ((config_value *) ptr)->get_value()->size() + 1;
}

void config_value_get_value(void *ptr, char *value) {
    strcpy(value, ((config_value *) ptr)->get_value()->c_str());
}

void config_value_set_value(void *ptr, const char *value) {
    ((config_value *) ptr)->set_value(value);
}

void *config_value_get_prev(void *ptr) {
    return ((config_value *) ptr)->get_prev();
}

void config_value_set_prev(void *ptr, void *prev) {
    ((config_value *) ptr)->set_prev((config_value *) prev);
}

void *config_value_get_next(void *ptr) {
    return ((config_value *) ptr)->get_next();
}

void config_value_set_next(void *ptr, void *next) {
    ((config_value *) ptr)->set_next((config_value *) next);
}

#include "config_value.h"