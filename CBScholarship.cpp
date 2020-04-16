#include <iostream>
using namespace std;
int main() {
    long long int n,m,x,y;
    cin>>n>>m>>x>>y;

    long long int s=0;
    long long int e=n;
    long long int maxStudents=0;

    while(s<=e){
        long long int mid=(s+e)/2;
        long long int couponsNeeded=mid*x;
        long long int couponsPaid=(n-mid)*y;
        long long int availCoupons=couponsPaid+m;

        if(couponsNeeded<=availCoupons){
            maxStudents=max(maxStudents,mid);
            s=mid+1;
        }
        else if(couponsNeeded>availCoupons){
            e=mid-1;
        }
    }
    cout<<maxStudents;
}
