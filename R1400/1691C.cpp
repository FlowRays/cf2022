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
    cin>>n>>k>>s;
    int p1 = 0, p2 = n-1;
    forn(i,n){
        if(s[i]=='1'){
            p1 = i;
            break;
        }
    }
    for(int i=n-1;i>=0;--i){
        if(s[i]=='1'){
            p2 = i;
            break;
        }
    }
    int t1 = p1, t2 = n-1-p2;
    if(k>=t1+t2){
        if(p1 != p2)
            swap(s[p1],s[0]),swap(s[p2],s[n-1]);
        else{
            swap(s[p2],s[n-1]);
        }
    }
    else if(k>=t2) swap(s[p2],s[n-1]);
    else if(k>=t1) swap(s[p1],s[0]);
    int ans = 0;
    forn(i,n){
        if(i == 0) ans += (s[i]-'0')*10;
        else if(i == n-1) ans += (s[i]-'0')*1;
        else ans += (s[i]-'0')*11;
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