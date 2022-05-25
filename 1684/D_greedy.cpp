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
    vi b(n);
    forn(i,n) b[i] = a[i] - (n-i-1);
    sort(all(b),greater<int>());
    ll ans = accumulate(all(a),0ll);
    ans -= k*(k-1)/2;
    forn(i,k) ans -= b[i];
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
/*
1
7 5
8 2 5 15 11 2 8
*/