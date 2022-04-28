#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define endl "\n"
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define pb push_back
#define vi vector<int>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int N = 1e5+10;

void solve(){
    int n;
    ll x;
    cin>>n>>x;
    vector<ll> a(n),s(n+1,0);
    forn(i,n) cin>>a[i];
    sort(all(a));
    forn(i,n) s[i+1] = s[i]+a[i];
    ll pre = -1;
    ll ans = 0;
    for(ll i=n;i>0;--i){
        if(x<s[i]) continue;
        ll t = (x-s[i])/i;
        ans += (t-pre)*i;
        pre = t;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}