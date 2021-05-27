#ifndef CONFIG_STATIC_CONFIG_PART_C_H
#define CONFIG_STATIC_CONFIG_PART_C_H

int config_part_get_title_length(void *ptr);

void config_part_get_title(void *, char *title);

void config_part_set_prev(void *, void *);

void config_part_set_next(void *, void *);

void *config_part_get_prev(void *);

void *config_part_get_next(void *);

void config_part_add_value(void *, const char *, const char *);

void *config_part_get_values(void *);

int config_part_value_title_length(void *, const char *);

void config_part_get_value_title(void *, const char *, char *);

int config_part_value_index_length(void *, int);

void config_part_get_value_index(void *, int, char *);

#endif //CONFIG_STATIC_CONFIG_PART_C_H
