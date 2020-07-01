//                                                              MAX POSSIBLE RECTANGLE AREA UNDER THE HISTOGRAM

// Approach 
// use the stack implementation
// we will push the elements (heights of the bars of histogram) in the stack if they are greater than the top element of the stack
// if the ith element is less than the top element of the stack then:-
        // pop out the top element of the stack till ith element < top element of the stack
        // if stack gets empty
        //     current area = topElement * i 
        // if stack does not gets empty 
        //     current area = topElement * (i - s.top() - 1)
        // area = max(area,current area) 

#include <bits/stdc++.h>
using namespace std;

void findMaxRect(int a[],int n){
    stack<int> s;
    s.push(0);

    int i=1;
    int area=INT_MIN;
    while(i<n){
        if(a[i]>a[s.top()]){
            s.push(i);
        }
        else{
            while(a[i]<a[s.top()]){
                int topElement=a[s.top()];
                s.pop();
                if(s.empty()){
                    int currentArea=topElement*i;
                    area=max(area,currentArea);
                    s.push(i);
                    break;
                }
                else{
                    int currentArea=topElement*(i-s.top()-1);
                    area=max(area,currentArea);
                }
            }
            s.push(i);
        }
        i++;
    }

    while(!s.empty()){
        int topElement=a[s.top()];
        s.pop();
        if(s.empty()){
            int currentArea=topElement*i;
            area=max(area,currentArea);
            break;
        }
        else{
            int currentArea=topElement*(i-s.top()-1);
            area=max(area,currentArea);
        }
    }

     cout<<area;
}

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    findMaxRect(a,n);
}
