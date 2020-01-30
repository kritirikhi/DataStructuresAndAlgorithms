// operator overloading in object oriented programming
#include <iostream>
using namespace std;

class complex{
private:
    int real;
    int img;
public:
    complex(){
        real=0;
        img=0;
    }
    complex(int r,int i){
        real=r;
        img=i;
    }
    void setReal(int r){
        real=r;
    }
    void setImg(int i){
        img=i;
    }
    void add(complex &c){
        real+=c.real;
        img+=c.img;
    }
    void operator+(complex &c){
        real+=c.real;
        img+=c.img;
    }
    void operator!(){
        img=img*(-1);
    }
    void operator[](string s){
        if(s=="real"){
            cout<<real<<endl;
        }
        else{
            cout<<img<<endl;
        }
    }
    void print(){
        if(img<0){
            cout<<real<<" - "<<-img<<" i"<<endl;
        }
        else{
             cout<<real<<" + "<<img<<" i"<<endl;
        }
    }
};

istream& operator >> (istream &is,complex &c){
    int r1,i1;
    cin>>r1>>i1;
    c.setReal(r1);
    c.setImg(i1);
    return is;
}

ostream& operator << (ostream &os,complex &c){
    c.print();
    return os;
}

int main() {
    complex c1(6,-8);
    complex c2(3,5);
    // adding two complex nos
    c1.add(c2);
    c1.print();

    // adding two nos using overloading of + operator
    complex c3(6,7);
    complex c4(2,5);
    c3+c4;
    c3.print();

    // negating the imaginary part using  ! operator
    !c3;
    c3.print();

    // using [] operator to print real or img part of the complex no
    c3["real"];
    c3["img"];

    // to overload left shift << and right shift >> operator
    // we will use << and >> for cin and cout the complex nos respectively
    complex d1,d2;
    cin>>d1>>d2;
    cout<<d1<<d2;
}
