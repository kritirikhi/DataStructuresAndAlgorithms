#include <iostream>
#include<cstring>
using namespace std;
int main() {
    char a[1000];
    cin>>a;
    int len=strlen(a);

    cout<<a[0];
    for(int i=1;i<len;i++){
        int x=a[i]-a[i-1];
        if(x>=0 && x<9){
            char y=x+48;
            cout<<y;
        }
        else if(x>9){
            int x1;
            int x2;
            int x3=x;
            x1=x3%10;
            x3=x3/10;
            x2=x3%10;
            cout<<x2;
            cout<<x1;
        }
        else if(x<0 && x>-9){
            char b=45;
            cout<<b;
            char b2=(-x)+48;
            cout<<b2;
        }
        else if(x<-9){
            int y3=-x;
            int y1;
            int y2;
            y1=y3%10;
            y3=y3/10;
            y2=y3%10;
            char y4=45;
            cout<<y4<<y2<<y1;

        }
        cout<<a[i];
    }
    
}
