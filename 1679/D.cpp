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

const ll inf = 1e18;
const ll mod = 1e9+7;
const ll N = 1e5+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    vi a(n);
    forn(i,n) cin>>a[i];
    vector<vector<ll>> e(n);
    forn(i,m){
        ll u,v;
        cin>>u>>v;
        u--,v--;
        e[u].pb(v);
    }
    auto check = [&](ll x){
        vector<ll> deg(n);
        vector<ll> dis(n,0);
        forn(i,n){
            if(a[i]>x) continue;
            for(auto v: e[i]){
                if(a[v]>x) continue;
                deg[v]++;
            }
        }
        vector<ll> num;
        queue<ll> q;
        int cnt = 0;
        forn(i,n){
            if(a[i]<=x) cnt++;
            if(deg[i]==0 && a[i]<=x) q.push(i),dis[i]=1;
        }
        while(q.size()){
            ll u = q.front();
            q.pop();
            num.pb(u);
            for(auto v: e[u]){
                if(a[v]>x) continue;
                dis[v] = max(dis[v],dis[u]+1);
                deg[v]--;
                if(deg[v]==0) q.push(v);
            }
        }
        if(num.size() < cnt) return true;
        if(*max_element(all(dis)) >= k) return true;
        return false;
    };
    ll l = 0, r = inf;
    while(l<r){
        ll mid = l+r >> 1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<(r==inf ? -1 : r)<<endl;

    return 0;
}