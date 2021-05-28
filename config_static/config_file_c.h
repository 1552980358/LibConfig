#ifndef CONFIG_STATIC_CONFIG_FILE_C_H
#define CONFIG_STATIC_CONFIG_FILE_C_H

#include "type.h"

config_file_t read_config(const char *);

void config_file_set_path(config_file_t, const char *);

void config_file_read_file(config_file_t);
config_file_t config_file_read(config_file_t);

config_part_t config_file_get_config_parts(config_file_t);

config_part_t config_file_get_config_part(config_file_t, const char *title);

int config_file_get_config_part_size(config_file_t);

#endif //CONFIG_STATIC_CONFIG_FILE_C_H
