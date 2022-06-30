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
const ll N = 2e5+10;

ll qpow(ll x,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = (res*x)%mod;
        x = x*x%mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    ll s = 0; 
    forn(i,m){
        ll l,r,x;
        cin>>l>>r>>x;
        s |= x;
    }
    cout<<s*qpow(2,n-1)%mod<<endl;
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
