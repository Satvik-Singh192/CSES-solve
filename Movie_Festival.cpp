#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;cin>>n;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        arr.emplace_back(a,b);
    }

    sort(arr.begin(),arr.end(),[](pair<int,int>&a,pair<int,int>&b){
        if(a.second<b.second){
            return true;
        }
        else if(a.second>b.second){
            return false;
        }
        else{
            if(a.first<b.first)return true;
        }
        return false;
    });

    int count=0;
    int busy_till=-1;

    for(auto&p:arr){
        if(p.first>=busy_till){
            count++;
            busy_till=p.second;
        }
    }
    cout<<count<<endl;
}