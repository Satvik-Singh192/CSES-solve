#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int> weights(n);
    for(int i=0;i<n;i++)cin>>weights[i];

    sort(weights.begin(),weights.end());
    int ans=0; 
    int ind=0;
    for(int i=n-1;i>=0;i--){
        if(ind>i)break;
        if(i==ind){
            ans++;break;
        }
        ans++;
        if(x-weights[i]>=weights[ind]){
            ind++;
        } 
    }
    cout<<ans<<endl;
    return 0;
}