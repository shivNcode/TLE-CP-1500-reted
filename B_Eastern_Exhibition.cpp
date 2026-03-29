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
    vector<int> x(n) , y(n);
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    int xmini = 0 , ymini = 0;
    sort(x.begin() , x.end());
    sort(y.begin() , y.end());
    int xcnt = 1  , ycnt = 1;
    if(x.size()%2==0){
       xcnt = 0;
       int idx = x.size()/2;
       xcnt = abs(x[idx] - x[idx-1]) + 1;
    }
    if(y.size()%2==0){
       ycnt = 0;
       int idx = x.size()/2;
       ycnt = abs(y[idx] - y[idx-1]) + 1;
    }
    cout << xcnt*ycnt << endl;


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