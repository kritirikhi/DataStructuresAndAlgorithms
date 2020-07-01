//                                                                              STOCK SPAN PROBLEM
//  ===================================================================================================================================================================
// "The Stock Span Problem"
// The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days.
// The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
// For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}


// Approach
// traverse the array of prices and maintain the stack of indices of the prices
// for every ith index check that whether the arr[stack of top] is less or greater than the current element
// if arr[s.top()] < current then we will pop the elements till we find the element int the stack which is greater than the current element and stack is not empty

// after that the better day will be equal to stack.top()
// span = current index - betterday 
// push the current element index in the stack 
// push the span of this element in the vector called ans 
#include <bits/stdc++.h>
using namespace std;

void stockspan(int prices[],int n){
    stack<int> s;
    vector<int> ans;
    for(int i=0;i<n;i++){
        while(!s.empty() && (prices[s.top()] <= prices[i]) ){
            s.pop();
        }

        int betterPriceDay;
        if(!s.empty()){
            betterPriceDay=s.top();
        }
        else if(i==0){
            betterPriceDay=0;
        }
        else if(i>0){
            betterPriceDay=-1;
        }
        int span=i-betterPriceDay;
        s.push(i);
        ans.push_back(span);
    }

    for(auto x:ans){
        cout<<x<<" ";
    }
}

int main() {
    int n;
    cin>>n;

    int prices[n];
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }

    stockspan(prices,n);

}
