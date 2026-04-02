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
    vector<pair<int,int>> arr(n-1);
    vector<int> temp(n+1 , 0);
    for(int i=0;i<n-1;i++){
        cin >> arr[i].first >> arr[i].second;
        temp[arr[i].first]++; temp[arr[i].second]++;
    }
    int maxi = 0;
    int val = 0;
    for(int i=1;i<=n;i++){
        if(temp[i]>=maxi){
            maxi = temp[i];
            val = i;
        }
    }
    //cout << val << endl;
    vector<int> ans(n-1); int cnt = 0;
    for(int i=0;i<n-1;i++){
        if(arr[i].first==val || arr[i].second==val){
            ans[i] = cnt;
            cnt++;
        }
    }
    for(int i=0;i<n-1;i++){
        if(arr[i].first!=val && arr[i].second!=val){
            ans[i] = cnt;
            cnt++;
        }
    }
    for(int i=0;i<n-1;i++) cout << ans[i] << "\n";
    //cout << "\n";

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