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
    vi b(k);
    forn(i,n) b[a[i]%k]++;
    ll left = 0;
    ll match = 0;
    for(ll i=1,j=k-1;i<=j;++i,--j){
        if(i == j){
            left += b[i];
        }
        else{
            ll t = min(b[i],b[j]+left);
            match += t;
            left += b[j]-t;
        }
    }
    ll ans = match + left/2;
    forn(i,n) ans += a[i]/k;
    cout<<ans<<endl;
}

/*
0 3 3 1 3 2

*/

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