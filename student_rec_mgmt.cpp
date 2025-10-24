#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

void addStudent() {
    Student s;
    cout << "Enter Roll No: ";
    cin >> s.roll;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Marks: ";
    cin >> s.marks;

    ofstream out("students.txt", ios::app);
    out << s.roll << " " << s.name << " " << s.marks << "\n";
    out.close();
    cout << "Student added successfully!\n";
}

void viewStudents() {
    ifstream in("students.txt");
    Student s;
    cout << "\n--- Student Records ---\n";
    while (in >> s.roll >> s.name >> s.marks) {
        cout << "Roll: " << s.roll << ", Name: " << s.name << ", Marks: " << s.marks << "\n";
    }
    in.close();
}

void searchStudent() {
    int target;
    cout << "Enter Roll No to search: ";
    cin >> target;

    ifstream in("students.txt");
    Student s;
    bool found = false;
    while (in >> s.roll >> s.name >> s.marks) {
        if (s.roll == target) {
            cout << "Found: Roll: " << s.roll << ", Name: " << s.name << ", Marks: " << s.marks << "\n";
            found = true;
            break;
        }
    }
    in.close();
    if (!found) cout << "Student not found.\n";
}

void deleteStudent() {
    int target;
    cout << "Enter Roll No to delete: ";
    cin >> target;

    ifstream in("students.txt");
    ofstream temp("temp.txt");
    Student s;
    bool deleted = false;

    while (in >> s.roll >> s.name >> s.marks) {
        if (s.roll != target) {
            temp << s.roll << " " << s.name << " " << s.marks << "\n";
        } else {
            deleted = true;
        }
    }

    in.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (deleted)
        cout << "Student deleted successfully.\n";
    else
        cout << "Student not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Student Record System ---\n";
        cout << "1. Add Student\n2. View All Students\n3. Search by Roll No\n4. Delete by Roll No\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
