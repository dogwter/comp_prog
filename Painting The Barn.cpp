#include <bits/stdc++.h>
using namespace std;

int barn[1001][1001];
int ans = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    for(auto i:barn){
        for(int j=0;j<1001;j++) i[j]=0;
    }
    for(int i=0,x1,y,x2,y2;i<n;i++){
        cin>>x1>>y>>x2>>y2;
        barn[x1][y]++;
        barn[x2][y2]++;
        barn[x1][y2]--;
        barn[x2][y]--;
    }
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            if(i>0)barn[i][j]+=barn[i-1][j];
            if(j>0)barn[i][j]+=barn[i][j-1];
            if(i>0&&j>0)barn[i][j]-=barn[i-1][j-1];
            if(barn[i][j]==k)ans++;
        }
    }
    cout<<ans<<"\n";
}
