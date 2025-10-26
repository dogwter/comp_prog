#include <bits/stdc++.h>
using namespace std;

bool go(long long x1, long long y1, long long t){
    if(t*t>=x1*x1+y1*y1)return true;
    return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int g,n; cin>>g>>n;
    int ans = 0;
    map<int,pair<int,int>>graze;
    for(int i=0,a,b,c;i<g;i++){
        cin>>a>>b>>c;
        graze[c]={a,b};
    }
    for(int i=0;i<n;i++){
        long long a, b; cin>>a>>b;
        long long t1; cin >> t1;
        bool guilty = true;
        int c, d, e;
        if(graze.lower_bound(t1)!=graze.end()){
            auto j = *graze.lower_bound(t1);
            c=j.first; d = j.second.first; e = j.second.second;
        } else {
            auto j = *prev(graze.end());
            c=j.first; d = j.second.first; e = j.second.second;
        }
        if(!go(a-d,b-e,c-t1)) guilty=false;
        if(graze.upper_bound(t1)!=graze.end()){
            auto j = *graze.upper_bound(t1);
            c=j.first; d = j.second.first; e = j.second.second;
        } else {
            auto j = *prev(graze.end());
            c=j.first; d = j.second.first; e = j.second.second;
        }
        if(!go(a-d,b-e,c-t1)) guilty=false;
        if(graze.lower_bound(t1)!=graze.begin()){
            auto j = *prev(graze.lower_bound(t1));
            c=j.first; d = j.second.first; e = j.second.second;
        }
        if(!go(a-d,b-e,c-t1)) guilty=false;
        if(!guilty)ans++;
    }
    cout<<ans;
}