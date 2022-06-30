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
    int ans = 0;
    vi dep(n+1);
    function<void(int,int)> dfs = [&](int x,int fa){
        int son = 0;
        for(auto v: e[x]){
            if(v == fa) continue;
            dep[v] = dep[x]+1;
            dfs(v,x);
            son++;
        }
        if(son<2){
            ans = max(ans,n-dep[x]*2-1-son);
        }
    };
    dfs(1,0);
    cout<<ans<<endl;
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