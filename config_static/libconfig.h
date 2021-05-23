#ifndef LIBCONFIG_LIBCONFIG_H
#define LIBCONFIG_LIBCONFIG_H

#include "config_file.h"

config_file *read_config(const char *);

config_file *read_config(const string &);

config_file *read_config(const char *, const bool &);

config_file *read_config(const string &, const bool &);

#endif //LIBCONFIG_LIBCONFIG_H
