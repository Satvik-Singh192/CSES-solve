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

    int x,n;cin>>x>>n;
    vector<int>arr(n);
    for(auto&a:arr)cin>>a;

    multiset<int> ms={0,x};
    multiset<int> dist={x};

    for(auto&a:arr){
        auto upper=ms.upper_bound(a);
        auto lower=prev(upper);
        int prev_dist=(*upper)-(*lower);

        auto temp=dist.find(prev_dist);
        dist.erase(temp);

        int new_dist1=a-(*lower);
        int new_dist2=(*upper)-a;

        dist.insert(new_dist1);
        dist.insert(new_dist2);

        ms.insert(a);

        cout<<*(prev(dist.end()))<<" ";
    }
    cout<<endl;
    return 0;
}