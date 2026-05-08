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
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin() , arr.end() , [](pair<int,int> &a , pair<int,int> &b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    });
    stack<pair<int,int>> st1 , st2;
    st1.push(arr[0]);
    if(n>1) st2.push(arr[1]);
    //for(int i=0;i<n;i++) cout << arr[i].first << " " << arr[i].second << endl;
    for(int i=2;i<n;i++){
        pair<int,int> temp = arr[i];
        if(temp.first>st1.top().second){
           // cout << temp.second << " " << st1.top().second << endl;
            st1.push(temp);
        }
        else if(temp.first>st2.top().second){
            st2.push(temp);
        }
        else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES\n";
    return;

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