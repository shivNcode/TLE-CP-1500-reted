#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;

void solve(){
    int n;
    cin >> n;

    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    ordered_set st;
    int ans = 0;

    for(int i=0;i<n;i++){
        int greater = st.size() - st.order_of_key(arr[i].second);
        ans += greater;

        st.insert(arr[i].second);
    }

    cout << ans << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}