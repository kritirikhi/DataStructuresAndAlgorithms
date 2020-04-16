#include <iostream>
using namespace std;

void readline(char a[],int maxlen,char delim='\n'){
    char ch;
    ch=cin.get();
    int idx=0;
    while(ch!=delim){
        a[idx]=ch;
        idx++;
        if(idx==(maxlen-1)){
            break;
        }
        ch=cin.get();
    }
    a[idx]='\0';
    return;
}

int main() {
    char a[1000];
    readline(a,1000);
    cout<<a;
	return 0;
}
