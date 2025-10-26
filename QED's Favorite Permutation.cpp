#include <bits/stdc++.h>
using namespace std;

int bad[200002];
int arr[200001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int t, n, q; cin>>t;
    for(int k=0;k<t;k++){
        cin>>n>>q;
        for(int i=1;i<=n;i++) bad[i]=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            bad[min(i,arr[i])+1]++;
            bad[max(i,arr[i])+1]--;
        }
        for(int i=1;i<=n;i++) bad[i]+=bad[i-1];
        set<int>blocked;
        string str; cin >> str;
        for(int i=2;i<=n;i++) if(str[i-1]=='R'&&str[i-2]=='L'&&bad[i]>0)blocked.insert(i);
        for(int i=0,j;i<q;i++){
            cin>>j;
            if(str[j-1]=='L'){
                if(j>1&&str[j-2]=='L'&&bad[j]>0)blocked.insert(j);
                if(j<n&&str[j]=='R'&&bad[j+1]>0)blocked.erase(j+1);
                str[j-1]='R';
            }else{
                if(j>1&&str[j-2]=='L'&&bad[j]>0)blocked.erase(j);
                if(j<n&&str[j]=='R'&&bad[j+1]>0)blocked.insert(j+1);
                str[j-1]='L';
            }
            if(blocked.empty())cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
