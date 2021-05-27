#include <iostream>
using std::cout;
using std::endl;
#include <libconfig.h>

extern "C" {
#include "test.h"
}

void test_cpp() {
    auto file = config_file("config.txt");
    auto *part = file.get_config_parts();
    while (part) {
        cout << "Part Title: " << part->get_title() << endl;
        auto *values = part->get_values();
        while (values) {
            cout << "Value name: " << *values->get_title() << " Value: " << *values->get_value() << endl;
            values = values->get_next();
        }
        part = part->get_next();
    }
}

int main() {
    test_cpp();
    test_c();
    return 0;
}