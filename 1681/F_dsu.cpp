// 可撤销并查集

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
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
const int N = 5e5+10;

int p[N],sz[N];
vector<pii> g[N],op;
ll ans;

int find(int x){
    return p[x]==x ? x : find(p[x]); // 不能路径压缩
}

void merge(int x,int y){
    int px = find(x), py = find(y);
    if(px != py){
        if(sz[px]>sz[py]) swap(px,py); // 把小的集合加入到大的集合
        op.pb({px,p[px]}); // 记录变动信息：p[px]
        p[px] = py;
        op.pb({-py,sz[py]}); // 记录变动信息：sz[py]
        sz[py] += sz[px];
    }
}

void undo(int t){
    while(op.size()>t){
        auto [x,v] = op.back();
        op.pop_back();
        if(x>0) p[x] = v;
        else sz[-x] = v;
    }
}

void solve(int l,int r){
    if(l == r){
        for(auto [u,v]: g[l]) ans += 1ll * sz[find(u)] * sz[find(v)];
        return;
    }
    int mid = l+r >> 1;
    int t = op.size();
    for(int i=mid+1;i<=r;++i)
        for(auto [u,v]: g[i])
            merge(u,v);
    solve(l,mid);
    undo(t);
    
    t = op.size();
    for(int i=l;i<=mid;++i)
        for(auto [u,v]: g[i])
            merge(u,v);
    solve(mid+1,r);
    undo(t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    fore(i,1,n) p[i] = i, sz[i] = 1;
    forn(i,n-1){
        int u,v,w;
        cin>>u>>v>>w;
        g[w].pb({u,v});
    }
    solve(1,n);
    cout<<ans<<endl;

    return 0;
}