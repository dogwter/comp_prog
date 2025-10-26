#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pair<int,int>>m(n);
    for(int i=0;i<n;i++){
        int del;
        cin>>m[i].first>>del;
        m[i].second=m[i].first+del;
        m[i].first-=del;
    }
    sort(m.begin(),m.end(),[](pair<int,int>a, pair<int,int>b){
        if(a.first!=b.first)return a.first<b.first;
        else return a.second>b.second;
    });
    int ans=1,l=m[0].first,r=m[0].second;
    for(int i=1;i<n;i++){
        if(m[i].first>=r){
            l=m[i].first; r = m[i].second; ans++;
        } else if(m[i].second>r){
            r=m[i].second; ans++;
        }
    }
    cout<<ans;
}