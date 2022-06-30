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
    string s;
    cin>>n>>s;
    vi p(n);
    forn(i,n) cin>>p[i],p[i]--;
    vi vis(n);
    ll ans = 1;
    forn(i,n){
        if(vis[i]) continue;
        string a;
        a.pb(s[i]);
        ll pos = i;
        while(p[pos] != i){
            pos = p[pos];
            a.pb(s[pos]);
            vis[pos] = 1;
        }
        if(a.size() == 1) continue;
        string b = a;
        ll cnt = 0;
        do{
            rotate(b.begin(),next(b.begin()),b.end());
            cnt++;
        }while(a != b);
        ans = lcm(ans,cnt);
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