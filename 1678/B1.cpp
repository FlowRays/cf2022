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
    string s;
    cin>>n>>s;
    vector<int> seg;
    forn(i,n){
        int cnt = 1;
        while(i+1<n && s[i+1]==s[i]) cnt++,i++;
        seg.pb(cnt);
    }
    int ans = 0;
    forn(i,seg.size()){
        if(seg[i]%2){
            ans++;
            if(i+1<seg.size()) seg[i+1]++;
        }
    }
    cout<<ans<<endl;
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