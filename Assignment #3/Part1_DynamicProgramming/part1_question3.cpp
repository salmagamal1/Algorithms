//
// Created by Malak on 12/28/2024.
//

#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;


int main() {
    fast
    int c;
    cin>>c;
    while(c--){
        int cap , n;
        cin>>cap>>n;
        vector<pair<int,int>> wv;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;

            wv.emplace_back(x,y);
        }
        for(auto i : wv){cout<<i.first<<" "<<i.second<<"\n";}
        vector<vector<int>> arr(n + 1, vector<int>(cap + 1, 0));
        for(int i=1 ;i<=n ; i++){
            for(int j=1 ; j<=cap ; j++){
                if(wv[i-1].first<=j){
                    arr[i][j]=max(arr[i-1][j],arr[i-1][j-wv[i-1].first]+wv[i-1].second);
                }else{
                    arr[i][j]=arr[i-1][j];
                }
            }
        }
        cout<<"Hey stupid robber, you can get "<<arr[n][cap]<<" .\n";
    }
}
/*
3
 34 5
 178 12
 30 1
 13 7
 34 8
 87 6
 900 1
 900 25
 100 10
 27 16
 131 9
 132 17
 6 5
 6 23
 56 21
 100 25
 1 25
 25 25
 100 2
 */