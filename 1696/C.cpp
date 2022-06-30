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
    ll n,m;
    cin>>n>>m;
    vi a(n);
    forn(i,n) cin>>a[i];
    ll k;
    cin>>k;
    vi b(k);
    forn(i,k) cin>>b[i];
    auto calc = [&](vi v){
        ll n = v.size();
        vector<pii> a(n),b;
        forn(i,n){
            ll t = v[i];
            ll k = 1;
            while(t%m == 0){
                t /= m;
                k *= m;
            }
            a[i] = {t,k};
        }
        forn(i,n){
            ll j = i;
            ll tot = a[i].second;
            while(j+1<n && a[j+1].first == a[i].first) j++, tot += a[j].second;
            b.pb({a[i].first,tot});
            i = j;
        }
        return b;
    };
    cout<<(calc(a)==calc(b) ? "YES" : "NO")<<endl;
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