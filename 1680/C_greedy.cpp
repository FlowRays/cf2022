// https://zhuanlan.zhihu.com/p/514201500

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
    string s;
    cin>>s;
    int n = s.size();
    vi s1(n+1);
    fore(i,1,n) s1[i] = s1[i-1] + (s[i-1]=='1');
    int ans = 1e9;
    int t = s1[n];
    forn(i,n){
        if(i+t>n) break;
        ans = min(ans,t-(s1[i+t]-s1[i]));
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