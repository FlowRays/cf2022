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

// 很有意思的题目，捕捉特征

void solve(){
    int n;
    cin>>n;
    vector<int> cnt(26);
    forn(i,2*n+1){
        string s;
        cin>>s;
        for(auto ch: s){
            cnt[ch-'a']++;
        }
    }
    forn(i,26){
        if(cnt[i]%2){
            cout<<char(i+'a')<<endl;
            return;
        }
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