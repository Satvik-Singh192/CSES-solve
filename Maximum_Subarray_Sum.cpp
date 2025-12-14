#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int main(){
    int n;cin>>n;vector<int> arr(n);
    int largest=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        largest=max(largest,arr[i]);
    }
    if(largest<=0){
        cout<<largest<<endl;
        return 0;
    }
    long long ans=arr[0];
    long long curr=0;

    for(int i=0;i<n;i++){
        curr+=arr[i];
        ans=max(ans,curr);
        if(curr<0){
            curr=0;
        }
    }
    ans=max(ans,curr);
    cout<<ans<<endl;
}