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
    string s;
    cin>>s;
    vi a;
    a.pb(-1);
    forn(i,n){
        if(s[i]=='W') a.pb(i);
    }
    a.pb(n);
    bool ok = true;
    fore(i,1,a.size()-1){
        int l = a[i-1], r = a[i];
        if(r-l-1==0) continue;
        if(r-l-1==1){
            ok = false;
            break;
        }
        int cnt0 = 0, cnt1 = 0;
        for(int j=l+1;j<=r-1;++j){
            if(s[j] == 'R') cnt0++;
            else cnt1++;
        }
        ok &= (cnt0!=0 && cnt1!=0);
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