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

void Solve()
{
    int n; cin >> n;
    vector<pair<pair<int,int>,int>> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].second = i+1;
    }
    sort(arr.begin(), arr.end(), [](const pair<pair<int,int>, int>& a,
                                    const pair<pair<int,int>, int>& b) {
        if(a.first.first != b.first.first) {
            return a.first.first < b.first.first;
        }
        return a.first.second > b.first.second;
    });

    int max_r = -1;
    int idx = -1;

    for(int i=0; i<n; i++){
        int current_r = arr[i].first.second;

        if(current_r <= max_r){
            cout << arr[i].second << " " << idx << endl;
            return;
        }
        if(current_r > max_r){
            max_r = current_r;
            idx = arr[i].second;
        }
    }

    cout << -1 << " " << -1 << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}