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

int p[N],cnt;
bool st[N];
int dp[N];
int s[85][N];

void init(){
    for(int i=2;i<N;++i){
        if(!st[i]) p[cnt++] = i;
        for(int j=0;p[j]*i<N;++j){
            st[p[j]*i] = true;
            if(i % p[j] == 0) break;
        }
    }
    vector<int> a(N-5);
    iota(all(a),1);
    int round = 0;
    while(a.size()){
        round++;
        vector<int> b;
        forn(i,a.size()){
            if(st[i+1]) b.pb(a[i]);
            else dp[a[i]] = round;
        }
        a = b;
    }

    fore(i,1,round){
        fore(j,1,N-5){
            s[i][j] = s[i][j-1] + (dp[j]==i);
        }
    }
    // fore(i,1,5) cout<<dp[i]<<" \n"[i==5];
    // fore(i,1,5) cout<<s[1][i]<<" \n"[i==5];
}

// 1 2 3 4 5
// 1 1 1 2 1

void solve(){
    int t,n,k;
    cin>>t>>n>>k;
    if(t == 1){
        // dp[k]: round几被淘汰, ans = 前面round(<=n)的个数之和
        int ans = 0;
        fore(i,1,dp[k]-1){
            ans += s[i][n];
        }
        ans += s[dp[k]][k];
        cout<<ans<<endl;
    }
    else{
        int round = 1;
        while(k>s[round][n]){
            k -= s[round][n];
            round++;
        }
        int p = lower_bound(s[round],s[round]+1+n,k)-s[round];
        cout<<p<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}

/*
10
1 5 1
1 5 2
1 5 3
1 5 4
1 5 5
2 5 1
2 5 2
2 5 3
2 5 4
2 5 5
*/