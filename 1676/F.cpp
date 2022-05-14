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
    int n,k;
    cin>>n>>k;
    map<int,int> mp;
    int ansl = -1, ansr = -1, len = 0;
    forn(i,n){
        int x;
        cin>>x;
        mp[x]++;
        if(mp[x]>=k){
            ansl = ansr = x, len = 1;
        }
    }
    if(ansl == -1){
        cout<<-1<<endl;
        return;
    }
    map<int,int> st;
    for(auto [x,y]: mp){
        if(st.count(x) == 0 && y>=k){
            int l = x, r = x, cnt = 1;
            st[l] = 1;
            while(mp[r+1]>=k){
                r++;
                cnt++;
                st[r] = 1;
            }
            if(cnt>len){
                len = cnt;
                ansl = l, ansr = r;
            }
        }
    }
    cout<<ansl<<" "<<ansr<<endl;
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