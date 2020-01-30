#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    // initialisation and declaration of array  finding xor of all the elements of array
    int a[n];
    int result=0;
    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        a[i]=no;
        result=result^no;
    }
  

    // finding position of 1st set bit in the xor of all the elements where xor==result
    int temp=result;
    int pos=0;
    while(temp>0){
        int lastbit=temp&1;
        if(lastbit==1){
            break;
        }
        temp=temp>>1;
        pos++;
    }
    
    // creation of mask
    int mask= 1<<pos;

    // finding one of the two nos which r unique
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if( (a[i]&mask)>0 ){
            x=x^a[i];
        }
    }
    // calculating the second unique number required 
    y=x^result;
    cout<<min(x,y)<<" "<<max(x,y);        
    return 0;
}
   
