//                                                              SPLITWISE ALGORITHM DESIGN

#include <bits/stdc++.h>
using namespace std;

//Approach

// first calculate the net profit/loss of a  person 
// store that in a map 
// on a particular input the net of person1 reduces and net of person2 increases by the input price 

// make a multiset which stores the name and net price which the person either gets or he/she needs to give 
// iterate till the multiset gets empty 
// take the first and last entry of the multiset 
// find the difference of the two amounts
// the first person will give this settled amount to the second person 
// then after settling the person1 net amount becomes originalNet+settledAmount
//                     the person2 net amount becomes originalNet-settledAmount
                    
// if anyones net becomes zero then we will not enter that to the multiset 
// else insert the person and the new net amount to the multiset


class comparison{
    public:
    bool operator()(pair<string,int> p1,pair<string,int> p2){
        return p1.second<p2.second;    
    }
    
};

int main() {
    
    // input original no of transactions 
    int transactions;
    cin>>transactions;
    
    string name1,name2;
    int price;
    
    // calculating the net profit or loss of every person 
    unordered_map<string,int> net;
    while(transactions--){
        cin>>name1>>name2>>price;
        if(net.count(name1)==0){
            net[name1]=0;
        }
        if(net.count(name2)==0){
            net[name2]=0;
        }
        
        net[name1]-=price;
        net[name2]+=price;
        
    }
    
    // adding the name and net profit/loss to the multiset
    multiset<pair<string,int>,comparison> set1;
    for(auto pair1:net){
        string name=pair1.first;
        int price=pair1.second;
        
        if(price!=0){
            set1.insert(make_pair(name,price));    
        }
        
    }
    
    // iterating over the multiset 
    int count=0;
    while(!set1.empty()){
        auto low=set1.begin();
        auto high=prev(set1.end());
        
        set1.erase(low);
        set1.erase(high);
        
        string name1=low->first;
        string name2=high->first;
        
        int debit=low->second;
        int credit=high->second;
        int settleAmount=min(-debit,credit);
        
        cout<<name1<<" gives "<<settleAmount<<" to "<<name2<<endl;
        
        if(debit+settleAmount!=0){
            set1.insert(make_pair(name1,debit+settleAmount));    
        }
        
        if(credit-settleAmount!=0){
            set1.insert(make_pair(name2,credit-settleAmount));   
        }
        
        count++;
    }
    
    cout<<"Total possible transactions are "<<count;
    
	return 0;
}
