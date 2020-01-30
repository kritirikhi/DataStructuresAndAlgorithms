#include <iostream>
using namespace std;

bool isOdd(int n){
    return n&1;
}

int getBit(int n,int i){
    int mask=1<<i;
    mask=mask&n;

    if(mask>1){
        return 1;
    }
    else if(mask==0){
        return 0;
    }
}

int setBit(int n,int i){
    int mask=1<<i;
    mask=mask|n;
    return mask;
}

int clearBits(int n,int i){
    int ones = ~(0);
    ones=ones<<i;

    return n & ones;
}

int clearXtoY(int n,int x,int y){
    int a,b;
    // creating a
    a= ~(0);
    a=a<<(y+1);

    //creating b
    b=(1<<x)-1;

    return (a|b) & n;   
}

int main() {
    int n;
    cin>>n;
    
    // to check whether the no is odd or even 
    bool dec;
    dec=isOdd(n);
    if(dec==1){
        cout<<"no is odd"<<endl;
    }
    else{
        cout<<"no is even"<<endl;
    }

    // to find the ith bit in no
    int i;
    cin>>i;

    int bit=getBit(n,i);
    cout<<i<<" bit in "<<n<<" is "<<bit<<endl;

    // to set the ith bit in no

    int ans=setBit(n,i);
    cout<<"after setting "<<i<<" bit the no becomes "<<ans<<endl;

    // to clear last i bits in no
    int clearNo=clearBits(n,i);
    cout<<"after clearing last "<<i<<" bits the no becomes "<<clearNo<<endl;

    // to clear the bits from range x to y;
    int x,y;
    cin>>x>>y;

    int clearRangeNo=clearXtoY(n,x,y);
    cout<<"after clearing the no from "<<x<<" to "<<y<<" the no becomes "<<clearRangeNo<<endl;
}
