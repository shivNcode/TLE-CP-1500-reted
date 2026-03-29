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
    int sum = 0;
    vector<pair<int,int>> arr(n+1 , {0,-1});
    for(int i=1;i<=n;i++){
        cin >> arr[i].first;
        sum+=arr[i].first;
    }
    vector<int> deg(n+1 , -1);
    for(int i=0;i<n-1;i++){
        int a , b;
        cin >> a >> b;
        arr[a].second++;
        arr[b].second++;
    }
    vector<pair<int,int>> v;

    sort(arr.begin()+1, arr.end(), [](pair<int,int> &a, pair<int,int> &b) {
        return a.first > b.first; // decreasing order
    });
    cout << sum << " ";
    for(int i=1;i<=n;i++){
        //cout << i <<" " << arr[i].first << " " << arr[i].second << "\n";
        while(arr[i].second){
            sum+=arr[i].first;
            cout << sum << " ";
            arr[i].second--;
        }
    }
    cout << '\n';

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