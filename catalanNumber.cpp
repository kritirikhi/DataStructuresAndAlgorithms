//                                                  CATALAN NUMBERS
// Finding the number of ways in which the BSTs can be formed from n nodes numbered 1 to n
// the number of bsts that can be formed from n nodes is the nth catalan number from the catalan series (1,1,2,5,14,42,132,429,--------)
// example:- if there are 3 nodes then possible no of ways for constructing bsts are 5 
#include <iostream>
using namespace std;

// method 1 (recursive soolution)
int catalan(int n){
    if(n==0){
        return 1;
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=catalan(i-1)*catalan(n-i);
    }
    return ans;
}
// method 2 is to calculate binomial coefficient 2nCn and nth catalan number will be 2nCn/(n+1)

int main() {

    for(int i=0;i<=4;i++){
        cout<<catalan2(2)/3<<"  ";
    }
}
