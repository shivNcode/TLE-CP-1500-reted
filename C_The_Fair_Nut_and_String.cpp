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
    string str; cin >> str;
    int n = str.size();
    vector<int> ans;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(str[i]=='a') cnt++;
        else if(str[i]=='b'){
            if(cnt!=0)ans.push_back(cnt);
            cnt = 0;
        }
    }
    int mod = (1e9+7);
    if(cnt!=0) ans.push_back(cnt);
    int temp = 1;
    for(auto it:ans){
        //cout << it << " ";
        temp = (temp*(it+1))%mod;
    }
    cout << temp-1 << endl;
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