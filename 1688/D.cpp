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
    ll n,k;
    cin>>n>>k;
    vi a(n),s(n+1);
    forn(i,n) cin>>a[i];
    forn(i,n) s[i+1]=s[i]+a[i];
    ll ans = 0;
    if(k<=n){
        forn(i,k){
            ans += i;
        }
        ll t = 0;
        fore(i,k,n){
            t = max(t,s[i]-s[i-k]);
        }
        ans += t;
    }
    else{
        ans = accumulate(all(a),0ll);
        forn(i,n) ans += k-i-1;
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