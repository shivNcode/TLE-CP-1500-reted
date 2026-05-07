// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <deque>
// #include <random>
// #include <chrono>
// #include <unordered_map>
// #include <map>
// #include <stack>
// using namespace std;

// #define int long long
// #define INF (int)1e18
// #define all(x) (x).begin(), (x).end()
// #define sz(x) (int)(x).size()

// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// vector<vector<int>> adj;
// vector<int> vis;
// vector<int> deg;
// int ans = 0;
// int dfs(int x){
//     vis[x] = 1;
//     for(auto it:adj[x]){
//         if(vis[it]==0){
//            int v = dfs(it);
//            if(v%2==0){
//             deg[x]--;
//             deg[v]--;
//             ans++;
//            }
//         }
//     }
//     return deg[x];

// }
// void Solve()
// {
//     int n; cin >> n;
//     adj.assign(n+1 , {});
//     vis.assign(n+1 , 0);
//     deg.assign(n+1 , 0);
//     for(int i=0;i<n-1;i++){
//         int a , b; cin >> a >> b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//         deg[a]++;
//         deg[b]++;
//     }
//     ans = 0;
//     int d = dfs(1);
//     //cout << ans << endl;
//     cout << ((d%2==0)?-1:ans) << endl;

// }

// int32_t main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t = 1;
//     //cin >> t;
//     while (t--)
//     {
//         Solve();
//     }

//     return 0;
// }


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
vector<vector<int>> adj;
vector<int> vis;
vector<int> sz;
void dfs(int x){
    vis[x] = 1;
    sz[x] = 1;
    for(auto it:adj[x]){
        if(vis[it]==0){
            dfs(it);
            sz[x]+=sz[it];
        }
    }
}
void Solve()
{
    int n; cin >> n;
    adj.assign(n+1 , {});
    vis.assign(n+1 , 0);
    sz.assign(n+1 , 0);
    for(int i=0;i<n-1;i++){
        int a , b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    if(n%2) cout << -1 << endl;
    else{
        dfs(1);
        for(int i=2;i<=n;i++){
            if(sz[i]%2==0){
                ans++;
            }
        }
        cout << ans << endl;
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

/*
the correct approach os to with the size of the subtree
but the degree logic is wrong because degree of the node doen't tell you about the grandchild and so on ...
*/