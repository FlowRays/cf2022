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
    string s,t;
    cin>>s>>t;
    int len1 = s.size(), len2 = t.size();
    int p = 0;
    if((len1-len2)%2==1){
        p = 1;
    }
    forn(i,len2){
        while(p<len1 && s[p]!=t[i]) p += 2;
        if(p>=len1){
            cout<<"NO"<<endl;
            return;
        }
        p++;
    }
    cout<<"YES"<<endl;
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