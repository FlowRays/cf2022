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

ll qpow(ll x,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*x%mod;
        x = x*x%mod;
        b>>=1;
    }
    return res;
}

void solve(){
    ll x,n;
    cin>>x>>n;
    vi v;
    for(ll i=2;i*i<=x;++i){
        if(x%i == 0){
            v.pb(i);
            while(x%i==0) x /= i;
        }
    }
    if(x>1) v.pb(x);
    auto calc = [&](ll x){
        ll res = 0;
        // 逐层累加
        for(ll i=n/x;i>0;i/=x) res += i;
        return res;
    };
    ll ans = 1;
    for(auto t: v){
        ll co = calc(t);
        ans = ans*qpow(t,co % (mod-1))%mod; // 指数取模
        // https://blog.csdn.net/doyouseeman/article/details/51863382
        // 欧拉定理
        //     若gcd(x,y)=1, 则 x ^ fpi(y) 同余 1 (mod y)
        //     所以有 x ^ y 同余 x ^ (y % fpi(m)) (mod m)
        // 欧拉函数 fpi(mod) = mod-1
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll tt = 1;
    while (tt--) {
        solve();
    }

    return 0;
}