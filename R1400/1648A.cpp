#include <bits/stdc++.h>

#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define fore(i, l, r) for (ll i = ll(l); i <= ll(r); ++i)
#define endl "\n"
#define pii pair<ll,ll>
#define all(x) x.begin(),x.end()
#define pb push_back
#define vi vector<ll>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
const ll N = 1e5+10;

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> a(1e5+1),b(1e5+1);
    forn(i,n){
        forn(j,m){
            ll x;
            cin>>x;
            a[x].pb(i+1);
            b[x].pb(j+1);
        }
    }
    ll ans = 0;
    fore(i,1,1e5){
        sort(all(a[i]),greater<ll>());
        ll t = a[i].size();
        forn(j,t){
            ans += (t-2*(j+1)+1)*a[i][j];
        }
    }
    fore(i,1,1e5){
        sort(all(b[i]),greater<ll>());
        ll t = b[i].size();
        forn(j,t){
            ans += (t-2*(j+1)+1)*b[i][j];
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}