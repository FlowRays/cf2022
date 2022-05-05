#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vi a(n),b(n);
    forn(i,n) cin>>a[i];
    ll ans = 1e18;
    forn(i,n){
        // [0,i-1]
        ll t = 0;
        ll pre = 0;
        for(ll j=i-1;j>=0;--j){
            ll cnt = pre/a[j] + 1;
            t += cnt;
            pre = cnt*a[j];
        }
        pre = 0;
        for(ll j=i+1;j<n;++j){
            ll cnt = pre/a[j] + 1;
            t += cnt;
            pre = cnt*a[j];
        }
        ans = min(ans,t);
    }
    cout<<ans<<endl;

    return 0;
}