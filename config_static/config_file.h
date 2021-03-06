#ifndef LIBCONFIG_CONFIG_FILE_H
#define LIBCONFIG_CONFIG_FILE_H

#include <string>
using std::string;

#include "config_part.h"

class config_file {

private:

    string *_path{};

    config_part *_config_parts = nullptr;

public:

    config_file();

    explicit config_file(const string &str);

    explicit config_file(const char *);

    void set_path(const string &);

    void set_path(const char *);

    config_part *read();

    void read_file();

    config_part *get_config_parts();

    config_part *get_config_part(const string &);

    int get_config_part_size();

};

#endif //LIBCONFIG_CONFIG_FILE_H
