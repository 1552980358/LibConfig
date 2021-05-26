# LibConfig

## About

- Read the config and load into memory, for software self-setting

## Language support
- C++

## Future maintenance
- Support C
- Modify config in memory and write to config file
- More complex scene of config support

## Config file format

- Config Part
  - Space is allowed between text
  - Space will be ignored after '[' and before ']' 
  - Example
    1. `[Title]` will give `Title`
    2. `[Ti tle] ` will give `Ti tle`
    3. `[ Tit tle ]` will give `Tit tle`
    
- Config title
  - Space before the first letter will be ignored
  - Space between last letter and `=` will be ignored
  - Example
    1. `Title=` will give `Title`
    2. `Tit le=` will give `Tit le`
    3. ` Tit le =` will give `Tit le`
    
- Config value
  - Space before the first letter will be ignored
  - Space between first letter and `=` will be ignored
  - Example
    1. `=value` will give `value`
    2. `=val ue` will give `val ue`
    3. `= val ue ` will give `val ue`
  
- `config_part` can be identified with "[]" pairs
- A `config_part` can contain more than one `config_value`s
- Please look at following "Example" part for more details

## Example
- [Full example](https://github.com/1552980358/LibConfig/tree/master/example)
- Following is the example of reading and outputting using `std::cout` in `c++`
  ```c++
  auto file = config_file("config.txt");// direct create object
  auto *part = file.get_config_parts(); // get the head of each parts of configs
  while (part) {                        // check whether the pointer is null or not
    cout << part->get_title() << endl;  // output title of config part
    auto *values = part->get_values();  // get the head of config values
    while (values) {                    // check whether the pointer is null or not
      cout << "Value name: " << *values->get_title()        // get the title of the value
           << " Value: " << *values->get_value() << endl;   // get the value
      values = values->get_next();      // move to next value, nullptr will be retuned if no further value
    }
    part = part->get_next();            // move to next part, nullptr will be retuned if no further value
  }
  ```
  - Remember to include the header file
    `#include "libconfig.h"`

  - Following is the output of example
    ```
    Part Title: Config File
    Value name: t1 Value: 13
    Value name: t2 Value: 32 4
    Value name: t3 Value: 123
    Part Title: Config File2
    Value name: v1 Value: bug
    Value name: v 2 Value: go
    Value name: v3 Value: aw ay
    ```
    
  - Following is the config file in example
    ```
    [Config File]
    t1 =13
       t2=32 4
     t3 =123  

    [ Config File2 ]
    v1 = bug
    v 2=go
     v3 = aw ay 
    ```
    
  - Following is the full version of example
  ```c++
  #include <iostream>
  using std::cout;
  using std::endl;
  #include <libconfig.h>

  int main() {

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
      return 0;
  }
  ```
  
## License - [GNU General Public License v3.0](https://github.com/1552980358/LibConfig/blob/master/LICENSE)
```
                   GNU GENERAL PUBLIC LICENSE
                     Version 3, 29 June 2007
                       
Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
Everyone is permitted to copy and distribute verbatim copies
of this license document, but changing it is not allowed.
```