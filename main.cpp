#include <iostream>
#include <fstream>

using namespace std;

struct Homework
{
    string title;
    bool isDone;
};


struct Student
{
    string firstName;
    string lastName;
    string Id;
    int arraySize;
    Homework *homework = new Homework[arraySize];
};


// Menu
void homeMenu();

int main()
{
    homeMenu();
    return 0;
}

void homeMenuOption(int &selected);

void newStudentMenu(int &selected);
void newHomeworkMenu(int &selected);
void assignHomework(int &selected);
void searchStudent(int &selected);
void list(int &selected);
void updateStudent(int &selected);
void remove(int &selected);

void homeMenu()
{
    system("clear");

    int selected = 0;

    while (true)
    {
        switch (selected)
        {
        case 0:
            homeMenuOption(selected);
            break;

        case 1:
            newStudentMenu(selected);
            break;

        case 2:
            newHomeworkMenu(selected);
            break;

        case 3:
            assignHomework(selected);
            break;
            cin >> selected;

        case 4:
            searchStudent(selected);
            break;

        case 5:
            list(selected);
            break;

        case 6:
            updateStudent(selected);
            break;

        case 7:
            remove(selected);
            break;

        default:
            system("clear");
            cout << "Error" << selected << endl;
            cin >> selected;
            break;
        }
    }
}

void homeMenuOption(int &selected)
{
    system("clear");
    int input;

    cout << "Welcome\n\n";
    cout << "	[1] Add new student\n";
    cout << "	[2] Add new homework\n";
    cout << "	[3] Assign homework to student\n";
    cout << "	[4] Search student details\n";
    cout << "	[5] Student & Homework list\n";
    cout << "	[6] Update student information\n";
    cout << "	[7] Delete student or homework record\n";
    cin >> input;

    if (0 < input && input < 8)
    {
        selected = input;
    }
    else
    {
        while (true)
        { // To hundle String or double input -- https://www.codegrepper.com/code-examples/cpp/how+to+make+sure+the+user+inputs+a+int+and+not+anything+else+c%2B%2B
            cout << "Error: Choose 1 to 7" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> input;
            if (0 < input && input < 8)
            {
                selected = input;
                break;
            }
        }
    }
}

void newStudentMenu(int &selected)
{
    system("clear"); // Put your code under this line
    // Add new studnt code here
    cout << "newStudentMenu\n";
    cout << "Write 0: ";

    cin >> selected;
}

void newHomeworkMenu(int &selected)
{
    system("clear"); // Put your code under this line
    // Add new homework code here
    cout << "newHomeworkMenu\n";
    cout << "Write 0: ";

    cin >> selected;
}

void assignHomework(int &selected)
{
    system("clear"); // Put your code under this line
    // Assign homework to student code here
    cout << "assignHomework\n";
    cout << "Write 0: ";

    cin >> selected;
}

void searchStudent(int &selected) 
{
    system("clear"); // Put your code under this line
    // Search student details code here
    cout << "searchStudent\n";
    cout << "Write 0: ";

    cin >> selected;
}

void list(int &selected)
{
    system("clear"); // Put your code under this line
    // Student & Homework list code here
    cout << "list\n";
    cout << "Write 0: ";

    cin >> selected;
}

void updateStudent(int &selected)
{
    system("clear"); // Put your code under this line
    // Update student information code here
    cout << "updateStudent\n";
    cout << "Write 0: ";

    cin >> selected;
}

void remove(int &selected)
{
    system("clear"); // Put your code under this line
    // Delete student or homework record code here
    cout << "remove\n";
    cout << "Write 0: ";

    cin >> selected;
}
