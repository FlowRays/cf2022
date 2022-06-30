#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
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

int ask(string s){
    cout<<"? "<<s<<endl;
    int res;
    cin>>res;
    return res;
}

void solve(){
    int n,m;
    cin>>n>>m;
    // 获取每条边的长度
    vector<pii> e(m);
    forn(i,m){
        string s(m,'0');
        s[i] = '1';
        e[i] = {ask(s),i};
    }
    sort(all(e),greater<pii>());
    string s(m,'1');
    int t = ask(s);
    int ans = 0;
    forn(i,m){
        auto [len,id] = e[i];
        if(i == m-1){
            ans += len;
            break;
        }
        s[id] = '0';
        int r = ask(s);
        int d = t-r;
        t = r;
        if(d == len){
            s[id] = '1';
            ans += len;
            t += len;
        }
    }
    cout<<"! "<<ans<<endl;
}

int main() {
    int tt = 1;
    while (tt--) {
        solve();
    }

    return 0;
}

/*
7 10
6 2 525
4 2 363
4 6 122
5 3 492
2 1 248
7 6 472
4 1 219
5 6 37
1 4 592
5 6 589

5 4
1 2 1
2 3 2
1 3 3
4 5 4

5 4
1
2
3
4
9
5
7
5
*/