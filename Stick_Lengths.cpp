#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;

unsigned long long calc_cost(vector<int>& arr, int target){
    unsigned long long cost=0;
    for(auto &x:arr){
        cost+=abs(x-target);
    }
    return cost;
}

int main(){
    int n;cin>>n;vector<int> arr(n);for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    int median=arr[n/2];


    cout<<calc_cost(arr,median)<<endl;

/*
    while(low<=high){
        int mid=low+(high-low)/2;
        int cost_mid=calc_cost(arr,mid);
        int cost_low=calc_cost(arr,max(low,mid-1));
        int cost_high=calc_cost(arr,min(high,mid+1));

        int forward_slope=(cost_high-cost_mid);
        int backward_slope(cost_mid-cost_low);

        if(forward_slope>=0&&backward_slope<=0){
            ans=min(ans,cost_mid);
            low++;
        }
        else if(forward_slope<0){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans;
*/
}