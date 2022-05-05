#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    vector<string> mp(n);
    forn(i,n) cin>>mp[i];
    int tot = 0;
    forn(i,n){
        forn(j,m){
            if(mp[i][j] == '*') tot++;
        }
    }
    int cnt = 0;
    forn(i,n){
        forn(j,m){
            if(mp[i][j]=='*' && j*n+i<tot) cnt++;
        }
    }
    int ans = tot-cnt;
    while(q--){
        int x,y;
        cin>>x>>y;
        x--,y--;
        if(mp[x][y] == '.'){
            if(y*n+x>=tot+1) ans++;
            else ans--;
            if(mp[tot%n][tot/n]=='.') ans++;
            else ans--;
            tot++;
            // if(y*n+x>=tot && mp[(tot-1)%n][(tot-1)/n]=='.') ans++;
            // if(y*n+x<tot) ans--;
            mp[x][y] = '*';
        }
        else{
            tot--;
            if(y*n+x<tot) ans++;
            else ans--;
            if(mp[tot%n][tot/n]=='.')
            if(y*n+x<tot && mp[tot%n][tot/n]=='*') ans++;
            else if(y*n+x>tot && mp[tot%n][tot/n]=='.') ans--; 
            mp[x][y] = '.';
        }
        cout<<ans<<endl;
    }

    return 0;
}