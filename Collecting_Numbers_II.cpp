#include<iostream>
#include<vector>
#include<set>
#include<bits/stdc++.h>
#include<algorithm>
#include<algorithm>
using namespace std;


#pragma region Macros_and_Debug
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(long long t) {cerr << t;}
void _print(string t) {cerr << '"' << t << '"';}
void _print(char t) {cerr << '\'' << t << '\'';}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(map<T, V> v);

template <class T, class V> void _print(pair<T, V> p) {
    cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";
}
template <class T> void _print(vector<T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T> void _print(set<T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T> void _print(multiset<T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
    cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";
}
#pragma endregion

int helper(vector<int>&arr,vector<int>&pos,int num1,int num2,int n){
    int curpos=pos[num1];
    int newpos=pos[num2];
    int ans=0;

    //already bad pair
    if(curpos>pos[min(n,num1+1)]){
        if(newpos<pos[min(n,num1+1)]){
            ans--;
        }
    }
    else{
        if(newpos>pos[min(n,num1+1)]){
            ans++;
        }
    }
    if(curpos<pos[max(1,num1-1)]){
        if(newpos>pos[max(1,num1-1)]){
            ans--;
        }
    }
    else{
        if(newpos<pos[max(1,num1-1)]){
            ans++;
        }
    }


    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    fastio();
    int n,m;cin>>n>>m;
    vector<int> arr(n);for(int i=0;i<n;i++)cin>>arr[i];
    vector<int>pos(n+1);
    vector<pair<int,int>> queries;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        queries.emplace_back(a,b);
    }
    for(int i=0;i<n;i++){
        pos[arr[i]]=i;
    }
    int ans=1;
    for(int i=1;i<n;i++){
        if(pos[i]>pos[i+1]){
            ans++;
        }
    }
    debug(arr)
    debug(ans)
    debug(pos)
    for(auto& q:queries){

        int a=q.first-1;
        int b=q.second-1;
        int num1=min(arr[a],arr[b]);
        int num2=max(arr[a],arr[b]);
        int factor1=helper(arr,pos,num1,num2,n);
        int factor2=helper(arr,pos,num2,num1,n);
        ans+=(factor1+factor2);

        swap(arr[a],arr[b]);
        swap(pos[num1],pos[num2]);

        
    
        cout<<ans<<endl;
    }

    return 0;
}
