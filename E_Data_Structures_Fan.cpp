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
    vector<int> arr(n) , pxor(n+1 , 0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        pxor[i+1] = (arr[i] ^ pxor[i]);
    }
    string str;
    cin >> str;
    int one  = 0 , zero = 0;
    for(int i=0;i<n;i++){
        if(str[i]=='0'){
            zero = zero ^ arr[i];
        }
        else{
            one = one ^ arr[i];
        }
    }
    int x;
    cin >> x;
    while(x--){
        int q;
        cin >> q;
        if(q==1){
            int l , r;
            cin >> l >> r;
            int v = pxor[l-1]^pxor[r];
            one = one ^ v;
            zero = zero ^ v;
        }
        else{
            int c;
            cin >> c;
            if(c==1){
                cout << one << " ";
            }
            else{
                cout << zero << " ";
            }
        }
    }
    cout << "\n";

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