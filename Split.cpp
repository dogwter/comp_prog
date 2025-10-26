#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pair<long long, long long>>cow(n);
    long long x1=0,x2=0,y1=0,y2=0;
    for(int i=0;i<n;i++){
        cin>>cow[i].first>>cow[i].second;
        if(x1==0)x1=cow[i].first;
        else x1 = min(x1,cow[i].first);
        x2=max(x2,cow[i].first);
        if(y1==0)y1=cow[i].second;
        else y1 = min(y1,cow[i].second);
        y2=max(y2,cow[i].second);
    }
    long long area = (x2-x1)*(y2-y1);
    vector<long long>f(n);
    vector<long long>b(n);
    sort(cow.begin(), cow.end());
    f[0]=0; y1=cow[0].second, y2=cow[0].second;
    for(int i=1;i<n;i++){
        y1 = min(y1,cow[i].second);
        y2 = max(y2,cow[i].second);
        f[i] = y2-y1;
    }
    b[n-1]=0; y1=cow[n-1].second, y2=cow[n-1].second;
    for(int i=n-2;i>=0;i--){
        y1 = min(y1,cow[i].second);
        y2 = max(y2,cow[i].second);
        b[i] = y2-y1;
    }
    long long ba = (cow[n-1].first-cow[1].first)*b[1];
    for(int i=1;i<n-1;i++){
        if(cow[i].first!=cow[i+1].first){
            ba=min(ba,(cow[i].first-cow[0].first)*f[i]+(cow[n-1].first-cow[i+1].first)*b[i+1]);
        }
    }
    sort(cow.begin(), cow.end(), [](auto a, auto b){return a.second<b.second;});
    f[0]=0; y1=cow[0].first, y2=cow[0].first;
    for(int i=1;i<n;i++){
        y1 = min(y1,cow[i].first);
        y2 = max(y2,cow[i].first);
        f[i] = y2-y1;
    }
    b[n-1]=0; y1=cow[n-1].first, y2=cow[n-1].first;
    for(int i=n-2;i>=0;i--){
        y1 = min(y1,cow[i].first);
        y2 = max(y2,cow[i].first);
        b[i] = y2-y1;
    }
    for(int i=1;i<n-1;i++){
        if(cow[i].second!=cow[i+1].second){
            ba=min(ba,(cow[i].second-cow[0].second)*f[i]+(cow[n-1].second-cow[i+1].second)*b[i+1]);
        }
    }
    cout<<area-ba;
}