//
// Created by Malak on 12/28/2024.
//

#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;


int main() {
    fast
   char c='9';

    vector<char> v;
    int f[26]={0};

    int n;
    cin>>c;
    while(c!=']'){
        cin>>c;
        if(c!='"'&&c!=','&&c!=']'){
            v.push_back(c);
        }
    }
    cin>>n;


    int freq[26]={0};
    int maxi=0, max_count=0;
    for(auto a:v){
        freq[a-'A']++;
    }
    for(int i=0 ; i<26; i++){
        if(maxi==freq[i]) max_count++;
        else if(maxi<freq[i]) {
            maxi=freq[i];
            max_count=1;
        }
    }
    int partcount= maxi-1;
    int empty = partcount*(n-(max_count-1));
    int avail = v.size()-(maxi*max_count);
    int idles = max(0, empty-avail);
    cout<<v.size()+idles;


}
// = ["A","A","A","B","B","B"] 2
//   ["A","C","A","B","D","B"] 1
//   ["A","A","A", "B","B","B"] 3
