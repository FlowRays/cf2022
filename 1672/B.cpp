#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    string s;
    cin>>s;
    vector<int> ca(s.size()),cb(s.size());
    for(int i=0;i<s.size();++i){
        if(i==0) ca[i] = (s[i]=='A' ? 1 : 0);
        else ca[i] = ca[i-1]+(s[i]=='A' ? 1 : 0);
    }
    for(int i=0;i<s.size();++i){
        if(i==0) cb[i] = (s[i]=='B' ? 1 : 0);
        else cb[i] = cb[i-1]+(s[i]=='B' ? 1 : 0);
    }
    if(s.back() != 'B'){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<s.size();++i){
        if(s[i]=='B' && ca[i]<cb[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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