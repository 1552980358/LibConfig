#ifndef CONFIG_STATIC_CONFIG_VALUE_H
#define CONFIG_STATIC_CONFIG_VALUE_H

#include <string>
using std::string;

class config_value {

private:

    string _title{};

    string _value{};

    config_value *_prev = nullptr;

    config_value *_next = nullptr;

public:

    config_value(const string &, const string &, config_value *);

    string *get_title();

    void set_title(const string &);

    string *get_value();

    void set_value(const string &);

    config_value *get_prev();

    void set_prev(config_value *);

    config_value *get_next();

    void set_next(config_value *);

};

config_value *get_last(config_value *);

config_value *get_head(config_value *);

int cal_config_value_size(config_value *head);

#endif //CONFIG_STATIC_CONFIG_VALUE_H
