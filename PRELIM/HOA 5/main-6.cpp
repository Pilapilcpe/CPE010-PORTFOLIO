#include <iostream>
#include <queue>
#include <string>

void display(std::queue<std::string> q)
{
    while (!q.empty())
    {

        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

int main()
{

    std::queue<std::string> students;

    std::string names[] = {"Loreen", "Keara", "Guillian", "Jasmine", "Marion"};

    for (int i = 0; i < 5; i++)
    {
        students.push(names[i]);
    }


    std::cout << "The queue is:  ";
    display(students);

    std::cout << "empty? "
              << students.empty() << std::endl;


    std::cout << "size: "
              << students.size() << std::endl;

    std::cout << "Front: "
              << students.front() << std::endl;

    std::cout << "Back: "
              << students.back() << std::endl;


    students.pop();
    std::cout << "pop: ";
    display(students);

    students.push("Sidney");
    std::cout << "push: ";
    display(students);



    return 0;
}