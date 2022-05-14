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
    vector<string> v(n);
    forn(i,n) cin>>v[i];
    int ans = 1e9;
    auto diff = [&](string a, string b){
        int res = 0;
        forn(i,m){
            res += abs(a[i]-b[i]);
        }
        return res;
    };
    forn(i,n){
        fore(j,i+1,n-1){
            ans = min(ans,diff(v[i],v[j]));
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