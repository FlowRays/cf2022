#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
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

map<pii,int> mp;

char ask1(int i){
    cout<<"? "<<1<<" "<<i<<endl;
    char res;
    cin>>res;
    return res;
}

int ask2(int l,int r){
    if(l == r) return 1;
    if(mp.count(make_pair(l,r))) return mp[make_pair(l,r)];
    cout<<"? "<<2<<" "<<l<<" "<<r<<endl;
    int res;
    cin>>res;
    mp[make_pair(l,r)] = res;
    return res;
}

int main() {
    int n;
    cin>>n;
    string ans(n,'a');
    vi s(n);
    s[0] = 1;
    fore(i,1,n){
        if(i == 1) ans[i-1] = ask1(i);
        else{
            s[i-1] = ask2(1,i);
            if(s[i-1]>s[i-2]) ans[i-1] = ask1(i);
            else{
                map<char,int> last;
                forn(j,i-1) last[ans[j]] = j+1;
                vi lasts;
                for(auto [ch,x]: last) lasts.pb(x);
                sort(all(lasts));
                vi cnt(i-1);
                set<char> st;
                for(int j=i-2;j>=0;--j){
                    st.insert(ans[j]);
                    cnt[j] = st.size();
                }
                int l = 0, r = lasts.size()-1;
                while(l<r){
                    int mid = l+r+1 >> 1;
                    if(ask2(lasts[mid],i)-cnt[lasts[mid]-1]<1) l=mid;
                    else r=mid-1;
                }
                ans[i-1] = ans[lasts[l]-1];
            }
        }
    }
    cout<<"! "<<ans<<endl;


    return 0;
}