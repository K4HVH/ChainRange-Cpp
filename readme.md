# ChainRange Template Class Documentation

The `ChainRange` template class allows you to create a range of values in a chained manner, similar to Python's `range()` function. It generates a sequence of values from a specified starting point to an ending point with a given step increment. This documentation provides an overview of the class, its constructors, and how to use it.

## Table of Contents
- [Introduction](#introduction)
- [Class Definition](#class-definition)
- [Constructors](#constructors)
- [Usage](#usage)
- [Example](#example)

## Introduction

The `ChainRange` template class provides a convenient way to iterate over a sequence of values. It can be particularly useful in cases where you need to generate a range of values for various purposes such as loops or calculations.

## Class Definition

```cpp
template<typename T>
class ChainRange {
public:
    class iterator : public std::iterator<std::input_iterator_tag, T> {
    public:
        explicit iterator(const ChainRange& cr, T value) : cr(cr), value(value) {}

        T operator*() const {
            return value;
        }

        iterator& operator++() {
            value += cr.step;
            return *this;
        }

        bool operator!=(const iterator& other) const {
            return (cr.step > 0 && value < other.value) || (cr.step < 0 && value > other.value);
        }

    private:
        const ChainRange& cr;
        T value;
    };

    ChainRange(T start, T stop, T step) : start(start), stop(stop), step(step) {}

    iterator begin() const {
        return iterator(*this, start);
    }

    iterator end() const {
        return iterator(*this, stop);
    }

private:
    T start;
    T stop;
    T step;
};
```

## Constructors

### `ChainRange(T start, T stop, T step)`

Creates a `ChainRange` object with the specified start, stop, and step values.

- `start` (T): The starting value of the range.
- `stop` (T): The ending value of the range (not included in the range).
- `step` (T): The increment between consecutive values in the range.

## Usage

To use the `ChainRange` class, follow these steps:

1. Include the necessary header files.
   
```cpp
#include <iostream>
#include "ChainRange.hpp" // Include the header file containing the ChainRange template class.
```

2. Create a `ChainRange` object by specifying the start, stop, and step values.

3. Use iterators to loop through the generated range.

4. Perform desired operations with the generated values.

## Example

Here's an example demonstrating how to use the `ChainRange` class:

```cpp
#include <iostream>
#include "ChainRange.hpp"

int main() {
    // Create a ChainRange object that generates values from 1 to 10 with a step of 2.
    ChainRange<int> range(1, 11, 2);

    // Loop through the range and print each value.
    for (int value : range) {
        std::cout << value << " ";
    }

    std::cout << std::endl;

    return 0;
}
```

Output:
```
1 3 5 7 9
```

In this example, we created a `ChainRange` object that generates values from 1 to 10 (inclusive of 1 and exclusive of 11) with a step of 2. We then used a `for` loop to iterate through the generated range and printed each value.
