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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<vector<int>> dp(n , vector<int>(2 , 1e9));
    if(arr[0]==1) dp[0][0] = dp[0][1] = 1;
    else dp[0][0] = dp[0][1] = 0;
    for(int i=1;i<n;i++){
        //first
        if(i>1){
            dp[i][0] = min(dp[i-1][1] , dp[i-2][1]);
        }
        else dp[i][0] = dp[i-1][1];

        //second
         if(i>1){
            if(arr[i]==1)
                dp[i][1] = 1 + min({max(dp[i-1][0] , dp[i-2][0]) , max(dp[i-1][1] , dp[i-2][0]) , max(dp[i-1][0] , dp[i-2][1])});
            else dp[i][1] = min({max(dp[i-1][0] , dp[i-2][0]) , max(dp[i-1][1] , dp[i-2][0]) , max(dp[i-1][0] , dp[i-2][1])});
        }
        else{
            if(arr[i]==1)
                dp[i][1] = 1 + min(dp[i-1][1] , dp[i-1][0]);
            else dp[i][1] = min(dp[i-1][1] , dp[i-1][0]);
        }
    }
    for(int i=0;i<n;i++){
        //cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << min(dp[n-1][0] , dp[n-1][1]) << endl;
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