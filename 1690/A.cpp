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
    if(n%3==0){
        cout<<n/3<<" "<<n/3+1<<" "<<n/3-1<<endl;
    }
    else if(n%3==1){
        cout<<n/3<<" "<<n/3+2<<" "<<n/3-1<<endl;
    }
    else{
        cout<<n/3+1<<" "<<n/3+2<<" "<<n/3-1<<endl;
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