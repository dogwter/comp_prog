#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
    map<string,int>cows;
    int p[201];
    for(int i=1;i<201;i++)p[i]=i;
    int idx = 3;
    string cow1, cow2;
    cin>>cow1>>cow2;
    cows[cow1]=1; cows[cow2]=2;
    for(int i=0;i<n;i++){
        string s1, s2; cin>>s1>>s2;
        if(cows[s1]==0) {cows[s1] = idx; idx++;}
        if(cows[s2]==0) {cows[s2] = idx; idx++;}
        p[cows[s2]]=cows[s1];
    }
    int dis1[201], dis2[201];
    for(int i=1;i<201;i++){
        dis1[i]=-1; dis2[i]=-1;
    }
    int p1=p[1]; int p2=p[2];
    queue<int>q;
    dis1[1]=0;
    q.push(1);
    while(!q.empty()){
        int e = q.front(); q.pop();
        p1=e;
        if(dis1[p[e]]==-1){
            dis1[p[e]]=dis1[e]+1;
            q.push(p[e]);
        }
    }
    dis2[2]=0;
    q.push(2);
    while(!q.empty()){
        int e = q.front(); q.pop();
        p2=e;
        if(dis2[p[e]]==-1){
            dis2[p[e]]=dis2[e]+1;
            q.push(p[e]);
        }
    }
    if(p1!=p2){cout<<"NOT RELATED"; return 0;}
    else{
        string ans;
        if(dis2[p2]>dis1[p1]){ //cow2 is younger
            swap(cow1,cow2);
            if(dis2[1]!=-1){
                if(dis2[1]==1)ans = "mother";
                else{
                    ans = "grand-mother";
                    for(int i=3;i<=dis2[1];i++)ans="great-"+ans;
                }
            }
            else if(dis2[p[1]]!=-1){
                if(dis2[p[1]]==1) {cout << "SIBLINGS"; return 0;}
                else{
                    ans = "aunt";
                    for(int i=3;i<=dis2[p[1]];i++)ans="great-"+ans;
                }
            }
            else {cout << "COUSINS"; return 0;}
        } else{
            if(dis1[2]!=-1){
                if(dis1[2]==1)ans = "mother";
                else{
                    ans = "grand-mother";
                    for(int i=3;i<=dis2[2];i++)ans="great-"+ans;
                }
            }
            else if(dis1[p[2]]!=-1){
                if(dis1[p[2]]==1) {cout << "SIBLINGS"; return 0;}
                else{
                    ans = "aunt";
                    for(int i=3;i<=dis1[p[2]];i++)ans="great-"+ans;
                }
            }
            else {cout << "COUSINS"; return 0;}
        }
        cout<<cow2<<" is the "<<ans<<" of "<<cow1;
    }
}
