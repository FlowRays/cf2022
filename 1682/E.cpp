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
const int N = 2e5+10;

vector<int> v[N];
vector<int> t_sort;
int vs[N];

void dfs_sort(int u){
    vs[u] = 1;
    for(auto j: v[u]){
        if(!vs[j]) dfs_sort(j);
    }
    t_sort.pb(u);
}

// void top_sort(int n){
//     fore(i,1,n){
//         if(!vs[i]){
//             dfs_sort(i);
//         }
//     }
//     reverse(all(t_sort));
// }

void top_sort(int n){
    queue<int> q;
    vector<int> deg(n+1);
    fore(i,1,n){
        for(auto j: v[i]){
            deg[j]++;
        }
    }
    fore(i,1,n){
        if(!deg[i]){
            q.push(i);
        }
    }
    while(q.size()){
        int t = q.front();
        t_sort.pb(t);
        q.pop();
        for(auto j: v[t]){
            deg[j]--;
            if(deg[j] == 0){
                q.push(j);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vi p(n+1),a(k),b(k);
    fore(i,1,n) cin>>p[i];
    vector<vector<pii>> g(n+1);
    forn(i,k){
        int x,y;
        cin>>x>>y;
        a[i] = x, b[i] = y;
        g[x].pb({y,i+1});
        g[y].pb({x,i+1});
    }
    vi id(n+1);
    vi ans;
    auto solve = [&](vi &cyc) {
        int n = cyc.size();
        if(n == 1) return;
        forn(i,n){
            id[cyc[i]] = i;
        }
        auto dist = [&](int x,int y){
            return (id[y]-id[x]+n)%n;
        };
        vi good;
        for(int i: cyc){
            sort(all(g[i]),[&](pii &a, pii &b){
                return dist(i,a.first) < dist(i,b.first);
            });
            fore(j,1,g[i].size()-1){
                v[g[i][j-1].second].pb(g[i][j].second);
            }
        }
    };
    vector<bool> vis(n+1);
    fore(i,1,n){
        if(vis[i]) continue;
        vi cycle;
        int cur = i;
        while(!vis[cur]) {
            cycle.pb(cur);
            vis[cur] = 1;
            cur = p[cur];
        }
        solve(cycle);
    }
    top_sort(k);
    for(auto i: t_sort){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}