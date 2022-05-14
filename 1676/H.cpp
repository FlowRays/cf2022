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

template <typename T>
class fenwick{
public:
    vector<T> fenw;
    ll n;
    
    fenwick(ll _n) : n(_n) {
        fenw.resize(n);
    }
    
    void modify(ll x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }
    
    T get(ll x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};

void solve(){
    ll n;
    cin>>n;
    vi a(n);
    vector<pii> v(n),q(n);
    forn(i,n){
        cin>>a[i];
        v[i] = {a[i],i};
        q[i] = {a[i],i};
    }
    sort(all(v));
    sort(all(q));
    fenwick<ll> fw(n);
    ll ans = 0;
    ll pos = 0;
    forn(i,n){
        ll x = q[i].first;
        while(pos<n && v[pos].first<=x) fw.modify(v[pos++].second,1);
        ll l = q[i].second, r = n-1;
        ans += fw.get(r) - fw.get(l);
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