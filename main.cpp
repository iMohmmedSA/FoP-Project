#include <iostream> // Usage get input send output
#include <fstream>  // Usage store data
#include <vector>   // Usage store data

using namespace std;

struct Homework
{
    string subject; // English 101(subject)
    bool isDone;    // is homework done - Note 1 mean Done, 0 mean isn't done
};

struct Student
{
    string firstName;          // Student First name
    string lastName;           // Student last name
    string Id;                 // University id
    int homeworkSize;          // Keep up with Vector size
    vector<Homework> homework; // Work like Dynamic Array
};

int studentSize = 0;         // student size
vector<Student> studentList; // using Dynamic Array
int homeworkSize = 0;        // homework size
vector<string> homeworkList; // using Dynaimc Array

void loadData() // load data from userEE.file
{
    ifstream userFile("userEE.file"); // select the file to check / Open file
    string temp, tempNum;             // temporary value

    if (!userFile.good()) // check if there is not userEE.file file
    {
        ofstream createFile("userEE.file");     // Create userEE.file file
        createFile << "student: 0 homework: 0"; // Set up the file
        createFile.close();                     // colse the file
    }

    getline(userFile, temp, ' ');    // Skip to next word
    getline(userFile, tempNum, ' '); // Student Count
    studentSize = stoi(tempNum);     // convert string to int
    getline(userFile, temp, ' ');    // Skip to next word
    getline(userFile, tempNum, ' '); // Homework Count
    homeworkSize = stoi(tempNum);    // convert string to int

    for (int i = 0; i < studentSize; i++) // Get student array
    {
        getline(userFile, temp);      // Skip to next line
        getline(userFile, temp, ' '); // Skip to word
        if (temp == "student:")       // check if it student line
        {
            Student student; // temporary value

            getline(userFile, student.firstName, ' '); // Get first name
            getline(userFile, student.lastName, ' ');  // Get last name
            getline(userFile, student.Id, ' ');        // Get ID
            getline(userFile, tempNum, ' ');           // Get homework array size
            student.homeworkSize = stoi(tempNum);      // convert string to int

            studentList.push_back(student); // append student to student list

            for (int j = 0; j < stoi(tempNum); j++) // Get homework array
            {
                Homework homework; // temporary value
                string isDoneS;    // temporary value

                getline(userFile, homework.subject, '`');    // Get homework subject
                getline(userFile, temp, ' ');                // Skip to next line
                getline(userFile, isDoneS, ' ');             // Get isDone - Note 1 mean Done, 0 mean isn't done
                homework.isDone = stoi(isDoneS);             // convert string to int
                studentList[i].homework.push_back(homework); // Append homework to student
            }
        }
        else if (temp == "-") // Check if file corrupted
        {
            cout << "# File corrupted - #001" << endl; // show that the file corrupted
            break;
        }
    }

    getline(userFile, temp);      // Skip to next line
    getline(userFile, temp);      // Skip to next line
    getline(userFile, temp, '`'); // Skip to next word

    if (temp == "homework:") // check if it student line
    {
        for (size_t i = 0; i < homeworkSize; i++) // load homework list
        {
            getline(userFile, temp, '`'); // Skip to next word
            homeworkList.push_back(temp); // append homework to homework list
        }
    }
    else if (temp == "-") // Get homework
    {
        cout << "# File corrupted - #002" << endl;
    }

    userFile.close(); // Close File
}

void saveData()                         // save Data to userEE.file
{                                       //
    string data;                        // Store data
    ofstream createFile("userEE.file"); // Create userEE.file file

    data += "students: " + to_string(studentSize) + " homeworks: " + to_string(homeworkSize) + " #\n"; // Ouput Example - students: 0 homeworks: 0 #

    for (size_t i = 0; i < studentSize; i++) // add students to data
    {
        //  Output Example - student: fristName lastName Id Homework(Int)
        data += "student: " + studentList[i].firstName + " " + studentList[i].lastName + " " + studentList[i].Id + " " + to_string(studentList[i].homeworkSize) + " ";

        // Output Example - subject`isDone 0 #
        for (size_t j = 0; j < studentList[i].homeworkSize; j++)
        {
            // Output Example - subject`isDone 0
            data += studentList[i].homework[j].subject + "`isDone " + to_string(studentList[i].homework[j].isDone) + " ";
        }
        data += "#\n"; // Next line
    }

    data += "-\nhomework:"; // set up homework Array

    for (size_t i = 0; i < homeworkSize; i++)
    {
        data += "`" + homeworkList[i];
    }

    data += "`#\n-"; // End

    createFile << data; // Save Data
    createFile.close(); // colse the file
}

// Menu
void homeMenu();
int main()
{
    homeMenu();
}

void homeMenuOption(int &selected);
void newStudentMenu(int &selected);
void newHomeworkMenu(int &selected);
void assignHomework(int &selected);
void searchStudent(int &selected);
void list(int &selected);
void updateStudent(int &selected);
void remove(int &selected);

void handleCin(int &selected, int from, int to)
{
    int input;
    cin >> input;
    if (0 < input && input < 8)
    {
        selected = input;
    }
    else
    {
        while (true)
        { // To handle String or double input -- https://www.codegrepper.com/code-examples/cpp/how+to+make+sure+the+user+inputs+a+int+and+not+anything+else+c%2B%2B
            cout << "Error: choice " << from << " to " << to << endl;
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
        }
    }
}

void homeMenuOption(int &selected)
{
    system("clear");

    cout << "Welcome\n\n";
    cout << "	[1] Add new student\n";
    cout << "	[2] Add new homework\n";
    cout << "	[3] Assign homework to student\n";
    cout << "	[4] Search student details\n";
    cout << "	[5] Student & Homework list\n";
    cout << "	[6] Update student information\n";
    cout << "	[7] Delete student or homework record\n";
    cout << "Enter choice: ";
    handleCin(selected, 1, 7);
}

void newStudentMenu(int &selected) // Add new student to the system
{
    system("clear"); // Put your code under this line
    loadData();      // Load Data
    Student student; // temp

    cout << "Add New Student\n"; // Title
    cout << "   First Name: ";   // Asking for input
    cin >> student.firstName;    // user should write first student's first name
    cout << "   Last Name: ";    // Asking for input
    cin >> student.lastName;     // user should write first student's last name
    cout << "   ID: ";           // Asking for input
    cin >> student.Id;           // user should write first student's id
    student.homeworkSize = 0;
    studentSize++;
    studentList.push_back(student); // append student to student list
    saveData();                     // Save Data :)
    selected = 0;
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
