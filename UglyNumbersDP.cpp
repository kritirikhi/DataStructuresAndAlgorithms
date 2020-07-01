//                                      UGLY NUMBERS PROBLEM

// You are provided a sequence of number. All numbers of that sequence is in increasing order (including 1) and whose only prime factors are 2, 3 or 5 (except 1). You need to find the nth number of that sequence.

// Input Format
// First line contains integer t which is number of test case. For each test case, it contains an integer n.

// Constraints
// 1<=t<=100 1<=n<=10000

// Output Format
// Print nth number of that sequence.

// Sample Input
// 2
// 7
// 10
// Sample Output
// 8
// 12
// Explanation
// Sequence : 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, …..




#include<iostream>
using namespace std;

void uglyNumbers(long long int ugly[]){
	ugly[0]=1;
        
    long long int i2,i3,i5;
    i2=i3=i5=0;
        
    long long int next2=ugly[i2]*2;
    long long int next3=ugly[i3]*3;
    long long int next5=ugly[i5]*5;
    long long int currUgly=1;
        
    for(long long int i=1;i<10005;i++){
        currUgly=min(next2,min(next3,next5));
        ugly[i]=currUgly;
        
        if(currUgly==next2){
            i2++;
            next2=ugly[i2]*2;
        }
        if(currUgly==next3){
            i3++;
            next3=ugly[i3]*3;
        }
        if(currUgly==next5){
            i5++;
            next5=ugly[i5]*5;
        }
    }
}

int main() {
	long long int ugly[10005];
	uglyNumbers(ugly);

	long long int t;
	cin>>t;

	for(long long int x=0;x<t;x++){
		long long int n;
		cin>>n;

		cout<<ugly[n-1]<<endl;
	}
	return 0;
}