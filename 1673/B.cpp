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
    bool ok = true;
    unordered_set<char> st,cnt;
    forn(i,n) st.insert(s[i]);
    int type = st.size();
    forn(i,type){
        cnt.insert(s[i]);
    }
    ok &= cnt.size()==type;
    if(ok){
        string t;
        forn(i,n){
            t.pb(s[i%type]);
        }
        ok &= t==s;
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