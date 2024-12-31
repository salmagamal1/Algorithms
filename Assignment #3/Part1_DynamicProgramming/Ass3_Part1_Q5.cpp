#include <bits/stdc++.h>
using namespace std;

//Question 5 [10 Marks]
//Given a list of numbers A, find the length of the longest increasing subsequence in it.
//A subsequence is a sequence that can be derived from the given sequence by
//deleting zero or more elements without changing the order of the remaining
//        elements. An increasing subsequence is a subsequence in which each element is
//        greater than all previous elements.
//For example, in the list {33 , 11 , 22 , 44}:
//The subsequences {33 , 44} and {11} are increasing subsequences while {11 , 22 ,
//44} is the longest increasing subsequence.
//Input
//        First line contains a single integer N (1 <= N <= 10) the length of the list A.
//The second line contains N numbers (1 <= each number <= 20), the numbers in the
//list A separated by spaces.
//Output
//        One line containing the length of the longest increasing subsequence in A.
//Sample input
//5
//1 4 2 4 3
//Sample output
//3

//understanding the problem
//For example, from [1, 4, 2, 4, 3],
// possible subsequences are [1, 2, 4], [4, 3], [1, 4]
// Longest Increasing Subsequence (LIS)
//In [1, 4, 2, 4, 3], the LIS is [1, 2, 4] (length = 3).
//dp[i] is the length of the longest increasing subsequence ending at index i

//base case:
//each element is a valid subsequence of length 1
//dp[i]=1 initially for all i

// Recurrence relation:
// to calculate dp[i], we need to check all the elements before i
// check all previous indices j < i

int LIS (vector<int> & seq){
     int n = seq.size();
     vector<int> DP(n , 1);
     for (int i = 1 ; i<=n ; i++){
       for (int j=0; j<i ; j++){
         // can we extend the subsequence ending at j?
         if (seq[i] > seq[j]){
           //dp[i]: Represents the length of the longest
           // increasing subsequence (LIS) ending at index i.
           //dp[j] + 1: Represents the potential LIS length if we extend
           // the subsequence ending at index j by adding the element at index i.
           DP[i] = max(DP[i], DP[j]+1); //this means
           //we can extend the subsequence ending at j to include i
           //if it results in a longer subsequence
           // why to maximize between the current value of DP[i] and DP[j]+1?
         }
       }
     }
     return *max_element(DP.begin(), DP.end());
}
int main(){
  int n;
  cin>>n;
  vector<int> seq(n);
  for (int i=0; i<n; i++){
    cin>>seq[i];
  }
  cout << LIS(seq) << '\n';
}