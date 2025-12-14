#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        tickets.insert(temp);
    }
    for(int i = 0; i < m; i++) {
        int limit;
        cin >> limit;
        auto it = tickets.upper_bound(limit);

        if (it == tickets.begin()) {
            cout << -1 << "\n";
        } 
        else {
            it--; 
            cout << *it << "\n";
            tickets.erase(it);
        }
    }
    return 0;
}