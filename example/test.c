#include "config_file_c.h"
#include "config_part_c.h"
#include "config_value_c.h"
#include <stdio.h>

void test_c() {
    void *config = read_config("config.txt");
    void *part = config_file_get_config_parts(config);
    while (part) {
        char title_part[config_part_get_title_length(part)];
        config_part_get_title(part, (char *) &title_part);
        printf("Part Title: %s\n", title_part);
        void *value = config_part_get_values(part);
        while (value) {
            char title_value[config_value_get_title_length(value)];
            config_value_get_title(value, (char *) &title_value);
            char value_str[config_value_get_value_length(value)];
            config_value_get_value(value, (char *) &value_str);
            printf("Value name: %s Value: %s\n", title_value, value_str);
        }
        part = config_part_get_next(part);
    }
}