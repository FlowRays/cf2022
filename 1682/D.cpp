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
    int cnt = count(all(s),'1');
    if(cnt>=2 && cnt%2 == 0){
        cout<<"YES"<<endl;
        int rt;
        forn(i,n){
            if(s[i] == '1'){
                rt = i+1;
                break;
            }
        }
        int pre = 1;
        int p = rt;
        vector<pii> ans;
        int tot = 0;
        while(tot<n) {
            int now = s[p]-'0';
            if((pre == 1 && now == 0) || (pre == 0 && now == 0)){
                ans.pb({(p==0 ? n : p),(p+1)});
            }
            pre = now;
            p++;
            tot++;
            p %= n;
        }
        vi a(n+1,0);
        for(auto [x,y]: ans){
            a[x]++;
            a[y]++;
        }
        forn(i,n){
            if((s[i]=='1' && a[i+1]==0) || (s[i]=='0' && a[i+1]==1)) {
                rt = i+1;
                break;
            }
        }
        forn(i,n){
            if(abs(a[i+1]-(s[i]-'0'))%2 == 1 && i+1 != rt){
                ans.pb({rt,i+1});
            }
        }
        for(auto [x,y]: ans) {
            cout<<x<<" "<<y<<endl;
        }
    }
    else{
        cout<<"NO"<<endl;
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

/*
1
3
101
*/