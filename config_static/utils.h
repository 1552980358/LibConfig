#ifndef CONFIG_STATIC_UTILS_H
#define CONFIG_STATIC_UTILS_H

#include <string>
using std::string;

bool str_starts_with(const string &str, char c);

bool str_ends_with(const string &str, char c);

string cut_value(const string &);

string remove_tab(const string &);

string get_config_part_value_title(const string &);

string get_config_part_value_value(const string &);

#endif //CONFIG_STATIC_UTILS_H
