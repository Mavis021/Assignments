#include <iostream>
#include <vector>
#include <string>


class student{

    private:
    std::string name;
    int age, id,i;
    int *marks;
    float per;

    public:
    student(){
        name = "hello";
        age = 0;
        id = 0;
        marks = new int[5];
    }

    // ~student(){
    //     delete [] marks;
    // }

    void getData(){
        std::cout<<"\n ENTER THE NAME OF STUDENT: ";
        std::cin>>name;
        std::cout<<"\n ENTER THE AGE OF STUDENT: ";
        std::cin>>age;

        std::cout<<"\n ENTER THE MARKS OBTAINED IN EACH SUBJECTS: ";
        for(i = 0; i < 5; i++){
            std::cout<<"\n SUBJECT "<< i+1 <<" : ";
            std::cin>>marks[i];
        }
        i = 0;
    }

    float getPercentage(){
        int sum = 0;
        for(i = 0; i < 5; i++){
            sum += marks[i];
        }
        per = sum/5;
        return(per);
    }

    void showData(int id){
        std::cout<<"STUDENT "<<id + 1<< ": \n"
        <<"NAME       : "<< name <<  std::endl
        <<"AGE        : "<< age  <<  std::endl
        <<"PERCENTAGE : "<< per  <<  std::endl;
    }

};

int main(){

    std::vector<student> studentVector;

    char prompt = 'y';

    while(prompt == 'y'){
        student s;
        s.getData();
        std::cout<<"\n THE OBTAINED PERCENTAGE IS "<<s.getPercentage();
        studentVector.push_back(s);


        std::cout<<"\n DO YOU WANT TO ENTER ANOTHER STUDENT? (press 'y' for yes)"<<std::endl;
        std::cin>>prompt;
        system("clear");
    }

    std::cout<<"\n THE STUDENT LIST: \n";
    int i = 0;
    for (student &s: studentVector){
        std::cout<<"------------------------------\n";
        s.showData(i);
        i++;
    }

    studentVector.clear();

    return 0;
}
