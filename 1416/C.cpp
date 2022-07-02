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
const ll N = 9e6+10;

ll t[2][N],id = 1;
vi g[N];
ll dp[2][30];

void add(ll x,ll pos){
    ll v = 0;
    for(ll i=29;i>=0;--i){
        ll bit = x>>i&1;
        if(!t[bit][v]) t[bit][v] = id++;
        v = t[bit][v];
        g[v].pb(pos);
    }
}

void calc(ll v,ll b){
    ll l = t[0][v], r = t[1][v];
    if(l) calc(l,b-1);
    if(r) calc(r,b-1);
    if(!l || !r) return;
    ll res = 0;
    ll p = 0;
    for(auto x: g[l]){
        while(p<g[r].size() && g[r][p]<x) p++;
        res += p;
    }
    dp[0][b] += res;
    /*
        令x=g[l].size(),y=g[r].size()
        C(x+y,2)-C(x,2)-C(y,2) = x*y = dp[0][b] + dp[1][b]
    */
    dp[1][b] += 1ll*g[l].size()*g[r].size()-res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    fore(i,1,n){
        ll x;
        cin>>x;
        add(x,i);
    }
    calc(0,29);
    ll inv = 0;
    ll res = 0;
    forn(i,30){
        inv += min(dp[0][i],dp[1][i]);
        if(dp[1][i]<dp[0][i]) res += (1<<i);
    }
    cout<<inv<<" "<<res<<endl;

    return 0;
}