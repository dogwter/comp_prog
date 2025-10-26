#include <bits/stdc++.h>
using namespace std;

bool sig(vector<pair<long long,long long>>&b,double dis,double l){
    double min_x = 0, max_x = 0, pt=0;
    for(auto i:b){
        if(abs(i.second)<=dis){
            min_x=i.first-sqrt(dis*dis-i.second*i.second);
            max_x=i.first+sqrt(dis*dis-i.second*i.second);
            if(min_x<=pt)pt=max(max_x,pt);
        }
        if(pt>=l)return true;
    }
    return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, l; cin>>n>>l;
    vector<pair<long long,long long>>b(n);
    double lo =1, hi=1.5e9;
    for(int i=0;i<n;i++)cin>>b[i].first>>b[i].second;
    while(hi-lo>0.0001){
        if(sig(b,(lo+hi)/2,l))hi=(lo+hi)/2;
        else lo = (lo+hi)/2;
    }
    cout<<fixed << setprecision(4)<<lo;
}