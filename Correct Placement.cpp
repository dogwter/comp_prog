#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    for(int i=0;i<t;i++){
        int n; cin >> n;
        vector<tuple<int,int,int>>f;
        vector<int>ans(n);
        for(int j=1,a,b;j<=n;j++){
            ans[j-1]=-1;
            cin>>a>>b;
            if(a>b)swap(a,b);
            f.push_back({a,b,j});
        }
        sort(f.begin(), f.end(), [](auto &a, auto &b){if(get<0>(a)!=get<0>(b))return get<0>(a)>get<0>(b); else return get<1>(a)>get<1>(b);});
        vector<pair<int,int>>m_w(n);
        int idx = n-1;
        for(int j=n-1;j>=0;j--){
            if(get<1>(f[j])<get<1>(f[idx]))idx=j;
            m_w[j].first = get<1>(f[idx]);
            m_w[j].second = get<2>(f[idx]);
        }
        idx=0;
        for(int j=0;j<n;j++){
            while(idx<n && get<0>(f[idx])>=get<0>(f[j]))idx++;
            if(idx!=n){
                if(m_w[idx].first<get<1>(f[j]))ans[get<2>(f[j])-1]=m_w[idx].second;
            }
        }
        for(auto j:ans)cout<<j<<" ";
        cout<<"\n";
    }
} 