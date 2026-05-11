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
    int n , q;
    cin >> n >> q;

    vector<int> arr(n+2, 0);
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    vector<int> temp(n+2 , 0);

    // range update
    for(int i=0;i<q;i++){
        int l , r ;
        cin >> l >> r;

        temp[l]++;
        temp[r+1]--;   // FIX
    }
    vector<int> pre(n+2 , 0);
    pre[1] = temp[1];
    // prefix sum
    for(int i=2;i<=n;i++){
        // temp[i] += temp[i-1];
        pre[i] = (pre[i-1] + temp[i]);
    }
    // for(int i=1;i<=n;i++){
    //     cout << pre[i] << " ";
    // }
    sort(pre.begin()+1 , pre.end()-1);
    sort(arr.begin()+1 , arr.end()-1);
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum+=(pre[i]*arr[i]);
    }
    cout << sum << endl;
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