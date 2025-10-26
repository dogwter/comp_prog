#include <bits/stdc++.h>
using namespace std;

bool boat(vector<pair<int,int>>&d, long long x, long long y, long long t){
    x-=d[d.size()-1].first*(t/d.size());
    y-=d[d.size()-1].second*(t/d.size());
    if(t%d.size()>0){
        x-=d[t%d.size()-1].first;
        y-=d[t%d.size()-1].second;
    }
    if(abs(x)+abs(y)<=t)return true;
    return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    long long x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    int n; cin>>n;
    vector<pair<int,int>>d(n);
    for(int i=0;i<n;i++){
        char c; cin>>c;
        if(c=='R') d[i].first++;
        else if(c=='U') d[i].second++;
        else if(c=='D') d[i].second--;
        else d[i].first--;
        if(i!=0){
            d[i].first+=d[i-1].first;
            d[i].second+=d[i-1].second;
        }
    }
    x2-=x1; y2-=y1; //amount needed to travel
    long long ok=-1;
    long long l = 0, h = INT64_MAX / 2; //why is this the max?
    while(l<=h){
        if(boat(d,x2,y2,(l+h)/2)){
            ok = (l+h)/2;
            h=(l+h)/2-1;
        } else l=(l+h)/2+1;
    }
    cout<<ok;
}