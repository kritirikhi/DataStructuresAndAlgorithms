#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    // initialisation and declaration of the array
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // finding maximum of the array input by the user
    int maximum=0;
    for(int i=0;i<n;i++){
        maximum=max(maximum,a[i]);
    }
    // building up of frequency array 
    int freq[maximum+1]={0};
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    // printing the elements from the frequency array in sorted manner 
    cout<<"sorted array is :- "<<endl;
    for(int i=0;i<=maximum;i++){
        if(freq[i]!=0){
            while(freq[i]!=0){
                cout<<i<<"  ";
                freq[i]--;
            }
        }
    }
    return 0;
}
