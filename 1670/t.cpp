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
    string s;
    cin>>n>>s>>k;
    map<char,int> mp;
    forn(i,k){
        char ch;
        cin>>ch;
        mp[ch] = 1;
    }
    int cnt = 0;
    int mx = 0;
    int tot = 0;
    forn(i,n){
        if(mp[s[i]]){
            cnt++;
            tot++;
            while(i+1<n && mp[s[i+1]]) i++,tot++;
        }
        else{
            int len = 1;
            while(i+1<n && !mp[s[i+1]]) i++,len++;
            if(i+1 != n) mx = max(mx,len);
        }
    }
    if(cnt == 0 || (tot==1 && mp[s[0]])) cout<<0<<endl;
    else if(mx == 0) cout<<1<<endl;
    else{
        cout<<mx+(cnt>=2 ? 1 : 0)<<endl;
    }
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