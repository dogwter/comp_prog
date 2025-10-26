#include <bits/stdc++.h>
using namespace std;

long long profit(vector<long long>&c,vector<pair<int,int>>&s,vector<long long>&f,long long r){
    long long p;
    if(r==0)p=0;
    else p=f[r-1]; 
    r = c.size()-r;
    if(r==0)return p;
    else{
        r = c[r-1];
        for(int i = 0;i<s.size();i++){
            if(r>0){
                p+=min(r,(long long)s[i].second)*s[i].first;
                r-=min(r,(long long)s[i].second);
            } else break;
        }
        return p;
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n,m,r; cin>>n>>m>>r;

    vector<long long>c(n);
    for(int i=0;i<n;i++)cin>>c[i];
    vector<pair<int,int>>s(m);
    for(int i=0;i<m;i++)cin>>s[i].second>>s[i].first;
    vector<long long>f(r);
    for(int i=0;i<r;i++)cin>>f[i];
    sort(c.begin(),c.end(),greater{});
    sort(s.begin(),s.end(),greater{});
    sort(f.begin(),f.end(),greater{});
    for(int i=1;i<n;i++)c[i]+=c[i-1];
    for(int i=1;i<r;i++)f[i]+=f[i-1];

    int lo=0,hi=min(r,n);
    while(lo<=hi){
        if(profit(c,s,f,(lo+hi)/2)>profit(c,s,f,(lo+hi)/2+1))hi=(lo+hi)/2-1;
        else lo = (lo+hi)/2+1;
    }
    cout<<profit(c,s,f,lo);
}