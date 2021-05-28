#ifndef CONFIG_STATIC_CONFIG_PART_C_H
#define CONFIG_STATIC_CONFIG_PART_C_H

#include "type.h"

int config_part_get_title_length(config_part_t);

void config_part_get_title(config_part_t, char *title);

void config_part_set_prev(config_part_t, config_part_t);

void config_part_set_next(config_part_t, config_part_t);

config_part_t config_part_get_prev(config_part_t);

config_part_t config_part_get_next(config_part_t);

void config_part_add_value(config_part_t, const char *, const char *);

config_value_t config_part_get_values(config_part_t);

int config_part_value_title_length(config_part_t, const char *);

void config_part_get_value_title(config_part_t, const char *, char *);

int config_part_value_index_length(config_part_t, int);

void config_part_get_value_index(config_part_t, int, char *);

#endif //CONFIG_STATIC_CONFIG_PART_C_H
