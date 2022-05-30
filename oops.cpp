#include <iostream>
#include <string>

using namespace std;

class Student{
    public:
        string name;
        int age;
        bool gender;

        void printInfo(){
            cout<<"My name is "<<name<<". I am "<<age<<" years old. "<<"I am a "<<gender;
        }
}

int main(){
    return 0;
}