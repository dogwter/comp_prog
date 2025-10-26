#include <bits/stdc++.h>
using namespace std;

int cows[2501][2501];
long long ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>>c;
    for(int i=0,a,b;i<n;i++){
        cin>>a>>b; c.push_back({a,b});
    }
    sort(c.begin(),c.end());
    for(int i=0;i<n;i++)c[i].first=i+1;
    sort(c.begin(),c.end(), [](auto a, auto b){return a.second < b.second;});
    for(int i=0;i<n;i++)c[i].second=i+1;
    sort(c.begin(),c.end());
    for(auto i:c)cows[i.first][i.second]++;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cows[i][j]+=cows[i-1][j]+cows[i][j-1]-cows[i-1][j-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            long long hi = cows[j][n]-cows[j][max(c[i-1].second,c[j-1].second)]-cows[i-1][n]+cows[i-1][max(c[i-1].second,c[j-1].second)]+1;
            long long lo = cows[j][min(c[i-1].second,c[j-1].second)-1]-cows[i-1][min(c[i-1].second,c[j-1].second)-1]+1;
            ans+=hi*lo;
        }
    }
    ans+=n+1;
    cout<<ans;
}
