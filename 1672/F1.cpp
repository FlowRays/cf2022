#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),pos(n);
    for(auto &x: a) cin>>x;
    int bais = 1;
    for(int i=1;i<n;++i){
        if(a[i] == a[i-1]){
            int t = 1;
            while(i+1<n && a[i+1]==a[i]) i++,t++;
            bais = max(bais,t);
        }
    }
    for(int i=bais;i<n;++i) cout<<a[i]<<" ";
    for(int i=0;i<bais;++i) cout<<a[i]<<" ";
    cout<<endl;
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