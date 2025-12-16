#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> arr(n);for(int i=0;i<n;i++)cin>>arr[i];
    vector<int>pos(n+1);
    for(int i=0;i<n;i++){
        pos[arr[i]]=i;
    }
    int ans=1;
    for(int i=1;i<n;i++){
        if(pos[i]>pos[i+1]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}