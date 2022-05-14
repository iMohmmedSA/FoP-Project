#include <iostream> // Usage get input send output
#include <fstream>  // Usage store data
#include <vector>   // Usage store data
using namespace std;

// structure  for homework details
// struct homework
// {
//     string subject;
//     string h_name;
//     double signs;
// };
// // structure for student details
// struct student
// {
//     string s_id;
//     string s_name;
//     string year;
//     struct homework h;
// } students[20];

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
    createFile.close();

    // Set data to default
    homeworkList.clear(); // Erase all homework data on memory
    studentList.clear();  // Erase all studtent data on memory
    homeworkSize = 0;
    studentSize = 0;
}

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
    cin.ignore();
}

int main()
{
    int selected = 0;
    ifstream userFile("userEE.file");
    if (!userFile.good()) // check if there is not userEE.file file
    {
        ofstream createFile("userEE.file");     // Create userEE.file file
        createFile << "student: 0 homework: 0"; // Set up the file
        createFile.close();                     // colse the file
    }
    cout << "Student Homework management" << endl;
    do
    {
        // Menu
        cout << "1.  Add new student" << endl;
        cout << "2. Add new homework" << endl;
        cout << "3. Assign homework to student" << endl;
        cout << "4. Find student details" << endl;
        cout << "5. Student list" << endl;
        cout << "6. Homework list" << endl;
        cout << "7. Update student details" << endl;
        cout << "8. Delete student/homework" << endl;
        cout << "enter your choice:" << endl;
        // get the user's choice
        handleCin(selected, 1, 8);

        switch (selected)
        {
        case 1:
        {
            loadData();      // Load Data
            Student student; // temp

            cout << "Add New Student\n";    // Title
            cout << "   First Name: ";      // Asking for input
            cin >> student.firstName;       // user should write first student's first name
            cout << "   Last Name: ";       // Asking for input
            cin >> student.lastName;        // user should write first student's last name
            cout << "   ID: ";              // Asking for input
            cin >> student.Id;              // user should write first student's id
            student.homeworkSize = 0;       // Set homework to 0
            studentSize++;                  // student count increase
            studentList.push_back(student); // append student to student list
            saveData();                     // Save Data :)
            selected = 0;
            break;
        }
        case 2:
        {
            string info = "EE"; // temp
            loadData();         // Load Data

            cout << "Add New Homewrok\n\n";                  // Title
            cout << "   Example: English 101 Page:23 Q2\n";  // Example for input
            cout << "   Write information about homework: "; // Asking for input
            getline(cin, info);                              // user write information about homework
            homeworkSize++;                                  // Increase homework size
            homeworkList.push_back(info);                    // append homework to homework list
            saveData();                                      // Save Data
            selected = 0;                                    // Back to main menu
        }
        case 3:
        { // assign the student's homework
          // get the status of the student's details

            cout << "enter student ID:" << endl;
            cin >> n1;
            cout << "Enter the homework name:" << endl;
            cin >> n2;
            for (int i = 0; i < s_count; i++)
            {
                if (students[i].s_id == n1)
                {
                    for (int j = 0; j < h_count; j++)
                    {
                        if (hw[j].h_name == n2)
                        {
                            students[i].h = hw[j];
                            // assign homework to student
                        }
                    }
                }
            }
            saveData(); // Save Data

            break;
        }

        case 4:
        {

            // Search student details

            cout << "Enter the student id: " << endl;
            cin >> n1;

            for (int i = 0; i < s_count; i++)
            { // Search student array
                if (students[i].s_id == n1)
                {

                    cout << "Student details: \n--------------" << endl; // Display details.

                    cout << "Student id: " << students[i].s_id << endl;

                    cout << "Student name: " << students[i].s_name << endl;

                    cout << "class: " << students[i].year << endl;

                    cout << "Homework Assigned: " << students[i].h.h_name << endl;

                    cout << "Subject: " << students[i].h.subject << endl;

                    // errer cout<<"Marks: "<<students[i].h.marks<<endl;

                    cout << " --------------" << endl;
                }
            }

            break;
        }
        case 5:
        { // Students list
            cout << "Student details: \n-----------------" << endl;

            for (int i = 0; i < s_count; i++)
            { // Display details for all students
                cout << "Student id: " << students[i].s_id << endl;

                cout << "Student name: " << students[i].s_name << endl;

                cout << "class: " << students[i].year << endl;

                cout << "Homework Assigned: " << students[i].h.h_name << endl;

                cout << "Subject: " << students[i].h.subject << endl;

                // errer cout<<"Marks: "<<students[i].h.marks<<endl;

                cout << "------------------------" << endl;
            }
            break;
        }
        case 6:
        { // Homework list

            cout << "Homework details: \n---------------" << endl;
            for (int i = 0; i < h_count; i++)
            { // Display details for all homeworks

                cout << "Homework name: " << hw[i].h_name << endl;

                cout << "Subject: " << hw[i].subject << endl;

                // cout<<"Marks: "<<hw[i].marks<<endl;  cout<<"------------------------"<<endl;
            }
            break;
        }

        case 7:
        { // Update student details
            cout << "Enter the student id to be updated: " << endl;
            cin >> n1;
            for (int i = 0; i < s_count; i++)
            {

                if (students[i].s_id == n1)
                { // Search student array

                    // Get the student details and change.
                    cout << "Student name: " << endl;

                    cin >> students[i].s_name;

                    cout << "class: " << endl;

                    cin >> students[i].year;

                    cout << "Enter the homework name: " << endl;

                    cin >> n2;
                    for (int j = 0; j < h_count; j++)
                    { // for homework details.

                        if (hw[j].h_name == n2)
                        {
                            students[i].h = hw[j];
                        }
                    }
                }
            }
            break;
        }

        case 8:
        { // Delete student/homework
            int c;

            cout << "1.Student In2.Homework" << endl;

            cout << "Enter your choice for deletion:" << endl;

            cin >> c; // Get the choice

            cin.ignore();
            if (c == 1)
            { // For student record

                cout << "Enter the student id to be deleted: " << endl;
                cin >> n1;

                for (int i = 0; i < s_count; i++)
                {

                    if (students[i].s_id == n1)
                    {
                        for (int j = i + 1; j < s_count; j++)
                        {

                            students[j - 1] = students[j]; // move the elements in the array
                        }
                        s_count--; // decrement student coun count
                    }
                }
            }

            else if (c == 2)
            { // For homework record
                cout << "Enter the homework name to be deleted: " << endl;
                cin >> n1;
                for (int i = 0; i < h_count; i++)
                {
                    if (hw[i].h_name == n1)
                    {

                        for (int j = i + 1; j < h_count; j++)
                        {
                            hw[j - 1] = hw[j]; // move the elements in the array
                        }
                        h_count--; // decrement homework count
                    }
                }
            }
            break;
        }
        default:
            exit(0);
        }
        // exit
    } while (1);
}
