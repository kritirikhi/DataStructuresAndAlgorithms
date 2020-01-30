#include <iostream>
#include<math.h>
using namespace std;
int main() {
    int cnt[64]={0};

    int n,no;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>no;
        int j=0;
        while(no>0){
            int lastbit = (no&1);
            cnt[j]=cnt[j]+lastbit;
            j++;
            no=no>>1;
        }
    }
   
    int uniqueNum=0;
    int p=1;
    for(int i=0;i<64;i++){
        int rem=cnt[i]%3;
        uniqueNum += rem*p;
        //p=pow(2,i+1);
        p=1<<(i+1);    // 1<<(i+1)  == 2 power (i+1)
    }
    cout<<uniqueNum;
    
    return 0;
}
