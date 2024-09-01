#include <iostream>
#include <string>

using namespace std;
class Student {
    public:
       string name;
        string regNum;
        int semester;
        float SGPA;
        Student* next;

        Student(string n, string rn, int s, float gpa) {
            name = n;
            regNum = rn;
            semester = s;
            SGPA = gpa;
            next = NULL;
        }
        
   
   
    float calculateCGPA(float SGPA[], int totalSemester) {
        float totalSGPA = 0.0;
        for (int i = 0; i < totalSemester; i++) {
            totalSGPA += SGPA[i];
        }
        return totalSGPA / totalSemester;
    }

};

class StudentList {
    public:
        Student* head;
        Student* tail;

        StudentList() {
            head = NULL;
            tail = NULL;
        }

        void addStudent(string name, string regNum, int semester, float SGPA) {
            Student* newStudent = new Student(name, regNum, semester, SGPA);
            if (head == NULL) {
                head = newStudent;
                tail = newStudent;
            } else {
                tail->next = newStudent;
                tail = newStudent;
            }
        }

        Student* searchByRegNum(string regNum) {
            Student* current = head;
            while (current != NULL) {
                if (current->regNum == regNum) {
                    return current;
                }
                current = current->next;
            }
            return NULL;
        }

        Student* searchByName(string name) {
            Student* current = head;
            while (current != NULL) {
                if (current->name == name) {
                    return current;
                }
                current = current->next;
            }
            return NULL;
        }
        
        Student* searchBySGPA(float SGPA) {
            Student* current = head;
            while (current != NULL) {
                if (current->SGPA == SGPA) {
                    return current;
                }
                current = current->next;
            }
            return NULL;
        }

        void deleteStudent(string regNum) {
            Student* current = head;
            if (current->regNum == regNum) {
                head = head->next;
                delete current;
                return;
            }
            while (current->next != NULL) {
                if (current->next->regNum == regNum) {
                    Student* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    return;
                }
                current = current->next;
            }
        }

        void updateStudent(string regNum,string name, int semester, float SGPA) {
            Student* student = searchByRegNum(regNum);
            if (student != NULL) {
                student->name = name;
                student->semester = semester;
                student->SGPA = SGPA;
            }
        }
        
        void displayAllStudents() {
        Student* current = head;
        while (current != NULL) {
            cout << "Name: " << current->name << endl;
            cout << "\n Registration Number: " << current->regNum << endl;
            cout << "\n Semester: " << current->semester <<endl;
            cout << "\n  SGPA: " << current->SGPA << std::endl;
            current = current->next;
        }
    }
};

int main() {
    StudentList studentList;
    int choice;

    while (true) {
        cout << "\t\t /******Welcome to Student Management System*******/ \n\n" <<endl;
        cout << "1. Add student \n" << endl;
        cout << "2. Search student by registration number \n" <<endl;
        cout << "3. Search student by name \n" << endl;
        cout << "4. Search student by SGPA \n" << endl;
        cout << "5. Delete student \n" << endl;
        cout << "6. Update student \n" <<endl;
        cout << "7. Display all students \n" << endl;
        cout << "8. Calculate CGPA \n" << endl;
	    cout << "9. Exit \n\n" << endl;
        cout << "\t\t Enter your choice:\n\n ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                string regNum;
                int semester;
                float SGPA;

                cout << "\n Enter student name: ";
                cin >> name;
                cout << "Enter student registration number: ";
                cin >> regNum;
                cout << "Enter student semester: ";
            	cin >> semester;
                cout << "Enter student SGPA: ";
                cin >> SGPA;

                studentList.addStudent(name, regNum, semester, SGPA);
                break;
            }
            case 2: {
                string regNum;
                cout << "Enter student registration number: ";
                cin >> regNum;

                Student* student = studentList.searchByRegNum(regNum);
                if (student == NULL) {
                    std::cout << "Student not found." <<endl;
                } else {
                    cout << "Name: " << student->name <<endl;
                    cout << "Registration Number: " << student->regNum <<endl;
                    cout << "Semester: " << student->semester <<endl;
                    cout << "SGPA: " << student->SGPA <<endl;
                }
                break;
            }
            case 3: {
                string name;
                cout << "Enter student name: ";
                cin >> name;

                Student* student = studentList.searchByName(name);
                if (student == NULL) {
                    cout << "Student not found." << std::endl;
                } else {
                    std::cout << "Name: " << student->name <<endl;
                    std::cout << "Registration Number: " << student->regNum <<endl;
                    std::cout << "Semester: " << student->semester <<endl;
                    std::cout << "SGPA: " << student->SGPA <<endl;
                }
                break;
            }
                       case 4: {
                float SGPA;
                cout << "Enter student SGPA: ";
                cin >> SGPA;

                Student* student = studentList.searchBySGPA(SGPA);
                if (student == NULL) {
                    cout << "Student not found." <<endl;
                } else {
                    cout << "Name: " << student->name <<endl;
                    cout << "Registration Number: " << student->regNum <<endl;
                    cout << "Semester: " << student->semester <<endl;
                    cout << "SGPA: " << student->SGPA <<endl;
                }
                break;
            }
            case 5: {
                string regNum;
                cout << "Enter the registration number of the student you want to delete: ";
                cin >> regNum;
                studentList.deleteStudent(regNum);
                break;
            }
            case 6: {
                string regNum;
                string name;
                int semester;
                float SGPA;
                cout << "Enter the registration number of the student you want to update: ";
                cin >> regNum;
                cout << "Enter the new name: ";
                cin >> name;
                cout << "Enter the new semester: ";
                cin >> semester;
                cout << "Enter the new SGPA: ";
                cin >> SGPA;
                studentList.updateStudent(regNum, name, semester, SGPA);
                break;
            }
            
              
        case 7: {
            studentList.displayAllStudents();
            break;
        
    }
    	   
        case 8: {
         
            string regNum;
            std::cout << "Enter student registration number: ";
            std::cin >> regNum;
            Student* student = studentList.searchByRegNum(regNum);
            if (student == NULL) {
                std::cout << "Student not found." << std::endl;
            } else {
            	int totalSemester;
                float SGPA[totalSemester];
                
                std::cout << "Enter the SGPA of all semesters: ";
                for (int i=0; i<totalSemester;i++)
                {
                    std::cin>>SGPA[i];
                }
                std::cout << "Enter the total number of semesters: ";
                std::cin >> totalSemester;
                float CGPA = student->calculateCGPA(SGPA, totalSemester);
                std::cout << "CGPA: " << CGPA << std::endl;
            }
        
            break;
        
    }
	

       
		    case 9: {
                cout << "Exiting..." <<endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." <<endl;
                break;
            }
        }
    }
    return 0;
}



