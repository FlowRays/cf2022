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
    vector<vector<int>> s(n,vector<int>(m));
    vector<vector<int>> s2(m,vector<int>(n));
    forn(i,n) forn(j,m) cin>>a[i][j];
    forn(i,n){
        forn(j,m){
            if(j == 0) s[i][j] = a[i][j];
            else s[i][j] = s[i][j-1]+a[i][j];
        }
    }
    forn(i,m){
        forn(j,n){
            if(j==0) s2[i][j] = a[j][i];
            else s2[i][j] = s2[i][j-1]+a[j][i];
        }
    }

    vector<pii> v = {{0,1},{0,1},{1,0},{1,0}};
    vector<pii> v2 = {{-1,0},{0,-1},{-1,0},{0,-1}};
    function<bool(int,int,int)> dfs = [&](int p,int q,int t){
        int x1 = p/m, y1 = p%m;
        int x2 = q/m, y2 = q%m;
        if(x1 == x2) return (s[x1][y2] - (y1>=1 ? s[x1][y1-1] : 0)) == t;
        if(y1 == y2) return (s2[y1][x2] - (x1>=1 ? s2[y1][x1-1] : 0)) == t;
        for(int i=0;i<4;++i){
            int nx = x1+v[i].first, ny = y1+v[i].second;
            int mx = x2+v2[i].first, my = y2+v2[i].second;
            int tar = t - (a[nx][ny]+a[mx][my]);
            if(dfs(nx*m+ny,mx*m+my,tar)) return true;
        }
        return false;
    };
    cout<<(dfs(0,n*m-1,0) ? "YES" : "NO")<<endl;
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