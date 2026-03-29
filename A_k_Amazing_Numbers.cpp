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
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<int> l(n+1 , 0) , k(n+1 , 1e9) , prev(n+1 , 0);
    for(int i=0;i<n;i++){

        int curr = i+1;
        //if(arr[i]==3) cout << prev[arr[i]] << " " << curr << endl;
        l[arr[i]] = max(l[arr[i]] , curr - prev[arr[i]]);
        prev[arr[i]] = curr;
    }
    for(int i=0;i<n;i++){

        //if(arr[i]==3) cout << prev[arr[i]] << " " << n+1 << endl;
        l[arr[i]] = max(l[arr[i]] , n + 1 - prev[arr[i]]);
    }
    for(int i=1;i<=n;i++){
        if(l[i]){
            //cout << i << " " << l[i] << endl;
            k[l[i]] = min(k[l[i]] , i);
        }
    }
    int mini = 1e9;
    for(int i=1;i<=n;i++){
        mini = min(mini , k[i]);
        int val = min(mini , k[i]);
        cout << (val==1e9?-1:val) << " ";
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
/*
Notes:
The question was very good the one good observation was that for each value we have to valculate the minimum window size it can be the part of lets the the element x can be the part of window y then i can also be the part of window >=y.

*/