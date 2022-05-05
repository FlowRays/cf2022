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
const int N = 2e5+10;

vector<vector<int>> e;
vector<int> path;
int p[N];
int d[N];
int a[N];
bool st[N];

void dfs(int x,int fa){
    p[x] = fa;
    d[x] = (x==fa ? 0 : d[fa]+1);
    for(auto v: e[x]){
        if(v != fa) dfs(v,x);
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    e.clear();
    e.resize(n+1);
    memset(st,0,sizeof(bool)*(n+5));
    memset(a,0,sizeof(int)*(n+5));
    int x,y;
    cin>>x>>y;
    forn(i,k) cin>>a[i];
    forn(i,n-1){
        int u,v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(x,x);
    int ans = 0;
    forn(i,k){
        int t = a[i];
        int len = 0;
        while(!st[t] && t != p[t]){
            st[t] = true;
            t = p[t];
            len++;
        }
        ans += len*2;
    }
    if(st[y]) ans -= d[y];
    else{
        int t = y;
        while(!st[t] && t != p[t]){
            st[t] = true;
            t = p[t];
            ans++;
        }
        ans -= d[t];
    }
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

/*
1
3 1
1 3
2
1 3
1 2
*/