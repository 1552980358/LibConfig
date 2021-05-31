extern "C" {
#include "config_value_c.h"
}
#include "config_value.h"
#include <cstring>

int config_value_get_title_length(config_value_t ptr) {
    return (int) ((config_value *) ptr)->get_title()->size() + 1;
}

void config_value_get_title(config_value_t ptr, char *title) {
    strcpy(title, ((config_value *) ptr)->get_title()->c_str());
}

void config_value_set_title(config_value_t ptr, const char *title) {
    ((config_value *) ptr)->set_title(title);
}

int config_value_get_value_length(config_value_t ptr) {
    return (int) ((config_value *) ptr)->get_value()->size() + 1;
}

void config_value_get_value(config_value_t ptr, char *value) {
    strcpy(value, ((config_value *) ptr)->get_value()->c_str());
}

void config_value_set_value(config_value_t ptr, const char *value) {
    ((config_value *) ptr)->set_value(value);
}

config_value_t config_value_get_prev(config_value_t ptr) {
    return ((config_value *) ptr)->get_prev();
}

void config_value_set_prev(config_value_t ptr, config_value_t prev) {
    ((config_value *) ptr)->set_prev((config_value *) prev);
}

config_value_t config_value_get_next(config_value_t ptr) {
    return ((config_value *) ptr)->get_next();
}

void config_value_set_next(config_value_t ptr, config_value_t next) {
    ((config_value *) ptr)->set_next((config_value *) next);
}

char *config_value_get_title_char(config_value_t ptr, int *size) {
    auto title_str = ((config_value *) ptr)->get_title();
    if (!title_str) {
        if (size) {
            *size = -1;
        }
        return nullptr;
    }
    if (size) {
        *size = (int) title_str->size() + 1;
    }
    auto title = (char *) malloc((title_str->size() + 1) * sizeof(char));
    strcpy(title, title_str->c_str());
    return title;
}

char *config_value_get_value_char(config_value_t ptr, int *size) {
    auto value_str = ((config_value *) ptr)->get_title();
    if (!value_str) {
        if (size) {
            *size = -1;
        }
        return nullptr;
    }
    if (size) {
        *size = (int) value_str->size() + 1;
    }
    auto value = (char *) malloc((value_str->size() + 1) * sizeof(char));
    strcpy(value, value_str->c_str());
    return value;
}