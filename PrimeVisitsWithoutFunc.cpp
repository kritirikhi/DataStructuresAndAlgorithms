#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    for(int x=0;x<t;x++){
        long long int a,b;
        cin>>a>>b;

        long long int count=0;
        for(long long int i=a;i<=b;i++){
            int flag=0;
            if(i!=1){
            for(long long int j=2;j<=sqrt(i);j++){
                if(i%j==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                count++;
            }
            }
        }
        cout<<count<<endl;
    }
	return 0;
}