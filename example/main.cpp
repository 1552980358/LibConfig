#include <iostream>
using std::cout;
using std::endl;
#include <libconfig.h>
#include "fstream"
using std::ifstream;


int main() {

    auto file = config_file("config.txt");
    auto *part = file.get_config_parts();
    while (part) {
        cout << part->get_title() << endl;
        auto *values = part->get_values();
        while (values) {
            cout << *values->get_title() << " " << *values->get_value() << endl;
            values = values->get_next();
        }
        part = part->get_next();
    }
    return 0;
}
