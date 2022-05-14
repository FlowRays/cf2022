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
const int N = 10;

char mp[N][N];

void solve(){
    int n,m;
    cin>>n>>m;
    forn(i,n) cin>>mp[i];
    int p = 10, q = 10;
    forn(i,n){
        forn(j,m){
            if(mp[i][j] == 'R'){
                p = min(p,i);
                q = min(q,j);
            }
        }
    }
    cout<<(mp[p][q]=='R' ? "YES" : "NO")<<endl;
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