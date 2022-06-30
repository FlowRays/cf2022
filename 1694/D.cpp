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
    ll n;
    cin>>n;
    vector<vector<ll>> e(n+1);
    forn(i,n-1){
        ll x;
        cin>>x;
        e[i+2].pb(x);
        e[x].pb(i+2);
    }
    vector<pii> v(n+1);
    forn(i,n) cin>>v[i+1].first>>v[i+1].second;
    ll ans = 0;
    function<ll(ll,ll)> dfs = [&](ll x,ll fa){
        ll cnt = 0;
        ll mx = 0;
        for(auto y: e[x]){
            if(y == fa) continue;
            cnt++;
            mx += dfs(y,x);
        }
        if(cnt==0){
            ans++;
            return v[x].second;
        }
        if(mx<v[x].first){
            ans++;
            mx = v[x].second;
        }
        else if(mx>v[x].second){
            mx = v[x].second;
        }
        return mx;
    };
    dfs(1,0);
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