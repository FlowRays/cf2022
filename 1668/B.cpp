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
    map<ll,ll> mp;
    ll t = 0;
    forn(i,n){
        ll x;
        cin>>x;
        mp[x]++;
        t = max(t,x);
    }
    bool beg = true;
    ll p = 0;
    for(auto [x,y]: mp){
        if(beg){
            p += (x+1)*(y-1);
            beg = false;
        }
        else p += (x+1)*y;
    }
    cout<<(m-1-p>=t ? "YES" : "NO")<<endl;
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