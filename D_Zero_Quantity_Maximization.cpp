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
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void Solve()
{
    int n;cin >>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    map<pair<int,int> , int> mpp;
    for(int i=0;i<n;i++){
        int p = a[i] , q = -b[i];
        if(p==0)continue;
        int g = gcd(abs(a[i]) , abs(b[i]));
        if(p<0){
            p = -p;
            q = -q;
        }
        p/=g;
        q/=g;
        mpp[{q, p}]++;


    }
    int temp = 0;
    for(auto it:mpp){
        //cout << it.second <<" ";
        temp = max(temp , it.second);
    }
    for(int i=0;i<n;i++){
        if(a[i]==0){
        if(b[i]==0) temp++;
        continue;
        }
    }
    cout << temp << endl;
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