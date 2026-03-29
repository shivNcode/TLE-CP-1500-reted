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
    cout << ((n<=3)?n-1:3) << endl;
}
// so this for the classic problem where the answer can go maximum up to 3 because any number let se x multiplt by 0 and then add 1 can become 1 so x - (1) - (1) + (1) so if x==1 so ans is 0 and x == 2 then ans is 1 and if x is 3 then aswer is 2 otherwise the answer is 3 


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