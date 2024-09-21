/*Q.No 1
Employee Management System
File handling has been effectively used for each feature of this project
Operation
1.	Add  Employee Information
2.	Search Employee Information
4.	Delete Employee Data
5.	Search Employee Record.
*/




#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee 
{
public:
    int empID;
    string name;
    string designation;
    double salary;

    void getDetails() {
        cout << "Enter Employee ID: ";
        cin >> empID;
        cin.ignore(); // to ignore newline character after empID
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Employee Designation: ";
        getline(cin, designation);
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    void showDetails() {
        cout << "Employee ID: " << empID << endl;
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Function to add employee details
void addEmployee() {
    Employee emp;
    emp.getDetails();
    ofstream file;
    file.open("employee.txt", ios::app); // Append mode
    if (file.is_open()) {
        file << emp.empID << " " << emp.name << " " << emp.designation << " " << emp.salary << endl;
        file.close();
        cout << "Employee added successfully!\n";
    } else {
        cout << "Unable to open file.\n";
    }
}

// Function to search for an employee by ID
void searchEmployee(int id) {
    ifstream file;
    Employee emp;
    bool found = false;
    file.open("employee.txt", ios::in);
    if (file.is_open()) {
        while (file >> emp.empID >> emp.name >> emp.designation >> emp.salary) {
            if (emp.empID == id) {
                emp.showDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Employee with ID " << id << " not found.\n";
        }
        file.close();
    } else {
        cout << "Unable to open file.\n";
    }
}

// Function to delete an employee record
void deleteEmployee(int id) {
    ifstream file;
    ofstream tempFile;
    Employee emp;
    bool found = false;

    file.open("employee.txt", ios::in);
    tempFile.open("temp.txt", ios::out);

    if (file.is_open() && tempFile.is_open()) {
        while (file >> emp.empID >> emp.name >> emp.designation >> emp.salary) {
            if (emp.empID == id) {
                found = true;
                cout << "Employee with ID " << id << " deleted successfully.\n";
            } else {
                tempFile << emp.empID << " " << emp.name << " " << emp.designation << " " << emp.salary << endl;
            }
        }
        file.close();
        tempFile.close();

        // Remove original file and rename temp file to original
        remove("employee.txt");
        rename("temp.txt", "employee.txt");

        if (!found) {
            cout << "Employee with ID " << id << " not found.\n";
        }
    } else {
        cout << "Unable to open file.\n";
    }
}

// Function to display all employee records
void displayAllEmployees() {
    ifstream file;
    Employee emp;
    file.open("employee.txt", ios::in);
    if (file.is_open()) {
        while (file >> emp.empID >> emp.name >> emp.designation >> emp.salary) {
            emp.showDetails();
            cout << "------------------------------------\n";
        }
        file.close();
    } else {
        cout << "Unable to open file.\n";
    }
}

// Main menu for the Employee Management System
int main() {
    int choice, id;

    do {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Employee Information\n";
        cout << "2. Search Employee Information\n";
        cout << "3. Delete Employee Data\n";
        cout << "4. Display All Employee Records\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                cout << "Enter Employee ID to search: ";
                cin >> id;
                searchEmployee(id);
                break;
            case 3:
                cout << "Enter Employee ID to delete: ";
                cin >> id;
                deleteEmployee(id);
                break;
            case 4:
                displayAllEmployees();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
