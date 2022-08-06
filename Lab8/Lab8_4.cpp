//Lab8_4.cpp
//Write a program that stores the information about students(name, student id, department, and address) 
//in a structure and then transfers the information to a file in your directory.
//Finally, retrieve the information from your fileand print it in the proper format on your output screen


#include<iostream>
#include<fstream>
using namespace std;

struct student
{
private:
    int studentID;
    string name,address,department;
public:
    void getData()
    {
        cout << "NAME:\t";
        cin >> name;
        cout << "STUDENTS ID:\t";
        cin >> studentID;
        cout << "ADDRESS:\t";
        cin >> address;
        cout << "DEPARTMENT:\t";
        cin >> department;
    }
    void showData()
    {
        cout <<endl<< "Name: "<<name << endl <<"Student's ID: " << studentID << endl <<"Address: " << address << endl <<"Department: " << department<<endl;
    }

};


void writeToFile(string fileN)
{
    int size;
    student* s;
    cout << "ENTER THE NUMBER OF STUDENTS YOU WANT TO REGISTER: ";
    cin >> size;

    system("clear");
    s = new student[size];

    ofstream file;
    file.open(fileN, ios::binary|ios::app);
    if (file.fail())
    {
        cout << "could't open the file.";
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        s[i].getData();
    }
    file.write(reinterpret_cast<const char*>(s), size*sizeof(student));
    file.close();

    delete[]s;
}
void readFromFile(string fileN)
{
    int size;
    student* s;
    
    cout << "DATA FROM THE FILE: ";

    ifstream file;
    file.open(fileN, ios::binary|ios::ate);
    if (file.fail())
    {
        cout << "could't open the file.";
        exit(1);
    }

    size = file.tellg() / sizeof(student);
    file.seekg(0, ios::beg);

    s = new student[size];
    file.read(reinterpret_cast<char*>(s), size*sizeof(student));
    for (int i = 0; i < size; i++)
    {
        s[i].showData();
    }
    file.close();

    delete[]s;
}

int main()
{
    string fileName;
    cout << "ENTER THE FILE NAME: ";
    cin >> fileName;

    writeToFile(fileName);
    readFromFile(fileName);

    return 0;
}
