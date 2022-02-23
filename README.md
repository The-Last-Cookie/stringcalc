# StringCalc

## Description

Integers and other data types alike have a specific set of values which they can have. If you want to use bigger numbers than these data types offer, you will need a workaround. Strings can theoretically be infinite (practically, they are limited by the maximum available memory space). This C++ library offers the ability to use strings and calculate equations with them as if they were numbers.

The maximum size of a string is given by `std::string().max_size()`. In standard C++ it is around 2^32 most of the times. However, this can vary due to compiler and memory implementation. I will try to optimize the code, so that strings can be as long as possible. An idea might be to use the [rope data structure](https://en.wikipedia.org/wiki/Rope_(data_structure)). This will need further investigation though.

Every main function can only have positive numbers as input and returns the calculated number as a string. The _base_ parameter can be between 2 and 36.

## Main features

### Mathematical operations

Here are a few examples of calculations that can be done with the library:

```cpp
// Addition
std::cout << "5 + 6 = " << StringCalc::add(10, "5", "6") << "\n";

// Subtraction
std::cout << "12 - 7 = " << StringCalc::sub(10, "12", "7") << "\n";

// Binary multiplication
std::cout << "10111 * 111 = " << StringCalc::mult(2, "10111", "111") << "\n";

// Binary division
std::cout << "10110 / 111 = " << StringCalc::div(2, "10110", "111") << "\n";
```

### Converter

With the converter, you can convert numbers from one base to another. The bases may be between 2 and 36. So there are the numbers 1 to 9 as well as the letters A to Z to represent a number. If you want to use one number several times, it is recommended to `parse` this number once and then call `convertTo` each time for a new base. Unfortunately, the converter can get quite slow with big numbers (more than 10 digits).

```cpp
StringCalc::Converter conv;
conv.parse("1679615", 10);
std::cout << "1679615 Base 10 in Base 16 is: " << conv.convertTo(16);
```

## Technical documentation

*Note: There are more functions available in the library, but they aren't listed here. These functions are used for internal calculations and therefore shouldn't be used when implementing this library. They are marked as `h_` (h as in helper). Additionally, using them without prior caution can lead to unexpected behavior.*

- Main functions:
    - function _add_: Addition
    - function _sub_: Subtraction
    - function _mult_: Multiplication
    - function _div_: Integer division (without remainder)
    - function _mod_: Modulo
    - function _pow_: Exponentiation
    - function _fact_: Factorial

- Class Converter:
    - method _parse_: Parse a number into the converter
    - method _convertTo_: Convert the number which was given via `parse` to a specific base

- Namespace Helper:
    - function _min_: Find the string with the smaller value
    - function _max_: Find the string with the higher value
    - function _intToString_: Convert the given number to its string value (10 and higher will be converted to A, B, etc. respectively)
    - function _charToInt_: Convert a string value to its integer value (e.g. A will be converted to 10)
    - function _removeLeadingZeros_: Removes zeros in front of a string (for example, "00" will be converted to "0")

## Planned features

### Major release v2

- [x] Merge all number categories into one namespace and use base as indicator
- [ ] Support for negative numbers
- [ ] Use more pointers (call-by-reference)

## Licence

This project is licensed under the [MIT Licence](https://mit-license.org/). See the [LICENCE](LICENCE.md) file for more information.
