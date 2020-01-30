#include <iostream>
using namespace std;
int main() {
    int n,m,k,s;
    cin>>n>>m>>k>>s;

    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        if(s<k){
            break;
        }
        for(int j=0;j<m;j++){
            if(s<k){
                break;
            }
            else if(a[i][j]=='*' && j!=(m-1)){
                s=s+4;
            }
            else if(a[i][j]=='.'&& j!=(m-1)){
                s=s-3;
            }
            else if(a[i][j]=='#'){
                break;
            }
            else if(a[i][j]=='*' && j==(m-1)){
                s=s+5;
            }
            else if(a[i][j]=='.'&& j==(m-1)){
                s=s-2;
            }
        }
    }
    if(s>=k){
        cout<<"Yes"<<endl;
        cout<<s;
    }
    else{
        cout<<"No";
    }
    
    return 0;
}
