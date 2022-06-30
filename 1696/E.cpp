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
const ll N = 5e5+10;

ll fac[N],invfac[N];

ll qpow(ll x,ll y){
    ll res = 1;
    while(y){
        if(y&1) res = res*x%mod;
        x = x*x%mod;
        y >>= 1;
    }
    return res;
}

ll C(ll n,ll m){
    return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}

void init(){
    fac[0] = invfac[0] = 1;
    fore(i,1,N-1) fac[i] = fac[i-1]*i%mod;
    fore(i,1,N-1) invfac[i] = qpow(fac[i],mod-2);
}

void solve(){
    ll n;
    cin>>n;
    vi a(n+1);
    forn(i,n+1) cin>>a[i];
    ll ans = 0;
    forn(i,n+1){
        ans = (ans + C(i+a[i],i+1)) % mod;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll tt = 1;
    init();
    while (tt--) {
        solve();
    }

    return 0;
}