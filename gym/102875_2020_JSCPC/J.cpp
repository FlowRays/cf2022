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
const int N = 1e6+10;

int dp[N];
int p;

int f(int x){
    if(dp[x]) return dp[x];
    if(x <= 1) return dp[x] = 1;
    return dp[x] = f(p%x)+1;
}

void solve(){
    cin>>p;
    memset(dp,0,sizeof(int)*(p+5));
    int s = 0;
    fore(i,1,p-1) s += f(i);
    cout<<fixed<<setprecision(10)<<1.0*s/(p-1)<<endl; 
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