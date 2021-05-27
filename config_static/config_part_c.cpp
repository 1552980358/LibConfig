extern "C" {
#include "config_part_c.h"
}
#include "config_part.h"
#include <cstring>

int config_part_get_title_length(void *ptr) {
    return (int) ((config_part *) ptr)->get_title().size() + 1;
}

void config_part_get_title(void *ptr, char *title) {
    strcpy(title, ((config_part *) ptr)->get_title().c_str());
}

void config_part_set_prev(void *ptr, void *prev) {
    ((config_part *) ptr)->set_prev((config_part *) prev);
}

void config_part_set_next(void *ptr, void *next) {
    ((config_part *) ptr)->set_next((config_part *) next);
}

void *config_part_get_prev(void *ptr) {
    return ((config_part *) ptr)->get_prev();
}

void *config_part_get_next(void *ptr) {
    return ((config_part *) ptr)->get_next();
}

void config_part_add_value(void *ptr, const char *title, const char *value) {
    ((config_part *) ptr)->add_value(title, value);
}

void *config_part_get_values(void *ptr) {
    return ((config_part *) ptr)->get_values();
}

int config_part_value_title_length(void *ptr, const char *title) {
    auto *str = ((config_part *) ptr)->get_value(title);
    return str ? (int) str->size() + 1 : -1;
}

void config_part_get_value_title(void *ptr, const char *title, char *value) {
    strcpy(value, ((config_part *) ptr)->get_value(title)->c_str());
}

int config_part_value_index_length(void *ptr, int index) {
    auto *str = ((config_part *) ptr)->get_value(index);
    return str ? (int) str->size() + 1 : -1;
}

void config_part_get_value_index(void *ptr, int index, char *value) {
    strcpy(value, ((config_part *) ptr)->get_value(index)->c_str());
}