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
    vector<int> arr(n); for(int i=0;i<n;i++) cin >> arr[i];
    int maxi = arr[0];
    int diff = 0;
    for(int i=1;i<n;i++){
        if(arr[i]<maxi){
            diff = max(diff , maxi - arr[i]);
        }
        maxi = max(maxi , arr[i]);
    }
    int cnt = 1;
    int ans = 0;
    while(cnt<=diff){
        ans++;
        cnt*=2;
    }
    cout << ans << endl;
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