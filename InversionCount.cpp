//                                                                          INVERSION COUNT
// InversionCount
// Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
// If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
// Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

//  =============================================================================================================================================================

// Approach

// we can use the divide and conquer
// eg :- for the given array 1 , 5 , 2 , 6 , 3 , 0
//       on dividing:-
//         the array looks like    1 , 5 , 2          6 , 3 , 0
//         so now the inversion count will be:-
//             the inversion pairs in left part + the inversion pairs in right part + the inversion pairs in crossSections (on combining the 2 parts) 

// For this we can use merge sort algorithm
//     the merge func will return the no of inversion pairs possible in the crossSections

#include <iostream>
using namespace std;

// merge function
int merge(int a[],int s,int e){
    int i=s;
    int mid=(s+e)/2;
    int j=mid+1;
    int k=s;

    int temp[10000];
    int count=0;
    while(i<=mid && j<=e){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }
        // when an ith element in left part > jth element in right part
        // then all the elements from i to last of the left part makes the inversion pairs
        // hence count+=mid-i+1
        else if(a[i]>a[j]){
            temp[k++]=a[j++];
            count=count+(mid-i+1);
        }
    }

    while(i<=mid){
        temp[k++]=a[i++];
    }

    while(j<=e){
        temp[k++]=a[j++];
    }

    for(int x=s;x<=e;x++){
        a[x]=temp[x];
    }
    // returning the count of pairs possible while combining the two parts of the array
    return count;
}

int inversionCount(int a[],int s,int e){
    if(s>=e){
        return 0;
    }

    int mid=(s+e)/2;
    int x=inversionCount(a,s,mid);      // calling to the left part of the array
    int y=inversionCount(a,mid+1,e);   // calling to the right part of the array
    int z=merge(a,s,e);                // calling the merge func to find the no. of inversion pairs while combining the two arrays

    return x+y+z;
}

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<inversionCount(a,0,n-1);
}
