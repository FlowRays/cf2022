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
    vector<set<int>> v(n+1);
    forn(i,n){
        v[a[i]].insert(i);
    }
    vi ans;
    int p = 0;
    while(true){
        int np = p;
        forn(i,n+1){
            vi t;
            for(auto x: v[i]){
                if(x<p){
                    t.pb(x);
                }
                else break;
            }
            for(auto x: t){
                v[i].erase(x);
            }
            if(v[i].size()==0){
                ans.pb(i);
                break;
            }
            else{
                np = max(np,*v[i].begin());
                v[i].erase(v[i].begin());
            }
        }
        p = np+1;
        if(p>=n) break;
    }
    cout<<ans.size()<<endl;
    forn(i,ans.size()) cout<<ans[i]<<" \n"[i==ans.size()-1];
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