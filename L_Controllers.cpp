#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
#include <numeric>
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
    string s;
    cin >> s;
    int pos = 0 , neg = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='+') pos++;
        else neg++;
    }
    if(pos==neg){
        int q;
        cin >> q;
        while(q--){
            int a , b;
            cin >> a >> b;
            cout << "YES\n";
        }
        return;
    }
    else{
        int q;
        cin >> q;
        while(q--){
            int a , b;
            cin >> a >> b;
            if(a==b){
                cout << "NO\n";
                continue;
            }
            else{
                int nu , d;
                int v = lcm(a , b);
                //cout << v << endl;
                if(a>b){
                    nu = v/a;
                    d = v/b;
                }
                else{
                    nu = v/b;
                    d = v/a;
                }
                //cout << min(pos , neg) << " " << max(pos , neg) <<'\n';
                //cout << nu << " " << d << "\n";

                int rnu = min(pos , neg)%nu;
                int rd = max(pos , neg)%d;
                rnu = min(pos,neg) - rd;
                rd = max(pos , neg) - rd;
                //cout << rnu << " " << rd << "\n";
                if(rd%rnu==d%nu){
                    cout << "YES\n";
                    continue;
                }
                else{
                    cout << "NO\n";
                    continue;
                }
            }
        }
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