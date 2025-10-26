#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>>c(n);
    for(int i=0;i<n;i++){
        cin>>c[i].first;
        c[i].second=i;
    }
    sort(c.begin(),c.end());
    int ans = 1;
    for(int i=0;i<n;i++){
        ans = max(ans, c[i].second-i+1);
    }
    cout<<ans;
} 