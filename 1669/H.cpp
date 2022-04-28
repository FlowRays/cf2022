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
    int n,k;
    cin>>n>>k;
    vi a(n);
    forn(i,n) cin>>a[i];
    vi cnt(31);
    forn(i,n){
        forn(j,31){
            cnt[j] += (a[i]>>j & 1);
        }
    }
    int res = 0;
    for(int i=30;i>=0;--i){
        if(k<n-cnt[i]) continue;
        res |= 1<<i;
        k -= n-cnt[i];
    }
    cout<<res<<endl;
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