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
const int N = 200+10;

int mp[N][N];
int a[2*N], b[2*N];

void solve(){
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    int n,m;
    cin>>n>>m;
    forn(i,n){
        forn(j,m){
            cin>>mp[i][j];
        }
    }
    forn(i,n){
        forn(j,m){
            a[i+j] += mp[i][j];
            b[i-j+N] += mp[i][j];
        }
    }
    int ans = 0;
    forn(i,n){
        forn(j,m){
            ans = max(ans,a[i+j]+b[i-j+N]-mp[i][j]);
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