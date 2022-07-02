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
    int n,a,b,da,db;
    cin>>n>>a>>b>>da>>db;
    vector<vector<int>> e(n+1);
    forn(i,n-1){
        int u,v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    vi d(n+1,-1);
    queue<int> q;
    q.push(a);
    d[a] = 0;
    int maxd = 0, maxv = a;
    while(q.size()){
        int u = q.front();
        q.pop();
        if(d[u]>maxd){
            maxd = d[u];
            maxv = u;
        }
        for(auto v: e[u]){
            if(d[v] == -1){
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }
    if(d[b]<=da){
        cout<<"Alice"<<endl;
        return;
    }
    fill(all(d),-1);
    q.push(maxv);
    d[maxv] = 0;
    while(q.size()){
        int u = q.front();
        q.pop();
        if(d[u]>maxd){
            maxd = d[u];
            maxv = u;
        }
        for(auto v: e[u]){
            if(d[v] == -1){
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }    
    cout<<(db>=da*2+1 && maxd>=da*2+1 ? "Bob" : "Alice")<<endl;
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