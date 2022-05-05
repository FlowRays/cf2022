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
    string s;
    cin>>s;
    int n = s.size();
    vector<bool> a(n),b(n);
    bool has = false;
    forn(i,s.size()){
        if(s[i]=='0') has = true;
        a[i] = has;
    }
    has = false;
    for(int i=n-1;i>=0;--i){
        if(s[i]=='1') has = true;
        b[i] = has;
    }
    int ans = 0;
    forn(i,n){
        if((i==0 || !a[i-1]) && (i==n-1 || !b[i+1])) ans++;
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