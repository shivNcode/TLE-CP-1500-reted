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
    vector<int> a(n+1) , b(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<int> ft(n+2 , 0)  , lt(n+2 , 0) , pr(n+1 , 0);
    for(int i=1;i<=n;i++){
        cin >> b[i];
        if(i==1) pr[i] = b[i];
        else pr[i] = pr[i-1] + b[i];
    }
    for(int i=1;i<=n;i++){
        int v = upper_bound(pr.begin() , pr.end() , a[i] + pr[i-1]) - pr.begin();
        //cout << v << endl;
        ft[i]+=1;
        ft[v]-=1;
        lt[v]+=(a[i] - (pr[v-1] - pr[i-1]));
    }
    for(int i=1;i<=n;i++){
        ft[i]+=ft[i-1];
    }
    for(int i=1;i<=n;i++){
        cout << b[i]*ft[i] + lt[i] <<" ";
    }
    cout << endl;
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