#include <bits/stdc++.h>
using namespace std;

int a[26][200001];

int sum(int l, int r){
    int b = 0;
    for(int i=0;i<26;i++){
        if(a[i][r]-a[i][l-1]>0)b++;
    }
    return b;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int q; cin>>q;
    for(int i=1;i<=s.length();i++){
        a[(int)(s[i-1]-'a')][i]++;
        for(int j=0;j<26;j++)a[j][i]+=a[j][i-1];
    }
    for(int i=0,l,r;i<q;i++){
        cin>>l>>r;
        if(l==r)cout<<"Yes\n";
        else if(s[r-1]!=s[l-1])cout<<"Yes\n";
        else if(sum(l,r)>2)cout<<"Yes\n";
        else cout<<"No\n";
    }
}
