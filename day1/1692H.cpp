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
    vi a(n);
    forn(i,n) cin>>a[i];
    vi dp(n);
    map<int,int> last;
    vi l(n);
    forn(i,n){
        if(last.count(a[i])){
            int p = last[a[i]];
            if(dp[p]+1-(i-p-1)>1) dp[i] = dp[p]+1-(i-p-1), l[i] = l[p];
            else dp[i] = 1, l[i] = i;
        }
        else{
            dp[i] = 1;
            l[i] = i;
        }
        last[a[i]] = i;
    }
    int L,R,ans = 0;
    forn(i,n){
        if(dp[i]>ans){
            ans = dp[i];
            L = l[i], R = i;
        }
    }
    cout<<a[R]<<" "<<L+1<<" "<<R+1<<endl;
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