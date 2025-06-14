//talyam123@gmail.com

#ifndef REVERSE_ORDER_HPP
#define REVERSE_ORDER_HPP

#include "MyContainer.hpp"
#include <vector>
#include <algorithm>   // for std::sort
#include <cstddef>     // for std::size_t
#include <stdexcept>   // for std::out_of_range

namespace Container {

    template<typename T>
    class MyContainer;

    /**
     * @brief Iterator that traverses the container in reverse insertion order.
     * 
     * For example: [7,15,6,1,2] will be traversed as [2,1,6,15,7]
     */
    template<typename T>// Template class for a container that can hold elements of type T, that the default type is int
    class ReverseOrder {

    private:
        const MyContainer<T>& container; // Reference to the container being iterated
        std::vector<T> reversedView;  // reversed copy of the original container
        std::size_t pos ;          // current pos in reversedView

    public:
        /**
         * @brief Constructor - reverses the container's elements.
         * 
         * @param elements Elements from the original container.
         * @param startPos Starting index in the reversed view (default = 0).
         */
        ReverseOrder(const MyContainer<T>& container, std::size_t startPos = 0)
            : container(container),pos(startPos)
        {
            const auto& elements = container.getElements();
            if (elements.empty()) {
                throw std::invalid_argument("Cannot create ReverseOrder with empty container");
            }
            reversedView = elements;
            std::reverse(reversedView.begin(), reversedView.end());
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
            if (pos >= reversedView.size()) {
                throw std::out_of_range("Iterator out of range");
            }
            return reversedView[pos];
        }

        /**
         * @brief Prefix increment.
         * Increments the iterator to the next element.
         * This operator modifies the current iterator state to point to the next element in the sorted order.
         * If the index exceeds the size of the sorted data, it throws an exception.
         * 
         * @return Reference to the updated iterator.
         */
        ReverseOrder& operator++() {
            if (pos >= reversedView.size()) {
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
        ReverseOrder operator++(int) {
            ReverseOrder temp = *this;
            ++(*this);// Call the prefix increment to update the current iterator state
            // The current iterator state is updated, but the original state is returned
            return temp;
        }

        /**
         * @brief Equality comparison.
         * Compares two ReverseOrder instances to check if they point to the same pos.
         * 
         * This operator checks if both iterators are at the same position in their respective sorted data.
         * It is used to determine if two iterators are equal, which is useful in algorithms that require comparison of iterators.
         * @param other Iterator to compare to.
         * @return true if both iterators point to the same pos.
         */
        bool operator==(const ReverseOrder& other) const {
            // Compare the indices of both iterators to determine equality
            return pos == other.pos && reversedView == other.reversedView;    }

        /**
         * @brief Inequality comparison.
         * 
         * Compares two ReverseOrder instances to check if they point to different indices.
         * This operator is the negation of the equality operator.
         * @param other Iterator to compare to.
         * @return true if the iterators are not equal.
         */
        bool operator!=(const ReverseOrder& other) const {
            return !(*this == other);
        }
    };

} // namespace Container

#endif // REVERSE_ORDER_HPP

