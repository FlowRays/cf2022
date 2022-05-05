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
    vi p(n+1),vis(n+1,0),leaf,st(n+1,0);
    forn(i,n) cin>>p[i+1],vis[p[i+1]]=1;
    if(n == 1) leaf.pb(1);
    fore(i,1,n){
        if(!vis[i]) leaf.pb(i);
    }
    cout<<leaf.size()<<endl;
    forn(i,leaf.size()){
        vector<int> path;
        int x = leaf[i];
        while(!st[x]){
            st[x] = 1;
            path.pb(x);
            x = p[x];
        }
        cout<<path.size()<<endl;
        for(int j=path.size()-1;j>=0;--j){
            cout<<path[j]<<(j==0 ? "\n" : " ");
        }
    }
    cout<<endl;
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