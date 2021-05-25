#ifndef LIBCONFIG_CONFIG_PART_H
#define LIBCONFIG_CONFIG_PART_H

#include <string>
using std::string;

#include "config_value.h"

class config_part {

private:

    string _title{};

    config_value *_values = nullptr;

    config_part *_prev = nullptr;

    config_part *_next = nullptr;

public:

    explicit config_part(const string &, config_part *);

    string get_title();

    void set_prev(config_part *prev);

    void set_next(config_part *next);

    config_part *get_prev();

    config_part *get_next();

    void add_value(const string &, const string &);

    config_value *get_values();

    string *get_value(const string &);

    string *get_value(const int &);

};

config_part *get_head(config_part *);

#endif //LIBCONFIG_CONFIG_PART_H
