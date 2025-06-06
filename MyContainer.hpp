//taliyam123@gmail.com

#ifndef MYCONTAINER_HPP
#define MYCONTAINER_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "AscendingOrder.hpp"
#include "DescendingOrder.hpp"
#include "SideCrossOrder.hpp"
#include "ReverseOrder.hpp"
#include "Order.hpp"
#include "MiddleOutOrder.hpp"

namespace Container{
    
    template<typename T = int> // Template class for a container that can hold elements of type T, that the default type is int
    /**
     * @brief A container class that holds elements of type T and provides various functionalities.
     * This class allows adding elements, removing elements, and iterating over them in different orders.
     * It supports copy construction and assignment, and provides an output operator for easy printing.
     */
    class Container {
    private:
        std::vector<T> elements; // Vector to hold elements of type T

    public:
        
        /**
         * @brief Default constructor for the Container class.
         * Initializes an empty container.
         * Default constructor
         */
        Container() = default;

         /**
         * @brief Default destructor.
         */
        ~MyContainer()= default;

        // /**
        //  * @brief Copy constructor for the Container class.
        //  * Initializes a new container as a copy of another container.
        //  * @param other The container to copy from.
        //  */
        // Container(const Container& other) : elements(other.elements) {}

        // /**
        //  * @brief Copy assignment operator for the Container class.
        //  * @param other The container to copy from.
        //  * @return A reference to this container.
        //  */
        // Container& operator=(const Container& other) {
        //     if (this != &other) {
        //         elements = other.elements;
        //     }
        //     return *this;
        // }

        /**
         * @brief Adds a value to the container.
         * @param value The value to add.
         */
        void add(const T& value) {
            elements.push_back(value);
        }

        /**
         * @brief Removes a value from the container.
         * If the value is not found, an exception is thrown.
         * @param value The value to remove.
         * @throws std::runtime_error if the value is not found in the container.
         */
        void remove(const T& value) {
            auto new_end = std::remove(elements.begin(), elements.end(), value); //

            if (new_end == elements.end()) {
                throw std::runtime_error("Element not found in container.");
            }

            elements.erase(new_end, elements.end()); // Erase the elements that were removed,from new_end to the end of the vector
        }


        /**
         * @brief Returns the number of elements in the container.
         * @return The size of the container.
         */
        size_t size() const {
            return elements.size();
        }

        /**
         * @brief Overloads the output operator to print the container.
         * @param stream The output stream.
         * @param container The container to print.
         * @return The output stream after printing the container.
         */
        friend std::ostream& operator<<(std::ostream& stream, const Container<T>& container) {
            stream << "[";
            for (size_t i = 0; i < container.elements.size(); ++i) {
                stream << container.elements[i];
                if (i != container.elements.size() - 1) {
                    stream << ", ";
                }
            }
            stream << "]";
            return stream;
        }

        /**
         * @brief Returns a constant reference to the elements in the container.
         * This allows access to the elements without modifying them.
         * @return A constant reference to the vector of elements.
         */
        const std::vector<T>& getElements() const {
            return elements;
        }

        
        /**
         * @brief Forward declaration of iterator classes for different orders.
         * 
         */
        class AscendingOrder;
        class DescendingOrder;
        class SideCrossOrder;
        class ReverseOrder;
        class Order;
        class MiddleOutOrder;

        // begin/end for each iterator
        AscendingOrder begin_ascending_order() const;
        AscendingOrder end_ascending_order() const;

        DescendingOrder begin_descending_order() const;
        DescendingOrder end_descending_order() const;

        SideCrossOrder begin_side_cross_order() const;
        SideCrossOrder end_side_cross_order() const;

        ReverseOrder begin_reverse_order() const;
        ReverseOrder end_reverse_order() const;

        Order begin_order() const;
        Order end_order() const;

        MiddleOutOrder begin_middle_out_order() const;
        MiddleOutOrder end_middle_out_order() const;
    };



    
}


#endif 