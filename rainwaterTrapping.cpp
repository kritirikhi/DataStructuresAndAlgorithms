#include <iostream>
using namespace std;
int main() {
    int n,building[100];
    cin>>n;
    int i;
    for(i=0;i<n;i++){
        cin>>building[i];
    }

    int left[100],right[100];

    // left array
    left[0]=building[0];
    for(i=1;i<n;i++){
        int max1=max(building[i],building[i-1]);
        left[i]=max(max1,left[i-1]);
    }
    //right array
    right[n-1]=building[n-1];
    for(i=n-2;i>=0;i--){
        int max1=max(building[i],building[i+1]);
        right[i]=max(max1,right[i+1]);
    }
    int water=0;
    for(i=0;i<n;i++){
        water+=min(left[i],right[i])-building[i]; 
    }
    cout<<water;


}
