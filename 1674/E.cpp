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
    vi b(a);
    sort(all(b));
    int ans = (b[0]+1)/2+(b[1]+1)/2;
    fore(i,1,n-1){
        int t1 = a[i-1], t2 = a[i];
        if(t1<=t2/2) ans = min(ans,t2);
        else if(t1/2>=t2) ans = min(ans,t1);
        else{
            int r1 = (2*t1-t2)/3;
            int r2 = (2*t2-t1)/3; 
            for(int j=max(r1-5,0);j<=r1+5;++j){
                for(int k=max(r2-5,0);k<=r2+5;++k){
                    if(2*j+k>=t1 && 2*k+j>=t2){
                        ans = min(ans,j+k);
                    }
                }
            }
        }
        if(i<n-1){
            ans = min(ans,(a[i-1]+1)/2+(a[i+1]+1)/2);
            ans = min(ans,1+(a[i-1]-1+1)/2+(a[i+1]-1+1)/2);
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    while (tt--) {
        solve();
    }

    return 0;
}