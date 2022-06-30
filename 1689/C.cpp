#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define endl "\n"
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define pb push_back
#define vi vector<int>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int N = 1e5+10;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> e(n+1);
    forn(i,n-1){
        int u,v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    vector<int> dp(n+1);
    int ans = 1e9;
    function<void(int,int)> dfs = [&](int x,int fa){
        if(x == 1){
            if(e[1].size()==1){
                ans = min(ans,2);
                return;
            }
            dp[1] = 2;
        }
        else{
            if(e[x].size()<=2){
                ans = min(ans,dp[fa]+(int)e[x].size());
                return;
            }
            dp[x] = dp[fa]+2;
        }
        for(auto v: e[x]){
            if(v == fa) continue;
            dfs(v,x);
        }
    };
    dfs(1,1);
    cout<<n-ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}