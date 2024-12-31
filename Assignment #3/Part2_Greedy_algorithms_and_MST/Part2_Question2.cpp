/*
*Author:Salma Gamal^_^
 *Date:12/30/2024
 *Problem:Task Scheduler
 *Link:https://leetcode.com/problems/task-scheduler/description/
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define START  ios::sync_with_stdio(false); cin.tie(nullptr);

int leastInterval(vector<int>tasks,int n) {
    // Create a frequency array to count the number of occurrences of each task (A-Z)
    vector<int> fq(26, 0);

    for (char task:tasks)  fq[task-'A']++;
    sort(fq.begin(), fq.end());

    // Calculate the number of groups needed for the most frequent task
    int group=fq[25]-1;
    int idle=group*n; // Calculate how many empty spots we need to fill between these groups

    for(int i=24;i>=0;i--) idle-=min(fq[i],group);

    return idle < 0 ? tasks.size() : idle + tasks.size();
}


int main() {

    START;
    // Example 1
    vector<int> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << "Output: " << leastInterval(tasks1, 2) << endl; // Output: 8

    // Example 2
    vector<int> tasks2 = {'A', 'C', 'A', 'B', 'D', 'B'};
    cout << "Output: " << leastInterval(tasks2, 1) << endl; // Output: 6

    // Example 3
    vector<int> tasks3 = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << "Output: " << leastInterval(tasks3, 3) << endl; // Output: 10

    return 0;
}
