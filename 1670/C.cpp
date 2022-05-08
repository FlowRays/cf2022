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
    vi a(n),b(n),c(n),p1(n+1),p2(n+1),st(n,0);
    forn(i,n) cin>>a[i];
    forn(i,n) cin>>b[i];
    forn(i,n) cin>>c[i];
    forn(i,n) p1[a[i]] = i;
    forn(i,n) p2[b[i]] = i;
    ll ans = 1;
    forn(i,n){
        if(c[i] == 0 && a[i]!=b[i] && !st[i]){
            st[i] = 1;
            bool ok = true;
            queue<int> q;
            q.push(i);
            while(q.size()){
                int t = q.front();
                q.pop();
                if(c[t] != 0) ok = false;
                int x1 = p1[b[t]], x2 = p2[a[t]];
                if(!st[x1]) q.push(x1),st[x1]=1;
                if(!st[x2]) q.push(x2),st[x2]=1;
            }
            if(ok) ans = ans*2%mod;
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

/*
1
6
1 2 3 4 5 6
2 3 1 5 6 4
0 0 0 0 0 0
*/