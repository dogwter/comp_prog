#include <bits/stdc++.h>
using namespace std;

bool meet(map<int,int>&f, double t){
    double l=0, r=(*prev(f.end())).first;
    for(auto i:f){
        l=max(l,i.first-i.second*t);
        r=min(r,i.first+i.second*t);
    }
    cout<<t<<" "<<l<<" "<<r<<"\n";
    if(l<=r)return true;
    return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int>x(n);
    vector<int>v(n);
    map<int,int>f;
    for(int i=0;i<n;i++)cin>>x[i];
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++){
        if(f[x[i]]==0)f[x[i]]=v[i];
        else f[x[i]]=min(f[x[i]],v[i]);
    }
    double lo=0, hi = (*prev(f.end())).first;
    while(lo+0.0000001<hi){
        if(meet(f,(lo+hi)/2.0))hi=(lo+hi)/2.0;
        else lo=(lo+hi)/2.0;
    }
    cout<<"\n";
    cout<<meet(f, 1.764705882353);
}