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
    vector<string> mp(n),ans(n,string(m,'.'));
    forn(i,n) cin>>mp[i];
    forn(j,m){
        int cnt = 0;
        forn(i,n){
            if(mp[i][j] == '*') cnt++;
            else if(mp[i][j] == 'o'){
                int p = i-1;
                ans[i][j] = 'o';
                forn(k,cnt){
                    ans[p--][j] = '*';
                }
                cnt = 0;
            }
        }
        int p = n-1;
        forn(k,cnt){
            ans[p--][j] = '*';
        }
    }
    forn(i,n) cout<<ans[i]<<endl;
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