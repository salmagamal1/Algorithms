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
    int n;
    cin>>c;
    while(c!=']'){
        cin>>c;
        if(c!='"'&&c!=','&&c!=']'){
            v.push_back(c);
        }
    }
    cin>>n;
    string result(n,'9');
    while(!v.empty()){
        int i=0;
        string sub=result.substr(result.size()-n,n);
        while(sub.find(v[i])<n){
            i++;
        }
        if(i>=v.size()) result+='1';
        else{
            result+=v[i];
            v.erase(v.begin()+i);
        }
    }
   for(int i=n ; i<result.size()-1;i++){
       if(result[i]=='1')cout<<"idle";
       else cout<<result[i];
       cout<<"->";
   }cout<<result[result.size()-1];

}
// = ["A","A","A","B","B","B"] 2
//   ["A","C","A","B","D","B"] 1
//   ["A","A","A", "B","B","B"] 3
