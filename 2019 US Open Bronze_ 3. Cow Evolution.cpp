#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
    int idx=1,hg=-1;
    map<string,int> group;
    vector<vector<string>>cows(n);
    for(int i=0,j;i<n;i++){
        cin>>j;
        for(int k=0;k<j;k++){
            string s;
            cin >> s;
            cows[i].push_back(s);
        }
    }
    sort(cows.begin(),cows.end(),[](const auto& l, const auto& r)
    {
        return l.size()<r.size();
    });
    for(auto x:cows){
        hg=-1;
        for(auto y:x){
            if(group[y]!=0){
                if(hg!=-1&&group[y]!=hg){cout<<"no"; return 0;}
                hg=group[y];
            }
        }
        if(hg==-1)swap(hg,idx);
        for(auto y:x)group[y]=hg;
        if(idx==-1){
            swap(hg,idx);
            idx++;
        }
    }
    cout<<"yes";
}
