extern "C" {
#include "config_part_c.h"
}
#include "config_part.h"
#include <cstring>

int config_part_get_title_length(config_part_t ptr) {
    return (int) ((config_part *) ptr)->get_title().size() + 1;
}

void config_part_get_title(config_part_t ptr, char *title) {
    strcpy(title, ((config_part *) ptr)->get_title().c_str());
}

void config_part_set_prev(config_part_t ptr, config_part_t prev) {
    ((config_part *) ptr)->set_prev((config_part *) prev);
}

void config_part_set_next(config_part_t ptr, config_part_t next) {
    ((config_part *) ptr)->set_next((config_part *) next);
}

config_part_t config_part_get_prev(config_part_t ptr) {
    return ((config_part *) ptr)->get_prev();
}

config_part_t config_part_get_next(config_part_t ptr) {
    return ((config_part *) ptr)->get_next();
}

void config_part_add_value(config_part_t ptr, const char *title, const char *value) {
    ((config_part *) ptr)->add_value(title, value);
}

config_value_t config_part_get_values(config_part_t ptr) {
    return ((config_part *) ptr)->get_values();
}

int config_part_value_title_length(config_part_t ptr, const char *title) {
    auto *str = ((config_part *) ptr)->get_value(title);
    return str ? (int) str->size() + 1 : -1;
}

void config_part_get_value_title(config_part_t ptr, const char *title, char *value) {
    strcpy(value, ((config_part *) ptr)->get_value(title)->c_str());
}

int config_part_value_index_length(config_part_t ptr, int index) {
    auto *str = ((config_part *) ptr)->get_value(index);
    return str ? (int) str->size() + 1 : -1;
}

void config_part_get_value_index(config_part_t ptr, int index, char *value) {
    strcpy(value, ((config_part *) ptr)->get_value(index)->c_str());
}

char *config_part_get_value_title_char(config_part_t ptr, const char *title, int *size) {
    auto str = ((config_part *) ptr)->get_value(title);
    if (!str) {
        if (size) {
            *size = -1;
        }
        return nullptr;
    }
    if (size) {
        *size = (int) str->size() + 1;
    }
    auto value = (char *) malloc((int) str->size() + 1);
    strcpy(value, str->c_str());
    return value;
}

char *config_part_get_value_index_char(config_part_t ptr, const int &index, int *size) {
    auto str = ((config_part *) ptr)->get_value(index);
    if (!str) {
        if (size) {
            *size = -1;
        }
        return nullptr;
    }
    if (size) {
        *size = (int) str->size() + 1;
    }
    auto value = (char *) malloc((int) str->size() + 1);
    strcpy(value, str->c_str());
    return value;
}