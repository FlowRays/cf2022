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
    int x;
    cin>>x;
    string s;
    int t = x;
    while(x){
        if(x&1) s.pb('1');
        else s.pb('0');
        x>>=1;
    }
    x = t;
    reverse(all(s));
    int cnt1 = count(all(s),'1');
    if(cnt1 == 1){
        if(x == 1) cout<<3<<endl;
        else cout<<x+1<<endl;
    }
    else{
        int y = 1;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]=='1'){
                cout<<y<<endl;
                return;
            }
            y*=2;
        }
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