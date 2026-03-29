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


unordered_map<int,int> mpp;
void Solve()
{
    int n = 1e5+4;
    vector<int> sq;
    for(int i=2;i*i<=1e10;i++){
        sq.push_back(i*i);
    }

    for(auto it:sq){
        cout << it << " ";
        for(int i=2;i*i<=it;i++){
            if(it%i==0){
                mpp[it]++;
                if(it/i != i) mpp[it]++;
            }
        }
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