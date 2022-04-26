#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int t = 0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        t += a[i]-1;
    }
    cout<<(t&1 ? "errorgorn" : "maomao90")<<endl;
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