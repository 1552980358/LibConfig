#ifndef CONFIG_STATIC_CONFIG_VALUE_C_H
#define CONFIG_STATIC_CONFIG_VALUE_C_H

int config_value_get_title_length(void *);

void config_value_get_title(void *, char *);

void config_value_set_title(void *, const char *);

int config_value_get_value_length(void *);

void config_value_get_value(void *, char *);

void config_value_set_value(void *, const char *);

void *config_value_get_prev(void *);

void config_value_set_prev(void *, void *);

void *config_value_get_next(void *);

void config_value_set_next(void *, void *);

#endif //CONFIG_STATIC_CONFIG_VALUE_C_H
