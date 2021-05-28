#ifndef CONFIG_STATIC_CONFIG_VALUE_C_H
#define CONFIG_STATIC_CONFIG_VALUE_C_H

#include "type.h"

int config_value_get_title_length(config_value_t);

void config_value_get_title(config_value_t, char *);

void config_value_set_title(config_value_t, const char *);

int config_value_get_value_length(config_value_t);

void config_value_get_value(config_value_t, char *);

void config_value_set_value(config_value_t, const char *);

config_value_t config_value_get_prev(config_value_t);

void config_value_set_prev(config_value_t, config_value_t);

config_value_t config_value_get_next(config_value_t);

void config_value_set_next(config_value_t, config_value_t);

#endif //CONFIG_STATIC_CONFIG_VALUE_C_H
