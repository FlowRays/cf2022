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
    int l,r;
    cin>>l>>r;
    int ans = 0;
    auto calc = [&](int l,int r){
        if(l>=r) return 0;
        int res = 0;
        int a = r-l;
        int b = r/10-l/10;
        res += a-b;
        int i = 2;
        while(b){
            res += (b%10 + b/10*9)*i;
            i++;
            b /= 10;
        }
        return res;
    };
    cout<<calc(1,r)-calc(1,l)<<endl;
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