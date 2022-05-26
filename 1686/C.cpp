// 1 8 4 9
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
    if(n%2){
        cout<<"NO"<<endl;
        return;
    }
    vi ans(n);
    sort(all(a));
    for(int i=0,j=0;i<n;i+=2,++j) ans[i] = a[j], ans[i+1] = a[j+n/2];
    bool ok = true;
    forn(i,n){
        if(i == 0){
            if(!((ans[i]>ans[i+1] && ans[i]>ans[n-1]) || (ans[i]<ans[i+1] && ans[i]<ans[n-1]))){
                ok = false;
                break;
            }
        }
        else if(i == n-1){
            if(!((ans[i]>ans[0] && ans[i]>ans[i-1]) || (ans[i]<ans[0] && ans[i]<ans[i-1]))){
                ok = false;
                break;
            }
        }
        else{
            if(!((ans[i]>ans[i+1] && ans[i]>ans[i-1]) || (ans[i]<ans[i+1] && ans[i]<ans[i-1]))){
                ok = false;
                break;
            }
        }
    }
    if(ok){
        cout<<"YES"<<endl;
        forn(i,n) cout<<ans[i]<<" \n"[i==n-1];
    }
    else cout<<"NO"<<endl;
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