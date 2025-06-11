#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, n, x;
    cin>>k>>n;
    for(int i=0;i<n;i++){
        cin >> x;
        int s = 1;
        int dis = k;
        int time = 0;
        while(dis>0){
            dis-=s;
            time++;
            if(dis<=0)break;
            if(s>=x){
                dis-=s;
                time++;
            }
            s++;
        }
        cout << time << "\n";
    }
}
