#include <iostream>
using namespace std;

int kadane(int arr[],int n){
    int csum=0,maxsum=0;
    for(int i=0;i<n;i++){
       csum=csum+arr[i];
       if(csum<0){
           csum=0;
       }
       else if(maxsum<csum){
           maxsum=csum;
       }
   }
   return maxsum;
}

int main() {
   int arr[100];
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }
    int sum=0;
    for(int j=0;j<8;j++){
        sum+=arr[j];
    }

   int candidate1=kadane(arr,n);;

   for(int i=0;i<8;i++){
       arr[i]= -arr[i];
   }
   int candidate2=kadane(arr,n);;

   cout<<max(candidate1,sum-(-candidate2));


}
