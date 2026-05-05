#include <bits/stdc++.h>
using namespace std;

#define int long long

int M = 1e9+7;

vector<vector<int>> adj;
vector<int> vis;

int modPow(int a, int b){
    a %= M;
    int res = 1;
    while(b){
        if(b & 1) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

int sz;

void dfs(int n){
    vis[n] = 1;
    sz++;
    for(auto it: adj[n]){
        if(!vis[it]){
            dfs(it);
        }
    }
}
//so here the main function that we have to see and iright now i a, finding some difficunt with it but will get use to it and some time
void Solve(){
    int n , k; cin >> n >> k;

    adj.assign(n+1 , {});
    vis.assign(n+1 , 0);

    for(int i=0;i<n-1;i++){
        int a , b , c; cin >> a >> b >> c;
        if(c==0){
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    int bad = 0;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            sz = 0;
            dfs(i);
            bad = (bad + modPow(sz , k)) % M;
        }
    }

    int total = modPow(n , k);

    cout << (total - bad + M) % M << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();
    return 0;
}
/*
ok so the problem was about just eliminating the black edges and then just count the group of the rend edges and solve the question further
*/

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