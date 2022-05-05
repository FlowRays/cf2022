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
    string s;
    cin>>s;
    string t = s;
    int cnt0 = 0;
    if(k&1){
        forn(i,t.size()){
            t[i] = (t[i]=='0' ? '1' : '0');
        }
    }
    forn(i,t.size()){
        if(t[i]=='0') cnt0++;
    }
    vi ans(n);
    int kk = k;
    if(kk>n){
        if(kk&1){
            if(n&1) kk = n;
            else kk = n-1;
        }
        else{
            if(n&1) kk = n-1;
            else kk = n;
        }
    }
    // cout<<" "<<kk<<" "<<cnt0<<endl;
    if(kk<=cnt0){
        forn(i,t.size()){
            if(kk==0) break;
            if(t[i]=='0'){
                t[i] = '1';
                ans[i] = 1;
                kk--;
            }
        }
    }
    else{
        if((kk-cnt0)%2==0){
            forn(i,t.size()){
                if(t[i]=='0'){
                    t[i] = '1';
                    ans[i] = 1;
                }
            }
        }
        else{
            forn(i,t.size()){
                if(t[i]=='0'){
                    t[i] = '1';
                    ans[i] = 1;
                }
            }
            t.back() = '0';
            ans[n-1]++;
        }
    }
    cout<<t<<endl;
    int cnt = 0;
    forn(i,t.size()){
        cnt += ans[i];
    }
    ans[0] += k-cnt;
    forn(i,n){
        cout<<ans[i]<<(i==n-1 ? "\n" : " ");
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