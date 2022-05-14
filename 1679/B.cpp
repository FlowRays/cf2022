#include <bits/stdc++.h>

#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define fore(i, l, r) for (ll i = ll(l); i <= ll(r); ++i)
#define sz(a) ll((a).size())
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,q;
    cin>>n>>q;
    vi a(n);
    map<ll,ll> mp;
    forn(i,n) cin>>a[i],mp[i+1]=a[i];
    ll base = 0;
    ll s = accumulate(all(a),0ll);
    forn(i,q){
        ll op;
        cin>>op;
        if(op == 1){
            ll x,y;
            cin>>x>>y;
            ll ori;
            if(mp.count(x) == 0){
                ori = base;
            }
            else ori = mp[x];
            s += y-ori;
            mp[x] = y;
        }
        else{
            ll x;
            cin>>x;
            base = x;
            mp.clear();
            s = n*x;
        }
        cout<<s<<endl;
    }

    return 0;
}