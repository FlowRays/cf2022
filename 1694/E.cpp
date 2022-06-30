// 感觉还是好迷

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
    int n,m;
    cin>>n>>m;
    vi deg(n+1);
    vector<vector<int>> adj(n+1);
    forn(i,m){
        int u,v;
        cin>>u>>v;
        adj[v].pb(u);
        deg[u]++;
    }
    priority_queue<pii,vector<pii>,greater<pii>> h;
    h.push({0,n});
    vi dis(n+1,-1);
    while(h.size()){
        auto [d,v] = h.top();
        h.pop();
        if(dis[v] != -1) continue;
        dis[v] = d;
        for(auto u: adj[v]){
            deg[u]--;
            h.push({d+deg[u]+1,u});
        }
    }
    cout<<dis[1]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    while (tt--) {
        solve();
    }

    return 0;
}