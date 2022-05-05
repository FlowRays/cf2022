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
    int tot = 0;
    for(auto ch: s){
        tot += ch-'a'+1;
    }
    int n = s.size();
    int x = tot;
    if(n%2==1) x -= min(s[0]-'a'+1,s[n-1]-'a'+1);
    int y = tot-x;
    cout<<(x>y ? "Alice" : "Bob")<<" "<<abs(x-y)<<endl;
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