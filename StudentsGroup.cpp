#include "StudentsGroup.h"



void StudentsGroup::Open() {
    std::string path {"../data.bin"};
    std::string result;
    std::ifstream in (path, std::ios::binary);
    result.resize(1024);
    in.read(result.data(), result.size());
    result.resize(in.gcount());
    std::cout << result << std::endl;
}

void StudentsGroup::Save() {
    std::string path {"../data.bin"};
    std::ofstream out(path, std::ios::binary);
    out.write(GetAllInfo().c_str(), std::size(GetAllInfo()));
}

double StudentsGroup::GetAverageScore(const FullName &name) {
    auto res = (m_arrayStudents.begin(), m_arrayStudents.end(), name);
    float score {};
    for (const auto &i : m_arrayStudents) {
        if (i.getFullName() == res) {
           score = (i.getAverage());
        }
    }
    return score;
}

std::string StudentsGroup::GetAllInfo(const FullName &name) {
    std::string getAll;
    auto res = (m_arrayStudents.begin(), m_arrayStudents.end(), name);
    getAll = res.getName() + " " + res.getLname() + " " + res.getPatronymic() + " " + "Ratings: ";
    for (const auto &i : m_arrayStudents) {
        if (i.getFullName() == res)
        for (const auto &u : i.getRatings()) {
            getAll.append(std::to_string(u) + " ");
        }
    }
    std::stringstream ss;
    getAll.append(" Average Rating: ");
    for (const auto &i : m_arrayStudents) {
        if (i.getFullName() == res) {
            ss << std::setprecision(2) << i.getAverage();
        }
    }
    getAll.append("(" + ss.str() + ") ");

    return getAll;
}

std::string StudentsGroup::GetAllInfo() {
    std::string getAll;
    std::stringstream ss;
    ss.precision(2);
    for (const auto &i : m_arrayStudents) {
        getAll.append(i.getFullName().getName() + " ");
        getAll.append(i.getFullName().getLname() + " ");
        getAll.append(i.getFullName().getPatronymic() + " ");
        for (const auto &u : i.getRatings()) {
            getAll.append(std::to_string(u) + " ");
        }
        ss.str("");
        ss << i.getAverage();
        getAll.append("Average:(" + ss.str() + ") ");
    }

    return getAll;
}

StudentsGroup::StudentsGroup(std::vector<Student>  students) : m_arrayStudents(std::move(students)) {}


