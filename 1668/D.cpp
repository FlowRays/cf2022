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
    vi a(n),s(n),dp(n,-1e9);
    forn(i,n) cin>>a[i];
    forn(i,n) s[i] = (i==0 ? a[i] : s[i-1]+a[i]);
    forn(i,n){
        forn(j,i){
            int p = 0;
            if(s[i]-s[j]>0) p = i-j;
            else if(s[i]-s[j]<0) p = j-i;
            dp[i] = max(dp[i],dp[j]+p);
        }
        int p = 0;
        if(s[i]>0) p = i+1;
        else if(s[i]<0) p = -(i+1);
        dp[i] = max(dp[i],p);
    }
    cout<<dp[n-1]<<endl;
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