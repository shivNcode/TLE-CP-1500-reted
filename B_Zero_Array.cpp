
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
    int cnt = 0;
    int maxi = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt+=x;
        maxi = max(maxi , x);
    }
    if(cnt&1 || maxi>cnt-maxi) cout << "NO\n";
    else cout << "YES\n";




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
/*
so what is the k-size of the main thing but of you look at the curcumference of the main thing thery might be very
*/