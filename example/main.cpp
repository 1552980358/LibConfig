#include <iostream>

#include "library/libconfig.h"

int main() {
    auto *config = read_config(R"(C:\Users\Huli\Desktop\config.txt)");

    return 0;
}
