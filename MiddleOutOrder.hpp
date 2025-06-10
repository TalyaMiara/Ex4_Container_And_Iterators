//talyam123@gmail.com

#ifndef MIDDLE_OUT_ORDER_HPP
#define MIDDLE_OUT_ORDER_HPP

#include "MyContainer.hpp"
#include <vector>
#include <algorithm>   // for std::sort
#include <cstddef>     // for std::size_t
#include <stdexcept>   // for std::out_of_range

namespace Container {

    template<typename T>
    class MyContainer;

    /**
     * @brief Iterator that traverses the container starting from the middle,
     * then alternates left and right: middle, left, right, left, right...
     * 
     * For example: [7,15,6,1,2] → [6,15,1,7,2]
     */

    template<typename T>// Template class for a container that can hold elements of type T, that the default type is int
    class MiddleOutOrder {

    private:
        const MyContainer<T>& container; // Reference to the container being iterated
        std::vector<T> middleOutView;  // ordered view of the elements
        std::size_t pos ;           // current position in middleOutView

    public:
        /**
         * @brief Constructor - builds the middle-out ordering.
         * This constructor takes a vector of elements, arranges them in a middle-out order,
         * and initializes the iterator to the specified starting index.
         * Middle-out order starts from the middle element and alternates between left and right.
         * The middle element is selected first, then the next element to the right, followed by the next to the left,
         * and so on, until all elements are included.
         * 
         * 
         * @param elements Input container elements in original order.
         * @param startPos Starting index (default = 0).
         */
        MiddleOutOrder(const MyContainer<T>& container, std::size_t startPos = 0)
            : container(container),pos(startPos)
        {
            const auto& elements = container.getElements();
            std::size_t n = elements.size();
            if (n == 0) return;

            std::vector<std::size_t> order;
            std::size_t mid = n / 2;
            order.push_back(mid);

            std::size_t left = mid, right = mid;

            while (order.size() < n) {
                if (left > 0) {
                    --left;
                    order.push_back(left);
                }
                if (right < n - 1) {
                    ++right;
                    order.push_back(right);
                }
            }

            middleOutView.reserve(n);
            for (std::size_t i : order) {
                middleOutView.push_back(elements[i]);
            }
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
            if (pos >= middleOutView.size()) {
                throw std::out_of_range("Iterator out of range");
            }
            return middleOutView[pos];
        }

        /**
         * @brief Prefix increment.
         * Increments the iterator to the next element.
         * This operator modifies the current iterator state to point to the next element in the sorted order.
         * If the index exceeds the size of the sorted data, it throws an exception.
         * 
         * @return Reference to the updated iterator.
         */
        MiddleOutOrder& operator++() {
            if (pos >= middleOutView.size()) {
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
        MiddleOutOrder operator++(int) {
            MiddleOutOrder temp = *this;
            ++(*this);// Call the prefix increment to update the current iterator state
            // The current iterator state is updated, but the original state is returned
            return temp;
        }

        /**
         * @brief Equality comparison.
         * Compares two MiddleOutOrder instances to check if they point to the same pos.
         * 
         * This operator checks if both iterators are at the same position in their respective sorted data.
         * It is used to determine if two iterators are equal, which is useful in algorithms that require comparison of iterators.
         * @param other Iterator to compare to.
         * @return true if both iterators point to the same pos.
         */
        bool operator==(const MiddleOutOrder& other) const {
            // Compare the indices of both iterators to determine equality
            return pos == other.pos && middleOutView == other.middleOutView;    }

        /**
         * @brief Inequality comparison.
         * 
         * Compares two MiddleOutOrder instances to check if they point to different indices.
         * This operator is the negation of the equality operator.
         * @param other Iterator to compare to.
         * @return true if the iterators are not equal.
         */
        bool operator!=(const MiddleOutOrder& other) const {
            return !(*this == other);
        }
    };

} // namespace Container

#endif // MIDDLE_OUT_ORDER_HPP
