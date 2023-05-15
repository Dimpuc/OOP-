#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

struct Student {
    std::string surname;
    std::string name;
    int mathGrade;
    int physicsGrade;
    int computerScienceGrade;

    Student(const std::string& s, const std::string& n, int math, int physics, int cs)
        : surname(s), name(n), mathGrade(math), physicsGrade(physics), computerScienceGrade(cs) {}
};

bool hasLowGrades(const Student& student) {
    return student.mathGrade <= 2 || student.physicsGrade <= 2 || student.computerScienceGrade <= 2;
}

bool compareNames(const Student& s1, const Student& s2) {
    if (s1.surname == s2.surname) {
        return s1.name < s2.name;
    }
    return s1.surname < s2.surname;
}

int main() {
    std::ifstream inputFile("data.txt");
    std::vector<Student> students;

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            std::string surname, name;
            int mathGrade, physicsGrade, csGrade;
            ss >> surname >> name >> mathGrade >> physicsGrade >> csGrade;
            students.push_back(Student(surname, name, mathGrade, physicsGrade, csGrade));
        }
        inputFile.close();
    } else {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    // Виведення студентів без трійок та двійок
    std::vector<Student> filteredStudents;
    std::copy_if(students.begin(), students.end(), std::back_inserter(filteredStudents), [](const Student& student) {
        return !hasLowGrades(student);
    });

    // Сортування за алфавітом
    std::sort(filteredStudents.begin(), filteredStudents.end(), compareNames);

    // Виведення результатів
    for (const auto& student : filteredStudents) {
        std::cout << student.surname << " " << student.name << std::endl;
    }

    return 0;
}