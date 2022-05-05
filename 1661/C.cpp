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
    vi a(n);
    forn(i,n) cin>>a[i];
    ll mx = *max_element(all(a));
    auto get = [&](ll x){
        ll odd = 0;
        ll even = 0;
        forn(i,n){
            ll dis = x-a[i];
            if(dis&1) odd++;
            even += dis/2;
        }
        even -= odd-1;
        if(even<=0) return odd*2-1;
        ll t = even%3;
        odd += even/3*2;
        if(t == 0) return odd*2-1;
        if(t == 1) return odd*2-1+1;
        return odd*2-1+3;
    };
    ll ans = min(get(mx),get(mx+1));
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