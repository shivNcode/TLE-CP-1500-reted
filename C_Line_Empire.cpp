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
    int n , a , b;
    cin >> n >> a >> b;
    vector<int> arr(n) , pr(n) , sf(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(i==0) pr[i] = arr[i];
        else pr[i] = pr[i-1] + arr[i];
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1) sf[i] = arr[i];
        else sf[i] = sf[i+1] + arr[i];
    }
    int curr = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=(b*abs(curr - arr[i]));
        int x , y;
        if(i==n-1){
            continue;
        }
        x = abs((sf[i] - arr[i]) - ((n - i-1)*curr))*b;
        y = a*abs(curr - arr[i]) + b*abs((sf[i] - arr[i]) - ((n - i-1)*arr[i]));
        if(x>=y){
            ans+=(a*abs(curr - arr[i]));
            curr = arr[i];
        }
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