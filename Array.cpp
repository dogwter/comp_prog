#include <bits/stdc++.h>
using namespace std;

bool atiful(vector<long long>&v, long long y, long long a, int len){
    y-=a*len;
    if(v[len-1]<=y)return true;
    return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int>c(2e5);
    vector<vector<long long>>v(2e5);
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0, a;i<n;i++){
        cin>>a;
        v[a-1].push_back(c[i]);
        if(v[a-1].size()>1)v[a-1][v[a-1].size()-1]+=v[a-1][v[a-1].size()-2];
    }
    for(int i=0;i<n;i++)c[i]=0;
    int q,col; cin>>q;
    long long a = 0;
    for(int i=0,b;i<q;i++){
        cin>>b;
        if(b==1){
            cin>>col>>b;
            a+=b;
            c[col-1]+=b;
        } else {
            long long y; 
            cin>>col>>y;
            int lo = 1, hi = v[col-1].size(), mi = 0;
            while(lo<=hi){
                if(atiful(v[col-1],y,a-c[col-1],(lo+hi)/2)){
                    mi = (lo+hi)/2;
                    lo=(lo+hi)/2+1;
                }
                else hi=(lo+hi)/2-1;
            }
            cout<<mi<<"\n";
        }
    }
} 