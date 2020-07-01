#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class car{
    public:
    string name;
    int x,y;

    car(string n,int x,int y){
        name=n;
        this->x=x;
        this->y=y;
    }

    int dist(){
        return x*x + y*y;
    }
};

bool compare(car obj1,car obj2){
    if(obj1.dist()==obj2.dist()){
        return obj1.name<obj2.name;
    }
    return obj1.dist() < obj2.dist();
}

int main() {
    vector<car> a;

    int t;
    cin>>t;

    for(int q=0;q<t;q++){
        string name;
        int x,y;
        cin>>name>>x>>y;

        car obj(name,x,y);
        a.push_back(obj);
    }

    sort(a.begin(),a.end(),compare);

    for(auto obj:a){
        cout<<"car "<<obj.name<<" location "<<obj.x<<","<<obj.y<<" from origin "<<obj.dist()<<endl;
    }
    return 0;
}
