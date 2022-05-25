// note: sos dp(cf blog)
// 没有完全理解

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
const ll mod = 998244353;
const ll N = 1e5+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll q;
    cin>>q;
    vector<string> qs(q);
    forn(i,q) cin>>qs[i];
    vi ans(q);
    for(ll len=1;len<=17;++len){
        vi a(1<<17),pw(n+1);
        pw[0] = 1;
        fore(i,1,n) pw[i] = (pw[i-1]*len)%mod;
        ll tot = count(all(s),'?');
        forn(i,n){
            ll cnt = 0; // 回文数区间中配对的?
            ll mask = 0;
            a[mask] += pw[tot];
            a[mask] %= mod;
            // 以i为中心枚举可能的回文数区间
            for(ll j=1;i-j>=0 && i+j<n;++j){
                ll l = i-j;
                ll r = i+j;
                if(s[l] == '?' && s[r] == '?') cnt++;
                else if(s[l] == '?'){
                    cnt++;
                    mask |= 1 << (s[r]-'a');
                }
                else if(s[r] == '?'){
                    cnt++;
                    mask |= 1 << (s[l]-'a');
                }
                else if(s[l] != s[r]) break;
                a[mask] += pw[tot-cnt];
                a[mask] %= mod;
            }
        }
        for(ll i=1;i<n;++i){
            ll cnt = 0;
            ll mask = 0;
            // 以i-1,i为中心
            for(ll j=0;i-j-1>=0 && i+j<n;++j){
                ll l = i-j-1;
                ll r = i+j;
                if(s[l] == '?' && s[r] == '?') cnt++;
                else if(s[l] == '?'){
                    cnt++;
                    mask |= 1 << (s[r]-'a');
                }
                else if(s[r] == '?'){
                    cnt++;
                    mask |= 1 << (s[l]-'a');
                }
                else if(s[l] != s[r]) break;
                a[mask] += pw[tot-cnt];
                a[mask] %= mod;
            }
        }
        for(ll i=1;i<(1<<17);i*=2){
            for(ll j=0;j<(1<<17);j+=2*i){
                for(ll k=0;k<i;++k){
                    a[i+j+k] += a[j+k];
                    a[i+j+k] %= mod;
                }
            }
        }
        forn(i,q){
            if(qs[i].size() == len){
                ll mask = 0;
                for(auto c: qs[i]) mask |= 1 << (c-'a');
                ans[i] = a[mask];
            }
        }
    }
    forn(i,q){
        cout<<ans[i]<<endl;
    }

    return 0;
}