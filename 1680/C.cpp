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
    int l = 0, r = n;
    int cnt1 = count(all(s),'1');
    vector<int> s0(n+1,0),s1(n+1,1);
    fore(i,1,n) s0[i] = s0[i-1]+(s[i-1]=='0'), s1[i] = s1[i-1]+(s[i-1]=='1');
    auto check = [&](int x){
        fore(i,1,n){
            int p = lower_bound(all(s0),s0[i-1]+x+1)-s0.begin();
            p = min(p,n);
            // cout<<i<<" "<<p<<endl;
            if(cnt1-(s1[p]-s1[i-1])<=x) return true;
        }
        return false;
    };
    while(l<r){
        int mid = l+r >> 1;
        if(check(mid)) r=mid;
        else l=mid+1;
        // break;
    }
    cout<<l<<endl;
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
101110110
*/