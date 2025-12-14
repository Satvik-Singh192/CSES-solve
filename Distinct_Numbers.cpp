 /*
 used unordered set but got tle
 normally on avg cases the unordered set is defo faster
 but here there are targested testcases which force every item in a single bucket (unordered_set uses hash function to determine a bucket) making it effectively O(n^2)
 but the set doesnt use hash function so its not hackable, it uses a self balancing bst (red black) which gurantees log(n) lookups in any case . so it doesnt get tle
 */

#include <iostream>
#include <set>
using namespace std;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main() {
    fastio();
    int t = 1;
    while(t--) {
        int n;cin>>n;
        set<int> arr;
        for(int i=0;i<n;i++){
            int temp;cin>>temp;
            arr.insert(temp);
        }
        cout<<arr.size()<<endl;
    
    }
    return 0;
}