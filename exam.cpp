#include <iostream>
using namespace std;
class Person
{
private:
    string person_name;

public:

    Person(string x)
    {
        person_name = x;
    }


    string getName()
    {
        return person_name;
    }

};
class Student : public Person
{
private:
    string student_id;
    int obtained_marks = 0;
public:
    Student(string person_name) : Person(person_name) {}
    Student(string person_name, string y) : Person(person_name)
    {
        student_id = y;
    }


    void operator+(int n)
    {
        obtained_marks+=n;
    }
    void showMarks()
    {
        cout<<obtained_marks<<endl;
    }
};

int countVote(string person_name)
{
    cout<<"\nPlease enter the likeness number(range from 1 to 5) for "<<person_name<<" : ";
    int n;
    cin>>n;
    while(1)
    {
        if(n<=5 and n>0) return n;
        else
        {
            cout<<"The likeness number you have given is invalid\n";
            cout<<"\nPlease enter the valid likeness number(range from 1 to 5) for "<<" : ";
            cin>>n;
        }

    }

}

int main()
{
    Student student[10]=
    {
        Student("Utpal"),
        Student("Evana"),
        Student("Arman"),
        Student("Sharif"),
        Student("Fomey"),
        Student("Shanto"),
        Student("Shipra"),
    };
    cout<<"Here are the 7 selected student, they will be voted.\n\n";

    for( int i=0; i<7; i++) cout<<i+1<<". "<<student[i].getName()<<endl;

    while(1)
    {
        cout<<"If you want to vote as a student type 's'.\nIf you want to vote as a teacher type 't'.\n";
        cout<<"(If you want to exit the voting competition type 'e' anytime)"<<endl;
        string indicator;
        cin>>indicator;
        if(indicator == "e")
        {
            for(int i=0; i<7; i++)
            {
                cout<<student[i].getName() <<" == ";
                student[i].showMarks();
            }
            break;
        }
        else if(indicator == "s" || indicator =="t")
        {
            if(indicator == "s") cout<<"I'm voting as a student\n";
            if(indicator == "t") cout<<"I'm voting as a teacher\n";
            cout<<"Enter student's serial number for whom you want to vote: ";
            int n;
            cin>>n;
            n--;

            while(1)
            {
                if(n<5 and n>=0)
                {
                    int x= countVote(student[n].getName());

                    student[n] + x;
                    break;
                }
                else
                {
                    cout<<"You have given invalid serial number.\n";
                    cout<<"Please enter student's valid serial number for whom you want to vote: ";
                    cin>>n;
                }
            }
        }
        else
        {
            cout<<"The input you have given is invalid character\n";
        }
    }

    return 0;

}
