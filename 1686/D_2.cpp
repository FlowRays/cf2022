// ABAAB BA 1 AB B BA  BA A AB BB AABBAA
// ABABAB
// 12222210012221000000
// 122222221  122221  -> c + d
// 奇数：可以任意分配
// ABABABA 最多3个 3 0 / 2 1 / 1 2 / 0 3
// 偶数：可能浪费一个
// ABABABABAB 10 -> 5 0 / 3 1 / 2 2 / 1 3 / 0 4 
// 对于每一个依次处理：奇数的任意，偶数=n/2个特定 | n/2-1个任意
// 先用特定的贪心一遍
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
    ll a,b,c,d;
    string s;
    cin>>a>>b>>c>>d>>s;
    ll cnta = count(all(s),'A');
    ll cntb = count(all(s),'B');
    if(cnta != a+c+d || cntb != b+c+d){
        cout<<"NO"<<endl;
        return;
    }
    ll n = s.size();
    vi v(n,0);
    forn(i,n){
        if(i>0 && s[i]!=s[i-1]) v[i]++; 
        if(i<n-1 && s[i]!=s[i+1]) v[i]++;
        // cout<<v[i]<<" \n"[i==n-1];
    }
    vi ta,tb; // 长度为偶数的段
    ll tot = 0;    // 任意
    forn(i,n){
        if(v[i]==1){
            ll p = i;
            while(i+1<n && v[i+1]!=1) i++;
            i++;
            ll len = i-p+1;
            if(len>0){
                // cout<<len<<" ";
                if(len%2){
                    tot += len/2;
                }
                else{
                    if(len == 2){
                        if(s[p]=='A' && c>0) c--;
                        else if(s[p]=='B' && d>0) d--;
                    }
                    else{
                        if(s[p]=='A') ta.pb(len/2);
                        else tb.pb(len/2); 
                    }
                }
            }
            p = i;
        }
    }
    // cout<<endl;

    ll sa = ta.size();
    sort(all(ta));
    for(auto x: ta){
        if(c>=x) c -= x;
        else{
            ll cur = min(c,x); 
            c -= cur;
            x--;
            x -= cur;
            d -= min(d,x);
        }
    }
    ll sb = tb.size();
    sort(all(tb));
    for(auto x: tb){
        if(d>=x) d -= x;
        else{
            ll cur = min(d,x); 
            d -= cur;
            x--;
            x -= cur;
            c -= min(c,x);
        }
    }
    cout<<(tot>= max(0ll,c)+max(0ll,d) ? "YES" : "NO")<<endl;
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
10 12 34 1
AABABBBABAABABABABABABABABABABAABBBABABAAABABABABAABABABABAAAAAABABABABABABABBBBBBBBBBABABAB
*/