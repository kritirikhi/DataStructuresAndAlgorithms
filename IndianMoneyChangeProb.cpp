// given an amount of money , we have to find the change needed for the money (minmum no of notes and coins)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool compare(int a,int b){
    return a<=b;
}

int main() {
    int a[]={1,2,5,10,20,50,100,200,500,2000};
    int n=sizeof(a)/sizeof(int);
    int money;
    cin>>money;
    
    while(money>0){
        int lb=lower_bound(a,a+n,money,compare)-a-1;
        int m=a[lb];
        cout<<m<<" ";
        money=money-m;
    }
	return 0;
}
