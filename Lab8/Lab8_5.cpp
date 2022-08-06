
//Lab8_5.cpp
//Write a program for transaction processing that writeand read object randomly toand from a random access file
//so that user can add, update, deleteand display the account information(account - number, last - name, first - name, total - balance).


#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

struct transaction
{
private:
    //static int recNum[];
    unsigned accountNumber, totalBalance;
    string lastName, firstName;
public:
    void getData()
    {
        cout << "FIRST NAME:\t";
        cin >> firstName;
        cout << "LAST NAME:\t";
        cin >> lastName;
        cout << "ACCOUNT NUMBER:\t";
        cin >> accountNumber;
        cout << "TOTAL BALANCE:\t";
        cin >> totalBalance;
    }
    void display()
    {
        cout <<endl<< "Full Name: "<<firstName << setw(5) << lastName<< endl << "ACCOUNT NUMBER: " << accountNumber << endl << "TOTAL BALANCE: " << totalBalance <<endl;
    }
    int readFromFile(string FileN);
    void addToFile(string fileN);
    void updateInFile(string fileN);
    void deleteFromFile(string fileN);
};


int transaction::readFromFile(string fileN)
{
    int size;
    cout << endl << "DATA FROM THE FILE: ";

    fstream file;
    file.open(fileN, ios::in | ios::binary | ios::ate);
    if (file.fail())
    {
        cout << "could't open the file.";
        exit(1);
    }

    size = file.tellg() / sizeof(*this);
    file.seekg(0, ios::beg);
    file.read(reinterpret_cast<char*>(this), size * sizeof(*this));
    for (int i = 0; i < size; i++)
    {
        this[i].display();
    }
    file.close();
    return size;
}

void transaction:: addToFile(string fileN)
{
    int size;
    cout << "ENTER THE NUMBER OF ACCOUNTS YOU WANT TO ADD: ";
    cin >> size;

    system("cls");

    ofstream file;
    file.open(fileN, ios::binary|ios::app);
    if (file.fail())
    {
        cout << "could't open the file. exiting....";
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        //recNum = i + 1;
        cout << endl << "ACCOUNT " << i + 1 << endl;
        this->getData();
        file.write(reinterpret_cast<const char*>(this),sizeof(*this));
    }
    //file.write(reinterpret_cast<const char*>(this), size*sizeof(*this));

    file.close();

    cout << "THE RECORD HAS BEEN ADDED." << endl << "ENTER X TO RETURN TO THE SELECTION PAGE: ";
}


void transaction::updateInFile(string fileN)
{
    int size,n;

    size = readFromFile(fileN);
    //delete
    fstream file;
    cout << endl << "ENTER THE RECORD NUMBER YOU  WANT TO DELETE: ";
    cin >> n;
    
    file.open(fileN, ios::out|ios::in|ios::binary);
    if (file.fail())
    {
        cout << "could't open the file. exiting....";
        exit(1);
    }
    file.seekg((n - 1) * sizeof(*this));
    cout << "ENTER THE DATA MODIFIED DATA: ";
    this->getData();
    file.write(reinterpret_cast<const char*>(this),  sizeof(*this));
    file.close();

    cout << "THE RECORD HAS BEEN UPDATED." << endl << "ENTER X TO RETURN TO THE SELECTION PAGE: ";
}

void transaction::deleteFromFile(string fileN)
{
    int size, n;

    size = readFromFile(fileN);

    //delete
    fstream file,tempFile;
    cout << endl << "ENTER THE RECORD NUMBER YOU  WANT TO DELETE: ";
    cin >> n;

    file.open(fileN, ios::in | ios::binary);
    if (file.fail())
    {
        cout << "could't open the file. exiting....";
        exit(1);
    }
    tempFile.open("tempfile.dat", ios::out | ios::binary);
    file.seekg(0, ios::beg);
    for (int i = 0; i < size; i++)
    {
        file.read(reinterpret_cast<char*>(this), sizeof(*this));
        if (i == (n - 1))
            continue;
        tempFile.write(reinterpret_cast<const char*>(this), sizeof(*this));
    }
    file.close();

    ofstream outfile(fileN, ios::binary);
    if (outfile.fail())
    {
        cout << "could't open the file. exiting....";
        exit(1);
    }

    tempFile.close();
    tempFile.open("tempfile.dat", ios::in | ios::binary);

    for (int i = 0; i < (size - 1); i++)
    {
        tempFile.read(reinterpret_cast<char*>(this), sizeof(*this));
        outfile.write(reinterpret_cast<const char*>(this), sizeof(*this));
    }

    tempFile.close();
    remove("tempfile.dat");
    outfile.close();

    cout << "DELETION COMPLETE." << endl << "ENTER X TO RETURN TO THE SELECTION PAGE: ";
}

int main()
{
    string fileName;
    transaction t;
    char ch;
    int choice,temp;
    cout << "ENTER THE FILE NAME: ";
    cin >> fileName;

    system("cls");

    do
    {
        cout << "YOU WANT TO " << endl
            << "1. READ DATA OF THE FILE" << endl
            << "2. ADD DATA TO THE FILE" << endl
            << "3. UPDATE DATA OF THE FILE" << endl
            << "4. DELETE DATA FROM THE FILE" << endl
            << "5. EXIT" << endl;
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            temp = t.readFromFile(fileName);
            cout << endl << "ENTER X TO RETURN TO THE SELECTION PAGE: ";
            cin >> ch;
            system("cls");
            break;
        case 2:
            t.addToFile(fileName);
            cin >> ch;
            system("cls");
            break;
        case 3:
            t.updateInFile(fileName);
            cin >> ch;
            system("cls");
            break;
        case 4:
            t.deleteFromFile(fileName);
            cin >> ch;
            system("cls");
            break;
        case 5:
            system("cls");
            exit(1);
            break;

        default:
            cout << "Improper choice entered. exiting the program.....";
            break;
        }

    } while (ch == 'x' || ch == 'X');

    return 0;
}

