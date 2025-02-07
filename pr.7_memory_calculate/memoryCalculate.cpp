#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MemoryCalculate
{
private:
    T id;
    string name;

public:
    MemoryCalculate(T id, string name) : id(id), name(name) {}

    // Display Student Details
    void display() const
    {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    // Getter for ID
    T getId() const
    {
        return id;
    }
};

class StudentManagement
{
private:
    vector<MemoryCalculate<int>> students;

public:
    // Add Student
    void addStudent(int id, string name)
    {
        students.push_back(MemoryCalculate<int>(id, name));
    }

    // Display All Students
    void displayStudents() const
    {
        if (students.empty())
        {
            cout << "No students found." << endl;
        }
        else
        {
            for (int i = 0; i < students.size(); i++)
            {
                students[i].display();
            }
        }
    }

    // Remove Student by ID
    void removeStudent(int id)
    {
        for (auto it = students.begin(); it != students.end(); ++it)
        {
            if (it->getId() == id)
            {
                students.erase(it);
                cout << "Student with ID " << id << " removed successfully." << endl;
                return;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
    }

    // Search Student by ID
    void searchStudent(int id) const
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getId() == id)
            {
                cout << "Student Found: ";
                students[i].display();
                return;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
    }
};

int main()
{
    StudentManagement sm;
    int choice, id;
    string name;

    do
    {
        cout << "Student Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Remove Student by ID" << endl;
        cout << "4. Search Student by ID" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            sm.addStudent(id, name);
            break;
        case 2:
            sm.displayStudents();
            break;
        case 3:
            cout << "Enter ID to remove: ";
            cin >> id;
            sm.removeStudent(id);
            break;
        case 4:
            cout << "Enter ID to search: ";
            cin >> id;
            sm.searchStudent(id);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
