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

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
public:
    ll n;
    vector<vector<T>> mat;
    F func;

    SparseTable(const vector<T>& a, const F& f): func(f) {
        n = static_cast<ll>(a.size());
        ll max_log = 32 - __builtin_clz(n);
        // __builtin_clz(x) 前导0的个数
        mat.resize(max_log);
        mat[0] = a;
        for(ll j=1;j<max_log;++j){
            mat[j].resize(n - (1<<j) + 1);
            for(ll i=0;i<=n-(1<<j);++i){
                mat[j][i] = func(mat[j-1][i],mat[j-1][i+(1<<(j-1))]);
            }
        }
    }

    T get(ll from, ll to) const {
        assert(0 <= from && from <= to && to <= n-1);
        ll lg = 32 - __builtin_clz(to-from+1)-1;
        return func(mat[lg][from],mat[lg][to-(1<<lg)+1]);
    }
};

void solve(){
    ll n;
    cin>>n;
    vi a(n);
    forn(i,n) cin>>a[i];
    vi s(n+1);
    forn(i,n) s[i+1] = s[i]+a[i];
    vi b(n);
    iota(all(b),0);
    SparseTable<ll> sa(b, [&](ll i,ll j){return a[i]>a[j] ? i : j;}); 
    SparseTable<ll> smin(s,[&](ll i,ll j){return min(i,j);});
    SparseTable<ll> smax(s,[&](ll i,ll j){return max(i,j);});
    bool ok = true;
    function<void(ll,ll)> Dfs = [&](ll l,ll r){
        if(l>r) return;
        ll x = sa.get(l,r); // 最大值的下标
        ll mn = smin.get(l,x);
        ll mx = smax.get(x+1,r+1);
        if(a[x] < mx-mn){
            ok = false;
            return;
        }
        Dfs(l,x-1);
        Dfs(x+1,r);
    };
    Dfs(0,n-1);
    cout<<(ok ? "YES" : "NO")<<endl;
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