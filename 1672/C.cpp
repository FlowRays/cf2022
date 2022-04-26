#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int p1 = -1, p2 = -1;
    for(int i=0;i<n-1;++i)
        if(a[i]==a[i+1]){
            p1 = i;
            break;
        }
    for(int i=n-1;i>0;--i)
        if(a[i]==a[i-1]){
            p2 = i;
            break;
        }
    if(p2-p1<=1) cout<<0<<endl;
    else cout<<(p2-p1+1==3 ? 1 : p2-p1+1-3)<<endl;
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