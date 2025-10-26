#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i=0;i<t;i++){
        int n, k; cin >> n >> k;
        int ans = 0;
        vector<int>t(n);
        for(int j=0;j<n;j++)cin>>t[j];
        vector<pair<pair<int,int>,int>>env(k);
        for(int j=0;j<k;j++)cin>>env[j].first.first>>env[j].first.second>>env[j].second;
        sort(t.begin(), t.end());
        sort(env.begin(), env.end());
        for(auto j:env){
            j.second=upper_bound(t.begin(),t.end(),j.first.second)-lower_bound(t.begin(),t.end(),j.first.first)-j.second;
        }
    }
}  