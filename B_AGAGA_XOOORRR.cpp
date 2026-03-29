#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

#define int long long
#define INF (int)1e18
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// bool check(vector<int>& arr, int total) {
//     unordered_set<int> st;
//     st.insert(0);

//     for (auto x : arr) {
//         unordered_set<int> nxt = st;
//         for (auto val : st) {
//             nxt.insert(val ^ x);
//         }
//         st = nxt;
//     }

//     return st.count(total);
// }

void Solve(){
    int n;
    cin >> n;
    vector<int> arr(n);

    int v = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        v ^= arr[i];
    }

    if(v == 0){
        cout << "YES\n";
        return;
    }

    int cur = 0, count = 0;

    for(int i = 0; i < n; i++){
        cur ^= arr[i];
        if(cur == v){
            count++;
            cur = 0;
        }
    }

    if(count >= 2) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}