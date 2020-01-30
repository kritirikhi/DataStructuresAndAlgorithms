#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;

    int a[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int target;
    cin>>target;

    sort(a,a+n);

    int left=0,right=n-1;
    while(left<right){
        if (a[left]+a[right]>target){
            right--;
            continue;
        }
        else if(a[left]+a[right]==target){
            cout<<a[left]<<" and "<<a[right]<<endl;
            left++;
            right--;
        }
        
    }
	return 0;
}