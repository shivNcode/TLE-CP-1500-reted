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

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve()
{
    int n; cin >> n;
    vector<int> arr(n);
    int check = 0;
    int one = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]==1) one++;
        //check = gcd(check , arr[i]);
    }
    if(one>0){
        //cout <<  "hfh";
        cout << n-one << endl;
    }
    else{
        int cnt = 1e9;
        for(int i=0;i<n;i++){
            int temp = arr[i];
            for(int j=i+1;j<n;j++){
                temp = gcd(temp , arr[j]);
                if(temp==1){
                   // cout << arr[i] << " " << arr[j] << endl;
                    cnt = min(cnt , j-i);
                }
            }
        }
        cout << ((cnt!=1e9)?(cnt + (n-1)):-1 )<< endl;
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