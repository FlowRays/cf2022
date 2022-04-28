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
    vi a(n);
    forn(i,n) cin>>a[i];
    vi s1(n),s2(n);
    forn(i,n){
        s1[i] = (i==0 ? a[i] : s1[i-1]+a[i]);
    }
    for(int i=n-1;i>=0;--i){
        s2[i] = (i==n-1 ? a[i] : s2[i+1]+a[i]);
    }
    int ans = 0;
    for(int i=0,j=n-1;i<j;){
        if(s1[i] == s2[j]){
            ans = max(ans,i+n-j+1);
            i++,--j;
        }
        else if(s1[i]<s2[j]) i++;
        else j--;
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