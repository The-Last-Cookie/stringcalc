# StringCalc

## Description

Integers and other data types alike have a specific set of values which they can have. If you want to use bigger numbers than these data types offer, you will need a workaround. Strings can theoretically be infinite (practically they are limited by the maximum available memory space). This C++ library offers the ability to use strings and calculate equations with them as if they were numbers.

Currently, the length of strings is limited to 2^31-1, so approximately 2 billion characters. I want to improve this in a future release.
At the moment, all implemented functions take positive _integers_ and return the calculated number as a string. The subtraction function will put a negative sign at the start of the string in case the result is negative. The input for all functions needs to be positive.

## Example usage

```cpp
// Addition
std::cout << "5 + 6 = " << StringCalc::add("5", "6") << "\n";

// Subtraction
std::cout << "12 - 7 = " << StringCalc::sub("12", "7") << "\n";

// Multiplication
std::cout << "8 * 11 = " << StringCalc::mult("8", "11") << "\n";

// Division
std::cout << "10 / 5 = " << StringCalc::div("10", "5") << "\n";
```

## Planned features

- [x] Function for factorials --> n!
- [x] Function for power --> base^exponent
- [ ] Functionality for calculation of binary strings (maybe even float and hex, not sure yet)
- [ ] Performance improvements: I want to take another look at the implementation to see if I can optimize some things

# Licence

This project is licensed under the [MIT Licence](https://mit-license.org/). See LICENCE file for more information.
