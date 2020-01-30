#include <iostream>
#include<math.h>
using namespace std;

// int product(int a,int b){
//     if(a<b){
//         product(b,a);
//     }
//     else if(b!=0){
//         return a+product(a,b-1);
//     }
//     else if(b==0){
//         return 0;
//     }
// }

int toInteger(char *a,int n){
    if(n==1){
        return a[0]-'0';
    }
    int ans=0;
    int power=pow(10,n-1);
    int num=a[0]-'0';
    ans = num*power + toInteger(a+1,n-1);
    return ans;
}

int main() {
    //int a,b;
    //cin>>a>>b;
   // cout<<product(a,b)<<endl;

    char a[4];
    cin>>a;
    cout<<toInteger(a,4);
}
