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
    int n,k;
    string s;
    cin>>n>>k>>s;
    auto calc = [&](string s){
        int res = 0;
        for(int i=1;i<n;++i){
            res += (s[i-1]-'0')*10+s[i]-'0';
        }
        return res;
    };
    int l = 0, r = n-1;
    for(int i=0;i<n;++i){
        if(s[i]=='1'){
            l = i;
            break;
        }
    }
    for(int i=n-1;i>=0;--i){
        if(s[i]=='1'){
            r = i;
            break;
        }
    }
    int ans = 1e9;
    forn(i,4){
        int cnt = 0;
        string t = s;
        if((i&1) && (s[0]=='0')){
            cnt += l;
            swap(t[0],t[l]);
        }
        if((i>>1 & 1) && (s[n-1]=='0')){
            cnt += n-r-1;
            swap(t[n-1],t[r]);
        }
        if(cnt<=k) ans = min(ans,calc(t));
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