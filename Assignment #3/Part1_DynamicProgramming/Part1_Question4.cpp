/*
*Author:Salma Gamal^_^
 *Date:12/29/2024
 *Problem:Diving for Gold
 *Link:https://vjudge.net/problem/UVA-990
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
#define START  ios::sync_with_stdio(false); cin.tie(nullptr);
#define MAX_N 31 // Max number of Treasures
#define MAX_T  1001 // Max time.break
# define  MAX_W = 101  // Maximum diving time per unit depth

int a[MAX_N + 1][2];      // Array to store treasures (depth and gold)
int dp[MAX_N][MAX_T];     //dp array

void clear() {
    // Initialize dp table with zeros
    memset(dp, 0, sizeof(dp));
}

void solve(int t,int w,int n) {
    vector<int>v;
    for (int i = 1; i <= n; i++) {
        // Calculate the total required time for diving to the treasure and ascending back.
        // required_time = (time to descend) + (time to ascend)
        // Time to descend = a[i][0](depth) * w
        // Time to ascend = 2 * a[i][0] * w
        int req_time = (a[i][0] * w) + (a[i][0] * 2 * w);
        for(int j=0;j<=t;j++) {
            if(j>=req_time) dp[i][j] = max(dp[i-1][j], a[i][1] + dp[i-1][j-req_time]);
            else   dp[i][j] = dp[i-1][j];
        }

    }
    // Print the maximum gold that can be collected
    cout << dp[n][t] << endl;

    // Backtracking to find the treasures that were taken
    while (n > 0) {
        int req_time = (a[n][0] * w) + (a[n][0] * 2 * w);

        // If the current treasure was taken, record it
        if (dp[n][t] != dp[n - 1][t]) {
            v.push_back(n);
            t -= req_time;
        }
        n--;
    }


    // Print the number of treasures taken
    cout << v.size() << endl;
    // Print each selected treasure's depth and gold
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << a[v[i]][0] << " " << a[v[i]][1] << endl;
    }
}


int main() {
    int t,w,n;
    bool newLine=false;
    while (cin >> t >> w >> n) {
        clear();
        // Read the treasure data (depth, gold)
        for (int i = 1; i <= n; i++) {
            cin >> a[i][0] >> a[i][1];
        }

        // Print a new line between test cases
        if (newLine) {
            cout << endl;
        }
        solve(t, w, n);
        newLine = true;
    }
}

/*
//Input
210 4
3
10 5
10 1
7 2
*/
/*
//Output
7
2
10 5
7 2
*/
