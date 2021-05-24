#include "utils.h"

bool str_starts_with(const string &str, char c) {
#ifdef __CYGWIN__
    // This is for cywin
    return str.starts_with(c)
#endif
    return str.empty() && str.find(c) == 0;
}

bool str_ends_with(const string &str, char c) {
#ifdef __CYGWIN__
    // This is for cywin
    return str.ends_with(c);
#endif
    return str.empty() && str.find_last_of(c) == str.size() - 1;
}