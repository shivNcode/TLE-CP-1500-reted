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
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    int rem = (sum)/2;
    int ans =(sum - rem);
    sort(arr.rbegin() , arr.rend());
    for(int i=0;i<n;i++){
        if(rem<=0){
            break;
        }
        ans++;
        rem-=arr[i];
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