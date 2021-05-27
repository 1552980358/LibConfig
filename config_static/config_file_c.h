#ifndef CONFIG_STATIC_CONFIG_FILE_C_H
#define CONFIG_STATIC_CONFIG_FILE_C_H

void * read_config(const char *);

void config_file_set_path(void *, const char *);

void config_file_read_file(void *);
void *config_file_read(void *);

void *config_file_get_config_parts(void *);

void *config_file_get_config_part(void *, const char *title);

int config_file_get_config_part_size(void *);

#endif //CONFIG_STATIC_CONFIG_FILE_C_H
