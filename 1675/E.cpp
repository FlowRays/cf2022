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
    string s;
    cin>>n>>k>>s;
    char t = *max_element(all(s));
    if(k>=t-'a'){
        s = string(n,'a');
        cout<<s<<endl;
        return;
    }
    char ch = 'a';
    forn(i,n){
        if(s[i]<=ch) s[i] = 'a';
        else if(k>0){
            if(k>=s[i]-ch){
                k -= s[i]-ch;
                ch = s[i];
                s[i] = 'a';
            }
            else{
                char c = s[i];
                s[i] -= k;
                k = 0;
                for(int j=i+1;j<n;++j){
                    if(s[j]<=ch) s[j] = 'a';
                    else if(s[j]<=c && s[j]>=s[i]) s[j] = s[i];
                }
                break;
            }
        }
    }
    cout<<s<<endl;
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