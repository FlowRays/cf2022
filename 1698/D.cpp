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
    int l = 1, r = n;
    while(l<r){
        int mid = l+r >> 1;
        cout<<"? "<<l<<" "<<mid<<endl;
        int len = mid-l+1;
        int cnt = 0;
        forn(i,len){
            int x;
            cin>>x;
            if(x>=l && x<=mid) cnt++; 
        }
        cnt = len-cnt;
        if((len%2==1 && cnt%2==0) || (len%2==0 && cnt%2==1)) r=mid;
        else l=mid+1; 
    }
    cout<<"! "<<l<<endl;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}