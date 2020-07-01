//                                                                              BUCKET SORT

// In a bucket sort the one cell of the array/vector is considered to be a bucket
// as bucket can have more than one item, similarly the one cell of the array can store the multiple values

// consider there are n students each having the marks scored in a test and we have to make a rank list 
// eg :-
//     A - 50
//     B - 40
//     C - 10
//     D - 50
//     E - 10

// The rank list will look like
//     A - 50 
//     D - 50
//     B - 40 
//     C - 10
//     E - 10

// As A and D has scored same marks so they can get the same bucket of index 50
// As C and E has scored same marks so they can get the same bucket of index 10

// It works in a way that one bucket will store similar info has in the above example one bucket of i marks can store those students who score i marks in test 
// store the data acc to the bucket values 
// and then print the whole array



#include <bits/stdc++.h>
using namespace std;

// class student storing the names and marks of the student
class student{
    public:
        string name;
        int marks;
};

// bucket sort
void bucketSort(student s[],int n){
    // array of vectors of students 
    vector<student> v[101];

    for(int i=0;i<n;i++){
        string name=s[i].name;
        int m=s[i].marks;
        // adding student with marks m to the array
        v[m].push_back(s[i]);
    }

    // printing the array of vectors
    for(int i=100;i>=0;i--){
        for(auto x:v[i]){
            cout<<x.name<<" "<<x.marks<<endl;
        }
    }
    
}

int main() {

    // declaring an array of students
    student s[100000];

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string name;
        int marks;
        cin>>name>>marks;
        s[i].name=name;
        s[i].marks=marks;
    }

    // calling the bucket sort function
    bucketSort(s,n);
}
