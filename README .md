# Container and Iterators Project (Assignment 4)

**Email:** taliyam123@gmail.com  
**Default Template Type:** `int` (supports any comparable type)


---
This project implements a generic container MyContainer<T> for comparable types with dynamic add/remove operations.

It includes six custom iterators following STL-style traversal.
All the project is under the namespace Container.
## Project Overview

`MyContainer<T>` is a generic container of comparable elements, supporting:

- `addElement(const T&)` – add an element to the container.
- `remove(const T&)` – remove all occurrences of a value (throws `std::runtime_error` if not found).
- `size() const noexcept` – returns number of elements.
- `operator<<` – prints as `[a, b, c]` or `[]`.

## Iterators

Each of the following iterators supports `begin()` and `end()` and throws `std::out_of_range` when overused:

- `OrderIterator` – Insertion order.
- `AscendingOrderIterator` – Sorted ascending.
- `DescendingOrderIterator` – Sorted descending.
- `SideCrossOrderIterator` – Alternating smallest largest (e.g. `[1, 15, 2, 7, 6]`).
- `ReverseOrderIterator` – Reverse of insertion order.
- `MiddleOutOrderIterator` – Starts from middle, alternates left/right (e.g. `[6, 15, 1, 7, 2]`).

## Supported Operators in Iterators

Each iterator implements the standard C++ interface:

- `*it` – returns the current element (`std::out_of_range` if `it == end()`).
- `++it` / `it++` – advances the iterator (`std::out_of_range` if past end).
- `it1 == it2`, `it1 != it2` – compare container and position.

When `begin() == end()`, iteration is complete and dereferencing is invalid.

Explain of each operator:
- `operator*()` – Dereferences the iterator to return the current element.  

- `operator++()` – Prefix increment. Advances the iterator to the next element.  

- `operator++(int)` – Postfix increment. Advances and returns the previous state.

- `operator==()` and `operator!=()` – Compare two iterators for equality or inequality.  
  Equality means both the container and the index are the same.

## Project Structure
## Unit Tests

The file `test.cpp` covers:

- Empty containers: `size`, `remove`, `operator<<`, and iterator behavior.
- Valid and invalid `remove()`.
- All iterator traversal patterns (including single, even, odd, duplicates).
- `operator==`, `operator!=`, exception cases.
- Valgrind tested for memory leaks.

## files 

- MyContainer.hpp  
- Order.hpp  
- AscendingOrder.hpp  
- DescendingOrder.hpp  
- SideCrossOrder.hpp  
- ReverseOrder.hpp  
- MiddleOutOrder.hpp  
- Demo.cpp  
- main.cpp  
- test.cpp  
- doctest.h  
- makefile  
- README.md  


## Makefile Targets

- `make Main` – Build and run the demo program.
- `make test` – Build and run unit tests (requires `doctest.h`).
- `make valgrind` – Check for memory leaks on the Demo and the Tests.
- `make clean` – Remove generated binaries.


## License & Academic Integrity

This project was developed as part of a university assignment.
