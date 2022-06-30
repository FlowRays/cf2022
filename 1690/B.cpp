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
    vi a(n),b(n);
    forn(i,n) cin>>a[i];
    forn(i,n) cin>>b[i];
    vector<pii> v(n);
    bool ok = true;
    forn(i,n){
        v[i] = {a[i]-b[i],b[i]};
    }
    sort(all(v),greater<pii>());
    forn(i,n){
        if(v[i].first < 0) ok = false;
        if(i==0 || v[i].first == v[i-1].first || v[i].second==0) continue;
        ok = false;
        break;
    }
    cout<<(ok ? "YES" : "NO")<<endl;
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