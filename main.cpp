#include <iostream>

#include "Students.pb.h"
#include "Student.h"
#include "FullName.h"
#include "StudentsGroup.h"


int main() {
//1.
/*С помощью компилятора protobuf в отдельном пространстве имен сгенерировать классы
FullName с полями имя, фамилия, отчество (отчество опционально).
Student с полями полное имя, массив оценок, средний балл.
StudentsGroup с полем массив студентов.*/

Entity::FullName name;
Entity::Student student;
Entity::StudentsGroup st_group;

//2.
/*Создать класс StudentsGroup (без использования protobuf), который реализует интерфейсы:*/
    FullName name1 {"Alexandr", "Pushkin", "Sergeevich"};
    std::vector<int> ratings_name1 {5, 5, 4, 3, 4, 4};
    Student student1(name1, ratings_name1);

    FullName name2 {"Sergei", "Esenin", "Alexandrovich"};
    std::vector<int> ratings_name2 {3, 3, 2, 3, 4, 4};
    Student student2(name2, ratings_name2);

    FullName name3 {"Alexandr", "Blok", "Alexandrovich"};
    std::vector<int> ratings_name3 {4, 4, 2, 3, 4, 5};
    Student student3(name3, ratings_name3);


    std::vector<Student> arrStudent {student1, student2, student3};
    StudentsGroup group1(arrStudent);
    std::cout << "Get Average Score: " << group1.GetAverageScore(name2) << std::endl;
    std::cout << "Get All Info(): " << group1.GetAllInfo(name2) << std::endl;
    std::cout << "GetALL(): " << group1.GetAllInfo() << std::endl;

    group1.Save();
    group1.Open();



    return 0;
}
