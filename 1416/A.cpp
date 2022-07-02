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
    vector<vector<int>> v(n+1),b(n+1);
    fore(i,1,n) v[i].pb(0);
    forn(i,n) v[a[i]].pb(i+1);
    fore(i,1,n) v[i].pb(n+1);
    fore(i,1,n){
        int d = -1;
        for(int j=1;j<v[i].size();++j){
            d = max(d,v[i][j]-v[i][j-1]);
        }
        if(d<=n) b[d].pb(i);
    }
    priority_queue<int,vector<int>,greater<int>> q;
    fore(i,1,n){
        for(auto x: b[i]) q.push(x);
        cout<<(q.size()==0 ? -1 : q.top())<<" \n"[i==n];
    }
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