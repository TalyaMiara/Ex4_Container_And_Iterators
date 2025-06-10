//talyam123@gmail.com

#ifndef SIDE_CROSS_ORDER_HPP
#define SIDE_CROSS_ORDER_HPP

#include "MyContainer.hpp"
#include <vector>
#include <algorithm>   // for std::sort
#include <cstddef>     // for std::size_t
#include <stdexcept>   // for std::out_of_range

namespace Container {

    template<typename T>
    class MyContainer;
    /**
     * @brief Iterator that traverses elements in side-cross order:
     * smallest, largest, next-smallest, next-largest, etc.
     * 
     * Original input: [7, 15, 6, 1, 2]
     * Sorted:         [1, 2, 6, 7, 15]
     * Side-cross:     [1, 15, 2, 7, 6]
     */

    template<typename T>// Template class for a container that can hold elements of type T, that the default type is int
    class SideCrossOrder {

    private:
        const MyContainer<T>& container; // Reference to the container being iterated
        std::vector<T> crossView;  // Side-cross ordered data
        std::size_t pos;       // Current position in crossView

    public:
        /**
         * @brief Constructor - builds the side-cross ordering.
         * 
         * @param elements Input container elements.
         * @param startPos Where to start (default: 0).
         */
    SideCrossOrder(const MyContainer<T>& container, std::size_t startPos = 0)
            : container(container),pos(startPos)
        {
            const auto& elements = container.getElements();
            if (elements.empty()) {
                throw std::invalid_argument("Cannot create SideCrossOrder with empty container");
            }

            std::vector<T> sorted = elements;
            std::sort(sorted.begin(), sorted.end());

            std::size_t left = 0;
            std::size_t right = sorted.size() - 1;
            while (left <= right) {
                if (left == right) {
                    crossView.push_back(sorted[left]);
                } else {
                    crossView.push_back(sorted[left]);
                    crossView.push_back(sorted[right]);
                }
                ++left;
                if (right > 0) --right;
            }
        }


        /**
         * @brief Dereference operator.
         * 
         * @return Reference to the element at current pos.
         * @throws std::out_of_range if pos is invalid.
         * This operator allows access only to the value of the element at the current pos.
         * If the pos is out of range, it throws an exception.
         */
        const T& operator*() const {
            if (pos >= crossView.size()) {
                throw std::out_of_range("Iterator out of range");
            }
            return crossView[pos];
        }

        /**
         * @brief Prefix increment.
         * Increments the iterator to the next element.
         * This operator modifies the current iterator state to point to the next element in the sorted order.
         * If the pos exceeds the size of the sorted data, it throws an exception.
         * 
         * @return Reference to the updated iterator.
         */
        SideCrossOrder& operator++() {
            if (pos >= crossView.size()) {
                throw std::out_of_range("Iterator increment past end");
            }
            ++pos;// Increment the pos to point to the next element
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
        SideCrossOrder operator++(int) {
            SideCrossOrder temp = *this;
            ++(*this);// Call the prefix increment to update the current iterator state
            // The current iterator state is updated, but the original state is returned
            return temp;
        }

        /**
         * @brief Equality comparison.
         * Compares two SideCrossOrder instances to check if they point to the same pos.
         * 
         * This operator checks if both iterators are at the same position in their respective sorted data.
         * It is used to determine if two iterators are equal, which is useful in algorithms that require comparison of iterators.
         * @param other Iterator to compare to.
         * @return true if both iterators point to the same pos.
         */
        bool operator==(const SideCrossOrder& other) const {
            // Compare the indices of both iterators to determine equality
            return pos == other.pos && crossView == other.crossView;    }

        /**
         * @brief Inequality comparison.
         * 
         * Compares two SideCrossOrder instances to check if they point to different indices.
         * This operator is the negation of the equality operator.
         * @param other Iterator to compare to.
         * @return true if the iterators are not equal.
         */
        bool operator!=(const SideCrossOrder& other) const {
            return !(*this == other);
        }
    };

} // namespace Container

#endif // SIDE_CROSS_ORDER_HPP

