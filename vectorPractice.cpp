#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    // entering elements by a lop
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        v.push_back(i);
    }
    // printing the elements of the vector
    cout<<"original vector contains"<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }  
    vector<int> v2;
    v2.swap(v);
    cout<<endl;
    cout<<"swapped vector is"<<endl;
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
}
