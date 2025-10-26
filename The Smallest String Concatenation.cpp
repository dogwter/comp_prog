#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    sort(s.begin(), s.end(),[](string &x, string &y){return x+y<y+x;});
    for(auto i:s)cout<<i;
}