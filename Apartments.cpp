#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>people(n),apt(m);
    for(int i=0;i<n;i++)cin>>people[i];
    for(int i =0;i<m;i++)cin>>apt[i];

    sort(people.begin(),people.end());
    sort(apt.begin(),apt.end());

    int ans=0;
    int aptind=0;

    for(int i=0;i<n;i++){
        if(aptind>(m-1))break;
        int person=people[i];
        int l=person-k;
        int u=person+k;
        if(apt[aptind]>=l && apt[aptind]<=u){
            ans++;
            aptind++;
            continue;
        }
        else if(apt[aptind]<l){
            aptind++;
            i--;
        }
    }
    cout<<ans<<endl;

}