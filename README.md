# StringCalc

## Description

Integers and other data types alike have a specific set of values which they can have. If you want to use bigger numbers than these data types offer, you will need a workaround. Strings can theoretically be infinite (practically they are limited by the maximum available memory space). This C++ library offers the ability to use strings and calculate equations with them as if they were numbers.

The maximum size of a string is given by `std::string().max_size()`. In standard C++ it is around 2^32. However, this can vary due to compiler and memory implementation. I will try to optimize the code, so that strings can be as long as possible. An idea might be to use pointers (call-by-reference) or the (rope data structure)[https://en.wikipedia.org/wiki/Rope_(data_structure)]. This will need further investigation though.

At the moment, all implemented functions take positive _integers_ and return the calculated number as a string. The subtraction function will put a negative sign at the start of the string in case the result is negative. The input for all functions needs to be positive.

## Example usage

```cpp
// Addition
std::cout << "5 + 6 = " << StringCalc::Decimal::add("5", "6") << "\n";

// Subtraction
std::cout << "12 - 7 = " << StringCalc::Decimal::sub("12", "7") << "\n";

// Binary multiplication
std::cout << "10111 * 111 = " << StringCalc::Binary::mult_b("10111", "111") << "\n";

// Binary division
std::cout << "10110 / 111 = " << StringCalc::Binary::div_b("10110", "111") << "\n";
```

## Planned features

- [x] Function for factorials --> n!
- [x] Function for power --> base^exponent
- [x] Functionality for calculation of binary strings
- [ ] Functionality for calculation of hexadecimal strings
- [ ] Function for modulo (for decimals) --> m mod n
- [ ] Improve code readability and error handling
    - [ ] Helping functions _isNegative_, _isZero_, _isDecimal_, ...
    - [ ] Improve error messages
    - [ ] Don't allow empty strings as input (functions return empty string in case an error occurs)
- [ ] Performance improvements: I want to take another look at the implementation to see if I can optimize some things
    - [ ] Use unsigned long long instead of int --> Strings can even be longer
    - [ ] Faster algorithmic calculation (if possible)

# Licence

This project is licensed under the [MIT Licence](https://mit-license.org/). See LICENCE file for more information.
