# StringCalc

## Description

Integers and other data types alike have a specific set of values which they can have. If you want to use bigger numbers than these data types offer, you will need a workaround. Strings can theoretically be infinite (practically, they are limited by the maximum available memory space). This C++ library offers the ability to use strings and calculate equations with them as if they were numbers.

The maximum size of a string is given by `std::string().max_size()`. In standard C++ it is around 2^32 most of the times. However, this can vary due to compiler and memory implementation. I will try to optimize the code, so that strings can be as long as possible. An idea might be to use pointers (call-by-reference) or the [rope data structure](https://en.wikipedia.org/wiki/Rope_(data_structure)). This will need further investigation though.

At the moment, all implemented functions take positive _integers_ and return the calculated number as a string. The input as well as the output for all functions needs to be positive.

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

## Overview over the library

- namespace Decimal:
    - function _add_
    - function _sub_
    - function _mult_
    - function _div_
    - function _pow_
    - function _fact_
    - funtion _max_

- namespace Binary:
    - function _add\_b_
    - function _sub\_b_
    - function _mult\_b_
    - function _div\_b_
    - funtion _max\_b_

- namespace Hexadecimal:
    - function _add\_h_
    - function _sub\_h_
    - function _mult\_h_
    - function _div\_h_
    - funtion _max\_h_

## Planned features

### Major release v1

- [x] Function for factorials --> n!
- [x] Function for power --> base^exponent
- [x] Functionality for calculation of binary strings
- [x] Functionality for calculation of hexadecimal strings
- [ ] Function for modulo (for decimals) --> m mod n
- [x] Improve code readability and error handling
    - [x] Helping functions _isZero_, _isDecimal_, ...
    - [x] Improve error messages
    - [x] Don't allow empty strings as input (functions return empty string in case an error occurs)
- [x] Performance improvements: I want to take another look at the implementation to see if I can optimize some things
    - [x] Use unsigned long long instead of int --> Strings can even be longer
    - [x] Faster algorithmic calculation (if possible)
    - [x] Check efficiency of _isZero_

# Licence

This project is licensed under the [MIT Licence](https://mit-license.org/). See LICENCE file for more information.
