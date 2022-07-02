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
    int s = accumulate(all(a),0);
    if(s%n != 0){
        cout<<-1<<endl;
        return;
    }
    int avg = s/n;
    vector<tuple<int,int,int>> ans;
    fore(i,1,n-1){
        int t = a[i]%(i+1);
        int k = 0;
        if(t != 0) k = i+1-t;
        a[i] += k;
        int x = a[i]/(i+1);
        a[i] = 0;
        ans.emplace_back(1,i+1,k);
        ans.emplace_back(i+1,1,x);
    }
    fore(i,1,n-1){
        ans.emplace_back(1,i+1,avg);
    }
    cout<<ans.size()<<endl;
    for(auto [a,b,c]: ans){
        cout<<a<<" "<<b<<" "<<c<<endl;
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