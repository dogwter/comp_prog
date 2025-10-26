#include <bits/stdc++.h>
using namespace std;

vector<int>cities; 
vector<int>towers;
vector<int>dis;
int n, m;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0,j;i<n;i++){
        cin>>j; cities.push_back(j);
        dis.push_back(-1);
    }
    for(int i=0,j;i<m;i++){
        cin>>j; towers.push_back(j);
    }
    int c=0;
    for(int i=0;i<m;i++){
        while(c<n && cities[c]<=towers[i]){
            dis[c] = abs(cities[c]-towers[i]);
            c++;
        }
    }
    c=n-1;
    for(int i=m-1;i>=0;i--){
        while(c>=0 && cities[c]>=towers[i]){
            if(dis[c]<0)dis[c] = abs(cities[c]-towers[i]);
            else dis[c] = min(dis[c],abs(cities[c]-towers[i]));
            c--;
        }
    }
    c = dis[0];
    for(auto i:dis)if(i>c)c=i;
    cout<<c;
}
