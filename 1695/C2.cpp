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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    vector<vector<int>> dp(n,vector<int>(m,-1e9));
    vector<vector<int>> dp2(n,vector<int>(m,1e9));
    forn(i,n) forn(j,m) cin>>a[i][j];
    dp[0][0] = a[0][0];
    forn(i,n){
        forn(j,m){
            if(i>0) dp[i][j] = max(dp[i][j],dp[i-1][j]+a[i][j]);
            if(j>0) dp[i][j] = max(dp[i][j],dp[i][j-1]+a[i][j]);
        }
    }
    dp2[0][0] = a[0][0];
    forn(i,n){
        forn(j,m){
            if(i>0) dp2[i][j] = min(dp2[i][j],dp2[i-1][j]+a[i][j]);
            if(j>0) dp2[i][j] = min(dp2[i][j],dp2[i][j-1]+a[i][j]);
        }
    }
    // cout<<dp[n-1][m-1]<<" "<<dp2[n-1][m-1]<<endl;
    if((n+m-1)%2==0 && dp[n-1][m-1]>=0 && dp2[n-1][m-1]<=0){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
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