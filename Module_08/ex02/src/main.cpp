/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:34:14 by passunca          #+#    #+#             */
/*   Updated: 2024/12/14 12:46:16 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/MutantStack.hpp"
// #include <cassert>
// #include <iostream>
//
// void test_default_constructor();
// void test_push_pop_operations();
// void test_copy_constructor();
// void test_assignment_operator();
// void test_iterator_access();
// void test_empty_stack_iterator();
// void test_iteration_order();
// void test_mixing_operations_and_iteration();
//
// int main() {
// 	test_default_constructor();
// 	test_push_pop_operations();
// 	test_copy_constructor();
// 	test_assignment_operator();
// 	test_iterator_access();
// 	test_empty_stack_iterator();
// 	test_iteration_order();
// 	test_mixing_operations_and_iteration();
// 	std::cout << "All tests passed!" << std::endl;
// 	return 0;
// }
//
// void test_default_constructor() {
// 	MutantStack<int> stack;
// 	assert(stack.size() == 0);
// 	std::cout << "Default constructor test passed!" << std::endl;
// }
//
// void test_push_pop_operations() {
// 	MutantStack<int> stack;
// 	stack.push(42);
// 	stack.push(15);
// 	stack.push(99);
// 	assert(stack.top() == 99); // Check top element
// 	stack.pop();
// 	assert(stack.top() == 15); // After pop, check top element
// 	assert(stack.size() == 2);
// 	std::cout << "Push and pop operations test passed!" << std::endl;
// }
//
// void test_copy_constructor() {
// 	MutantStack<int> stack1;
// 	stack1.push(42);
// 	stack1.push(15);
//
// 	MutantStack<int> stack2(stack1);        // Copy constructor
// 	assert(stack2.size() == stack1.size()); // Ensure sizes are the same
// 	assert(stack2.top() == stack1.top());   // Ensure top elements are the same
// 	std::cout << "Copy constructor test passed!" << std::endl;
// }
//
// void test_assignment_operator() {
// 	MutantStack<int> stack1;
// 	stack1.push(42);
// 	stack1.push(15);
//
// 	MutantStack<int> stack2;
// 	stack2 = stack1; // Assignment operator
// 	assert(stack2.size() == stack1.size());
// 	assert(stack2.top() == stack1.top());
// 	std::cout << "Assignment operator test passed!" << std::endl;
// }
//
// void test_iterator_access() {
// 	MutantStack<int> stack;
// 	stack.push(42);
// 	stack.push(15);
// 	stack.push(99);
//
// 	// Iterate using begin() and end()
// 	MutantStack<int>::dequeIt it = stack.begin();
// 	assert(*it == 42); // First element
// 	++it;
// 	assert(*it == 15); // Second element
// 	++it;
// 	assert(*it == 99); // Third element
// 	std::cout << "Iterator access test passed!" << std::endl;
// }
//
// void test_empty_stack_iterator() {
// 	MutantStack<int> stack;
// 	MutantStack<int>::dequeIt it = stack.begin();
// 	assert(it ==
// 		   stack.end()); // No elements should result in same begin and end iterators
// 	std::cout << "Empty stack iterator test passed!" << std::endl;
// }
//
// void test_iteration_order() {
// 	MutantStack<int> stack;
// 	stack.push(1);
// 	stack.push(2);
// 	stack.push(3);
//
// 	int count = 1;
// 	for (MutantStack<int>::dequeIt it = stack.begin(); it != stack.end(); ++it) {
// 		assert(*it == count); // Should print 1, 2, 3
// 		count++;
// 	}
// 	std::cout << "Iteration order test passed!" << std::endl;
// }
//
// void test_mixing_operations_and_iteration() {
// 	MutantStack<int> stack;
// 	stack.push(1);
// 	stack.push(2);
// 	stack.push(3);
//
// 	MutantStack<int>::dequeIt it = stack.begin();
// 	assert(*it == 1); // Should print 1
// 	stack.push(4);    // Add element while iterating
// 	++it;
// 	assert(*it == 2);   // Should print 2
// 	stack.pop();        // Remove element while iterating
// 	it = stack.begin(); // Reset iterator
// 	assert(*it == 1);   // Should print 1 after pop
// 	std::cout << "Mixing operations and iteration test passed!" << std::endl;
// }

#include "../inc/MutantStack.hpp"
#include <cassert>
#include <iostream>

void test_default_constructor();
void test_push_pop_operations();
void test_copy_constructor();
void test_assignment_operator();
void test_iterator_access();
void test_empty_stack_iterator();
void test_iteration_order();
void test_mixing_operations_and_iteration();

int main() {
	headerPrinter("MutantStack", 50, '-', GRN);
    test_default_constructor();
    test_push_pop_operations();
    test_copy_constructor();
    test_assignment_operator();
    test_iterator_access();
    test_empty_stack_iterator();
    test_iteration_order();
    test_mixing_operations_and_iteration();
    std::cout << GRN "All tests passed!" NC << std::endl;
    return 0;
}

void test_default_constructor() {
    MutantStack<int> stack;
    assert(stack.size() == 0);
    std::cout << CYN "Default constructor test passed!" NC << std::endl;
}

void test_push_pop_operations() {
    MutantStack<int> stack;
    stack.push(42);
    stack.push(15);
    stack.push(99);
    assert(stack.top() == 99); // Check top element
    stack.pop();
    assert(stack.top() == 15); // After pop, check top element
    assert(stack.size() == 2);
    std::cout << YEL "Push and pop operations test passed!" NC << std::endl;
}

void test_copy_constructor() {
    MutantStack<int> stack1;
    stack1.push(42);
    stack1.push(15);

    MutantStack<int> stack2(stack1);        // Copy constructor
    assert(stack2.size() == stack1.size()); // Ensure sizes are the same
    assert(stack2.top() == stack1.top());   // Ensure top elements are the same
    std::cout << MAG "Copy constructor test passed!" NC << std::endl;
}

void test_assignment_operator() {
    MutantStack<int> stack1;
    stack1.push(42);
    stack1.push(15);

    MutantStack<int> stack2;
    stack2 = stack1; // Assignment operator
    assert(stack2.size() == stack1.size());
    assert(stack2.top() == stack1.top());
    std::cout << BLU "Assignment operator test passed!" NC << std::endl;
}

void test_iterator_access() {
    MutantStack<int> stack;
    stack.push(42);
    stack.push(15);
    stack.push(99);

    // Iterate using begin() and end()
    MutantStack<int>::dequeIt it = stack.begin();
    assert(*it == 42); // First element
    ++it;
    assert(*it == 15); // Second element
    ++it;
    assert(*it == 99); // Third element
    std::cout << GRN "Iterator access test passed!" NC << std::endl;
}

void test_empty_stack_iterator() {
    MutantStack<int> stack;
    MutantStack<int>::dequeIt it = stack.begin();
    assert(it == stack.end()); // No elements should result in same begin and end iterators
    std::cout << BLU "Empty stack iterator test passed!" NC << std::endl;
}

void test_iteration_order() {
    MutantStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    int count = 1;
    for (MutantStack<int>::dequeIt it = stack.begin(); it != stack.end(); ++it) {
        assert(*it == count); // Should print 1, 2, 3
        count++;
    }
    std::cout << YEL "Iteration order test passed!" NC << std::endl;
}

void test_mixing_operations_and_iteration() {
    MutantStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    MutantStack<int>::dequeIt it = stack.begin();
    assert(*it == 1); // Should print 1
    stack.push(4);    // Add element while iterating
    ++it;
    assert(*it == 2);   // Should print 2
    stack.pop();        // Remove element while iterating
    it = stack.begin(); // Reset iterator
    assert(*it == 1);   // Should print 1 after pop
    std::cout << RED "Mixing operations and iteration test passed!" NC << std::endl;
}

