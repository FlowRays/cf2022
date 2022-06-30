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
    vi v(n),s(n+1);
    forn(i,n) cin>>v[i];
    forn(i,n) s[i+1] = s[i]+v[i];
    vi mi(n);
    ll ti = 0;
    forn(i,n){
        mi[i] = (s[i+1]+i)/(i+1);
        ti = max(ti,mi[i]);
    }
    // cout<<" "<<ti<<endl;
    vi t(n);
    forn(i,n){
        t[i] = max(ti,(s[n]+i)/(i+1));
    }
    ll q;
    cin>>q;
    while(q--){
        ll tt;
        cin>>tt;
        if(tt<t[n-1]) cout<<-1<<endl;
        else{
            ll l = 0, r = n-1;
            while(l<r){
                ll mid = l+r>>1;
                if(t[mid]<=tt) r=mid;
                else l=mid+1;
            }
            cout<<l+1<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll tt = 1;
    while (tt--) {
        solve();
    }

    return 0;
}