#ifndef DIFFICULTMOMENTSCPP_STUDENT_H
#define DIFFICULTMOMENTSCPP_STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <iomanip>

#include "FullName.h"


class Student {
public:
    explicit Student(FullName fName, std::vector<int> ratings);
    ~Student();

    [[nodiscard]] float getAverage() const;
    [[nodiscard]] const FullName &getFullName() const;
    [[nodiscard]] const std::vector<int>& getRatings() const;

    friend std::ostream& operator<<(std::ostream& os, const Student& st);
private:
    FullName m_fullName;
    std::vector<int> m_arrayRatings;
    float m_average;
};


#endif //DIFFICULTMOMENTSCPP_STUDENT_H
