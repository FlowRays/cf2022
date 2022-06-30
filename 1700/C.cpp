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
    vi a(n),b(n);
    forn(i,n) cin>>a[i];
    if(n == 1){
        cout<<abs(a[0])<<endl;
        return;
    }
    forn(i,n){
        if(i==0) b[i] = a[i];
        else b[i] = a[i]-a[i-1];
    }
    ll cnt = 0;
    ll ans = 0;
    fore(i,1,n-1){
        if(b[i]<0) cnt -= b[i];
        else ans += b[i];
    }
    ans += cnt;
    b[0] += -cnt;
    ans += abs(b[0]);
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