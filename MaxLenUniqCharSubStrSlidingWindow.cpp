#include <iostream>
#include<cstring>
using namespace std;
int main() {
    char a[1000];
    cin>>a;
    int n=strlen(a);

    int curr_len=1;
    int max_len=1;
    int visited[256];
    for(int i=0;i<256;i++){
        visited[i]=-1;
    }

    visited[a[0]]=0;
    for(int i=1;i<n;i++){
        int last_occur=visited[a[i]];
        if(last_occur==-1 || (last_occur < i-curr_len)){
            curr_len++;
            max_len=max(max_len,curr_len);
        }
        else{
            max_len=max(curr_len,max_len);
            curr_len=i-last_occur;
        }
        visited[a[i]]=i;
    }
    cout<<max_len;
}
