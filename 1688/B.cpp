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
    int x = 1e9;
    int tot = 0;
    forn(i,n){
        int t = a[i];
        int c = 0;
        while(t%2==0){
            t /= 2;
            c++;
        }
        x = min(x,c);
        tot += (a[i]%2==0);
    }
    if(tot == 0) cout<<0<<endl;
    else if(tot == n) cout<<x+tot-1<<endl;
    else cout<<tot<<endl;
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