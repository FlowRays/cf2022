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

/*
用unordered_map
mp.reserve(1024);
mp.max_load_factor(0.25);
*/

void solve(){
    int n;
    scanf("%d",&n);
    vi a(n);
    forn(i,n) scanf("%d",&a[i]);
    sort(all(a));
    int t = 1;
    forn(i,n){
        int r = 1;
        while(i+1<n && a[i+1]==a[i]) i++,r++;
        t = max(t,r);
    }
    int ans = n-t;
    int s = t;
    while(s<n){
        s *= 2;
        ans++;
    }
    printf("%d\n",ans);
}

int main() {
    int tt;
    // cin >> tt;
    scanf("%d",&tt);
    while (tt--) {
        solve();
    }

    return 0;
}