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
    vi a(n),b(n),d(n);
    forn(i,n) cin>>a[i],a[i]--;
    forn(i,n) cin>>b[i],b[i]--;
    forn(i,n) cin>>d[i],d[i]--;
    int ans = 1;
    vi vis(n),pos(n);
    forn(i,n){
        pos[a[i]] = i;
    }
    forn(i,n){
        if(vis[i]) continue;
        vi t;
        int p = i;
        t.pb(p);
        vis[i] = 1;
        while(pos[b[p]] != i){
            p = pos[b[p]];
            vis[p] = 1; 
            t.pb(p);
        }
        bool ok = true;
        forn(j,t.size()){
            if(d[t[j]] != -1){
                ok = false;
                break;
            }
        }
        if(ok && t.size()>=2) ans = ans*2%mod;
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