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
    vector<string> mp(n);
    forn(i,n) cin>>mp[i];
    set<pii> a,b;
    pii p;
    forn(i,n){
        forn(j,m){
            if(mp[i][j] == 'B'){
                a.insert({i-j,i});
                b.insert({i+j,i});
                p = {i,j};
            }
        }
    }
    set<pii> mat;
    mat.insert({a.begin()->second,a.begin()->second-a.begin()->first});
    mat.insert({a.rbegin()->second,a.rbegin()->second-a.rbegin()->first});
    mat.insert({b.begin()->second,b.begin()->first-b.begin()->second});
    mat.insert({b.rbegin()->second,b.rbegin()->first-b.rbegin()->second});
    // for(auto [x,y]:mat) cout<<" "<<x<<" "<<y<<endl;
    pii ans;
    int cnt = 1e9;
    forn(i,n){
        forn(j,m){
            int mx = 0;
            for(auto [x,y]: mat) mx = max(mx,abs(x-i)+abs(y-j));
            if(mx<cnt){
                cnt = mx;
                ans = {i,j};
            }
        }
    }
    cout<<ans.first+1<<" "<<ans.second+1<<endl;
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
/*
1
2 2
BW
WB
*/