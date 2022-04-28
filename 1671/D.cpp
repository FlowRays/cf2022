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
    ll n,x;
    cin>>n>>x;
    vi a(n);
    forn(i,n) cin>>a[i];
    ll s = 0;
    fore(i,1,n-1) s += abs(a[i]-a[i-1]);
    ll mi = *min_element(all(a));
    ll mx = *max_element(all(a));
    s += min(2*(mi-1),min(a[0],a[n-1])-1);
    if(x>mx) s += min(2*(x-mx),x-max(a[0],a[n-1]));
    cout<<s<<endl;
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