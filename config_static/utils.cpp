#include "utils.h"

bool str_starts_with(const string &str, char c) {
#ifdef __CYGWIN__
    // This is for cywin
    return str.starts_with(c)
#endif
    return !str.empty() && str.find(c) == 0;
}

bool str_ends_with(const string &str, char c) {
#ifdef __CYGWIN__
    // This is for cywin
    return str.ends_with(c);
#endif
    return !str.empty() && str.find_last_of(c) == str.size() - 1;
}

string cut_value(const string &str) {
    auto tmp = string(str);
    if (str_starts_with(str, ' ')) {
        for (int i = 0; i < tmp.length(); ++i) {
            if (tmp[i] != ' '){
                tmp = tmp.substr(i);
                break;
            }
        }
    }
    if (str_ends_with(tmp, ' ')) {
        for (int i = (int) tmp.length() - 1; i > -1 ; --i) {
            if (tmp[i] != ' ') {
                return tmp.substr(0, i + 1);
            }
        }
    }
    return tmp;
}

string remove_tab(const string &str) {
    string tmp;
    for (char i : str) {
        tmp += i == '\t' ? ' ' : i;
    }
    return tmp;
}