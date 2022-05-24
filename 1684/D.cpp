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
    vi a(n);
    forn(i,n) cin>>a[i];
    map<ll,ll> dp;
    forn(i,n){
        map<ll,ll> dp2;
        fore(j,max(0ll,i-n+k),min(k,i+1)){
            dp2[j] = dp[j]+a[i]+j;
            if(j>0) dp2[j] = min(dp2[j],dp[j-1]);
        }
        dp = dp2;
    }
    cout<<dp[k]<<endl;
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