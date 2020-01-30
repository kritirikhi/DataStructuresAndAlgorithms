#include<iostream>
#include<math.h>
using namespace std;

int checkprime(long long int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    int flag=1;
    for(long long int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            flag=0;
            return 0;
            break;
        }
    }
    if(flag){
        return 1;
    }
}

int main() {
    int t;
    cin>>t;
    
    for(int x=0;x<t;x++){
        long long int a,b;
        cin>>a>>b;

        long long int count=0;
        for(long long int i=a;i<=b;i++){
            int y;
            y=checkprime(i);
            if(y){
                count++;
            }
        }
        cout<<count<<endl;
    }
	return 0;
}