#include <iostream>
#include<cstring>
using namespace std;
void filterchar(char a[],int n){
    int j=0;
    while(n>0){
        int lastbit=(n&1);
        if(lastbit==1){
            cout<<a[j];
        }
        j++;
        n=n>>1;
    }
    cout<<endl;
}
int main() {
    char a[100005];
    cin>>a;
    int n=strlen(a);
    for(int i=0;i<(1<<n);i++){
        filterchar(a,i);
    }
}
