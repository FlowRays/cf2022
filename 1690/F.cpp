#include <bits/stdc++.h>

#define forn(i, n) for (ull i = 0; i < ull(n); i++)
#define fore(i, l, r) for (ull i = ull(l); i <= ull(r); ++i)
#define endl "\n"
#define pii pair<ull,ull>
#define aull(x) x.begin(),x.end()
#define pb push_back
#define vi vector<ull>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ull inf = 0x3f3f3f3f;
const ull mod = 1e9+7;
const ull N = 1e5+10;

void solve(){
    ull n;
    cin>>n;
    string s;
    cin>>s;
    vi a(n);
    forn(i,n) cin>>a[i];
    forn(i,n) a[i]--;
    vi vis(n);
    ull ans = 1;
    forn(i,n){
        if(vis[i]) continue;
        vi v = {i};
        vis[i] = 1;
        ull p = i;
        while(a[p] != i){
            v.pb(a[p]);
            p = a[p];
            vis[p] = 1;
        }
        ull len = v.size();
        forn(j,v.size()){
            if(j == 0) continue;
            if(s[v[j]] == s[v[0]]){
                bool ok = true;
                forn(k,v.size()){
                    if(s[v[(j+k)%v.size()]] != s[v[k]]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    len = j;
                    break;
                }
            }
        }
        ans = lcm(ans,len);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}