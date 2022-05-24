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
    ll ans = 0, step = 0;
    priority_queue<ll,vector<ll>,greater<ll>> q;
    forn(i,n){
        ll t1 = a[i]+step, t2 = 0;
        if(step == k){
            if(q.size()){
                ll tt = q.top();
                q.pop();
                ll diff = a[i]+k-1;
                // cout<<i<<": "<<tt<<" "<<diff<<endl;
                if(diff>tt){
                    q.push(diff);
                    ans += tt;
                }
                else{
                    ans += t1;
                    q.push(tt);
                }
            }
            else 
                ans += t1;
            // cout<<i<<": ans = "<<ans<<endl;
            continue;
        }
        // cout<<i<<": "<<t1<<" "<<t2<<endl;
        if(t1<=t2) ans += t1;
        else ans += t2, step++, q.push(t1);
        // cout<<i<<": ans = "<<ans<<endl;
        
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
/*
1
7 5
8 2 5 15 11 2 8
*/