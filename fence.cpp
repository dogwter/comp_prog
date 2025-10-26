#include <bits/stdc++.h>
using namespace std;

void merge(int a, int b, auto& c){
    if(get<0>(c[a])==a) swap(a,b);
    get<0>(c[a])=get<0>(c[b]);
    get<1>(c[b])=max(get<1>(c[a]),get<1>(c[b]));
    get<2>(c[b])=max(get<2>(c[a]),get<2>(c[b]));
    get<3>(c[b])=min(get<3>(c[a]),get<3>(c[b]));
    get<4>(c[b])=min(get<4>(c[a]),get<4>(c[b]));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    vector<tuple<int,int,int,int,int>>p(n);
    for(int i=0;i<n;i++){
        cin>>get<1>(p[i])>>get<2>(p[i]);
        get<3>(p[i])=get<1>(p[i]);
        get<4>(p[i])=get<2>(p[i]);
        get<0>(p[i])=i;
    }
    for(int j=0;j<m;j++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        merge(get<0>(p[a]),get<0>(p[b]),p);
    }
    int ans=-1;
    for(int i=0;i<n;i++){
        if(get<0>(p[i])==i){
            if(ans==-1) ans = 2*((get<1>(p[i])-get<3>(p[i]))+(get<2>(p[i])-get<4>(p[i])));
            else ans = min (ans,2*((get<1>(p[i])-get<3>(p[i]))+(get<2>(p[i])-get<4>(p[i]))));
        }
    }
    cout<<ans;
}