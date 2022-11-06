# StringCalc

## Content

1. [Description](#description)
2. [Main features](#main-features)
3. [Technical documentation](#technical-documentation)
4. [Testing](#testing)
5. [Planned features](#planned-features)
6. [Links](#links)
7. [Licence](#licence)

## Description

Integers and other data types alike have a specific set of values which they can have. If you want to use bigger numbers than these data types offer, you will need a workaround. Strings can theoretically be infinite (practically, they are limited by the maximum available memory space). This C++ library offers the ability to use strings and calculate equations with them as if they were numbers.

The maximum size of a string is given by `std::string().max_size()`. In standard C++ it is around 2^32 most of the times. However, this can vary due to compiler and memory implementation. I will try to optimize the code, so that strings can be as long as possible. An idea might be to use the [rope data structure](https://en.wikipedia.org/wiki/Rope_(data_structure)). This will need further investigation though.

Every operator function can have positive as well as negative numbers as input and returns the calculated number as a string. The *base* parameter can be between 2 and 36. **Note: Negative inputs for the factorial function will be used as if they are positive.**

## Main features

This section lists a few examples of calculations that can be done with the library. More examples can be found in the `example.cpp` file.

### Mathematical operations

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

With the converter, you can convert positive numbers from one base to another. The bases may be between 2 and 36. So there are the numbers 1 to 9 as well as the letters A to Z to represent a number. If you want to use one number several times, it is recommended to `parse` this number once and then call `convertTo` each time for a new base. Unfortunately, the converter can get quite slow with big numbers (more than 30 digits).

```cpp
StringCalc::Converter conv;
conv.parse("1679615", 10);
std::cout << "1679615 Base 10 in Base 16 is: " << conv.convertTo(16);
```

## Technical documentation

### Overview

#### Main functions

| Name | Description | Input | Output |
|---|---|---|---|
| *add* | Addition | Number base and two integers | Sum |
| *sub* | Subtraction | Number base and two integers | Difference |
| *mult* | Multiplication | Number base and two integers | Product |
| *div* | Integer division (without remainder) | Number base and two integers | Quotient |
| *mod* | Modulo | Number base and two integers | Remainder |
| *pow* | Exponentiation | Number base and two integers | Power |
| *fact* | Factorial | Number base and one positive integer | Factorial |

#### Converter methods

| Name | Description | Input | Output |
|---|---|---|---|
| *parse* | Parse a number into the converter | Number base and one positive integer | *Nothing* |
| *convertTo* | Convert the number which was given via `parse` to a specific base | Number base | Number in given number base |

#### Helper functions

| Name | Description | Input | Output | Commentary |
|---|---|---|---|---|
| *min* | Find the string with the smaller value | Two positive integers | String with smaller value | Can lead to unexpected behaviour if the given numbers are invalid |
| *max* | Find the string with the higher value | Two positive integers | String with the higher value | Can lead to unexpected behaviour if the given numbers are invalid |
| *intToString* | Convert the given number to its string value | One positive integer | String value of integer | (`10` and higher will be converted to `A`, `B`, etc. respectively) |
| *charToInt* | Convert a string value to its integer value | Char value | Actual integer value of char | E.g. `A` will be converted to `10` |
| *removeLeadingZeros* | Remove zeros in front of a string | One positive integer | Positive integer without any zeros in front | |

#### Private functions

*Notice: These functions here are available in the library, however they are used for internal calculations and therefore shouldn't be used when implementing this library as they have no input validation. Though, the functions are listed here, so that the documentation is complete. Additionally, using them without prior caution can lead to unexpected behavior.*

| Name | Description | Input | Output | Commentary |
|---|---|---|---|---|
| *h\_add* | Helper function for addition | Number base and two positive integers | Sum |
| *h\_sub* | Helper function for subtraction | Number base and two positive integers | Difference |
| *h\_mult* | Helper function for multiplication | Number base and two positive integers | Product |
| *h\_div\_sub* | Normal integer division with naive subtraction | Two positive integers | Quotient without remainder | Needed as a component for the actual division algorithm |
| *h\_div* | Helper function for integer division | Number base, two positive integers and a parameter if quotient or remainder should be returned | Quotient or remainder |
| *h\_mod* | Helper function for modulo | Number base and two positive integers | Remainder |
| *h\_pow* | Helper function for exponentiation | Number base and two positive integers | Power |
| *h\_fact* | Helper function for factorial | Number base and one positive integer | Factorial |

### Testing

This library uses [doctest](https://github.com/doctest/doctest) for testing its functionalities. All tests can be found in the [`tests`](testing/tests) folder.

However, there is one problem while executing tests. Since I decided to not use custom exceptions, the program will print out errors for every test (only if there are any of course). I'm not sure at the moment how to deactivate/activate these error messages depending on the context, so I will leave it like this for now (I'm aware that you can define a global variable for such things, but I'm not fond of this approach).

To add new tests, you need to create a header file (`.h`) in the `tests` subfolder. Every file in there has the following structure:

```cpp
// Test.h
#pragma once

#include "../doctest.h"

TEST_SUITE("test") {
    // Your test cases
}
```

As a final step, you need to include the header file in the `main.cpp` file in the testing directory, like so:

```cpp
#include "tests/Test.h"
```

## Planned features

### Major release v2

- [x] Merge all number categories into one namespace and use base as indicator
- [x] Support for negative numbers
- [ ] Use more pointers (call-by-reference)

## Links

- [doctest](https://github.com/doctest/doctest) ([v2.4.8](https://github.com/doctest/doctest/releases/tag/v2.4.8))

## Licence

This project is licensed under the [MIT Licence](https://mit-license.org/). See the [LICENCE](LICENCE.md) file for more information.
