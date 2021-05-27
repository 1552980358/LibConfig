extern "C" {
#include "config_file_c.h"
}
#include "config_file.h"

void *read_config(const char *c) {
    return new config_file(c);
}

void config_file_set_path(void *ptr, const char *c) {
    ((config_file *)ptr)->set_path(c);
}

void config_file_read_file(void *ptr) {
    ((config_file *)ptr)->read_file();
}

void *config_file_read(void *ptr) {
    return ((config_file *)ptr)->read();
}

void *config_file_get_config_parts(void *ptr) {
    return ((config_file *)ptr)->get_config_parts();
}

void *config_file_get_config_part(void * ptr, const char *title) {
    return ((config_file *)ptr)->get_config_part(title);
}

int config_file_get_config_part_size(void *ptr) {
    return ((config_file *)ptr)->get_config_part_size();
}