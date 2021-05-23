#include "libconfig.h"

#include <iostream>

config_file *read_config(const char *c_str) {
    return new config_file(c_str);
}

config_file *read_config(const string &str) {
    return new config_file(str);
}

config_file *read_config(const char *c_str, const bool &read) {
    return new config_file(c_str, read);
}

config_file *read_config(const string &str, const bool &read) {
    return new config_file(str, read);
}