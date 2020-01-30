#include <iostream>
using namespace std;
int main() {

    int t;
    cin>>t;
    int i=1;
    while(i<=t){

        int c1,c2,c3,c4,n,m,rcost=0,cabcost=0,total=0,a[1000],b[1000];
        cin>>c1>>c2>>c3>>c4;
        cin>>n>>m;
        int j;
        for(j=0;j<n;j++){
            cin>>a[j];
        }

        for(j=0;j<m;j++){
            cin>>b[j];
        }
        

        //rickshaws cost
        for(j=0;j<n;j++){
            rcost=rcost+min(a[j]*c1,c2);
        } 
        rcost=min(rcost,c3);

        //cabcost
        for(j=0;j<m;j++){
            cabcost=cabcost+min(b[j]*c1,c2);
        }
        cabcost=min(cabcost,c3);

        //total cost

        total=min(c4,(cabcost+rcost));
        cout<<total<<endl;
        i++;
    }
}
