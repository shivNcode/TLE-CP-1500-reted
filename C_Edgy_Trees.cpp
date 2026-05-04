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