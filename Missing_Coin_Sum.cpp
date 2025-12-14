#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n;cin>>n;vector<int>arr(n);for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    if(arr[0]!=1){
        cout<<1<<endl;
        return 0;
    }
    long long can_make=1;
    bool first=true;
    for(auto&x:arr){
        if(first){
            first=false;
            continue;
        }
        if(x<=can_make+1){
            can_make+=x;
        }
        else{
            cout<<can_make+1<<endl;
            return 0;
        }
    }
    cout<<can_make+1<<endl;
}