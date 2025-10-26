#include <bits/stdc++.h>
using namespace std;

bool field(vector<pair<int,int>>&c, int m){
    //something that is O(n)
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>>c(n);
    for(int i=0;i<n;i++)cin>>c[i].first>>c[i].second;
    sort(c.begin(),c.end());
    
    int idx =0, j=c[0].first;
    c[0].first=0;
    for(int i=1;i<n;i++){
        if(c[i].first==j){
            j=c[i].first; c[i].first=idx;
        } else {
            j=c[i].first; idx++; c[i].first=idx;
        }
    }
    sort(c.begin(),c.end(),[](auto a, auto b){return a.second<b.second;});
    idx=0, j=c[0].second;
    c[0].second=0;
    for(int i=1;i<n;i++){
        if(c[i].second==j){
            j=c[i].second; c[i].second=idx;
        } else {
            j=c[i].second; idx++; c[i].second=idx;
        }
    }
    sort(c.begin(),c.end());

    int l = (n+3)/4, h = n;
    while(l<=h){
        if(field(c,(l+h)/2)) h = (l+h)/2-1;
        else l = (l+h)/2+1;
    }
}