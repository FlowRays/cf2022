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
    ll n,a,b;
    cin>>n>>a>>b;
    vi v(n);
    forn(i,n) cin>>v[i];
    ll cur = 0;
    ll ans = 0;
    forn(i,n){
        ans += b*(v[i]-cur);
        ll cost = a*(v[i]-cur);
        ll reap = b*(v[i]-cur)*(n-i-1);
        if(reap>cost) ans += cost, cur = v[i];
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}