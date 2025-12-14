#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,x;cin>>n>>x;
    map<int,int> hash;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        if(hash.count(x-temp)){
            cout<<hash[x-temp]<<" "<<i+1<<endl;
            return 0;
        }
        hash[temp]=i+1;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}