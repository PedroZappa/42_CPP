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
#include "../inc/MutantStack.hpp"
#include "../inc/Ansi.h" // Include the ANSI header
#include <list>
#include <iostream>

int main(void) {
    // Testing MutantStack
    {
        std::cout << BBLU << "Testing MutantStack:" << RESET << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(737);
        mstack.push(42);

        std::cout << "Top element: " << GRN << mstack.top() << RESET << std::endl;
        mstack.pop();
        std::cout << "Size after pop: " << GRN << mstack.size() << RESET << std::endl;

        // Regular iterator
        std::cout << "\n" << CYN << "Regular iterator (begin -> end):" << RESET << std::endl;
        MutantStack<int>::it it = mstack.begin();
        MutantStack<int>::it ite = mstack.end();
        while (it != ite) {
            std::cout << MAG << *it << " " << RESET;
            ++it;
        }
        std::cout << std::endl;

        // Const iterator
        std::cout << CYN << "Const iterator (cbegin -> cend):" << RESET << std::endl;
        MutantStack<int>::const_it cit = mstack.begin(); // Fixed to use cbegin/cend
        MutantStack<int>::const_it cite = mstack.end();
        while (cit != cite) {
            std::cout << MAG << *cit << " " << RESET;
            ++cit;
        }
        std::cout << std::endl;

        // Reverse iterator
        std::cout << CYN << "Reverse iterator (rbegin -> rend):" << RESET << std::endl;
        MutantStack<int>::rev_it rit = mstack.rbegin();
        MutantStack<int>::rev_it rite = mstack.rend();
        while (rit != rite) {
            std::cout << MAG << *rit << " " << RESET;
            ++rit;
        }
        std::cout << std::endl;

        // Const reverse iterator
        std::cout << CYN << "Const reverse iterator (crbegin -> crend):" << RESET << std::endl;
        MutantStack<int>::const_rev_it crit = mstack.rbegin(); // Fixed to use crbegin/crend
        MutantStack<int>::const_rev_it crite = mstack.rend();
        while (crit != crite) {
            std::cout << MAG << *crit << " " << RESET;
            ++crit;
        }
        std::cout << std::endl;

        // Copy to std::stack
        std::stack<int> s(mstack);
        std::cout << "Copied to std::stack, size: " << GRN << s.size() << RESET << std::endl;
    }

    sepPrinter(30, '-', YEL, 1);

    // Testing std::list for comparison
    {
        std::cout << BBLU << "Testing std::list:" << RESET << std::endl;
        std::list<int> mlist;
        mlist.push_back(5);
        mlist.push_back(17);
        mlist.push_back(3);
        mlist.push_back(737);
        mlist.push_back(42);

        std::cout << "Back element: " << GRN << mlist.back() << RESET << std::endl;
        mlist.pop_back();
        std::cout << "Size after pop: " << GRN << mlist.size() << RESET << std::endl;

        // Regular iterator
        std::cout << "\n" << CYN << "Regular iterator (begin -> end):" << RESET << std::endl;
        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();
        while (it != ite) {
            std::cout << MAG << *it << " " << RESET;
            ++it;
        }
        std::cout << std::endl;

        // Const iterator
        std::cout << CYN << "Const iterator (cbegin -> cend):" << RESET << std::endl;
        std::list<int>::const_iterator cit = mlist.begin();
        std::list<int>::const_iterator cite = mlist.end();
        while (cit != cite) {
            std::cout << MAG << *cit << " " << RESET;
            ++cit;
        }
        std::cout << std::endl;

        // Reverse iterator
        std::cout << CYN << "Reverse iterator (rbegin -> rend):" << RESET << std::endl;
        std::list<int>::reverse_iterator rit = mlist.rbegin();
        std::list<int>::reverse_iterator rite = mlist.rend();
        while (rit != rite) {
            std::cout << MAG << *rit << " " << RESET;
            ++rit;
        }
        std::cout << std::endl;

        // Const reverse iterator
        std::cout << CYN << "Const reverse iterator (crbegin -> crend):" << RESET << std::endl;
        std::list<int>::const_reverse_iterator crit = mlist.rbegin();
        std::list<int>::const_reverse_iterator crite = mlist.rend();
        while (crit != crite) {
            std::cout << MAG << *crit << " " << RESET;
            ++crit;
        }
        std::cout << std::endl;

        // Copy to another list
        std::list<int> l(mlist);
        std::cout << "Copied to std::list, size: " << GRN << l.size() << RESET << std::endl;
    }

    return 0;
}
