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
const int N = 2e5+10;

char s[2][N];

void solve(){
    int n;
    cin>>n;
    forn(i,2) cin>>s[i];
    int l = n, r = 1;
    int cnt[2] = {0};
    int tot = 0;
    int ans = 0;
    int dir = 0;
    vector<int> d(n+1,-1);
    d[0] = 0;
    forn(i,n){
        int c = 0;
        forn(j,2){
            if(s[j][i] == '*'){
                c++;
                tot++;
                l = min(l,i), r = max(r,i);
                cnt[j]++;
            }
        }
        if(c == 2) ans++, dir = 0;
        else if(c == 1){
            dir = (s[0][i]=='*' ? 1 : 2);
            d[i+1] = dir;
            if(d[i]>0 && s[d[i]-1][i] != '*'){
                if(!(d[i]>0 && i>0 && d[i-1]>0 && d[i]!=d[i+1] && d[i]!=d[i-1])){
                    ans++;
                }
            }
        }
        else d[i+1] = d[i];
    }
    if(tot == 1) cout<<0<<endl;
    else cout<<r-l+ans<<endl;
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