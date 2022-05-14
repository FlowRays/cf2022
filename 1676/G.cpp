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
const int N = 4e3+10;

int n;
int p[N];
char s[N];
int ans;
vector<vector<int>> e;
vector<int> st;

pair<int,int> dfs(int x, int fa){
    st[x] = 1;
    int w = 0, b = 0;
    if(s[x] == 'W') w++;
    else b++;
    for(auto v: e[x]){
        if(v == fa || st[v]) continue;
        auto [W,B] = dfs(v, x);
        w += W, b += B;
    }
    if(w == b) ans++;
    return {w,b};
}

void solve(){
    cin>>n;
    e.clear();
    e.resize(n+1);
    st.clear();
    st.resize(n+1);
    fill(all(st),0);
    fore(i,2,n){
        cin>>p[i];
        e[i].pb(p[i]);
        e[p[i]].pb(i);
    }
    cin>>s+1;
    ans = 0;
    dfs(1,1);
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