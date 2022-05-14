#include <iostream>
using namespace std;
// structure  for homework details
struct homework
{
    string subject;
    string h_name;
    double signs;
};
// structure for student details
struct student
{
    string s_id;
    string s_name;
    string year;
    struct homework h;
} students[20];
int main()
{

    // Variables
    int ch, s_count = 0, h_count = 0;
    string n1, n2;
    struct homework hw[10];
    cout << "Student Homework management" << endl;
    do
    {
        // Menu
        cout << " \nl.  Add new student" << endl;
        cout << "2. Add new homework" << endl;
        cout << "3. Assign homework to student" << endl;
        cout << "4. Find student details" << endl;
        cout << "5. Student list" << endl;
        cout << "6. Homework list" << endl;
        cout << "7. Update student details" << endl;
        cout << " 8. Delete student/homework" << endl;
        cout << "enter your choice:" << endl;
        // get the user's choice
        cin >> ch;
        cin.ignore();
        switch (ch)
        {
        case 1:
        {
            // add new student
            //  get student details)
            cout << "enter student ID:" << endl;
            cin >> students[s_count].s_id;
            cout << "insert student name:" << endl;
            cin >> students[s_count].s_name;
            cout << "Enter the requester class:" << endl;
            cin >> students[s_count].year;
            s_count++;
            // increment of students count
            break;
        }
        case 2:
        {
            // add new homework
            // get homework details.
            cout << "Enter the homework subject:" << endl;
            cin >> hw[h_count].subject;
            cout << "Enter the homework name:" << endl;
            cin >> hw[h_count].h_name;
            cout << "Enter the maximum marks :" << endl;
            // ERROR cin >> hw [h_count].marks;
            cin.ignore();
            h_count++;
            // ERROR breaks;
            // increament the homework coymt
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
