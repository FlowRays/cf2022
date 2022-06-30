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
    int n,m;
    cin>>n>>m;
    vi a(n);
    forn(i,n) cin>>a[i];
    map<int,int> mp;
    forn(i,n){
        int l = i, r = i;
        while(r+1<n && a[r+1]>=a[l]) r++;
        i = r;
        mp[l+1] = a[l];
    }
    // for(auto [x,y]: s) cout<<x<<" "<<y<<endl;
    forn(i,m){
        int k,d;
        cin>>k>>d;
        a[k-1] -= d;
        auto it1 = mp.upper_bound(k);
        it1--;
        auto [l,x] = *it1;
        // cout<<" "<<x<<" "<<a[k-1]<<endl;
        if(x>a[k-1]){
            int now = a[k-1];
            auto it2 = it1;
            while(it2->second >= now && it2 != mp.end()) it2++;
            if(k>l) it1++;
            mp.erase(it1,it2);
            if(k==l){
                mp[l] = now;
            }
            else{
                mp[k] = now;
            }
        }
        cout<<mp.size()<<" ";
    }
    cout<<endl;
}

/*
1

4 2
6 2 3 7
3 2
4 7


*/

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