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
    int n , a , b; cin >> n >> a >> b ;
    int k = a + b;
    vector<int> arr(n);
    int sum = 0;
    vector<int> x(n) , y(n);
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    for(int i=0;i<n;i++){
        cin >> y[i];
    }
    for(int i=0;i<n;i++){
        int v = abs(x[i] - y[i]);
        arr[i] = v;
        sum+=v;
    }
    //cout << sum << " " << k << endl;
    if(sum>=k){
        sum-=k;
        int avg = sum/n;
        int left = sum % n;
        int ans = (n-1)*(avg*avg) + ((avg+left)*(avg+left));
        cout << ans << endl;
    }
    else{
        int val = k-sum;
        cout << ((val%2==0)?0:1) << endl;
    }
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