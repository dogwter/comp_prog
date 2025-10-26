#include <bits/stdc++.h>
using namespace std;

bool det(vector<int>&h,vector<int>&l, vector<int>&r, int d){
    int a = upper_bound(r.begin(),r.end(),d)-r.begin()-1;
    int b = upper_bound(h.begin(),h.end(),h[a]+2*d)-h.begin()-1;
    if(l[b]>d)return false;
    else return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int>hay(n);
    vector<int>f_r(n);
    vector<int>f_l(n);
    for(int i=0;i<n;i++){
        cin>>hay[i];
        hay[i]*=2;
    }
    sort(hay.begin(), hay.end());
    f_r[0]=2; f_r[1]=hay[1]-hay[0]+2;
    f_l[n-1]=2; f_l[n-2]=hay[n-1]-hay[n-2]+2;
    int cur = 1;
    for(int i=2;i<n;i++){
        if(hay[i]<=hay[cur]+f_r[cur]+2)f_r[i]=f_r[cur]+2;
        else{
            if(hay[i]-hay[i-1]+2>f_r[i-1]+2){
                f_r[i]=hay[i]-hay[i-1]+2;
                cur=i;
            } else {
                f_r[i]=f_r[i-1]+2;
                cur = i-1;
            }
        }
    }
    cur=n-2;
    for(int i=n-3;i>=0;i--){
        if(hay[i]>=hay[cur]-f_l[cur]-2)f_l[i]=f_l[cur]+2;
        else{
            if(hay[i+1]-hay[i]+2>f_l[i+1]+2){
                f_l[i]=hay[i+1]-hay[i]+2;
                cur=i;
            } else {
                f_l[i]=f_l[i+1]+2;
                cur = i+1;
            }
        }
    }
    if(n==2) cout<<fixed<<setprecision(1)<<(hay[1]-hay[0])/4.0;
    else{
        int lo = 1, hi = max(f_r[n-1],f_l[1]);
        while(lo<=hi){
            if(det(hay,f_l,f_r,(lo+hi)/2))hi=(lo+hi)/2-1;
            else lo=(lo+hi)/2+1;
        }
        cout<<fixed<<setprecision(1)<<lo/2.0;
    }
}