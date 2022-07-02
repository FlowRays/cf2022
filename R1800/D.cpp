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
    vi a(n),b(n),s1(n+1),s2(n+1);
    forn(i,n) cin>>a[i];
    forn(i,n) cin>>b[i];
    // find all possible values of sum(a)
    vi dp(1e4+10);
    forn(i,n){
        if(i==0){
            dp[a[0]] = dp[b[0]] = 1;
            continue;
        }
        for(int j=1e4;j>=1;--j){
            if(dp[j]){
                dp[j+a[i]] = 1;
                dp[j+b[i]] = 1;
                dp[j] = 0;
            }
        }
    }
    int ans = 1e9;
    fore(i,1,1e4){
        if(dp[i]){
            int A = i, B = accumulate(all(a),0)+accumulate(all(b),0) - A;
            ans = min(ans,A*A+B*B);
        }
    }
    forn(i,n){
        ans += (a[i]*a[i]+b[i]*b[i])*(n-2);
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