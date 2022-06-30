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
const ll mod = 998244353;
const ll N = 1e5+10;

void solve(){
    ll n,s;
    cin>>n>>s;
    vi a(n),b(n);
    map<int,int> mp;
    forn(i,n) cin>>a[i];
    forn(i,n) cin>>b[i],mp[b[i]]=a[i];
    ll cnt = 0;
    vi vis(n+1);
    vi v;
    forn(i,n){
        if(b[i] == -1) cnt++,v.pb(a[i]);
        else vis[b[i]] = 1;
    }
    sort(all(v));
    ll ans = 1;
    ll k = 0;
    bool ok = true;
    fore(i,1,n){
        if(vis[i]){
            if(mp[i]>=i+s+1) ok = false;
            continue;
        }
        ll t = lower_bound(all(v),i+s+1)-v.begin();
        // cout<<t-k<<" ";
        ans = (ans * (t-k))%mod;
        k++;
    }
    // cout<<endl;
    cout<<(ok ? ans : 0)<<endl;
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
7 4
6 1 3 7 5 4 2
-1 -1 2 6 -1 5 -1
*/