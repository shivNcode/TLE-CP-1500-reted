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
    int n , k; cin >> n >> k;
    string str; cin >> str;
    vector<char> check(k , '?');

    int o = 0 , z = 0;
    for(int i = 0;i<n;i++){
        int v = i%k;
        if(check[v]=='?'){
            check[v] = str[i];
        }
        else{
            if(check[v]!=str[i] && str[i]!='?'){
                cout << "NO\n";
                return;
            }
        }
    }

    for(int i=0;i<k;i++){
        if(check[i]=='0') z++;
        else if(check[i]=='1') o++;
    }
    if(z>k/2 || o>k/2){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    return;




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
So this question is becoming little difficult i dont know why it looks simple when i saw it but now it creating some problem to solve

*/