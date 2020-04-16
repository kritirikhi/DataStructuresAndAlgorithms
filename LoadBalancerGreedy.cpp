//                     LOAD BALANCER PROBLEM 
// the prob is from spoj
// https://www.spoj.com/problems/BALIFE/


// Approach 1
// first calculate the whether the jobs can equally be divided among the processors
// if yes
//      then first calc the no of jobs each processor must do  i.e (total jobs)/no of processors
//      for each cell we have to calc atleast how many rounds must be taken to transfer the elements from right to left part of array or vice versa
//      the max of all the atleast rounds is the optial rounds needed to transfer the jobs among the processors
// if no
//      cout<<"-1"

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     while(1){
        
//         long long int n;
//         cin>>n;
//         if(n == -1){
//             break;
//         }
        
//         long long int sum=0;
//         long long int a[n];
//         for(long long int i=0;i<n;i++){
//             cin>>a[i];
//             sum+=a[i];
//         }
        
//         if(sum%n==0){
//             long long int processNeed=sum/n;
//             long long int ans=INT_MIN;
//             for(long long int i=0;i<n;i++){
//                 long long int j=0;
//                 long long int sumleft=0;
//                 long long int sumleftNeeded=0;
//                 for(j=0;j<=i;j++){
//                     sumleft+=a[j];
//                     sumleftNeeded=sumleftNeeded+processNeed ;
//                 }
                
//                 long long int sumright=0;
//                 long long int sumrightNeeded=0;
//                 long long int k=i+1;
//                 for(;k<n;k++){
//                     sumright+=a[k];
//                     sumrightNeeded=sumrightNeeded+processNeed;
//                 }
                
//                 long long int rounds=abs(sumleftNeeded-sumleft);
//                 ans=max(ans,rounds);
//             }
            
//             cout<<ans<<endl;
            
//         }
        
//         else{
//             cout<<"-1"<<endl;
            
//         }
        
//         cin.get();
       
//     }
// 	return 0;
// }
 
// approach 2 same as approach 1 but implementation is different
// the cells whih we were taking one by one can be maintained by a difference var 
// difference var will tell that for each division how many transfers of jobs are needed from left to right part of the array and vice versa
// make a running difference

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    while(1){
        
        long long int n;
        cin>>n;
        if(n == -1){
            break;
        }
        
        long long int sum=0;
        long long int a[n];
        for(long long int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        
        if(sum%n!=0){
            cout<<"-1"<<endl;
            continue;
        }
        
        int load=sum/n;
        int diff=0; 
        int ans;
        int noOfRounds=INT_MIN;
        for(int i=0;i<n;i++){
            diff+=a[i]-load;
            ans=max(diff,-diff);
            noOfRounds=max(noOfRounds,ans);
        }
        
        cout<<noOfRounds<<endl;
        cin.get();
       
    }
	return 0;
}































