#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int>cards(2*n+1);
    vector<int>h(n/2);
    vector<int>l(n/2);
    vector<int>b;
    for(int i=0,a;i<n;i++){
        cin>>a;
        cards[a]++;
        if(i<n/2)h[i%(n/2)]=a;
        else l[i%(n/2)]=a;
    }
    sort(h.begin(),h.end());
    sort(l.begin(),l.end());
    int ans = 0;
    for(int i=1;i<=2*n;i++)if(cards[i]!=1)b.push_back(i);
    int idx = n/2-1; //low card checking
    for(int i=n/2-1;i>=0;i--){
        while(b[idx]>l[i] && idx>0) idx--;
        if(b[idx]<l[i]){
            ans++; idx--;
        }
        if(idx<0)break;
    }
    idx = n/2; // high card checking
    for(int i=0;i<n/2;i++){
        while(b[idx]<h[i] && idx<n-1) idx++;
        if(b[idx]>h[i]){
            ans++; idx++;
        }
        if(idx>n-1)break;
    }
    cout<<ans;
} 