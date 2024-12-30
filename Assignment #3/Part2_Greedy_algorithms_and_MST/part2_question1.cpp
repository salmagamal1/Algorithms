//
// Created by Malak on 12/28/2024.
//

#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
int maxChildren(vector<int>&greed, vector<int>&cookie){
    int i=0, j=0 , result=0;
    sort(greed.begin(), greed.end());
    sort(cookie.begin(),cookie.end());
    while(i<greed.size()&&j<cookie.size()){
        if(greed[i]<=cookie[j]) {
            result++;
            i++;
            j++;
        }else j++;
    }
return result;
}
int main() {
    vector<int> greed = {9,9,4,9};
    vector<int> cookie = { 6, 5, 10, 1 ,7 ,7, 5, 5};

    cout << maxChildren(greed, cookie);
}
// = ["A","A","A","B","B","B"] 2
//   ["A","C","A","B","D","B"] 1
//   ["A","A","A", "B","B","B"] 3
