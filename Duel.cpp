#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<int>atk,def;
    vector<pair<int,int>>c(m);
    for(int i=0,j;i<n;i++){
        string s; 
        cin>>s>>j;
        if(s=="ATK")atk.push_back(j);
        else def.push_back(j);
    }
    for(int i=0;i<m;i++) cin>>c[i].first;
    sort(c.begin(),c.end());
    sort(atk.begin(),atk.end());
    sort(def.begin(),def.end());
    int ans = 0, temp = -1, idx = 0;
    for(int i=0;i<min(m,(int)atk.size());i++){
        if(c[m-i-1].first>=atk[i])ans+=c[m-i-1].first-atk[i];
        else break;
    }
    if(m>n){
        for(int i=0;i<def.size();i++){
            while(idx<m&&c[idx].first<=def[i])idx++;
            if(idx==m){
                temp=0; break; //cant kill all def
            }
            c[idx].second = 1;
            idx++;
        }
        if(temp!=0){ // all def done, check if can atk all
            temp = 0, idx = 0;
            for(int i=0;i<atk.size();i++){
                while(idx<m&&(c[idx].second==1||c[idx].first<atk[i]))idx++;
                if(idx == m){
                    temp = -1;
                    break;
                } else {
                    temp += c[idx].first-atk[i];
                    c[idx].second = 1;
                }
            }
            if(temp!=-1) for(int i=0;i<m;i++)if(c[i].second!=1)temp+=c[i].first;
        }
        ans = max(ans,temp);
    }
    cout<<ans;
} 