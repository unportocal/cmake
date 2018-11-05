/*
 * student.cpp
 *
 *  Created on: Nov 5, 2018
 *      Author: VBordea
 */

#include <iostream>
#include "students.hpp"
using namespace std;

Student::Student(string name):nume(name){}

void Student::display()
    {
    std::cout << "A student with name: " << this->nume << std::endl;
    }

