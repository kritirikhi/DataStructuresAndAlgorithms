//                                                                              UNORDERED_MAP WITH CUSTOM CLASS

// we have to make a map of type PERSON
// PERSON type includes first name, last name, roll no 
// the unordered_map will store the entire PERSON object 
// we have to do 2 tasks
//     i)   make our own hash function
//     ii)  overload the operator == to check whether the 2 persons are same or not, 2 persons are same if they have same name and same roll no 

// task1 
//     to make the hashfunc we will make a simple formula that is to return person1.firstName.length() + person1.secondName.length()

// task2 
//     use operator overloading ans if person.rollno = rollno return true else return false

#include <bits/stdc++.h>
#include<cstring>
using namespace std;

// class person
class Person{
    public:

    string firstname;
    string lastname;
    string rollno;

    Person(string f,string l,string no){
        firstname = f;
        lastname  = l;
        rollno = no;
    }

    bool operator==(const Person &s)const{
        return rollno==s.rollno;
    }
};

// hashfunction
class hashfunc{
public:
    size_t operator()(const Person &s) const{
        return s.firstname.length() + s.lastname.length();
    }
};


int main() {
    unordered_map<Person,int,hashfunc> mp;
    // creating the objects of class person
    Person p1("Prateek","Narang","010");
    Person p2("Rahul","Kumar","023");
    Person p3("Prateek","Gupta","030");
    Person p4("Rahul","Kumar","120");

    // adding the contents to the hash map
    mp[p1]=100;
    mp[p2]=120;
    mp[p3]=90;
    mp[p4]=200;

    
    // check whether the 2 persons are same or not
    Person p("Prateek","Narang","200");
    if(p==p1){
        cout<<"same"<<endl;
    }

    // printing the contents of the hash map
    for(auto x:mp){
        cout<<x.first.firstname<<" "<<x.first.rollno<<endl<<" "<<x.second<<endl;
    }

    return 0;
}
