#include <bits/stdc++.h>
using namespace std;

int canvas[1001][1001];
int layers[1002][1002];
vector<pair<int,int>>topl(1000000);
vector<pair<int,int>>botr(1000000);
set<int>c;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<bool>ok;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ok.push_back(true);
            cin>>canvas[i][j];
            if(canvas[i][j]>0){
                c.insert(canvas[i][j]);
                if(topl[canvas[i][j]-1].first==0){
                    topl[canvas[i][j]-1]={i,j};
                    botr[canvas[i][j]-1]={i+1,j+1};
                } else{ 
                    topl[canvas[i][j]-1]={min(i,topl[canvas[i][j]-1].first),min(j,topl[canvas[i][j]-1].second)};
                    botr[canvas[i][j]-1]={max(i+1,botr[canvas[i][j]-1].first), max(j+1,botr[canvas[i][j]-1].second)};
                }
            }
        }
    }
    if(c.size()==1) cout << n*n-1;
    else{
        for(int i=0;i<n*n;i++){
            layers[topl[i].first][topl[i].second]++;
            layers[topl[i].first][botr[i].second]--;
            layers[botr[i].first][topl[i].second]--;
            layers[botr[i].first][botr[i].second]++;
        }
        //edge case: if only 1 color is visible then its n^2-1
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                layers[i][j]+=layers[i-1][j]+layers[i][j-1]-layers[i-1][j-1];
                if(layers[i][j]>1&&canvas[i][j]>0)ok[canvas[i][j]-1]=false;
            }
        }
        int ans =0;
        for(auto x:ok)if(x)ans++;
        cout<<ans;
    }
}
