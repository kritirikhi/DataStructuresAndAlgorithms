//                                                                      FACTORIAL OF LARGER NUMBER i.e fact(100)

// this can be done with the help of array


#include <iostream>
using namespace std;

void multiply(int a[],int &idx,int no){
    int carry=0;
    for(int i=0;i<idx;i++){
        int product=a[i]*no + carry;
        a[i]=product%10;
        carry=product/10;
    }
    
    while(carry){
        a[idx]=carry%10;
        carry=carry/10;
        idx++;
    }
}

int facto(int n){
    int a[10000];
    a[0]=1;
    
    int idx=1;
    for(int i=2;i<=n;i++){
        multiply(a,idx,i);
    }
    
    for(int i=idx-1;i>=0;i--){
        cout<<a[i];
    }
}

int main() {
	
	int n;
	cin>>n;
	
	facto(n);
	return 0;
}
