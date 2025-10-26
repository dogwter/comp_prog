#include <bits/stdc++.h>
using namespace std;

int search(vector<vector<int>>c, int x){
    int ans = 0;
    bool r[c.size()];
    for(int i=0;i<c.size();i++)r[i]=false;
    queue<int>q;
    q.push(x);
    while(!q.empty()){
        int e = q.front(); q.pop();
        for(auto i:c[e]){
            if(!r[i]){
                ans++;
                r[i]=true;
                q.push(i);
            }
        }
    }
    return ans;
}

bool ok(int a[],int b[]){
    return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1])<=a[2]*a[2];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<vector<int>>c(n);
    int cow[200][3];
    for(int i=0;i<n;i++)cin>>cow[i][0]>>cow[i][1]>>cow[i][2];
    for(int i=0;i<n;i++){
        c[i].push_back(i);
        for(int j=i+1;j<n;j++){
            if(ok(cow[i],cow[j])) c[i].push_back(j);
            if(ok(cow[j],cow[i])) c[j].push_back(i);
        }
    }
    int b = 0;
    for(int i=0;i<n;i++){
        b=max(b,search(c,i));
    }
    cout<<b;
}