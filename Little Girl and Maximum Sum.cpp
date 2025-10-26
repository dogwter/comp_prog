#include <bits/stdc++.h>
using namespace std;

int freq[200001];
long long ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    vector<long long>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0,a,b;i<q;i++){
        cin>>a>>b;
        freq[a-1]++;
        freq[b]--;
    }
    for(int i=1;i<n;i++) freq[i]+=freq[i-1];
    sort(freq,freq+n,greater<int>());
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++)ans+=arr[n-1-i]*freq[i];
    cout<<ans;
}
