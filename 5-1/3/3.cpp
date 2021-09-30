#include<iostream>
using namespace std;

class Student
{
    private:
        string _name, _major, _studentID;
    public:
        Student();
        void setName(string name);
        void setMajor(string major);
        void setStudentID(string studentID);
        void showStudentInfo(void);
};

Student::Student(void)
{
    _name=_major=_studentID="";
}
void Student::setName(string name)
{
    _name=name;
}
void Student::setMajor(string major)
{
    _major=major;
}
void Student::setStudentID(string studentID)
{
    _studentID=studentID;
}

void Student::showStudentInfo(void)
{
    cout << _name << " / " << _major << " / " << _studentID;
}

int main(void)
{
    string name,major,studentID;
    cout << "name :";
    getline(cin, name);
    cout << "major :";
    getline(cin, major);
    cout << "studentID :";
    getline(cin, studentID);

    Student stu;
    stu.setName(name);
    stu.setMajor(major);
    stu.setStudentID(studentID);

    stu.showStudentInfo();
}