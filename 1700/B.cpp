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

vector<int> sub(vector<int> &A, vector<int> &B){
    vector<int> C;
    for(int i=0,t=0;i<A.size();++i){
        t = A[i]-t;
        if(i<B.size()) t -= B[i];
        C.pb((t+10)%10);
        if(t<0) t = 1;
        else t = 0;
    }
    while(C.size()>1 && C.back() == 0) C.pop_back();
    return C;
}

void solve(){
    int n;
    string s;
    cin>>n>>s;
    if(s[0] != '9'){
        forn(i,n){
            cout<<char(9-(s[i]-'0')+'0');
        }
        cout<<endl;
    }
    else{
        vi A(n+1,1),B;
        for(int i=n-1;i>=0;--i) B.pb(s[i]-'0');
        vi C = sub(A,B);
        for(int i=C.size()-1;i>=0;--i) cout<<C[i];
        cout<<endl;
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