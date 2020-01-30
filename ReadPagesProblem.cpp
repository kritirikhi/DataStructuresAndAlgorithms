#include <iostream>
using namespace std;
bool isvalid(int a[],int m,int n,int mid){
    int students=1;
    int pages=0;
    for(int i=0;i<n;i++){
        if(pages+a[i]>mid){
            pages=a[i];
            students++;
            if(students>m){
                return false;
            }
        }
        else{
            pages=pages+a[i];
        }
    }
    return true;
}
int main() {
    int n,m;
    cin>>n>>m;

    int a[n]={22,44,11,63};

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }

    int s=0;
    int e=sum;
    int finalAns=0;
    while(s<=e){
        int mid=(s+e)/2;

        if(isvalid(a,m,n,mid)){
            finalAns=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }

    }
    cout<<finalAns;
}
