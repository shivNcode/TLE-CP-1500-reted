#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int,int> , int>> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].second = i;
    }
    vector<int> ans(n);
    sort(arr.begin(), arr.end(), [](const auto &a, const auto &b) {
    return a.first.first < b.first.first;
    });
    pair<int,int> temp = {arr[0].first.first , arr[0].first.second};
    int v = 0;
    for(int i=1;i<n;i++){
        int a = arr[i].first.first , b = arr[i].first.second ;
        if(a>temp.second){
            v = i;
            break;
        }
        else{
            temp.first = min(temp.first , a);
            temp.second = max(temp.second , b);
        }
    }
    for(int i=0;i<n;i++){
        if(i<v){
            ans[arr[i].second] = 1;
        }
        else ans[arr[i].second] = 2;
    }
    if(v==0){
        cout << -1 << endl;
        return;
    }
    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //don't judge this code from this statement just checking come stuff
    if(!(cin >> t)) return 0;

    while(t--) {
        solve();
    }

    return 0;
}
