#include <bits/stdc++.h>
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

int32_t main() {
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    fastio();
    int n;cin>>n;vector<int>arr(n);for(auto&x:arr)cin>>x;

    map<int,int> last_pos;
    vector<long long> count_before_this_index(n+1);
    long long total_count=2;
    count_before_this_index[0]=0;
    count_before_this_index[1]=1;
    last_pos[arr[0]]=0;

    for(int i=1;i<n;i++){
        int curr=arr[i];
        count_before_this_index[i]=total_count;
        if(last_pos.find(curr)==last_pos.end()){
            //aisi koi subsequence nhi hai jisme ye element present hai to total_count number of subsequence aur bna skte easily and +1 for a new subsequence whose starting element si curr
            total_count+=(total_count+1);
            
        }
        else{
            long long sub_count_which_dont_have_curr=count_before_this_index[last_pos[curr]];
            total_count+=sub_count_which_dont_have_curr;
        }
        last_pos[curr]=i;
    }
    cout<<total_count<<endl;
    return 0;
}