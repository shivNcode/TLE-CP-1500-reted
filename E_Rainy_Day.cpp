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
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin >> arr[i];
    int s = 1;
    while(true){
        int i = s;
        int t = 1;
        bool check = true;;
        while(i<=n){
            if(arr[i]<=t){
                if(t%arr[i]==0){
                    check = false;
                    break;
                }
            }
            t++;
            i+=s;
        }
        if(check){
            cout << s << endl;
            return;
        }
        s++;
    }
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