#include <bits/stdc++.h>
using namespace std;

bool cow(int n, long long d, vector<pair<long long, long long>>&g){
    //given min dis between 2 cows is d, can we fit n cows
    long long idx = g[0].first;
    int c = 1;
    for(int i=0;i<g.size();i++){
        if(i!=0){
            if(g[i].first-idx>=d){
                idx=g[i].first; c++;
            }
            else if(idx+d>g[i].first&&idx+d<=g[i].second){
                idx+=d; c++;
            }
        }
        while(idx+d<=g[i].second){
            c++; idx+=d;
        }
        if(c>=n)return true;
    }
    return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<pair<long long, long long>>g(m);
    for(int i=0;i<m;i++){
        cin>>g[i].first;
        cin>>g[i].second;
    }
    sort(g.begin(),g.end());
    long long lo = 1;
    long long hi = g[m-1].second-g[0].first+1;
    while(lo<=hi){
        if(cow(n,(lo+hi)/2,g)) lo = (lo+hi)/2+1;
        else hi = (lo+hi)/2-1;
    }
    cout<<hi;
}