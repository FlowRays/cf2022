#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(auto &x: a) cin>>x;
    for(auto &x: b) cin>>x;
    unordered_map<int,set<int>> mp;
    for(int i=0;i<n;++i){
        mp[a[i]].insert(i);
    }
    for(int i=0;i<n;++i){
        if(a[i]==b[i]) continue;
        int pos = *upper_bound(mp[b[i]].begin(),mp[b[i]].end(),i);
        // [i,pos] right move 1
        for(int j=i;j<pos;++j){
            mp[a[j]].erase(j);
            mp[a[j]].insert(j+1);
        }
        for(int j=pos;j>i;--j) a[j] = a[j-1];
        a[i] = b[i];
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