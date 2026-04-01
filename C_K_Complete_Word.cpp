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
    vector<vector<int>> arr(k , vector<int>(26 , 0));
    for(int i=0;i<n;i++){
        char ch = str[i];
        int val = (ch - 'a');
        arr[i%k][val]++;
    }
    int th = n/k;
    int ans = 0;
    for(int i=0;i<k/2;i++){
        int maxi = 0;
        for(int j=0;j<26;j++){
            //cout <<char(j+'a') << "-" << arr[i][j] << " ";
        }
        vector<int> temp(26 , 0);
        for(int j=0;j<26;j++){
           // if(arr[i][j]>0) cout << char(j+'a')<< arr[i][j] << " ";
           temp[j]+=arr[i][j];
           maxi = max(maxi , temp[j]);
        }

        for(int j=0;j<26;j++){
           // if(arr[k-i-1][j]>0) cout << char(j+'a')<< arr[i][j] << " ";
            temp[j]+=arr[k-i-1][j];
            maxi = max(maxi , temp[j]);
        }
        //cout << endl;
        ans+=((2*th) - maxi);
    }
    if(k&1){
        vector<int> temp(26 , 0);
        int maxi = 0;
        for(int i=0;i<26;i++){
            temp[i]+=arr[k/2][i];
            maxi = max(maxi , temp[i]);
        }
         ans+=((th) - maxi);
    }
    cout << ans << endl;
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