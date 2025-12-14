#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    int n;cin>>n;vector<int> arr(n);for(int i=0;i<n;i++)cin>>arr[i];
    int low=0;
    int high=*max_element(arr.begin(),arr.end());
    int ans=INT_MAX;

    while(low<=high){
        int mid=low+(high-low)/2;
        int bruh=0;
        
        for(auto&x: arr){
            bruh+=x-mid;
        }
        if(bruh<0){
            // too smal
        }

        if()
    }

}