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

map<int,char> mp;

void init(){
    for(int i=0;i<26;++i){
        if(i == 0) mp[0] = 'Z';
        else mp[i] = i-1+'A';
    }
}

string convert(int x){
    string res;
    while(x>0){
        res.pb(mp[x%26]);
        if(x%26 == 0){
            x /= 26;
            x--;
        }
        else{
            x /= 26;
        }
    }
    reverse(all(res));
    return res;
}

int f(string s){
    int res = 0;
    int base = 1;
    for(int i=s.size()-1;i>=0;--i){
        res += base * (s[i]-'A'+1);
        base *= 26;
    }
    return res;
}

void solve(){
    string s;
    cin>>s;
    int p = 0;
    while(isalpha(s[p])) p++;
    while(isdigit(s[p])) p++;
    if(p != s.size()){
        int r = 0;
        int i = 1;
        for(;i<s.size() && isdigit(s[i]);++i){
            r = r*10+s[i]-'0';
        }
        int c = 0;
        for(i = i+1; i<s.size() && isdigit(s[i]);++i){
            c = c*10+s[i]-'0';
        }
        cout<<convert(c)<<r<<endl;
    }
    else{
        string t;
        int i = 0;
        for(;i<s.size() && isalpha(s[i]);++i) t += s[i];
        int r = 0;
        for(;i<s.size();++i) r = r*10+s[i]-'0';
        cout<<"R"<<r<<"C"<<f(t)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}