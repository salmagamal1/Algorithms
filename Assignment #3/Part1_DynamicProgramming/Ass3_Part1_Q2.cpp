// Created By : Aya Ehab Ramadan 20221209
//Date: 12/29/2024

#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 +7;


// Question 2:
/**
 * Our friends at TXT have a bug-ridden message sender.
Specifically, this sender can send a string s to TXT or others, but if the character “w”
is entered, it will send “uu” instead of “w”, and if the character “m” is entered, it will
send “nn” instead of “m”.
That day TXT received a message from his friend, and he knew the message was
wrong.
Now please can you help TXT calculate the number of the possibilities of the original
string s
Input
The input consists of a line containing a string s contains only lowercase Latin
letters. (1 ≤ | s | ≤ 10^5)
Output
Print an integer - the original string s number of possibilities, modulo 10^9+7.
 * */
// Understanding the problem:
// - We have a string s that contains only lowercase Latin letters.
// - We need to calculate the number of possibilities of the original string s.
// - If the character “w” is entered, it will send “uu” instead of “w”.
// - If the character “m” is entered, it will send “nn” instead of “m”.

//--------------------------------------------------------------------------------------------
// we will use dynamic programming to solve this problem
//Dynamic Programming (DP) is used here because:
//We can calculate the number of valid strings for each part of s based on smaller parts.
//We use a dp array:
//dp[i] = number of ways to decode the string up to index i.
// Base Case if the string is empty, there is only one way to decode it.
//dp[0] = 1

// Case 1: Treat the current character normally:
//If it’s valid (not 'w' or 'm'), carry over the value from dp[i-1].
//Case 2: Check for special pairs 'uu' or 'nn':
//If s[i-1] and s[i-2] form 'uu' or 'nn', add the value of dp[i-2] (we combine them as one original character).
//If 'm' or 'w' is found, the string is invalid, and the result is 0.

// Modulo Arithmetic
//To avoid large numbers, every calculation is taken modulo 10^9+7.

//dp[i] represents the number of
//valid original strings that
//can match the first i characters
// of the input string s.

//example: s = "ouuoharinn"
//base case: dp[0] = 1 ->For an empty string (length 0), there's exactly 1 valid way to decode it.
//for each character in the string
// we calculate dp[i] based on
// If it’s a valid character ('a' to 'z' but not 'm' or 'w'),
// we add the result from the previous step:
//dp[i] = dp[i - 1].
//If it’s part of a valid pair ('uu' or 'nn'),
// we also add the result from two steps back:
//dp[i] += dp[i - 2].

//Why Use dp[i - 1] and dp[i - 2]?
//dp[i - 1]: To include valid single characters.
//dp[i - 2]: To include valid pairs (uu or nn).


int countPossibilies (string s){
  int stringLength = s.length();
  vector<int> DP(stringLength + 1, 0);
  DP[0] = 1; // base case
  for (int i = 1; i<=stringLength ; i++){
    // Case 1: add one single valid character
    DP[i] = DP[i - 1]; // here we add the result from the previous step
    // Case 2: add a valid pair
    if (i>1&& ((s[i-1] =='u'&& s[i-2]=='u')||(s[i-1] =='n'&& s[i-2]=='n'))){
      DP[i] += DP[i-2]; // here we add the result from two steps back
      // why dp[i-2]?
        // dp[i-1] to include valid single characters
        // dp[i-2] to include valid pairs (uu or nn)
        // we add the result from two steps back
        // to avoid large numbers
      DP[i] %= Mod;
    }
    // Case 3: invalid character
    if (s[i-1] == 'm' || s[i-1]=='w'){
        return 0;
    }
  }
  return DP[stringLength];
}
int main() {
  string s;
  while (cin>> s){
    cout<< countPossibilies(s)<< '\n';
  }

}
// s = "ouuoharinn":
//Step 1 ('o'):
//Valid single character → dp[1] = dp[0] = 1.
//Step 2 ('u'):
//Valid single character → dp[2] = dp[1] = 1.
//Step 3 ('u'):
//Forms 'uu' with the previous 'u' → Add dp[1] → dp[3] = dp[2] + dp[1] = 1 + 1 = 2.
