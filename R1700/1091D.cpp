#include <bits/stdc++.h>

#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define fore(i, l, r) for (ll i = ll(l); i <= ll(r); ++i)
#define sz(a) ll((a).size())
#define endl "\n"
#define pii pair<ll,ll>
#define all(x) x.begin(),x.end()
#define pb push_back
#define vi vector<ll>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
const ll N = 1e5+10;

ll qpow(ll x,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*x%mod;
        x = x*x%mod;
        b>>=1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vi f(n+1),invf(n+1);
    f[0] = invf[0] = 1;
    fore(i,1,n) f[i] = f[i-1]*i%mod;
    fore(i,1,n) invf[i] = qpow(f[i],mod-2);
    ll ans = f[n];
    fore(k,2,n-1){
        ans = (ans + f[n]*invf[k]%mod*(k-1)%mod * (n-k)%mod) % mod;
    }    
    cout<<ans<<endl; 

    return 0;
}