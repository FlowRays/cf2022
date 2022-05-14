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
    forn(i,n){
        int x;
        cin>>x;
        mp[x]++;
    }
    int l = -1, r = -1, len = 0;
    int ansl = -1, ansr = -1;
    int pre = -1;
    bool in = false;
    for(auto [x,y]: mp){
        if(in){
            if(y<k){
                in = false;
                if(len < r-l+1){
                    len = r-l+1;
                    ansl = l, ansr = r;
                }
            }
            else{
                if(x == pre+1){
                    r++, pre++;
                }
                else{
                    if(len < r-l+1){
                        len = r-l+1;
                        ansl = l, ansr = r;
                    }
                    l = r = pre = x;
                }
            }
        }
        else{
            if(y>=k) in = true, l = r = x, pre = x;
        }
    }
    if(in && len<r-l+1){
        len = r-l+1;
        ansl = l, ansr = r;
    }
    if(ansl == -1) cout<<-1<<endl;
    else cout<<ansl<<" "<<ansr<<endl;
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