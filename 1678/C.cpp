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
    vi a(n+1);
    fore(i,1,n) cin>>a[i];
    vector<vector<ll>> s(n+1,vector<ll>(n+1,0));
    fore(i,1,n){
        fore(j,1,n){
            s[i][j] = s[i-1][j] + (a[i]<j);
        }
    }
    ll ans = 0;
    fore(i,2,n-2){
        fore(j,i+1,n-1){
            ans += s[i-1][a[j]] * (s[n][a[i]]-s[j][a[i]]);
        }
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
