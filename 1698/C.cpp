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
    vi a(n);
    forn(i,n) cin>>a[i];
    ll cnt0 = 0, cnt1 = 0, cnt2 = 0;
    vi t;
    forn(i,n){
        if(abs(a[i])>0) t.pb(a[i]);
        if(a[i]>0) cnt1++;
        else if(a[i] == 0) cnt0++;
        else cnt2++;
    }
    if(cnt1>=3 || cnt2>=3){
        cout<<"NO"<<endl;
        return;
    }
    if(cnt0>=1) t.pb(0);
    ll m = t.size();
    map<ll,ll> vis;
    forn(i,m) vis[t[i]] = 1;
    for(ll i=0;i<m;++i){
        for(ll j=i+1;j<m;++j){
            for(ll k=j+1;k<m;++k){
                ll s = t[i]+t[j]+t[k];
                if(!vis[s]){
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"YES"<<endl;
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