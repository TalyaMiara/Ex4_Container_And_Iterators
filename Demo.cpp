
//taliyam123@gmail.com
#include "MyContainer.hpp"

#include <iostream>
using namespace Container;
int main() {
    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);
    //- -> [7,15,6,1,2]

    std::cout << "\n===== Integer Container =====" << std::endl;

    std::cout << "Size of container: " << container.size() << std::endl;

    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        std::cout << *it << ' ';   // 1 2 6 7 15
    }
    std::cout << std::endl;

    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it) {
        std::cout << *it << ' ';  // 15 7 6 2 1
    }
    std::cout << std::endl;

    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it) {
        std::cout << *it << ' ';  // 1 15 2 7 6
    }
    std::cout << std::endl;

    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it) {
        std::cout << *it << ' ';  // 2 1 6 15 7
    }
    std::cout << std::endl;

    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        std::cout << *it << ' ';  // 7 15 6 1 2
    }
    std::cout << std::endl;

    for (auto it = container.begin_middle_out_order(); it != container.end_middle_out_order(); ++it) {
        std::cout << *it << ' ';  // 6 15 1 7 2
    }
    std::cout << std::endl;

    container.remove(6);
    std::cout << "After removing 6: ";
    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        std::cout << *it << ' ';  // expected: 7 15 1 2
    }
    std::cout << std::endl;

    try {
    container.remove(42);  // Member does not exist
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "Container contents: " << container << std::endl;  // [7, 15, 1, 2]

    MyContainer<std::string> words;
    words.add("banana");
    words.add("apple");
    words.add("cherry");

    std::cout << "String container in ascending order: ";
    for (auto it = words.begin_ascending_order(); it != words.end_ascending_order(); ++it) {
        std::cout << *it << ' ';  // apple banana cherry
    }
    std::cout << std::endl;


    // -------Demonstrating the use of iterators in MyContainer

    // Print container in ascending order using the iterator
    std::cout << "\nintContainer in ascending order: ";
    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        std::cout << *it << " "; //expected: 1 2 7 15
    }
    std::cout << std::endl;

    // Print container in begin descending order using the iterator
    std::cout << "\nintContainer in descending order: ";
    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it) {
        std::cout << *it << " "; //expected: 15 7 2 1
    }
    std::cout << std::endl;

    // Print container in insertion order using the iterator
    std::cout << "\nintContainer in side cross order: ";
    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it) {
        std::cout << *it << " "; //expected: 1 15 2 7 6
    }
    std::cout << std::endl;

    // Print container in middle-out order using the iterator
    std::cout << "\nintContainer in reverse order: ";
    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it) {
        std::cout << *it << " ";//expected: 2 1 6 15 7
    }
    std::cout << std::endl;



    // ==========================================================

    std::cout << "\n===== Double Container 2 =====" << std::endl;

    // Create a second container for doubles
    MyContainer<double> doubleContainer2;

    // Add elements
    doubleContainer2.add(8.8);
    doubleContainer2.add(1.1);
    doubleContainer2.add(4.4);
    doubleContainer2.add(9.9);
    doubleContainer2.add(6.6);

    // Print container
    std::cout << "\ndoubleContainer2: " << doubleContainer2 << std::endl;

    // Print size
    std::cout << "\nSize: " << doubleContainer2.size() << std::endl;

    std::cout << "\nDouble Container 2 Iterators: " << std::endl;

    // Ascending
    std::cout << "\ndoubleContainer2 in ascending order: ";
    for (auto it = doubleContainer2.begin_ascending_order(); it != doubleContainer2.end_ascending_order(); ++it) {
        std::cout << *it << " "; // 1.1 4.4 6.6 8.8 9.9
    }
    std::cout << std::endl;

    // Descending
    std::cout << "\ndoubleContainer2 in descending order: ";
    for (auto it = doubleContainer2.begin_descending_order(); it != doubleContainer2.end_descending_order(); ++it) {
        std::cout << *it << " "; // 9.9 8.8 6.6 4.4 1.1
    }
    std::cout << std::endl;

    // Side-cross
    std::cout << "\ndoubleContainer2 in side-cross order: ";
    for (auto it = doubleContainer2.begin_side_cross_order(); it != doubleContainer2.end_side_cross_order(); ++it) {
        std::cout << *it << " "; // 1.1 9.9 4.4 8.8 6.6
    }
    std::cout << std::endl;

    // Reverse
    std::cout << "\ndoubleContainer2 in reverse order: ";
    for (auto it = doubleContainer2.begin_reverse_order(); it != doubleContainer2.end_reverse_order(); ++it) {
        std::cout << *it << " "; // 6.6 9.9 4.4 1.1 8.8
    }
    std::cout << std::endl;

    // Insertion
    std::cout << "\ndoubleContainer2 in insertion order: ";
    for (auto it = doubleContainer2.begin_order(); it != doubleContainer2.end_order(); ++it) {
        std::cout << *it << " "; // 8.8 1.1 4.4 9.9 6.6
    }
    std::cout << std::endl;

    // Middle-out
    std::cout << "\ndoubleContainer2 in middle-out order: ";
    for (auto it = doubleContainer2.begin_middle_out_order(); it != doubleContainer2.end_middle_out_order(); ++it) {
        std::cout << *it << " "; // 4.4 9.9 1.1 6.6 8.8
    }
    std::cout << std::endl;

    // Remove element (removes all occurrences of 4.4)
    doubleContainer2.remove(4.4);

    // Print after removal
    std::cout << "\nAfter removing 4.4: " << doubleContainer2 << std::endl;

    // Print size after removal
    std::cout << "\nSize after removal: " << doubleContainer2.size() << std::endl;

    // Attempt to remove an element that does not exist
    std::cout << "\nAttempting to remove an element that does not exist (7.7): ";
    try {
        doubleContainer2.remove(7.7);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;


    return 0;
}
