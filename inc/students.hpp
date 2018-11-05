/*
 * students.hpp
 *
 *  Created on: Nov 5, 2018
 *      Author: VBordea
 */

#ifndef INC_STUDENTS_HPP_
#define INC_STUDENTS_HPP_

#include <string>

class Student
    {
private:
    std::string nume;
public:
    Student(std::string);
    virtual void display();
    };



#endif /* INC_STUDENTS_HPP_ */
