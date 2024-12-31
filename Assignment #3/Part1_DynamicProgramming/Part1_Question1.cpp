/*
*Author:Salma Gamal^_^
 *Date:12/29/2024
 *Problem:Dividing coins
 *Link:https://vjudge.net/problem/UVA-562
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
#define START  ios::sync_with_stdio(false); cin.tie(nullptr);
#define MAX_M 101 // Max number of coins (m ≤ 100)
#define MAX_SUM 50001  // Max sum of coin values (1 ≤ value ≤ 500, max total sum = 100 * 500 = 50000)
int m;
int a[MAX_M];
int dp[MAX_M][MAX_SUM];
int TotalSum;

int solve(int idx , int cur_sum)
 {
  //Base case
  if(idx == m) return abs(cur_sum -(TotalSum - cur_sum));
  //checking
  if(dp[idx][cur_sum] != -1) return dp[idx][cur_sum];
 return dp[idx][cur_sum] = min(solve(idx + 1, cur_sum), solve(idx + 1, cur_sum + a[idx]));

  }
  void clear()
  {
      TotalSum = 0;
      // memset(dp, -1, sizeof(dp));
  }



int main() {
    START;
    int t;
    cin>>t;
    while(t--)
    {
      clear();
      cin>>m;
      for(int i = 0; i < m; i++)
      {
         cin>>a[i];
         TotalSum += a[i];
      }
         cout<<solve(0,0)<<endl;
    }


      return 0;
}

/*
//Input
2
3
2 3 5
4
1 2 4 6
*/
/*
//Output
0
1
*/
