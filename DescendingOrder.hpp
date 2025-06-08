//talyam123@gmail.com

#ifndef DESCENDING_ORDER_HPP
#define DESCENDING_ORDER_HPP

#include "MyContainer.hpp"
#include <vector>
#include <algorithm>   // for std::sort
#include <cstddef>     // for std::size_t
#include <stdexcept>   // for std::out_of_range

namespace Container {

/**
 * @brief Iterator that traverses elements of a container in descending order.
 * 
 * Upon construction, the iterator creates a sorted descending view of the container’s elements.
 * 
 * For example:
 * 
 * Original input: [7, 15, 6, 1, 2]
 * Sorted descending: [15, 7, 6, 2, 1]
 * Traversal order (left to right): 15, 7, 6, 2, 1
 */

template<typename T>// Template class for a container that can hold elements of type T, that the default type is int
class DescendingOrder {

private:
    std::vector<T> sortedView;   ///< Sorted copy of container’s elements
    std::size_t index=0;            ///< Current index in sortedView- Current iterator position

public:
     /**
     * @brief Constructor: copies and sorts the container's data in descending order.
     * This constructor takes a vector of elements, sorts them in descending order,
     * and initializes the iterator to the specified starting index.
     * 
     * @param elements Vector of container elements.
     * @param startPos Starting index (default = 0).
     */
    DescendingOrder(const std::vector<T>& elements, std::size_t startPos = 0)
        : pos(startPos)
    {
        sortedView = elements;
        std::sort(sortedView.begin(), sortedView.end(), std::greater<T>()); // sort descending
    }


    /**
     * @brief Dereference operator.
     * 
     * @return Reference to the element at current index.
     * @throws std::out_of_range if index is invalid.
     * This operator allows access only to the value of the element at the current index.
     * If the index is out of range, it throws an exception.
     */
    const T& operator*() const {
        if (index >= sortedView.size()) {
            throw std::out_of_range("Iterator out of range");
        }
        return sortedView[index];
    }

    /**
     * @brief Prefix increment.
     * Increments the iterator to the next element.
     * This operator modifies the current iterator state to point to the next element in the sorted order.
     * If the index exceeds the size of the sorted data, it throws an exception.
     * 
     * @return Reference to the updated iterator.
     */
    DescendingOrder& operator++() {
        if (index >= sortedView.size()) {
            throw std::out_of_range("Iterator increment past end");
        }
        ++index;// Increment the index to point to the next element
        return *this;
    }

    /**
     * @brief Postfix increment.
     * Increments the iterator to the next element, returning a copy of the iterator before incrementing.
     * This operator allows the use of the iterator in expressions where the original state is needed before the increment.
     * It returns a copy of the iterator before the increment operation, allowing for use in expressions.
     * @param int Dummy parameter to distinguish from prefix increment.
     * 
     * @return Copy of iterator before increment.
     */
    DescendingOrder operator++(int) {
        DescendingOrder temp = *this;
        ++(*this);// Call the prefix increment to update the current iterator state
        // The current iterator state is updated, but the original state is returned
        return temp;
    }

    /**
     * @brief Equality comparison.
     * Compares two DescendingOrder instances to check if they point to the same index.
     * 
     * This operator checks if both iterators are at the same position in their respective sorted data.
     * It is used to determine if two iterators are equal, which is useful in algorithms that require comparison of iterators.
     * @param other Iterator to compare to.
     * @return true if both iterators point to the same index.
     */
    bool operator==(const DescendingOrder& other) const {
        // Compare the indices of both iterators to determine equality
        return pos == other.pos && sortedView == other.sortedView;    }

    /**
     * @brief Inequality comparison.
     * 
     * Compares two DescendingOrder instances to check if they point to different indices.
     * This operator is the negation of the equality operator.
     * @param other Iterator to compare to.
     * @return true if the iterators are not equal.
     */
    bool operator!=(const DescendingOrder& other) const {
        return !(*this == other);
    }
};

} // namespace Container

#endif // DESCENDING_ORDER_HPP
