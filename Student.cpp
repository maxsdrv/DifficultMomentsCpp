#include "Student.h"

Student::~Student() {
    std::cout << "~Student()" << std::endl;
}

Student::Student(FullName fName, std::vector<int> ratings) : m_fullName(std::move(fName)),
m_arrayRatings(std::move(ratings))
{
    auto result = std::accumulate(m_arrayRatings.begin(), m_arrayRatings.end(), 0);
    m_average = static_cast<float>(result) / static_cast<float>(m_arrayRatings.size());
}

std::ostream &operator<<(std::ostream &os, const Student &st) {
    std::cout.precision(2);
    os << st.m_fullName.getName() << " " <<
    st.m_fullName.getLname() << " " << st.m_fullName.getPatronymic() << '\t';
    os << "Ratings: ";
    for (const auto& i : st.m_arrayRatings) {
        os << i << " ";
    }
    os << '\t' << "Average rating = " << st.m_average << std::endl;

    return os;
}

float Student::getAverage() const {
    return m_average;
}

const FullName &Student::getFullName() const{
    return m_fullName;
}

const std::vector<int> &Student::getRatings() const{
    return m_arrayRatings;
}



