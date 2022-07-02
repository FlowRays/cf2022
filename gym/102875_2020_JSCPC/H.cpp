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
    vector<string> v(m+1);
    string s;
    fore(i,1,m) cin>>s>>v[i];
    cin>>s;
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    vector<vector<int>> mark(n+1,vector<int>(m+1));
    dp[0][0] = 1;
    mark[0][0] = 1;
    fore(i,1,n){
        fore(j,1,m){
            if(i<v[j].size()) continue;
            if(s.substr(i-v[j].size(),v[j].size()) == v[j]){
                dp[i][j] = (dp[i][j] + dp[i-v[j].size()][0])%128;
                mark[i][j] = min(mark[i][j]+mark[i-v[j].size()][0],2);
            }
            dp[i][0] = (dp[i][0]+dp[i][j])%128;
            mark[i][0] = min(mark[i][0]+mark[i][j],2);
        }
    }
    if(mark[n][0] == 0) cout<<"nonono"<<endl;
    else if(mark[n][0] == 1) cout<<"happymorsecode"<<endl;
    else cout<<"puppymousecat"<<" "<<dp[n][0]<<endl;
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