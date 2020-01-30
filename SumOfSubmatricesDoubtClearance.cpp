#include<iostream>
using namespace std;
int main() {
int arr[2][2]={{1,1},{1,1}};
int r=2,c=2;
int sum;
// making prefix matrix using col wise addition
for(int i=0;i<r;i++){
int sum=arr[i][0];
for(int j=0;j<c;j++){
arr[i][j]=sum;
sum=sum+arr[i][j+1];
}
}

// making prefix matrix row wise addition after col wise addition is performed
for(int j=0;j<c;j++){
    sum=arr[0][j];
    for(int i=0;i<r;i++){
        arr[i][j]=sum;
        sum=sum+arr[i+1][j];
    }
}
// printing of prefix matrix
for(int j=0;j<r;j++){
    for(int i=0;i<c;i++){
        cout<<arr[j][i]<<"    ";
    }
    cout<<endl;
}
//calculation of sum of submatrices 
int ans=0;
for(int li=0;li<r;li++){
    for(int lj=0;lj<c;lj++){
        for(int bi=li;bi<r;bi++){
            for(int bj=lj;bj<c;bj++){
               
                if(li != 0 && lj != 0)
                ans = ans + arr[bi][bj] - arr[li-1][bj] - arr[bi][lj-1] + arr[li-1][lj-1];
                else if(li == 0 && lj == 0)
                ans = ans + arr[bi][bj];
                else if(li == 0) 
                ans = ans + arr[bi][bj] - arr[bi][lj-1];
                else
                ans = ans + arr[bi][bj] - arr[li-1][bj]; 

            }
        }
    }
}
cout<<ans;
}