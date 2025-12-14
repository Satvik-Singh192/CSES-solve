#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int main(){
    int n;cin>>n;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr.emplace_back(make_pair(a,1));
        arr.emplace_back(make_pair(b,-1));
    }
    sort(arr.begin(),arr.end(),[](pair<int,int>& a, pair<int,int>& b){
        if(a.first<b.first)return true;
        return false;
    });
    int ans=0;
    int temp=0;
    int prev=-5;
    for(auto& p: arr){
        if(p.second==-1){
            temp--;
        }
        else{
            temp++;
        }
        if(p.first!=prev){
            ans=max(ans,temp);
        }
        prev=p.first;
    }
    cout<<ans<<endl;
}