#include <bits/stdc++.h>
using namespace std;

const int mod = 10e9+7;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<vector<pair<int,int>>>x(2e4+1),y(2e4+1);
    vector<tuple<int,int,long long,long long>>f;
    for(int i=0,a,b;i<n;i++){
        cin>>a>>b;
        a+=1e4,b+=1e4;
        f.push_back({a,b,0,0});
    }
    sort(f.begin(), f.end());
    x[get<0>(f[0])].push_back({get<1>(f[0]),0});
    for(int i=1;i<n;i++){
        if(get<0>(f[i])==get<0>(f[i-1])){
            x[get<0>(f[i])].push_back({get<1>(f[i]),get<1>(f[i])-x[get<0>(f[i])][0].first});
            x[get<0>(f[i])][x[get<0>(f[i])].size()-1].second+=x[get<0>(f[i])][x[get<0>(f[i])].size()-2].second;
        }
        else x[get<0>(f[i])].push_back({get<1>(f[i]),0});
    }
    long long a;
    int idx;
    for(int i=0;i<2e4+1;i++){
        if(x[i].size()>1){
            x[i][0].second=x[i][x[i].size()-1].second;
            idx = lower_bound(f.begin(),f.end(),make_tuple(i,x[i][0].first,0,0))-f.begin();
            get<2>(f[idx])=x[i][0].second;
            for(int j=1;j<x[i].size();j++){
                a = (2*j-x[i].size()+1)*(x[i][j].first-x[i][0].first) - x[i][j].second;
                a %=mod;
                a += x[i][x[i].size()-1].second;
                a %=mod;
                idx = lower_bound(f.begin(),f.end(),make_tuple(i,x[i][j].first,0,0))-f.begin();
                get<2>(f[idx])=a;
            }
        }
    }
    sort(f.begin(), f.end(), [](auto &b, auto &c){if(get<1>(b)!=get<1>(c))return get<1>(b)<get<1>(c); else return get<0>(b)<get<0>(c);});
    y[get<1>(f[0])].push_back({get<0>(f[0]),0});
    for(int i=1;i<n;i++){
        if(get<1>(f[i])==get<1>(f[i-1])){
            y[get<1>(f[i])].push_back({get<0>(f[i]),get<0>(f[i])-y[get<1>(f[i])][0].first});
            y[get<1>(f[i])][y[get<1>(f[i])].size()-1].second+=y[get<1>(f[i])][y[get<1>(f[i])].size()-2].second;
        }
        else y[get<1>(f[i])].push_back({get<0>(f[i]),0});
    }
    for(int i=0;i<2e4+1;i++){
        if(y[i].size()>1){
            y[i][0].second=y[i][y[i].size()-1].second;
            idx = lower_bound(f.begin(),f.end(),make_tuple(y[i][0].first,i,0,0))-f.begin();
            get<3>(f[idx])=y[i][0].second;
            for(int j=1;j<y[i].size();j++){
                a = (2*j-y[i].size()+1)*(y[i][j].first-y[i][0].first)- y[i][j].second;
                a %=mod;
                a += y[i][y[i].size()-1].second;
                a %=mod;
                idx = lower_bound(f.begin(),f.end(),make_tuple(y[i][j].first,i,0,0))-f.begin();
                get<3>(f[idx])=a;
            }
        }
    }
    long long ans = 0;
    for(auto i:f){
        ans += get<2>(i)*get<3>(i)%mod;
    }
    cout<<ans;
} 