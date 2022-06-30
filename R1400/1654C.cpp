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
    map<ll,ll> mp;
    ll t = 0;
    forn(i,n){
        ll x;
        cin>>x;
        t += x;
        mp[x]++;
    }
    function<bool(ll)> dfs = [&](ll x){
        if(mp[x]){
            mp[x]--;
            return true;
        }
        if(x == 1) return false;
        return dfs(x/2) && dfs((x+1)/2);
    };
    cout<<(dfs(t) ? "YES" : "NO")<<endl;
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