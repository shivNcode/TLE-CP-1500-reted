#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define INF (int)1e18
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
vector<vector<int>> arr;
vector<int> vis;
priority_queue<int, vector<int>, greater<int>> pq;

void bfs(int x){
    cout << x << " ";
    vis[x] = 1;

    for(int i : arr[x]){
        if(!vis[i]){
            vis[i] = 1;
            pq.push(i);
        }
    }
}
void Solve()
{

    int n , m; cin >> n >> m;
    arr.assign(n+1 , {});
    vis.assign(n+1 , 0);
    for(int i=0;i<m;i++){
        int a , b; cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    pq.push(1);
    while(!pq.empty()){
        int p = pq.top();
        pq.pop();
        bfs(p);
    }
    cout << endl;


}


int main()
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