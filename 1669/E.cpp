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
    cin>>n;
    vector<string> v(n);
    unordered_map<string,ll> mp;
    forn(i,n) cin>>v[i],mp[v[i]]++;
    ll ans = 0;
    forn(i,n){
        for(char ch='a';ch<='k';++ch){
            if(ch == v[i][1]) continue;
            string t;
            t.pb(v[i][0]);
            t.pb(ch);
            ans += mp[t];
        }
        for(char ch='a';ch<='k';++ch){
            if(ch == v[i][0]) continue;
            string t;
            t.pb(ch);
            t.pb(v[i][1]);
            ans += mp[t];
        }
    }
    cout<<ans/2<<endl;
    
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