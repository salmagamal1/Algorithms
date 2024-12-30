/*
 *Author:Salma Gamal^_^
 *Date:12/30/2024
 *Problem:Roads in HackerLand
 *Link:https://www.hackerrank.com/challenges/johnland/problem
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define START  ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define pt pair<int, int>
const int N =100100;

struct DSU {
    int size;          // Total number of elements
    vector<int> p;     // Parent array
    vector<int> w;     // Weight array (size of each set)

    DSU(int n) : size(n), p(n, -1), w(n, 1) {}

    int Find(int x) {
        if (p[x] == -1) // If x is the root
            return x;
        return p[x] = Find(p[x]); // Path compression
    }


    void Union(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (u != v) { // If they are in different components
            if (w[u] < w[v]) swap(u, v); // Union by size
            p[v] = u;      // Merge v's component into u's
            w[u] += w[v];  // Update size of u's component
        }
    }
};

vector<pt> g[N];
vector<pt> tree[N];
ll total;
int subt[N];
vector<ll> ans;



int Dfs(int v, int prev, int w) {
    subt[v] = 1;
    for (pt &e : tree[v]) {
        if (e.first == prev)
            continue;
        subt[v] += Dfs(e.first, v, e.second);
    }
    if (w >= 0) {
        ll used = (total - subt[v]) * subt[v];
        while (w >= ans.size()) {
            ans.push_back(0);
        }
        ans[w] += used;
    }
    return subt[v];
}
int main() {
    int n, m;
    cin >> n >> m;
    total = n;
    vector<pair<int, pt>> edges;
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        --x, --y;
        edges.push_back({w, {x, y}});
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    for (auto &e : edges) {
        int x = e.second.first;
        int y = e.second.second;
        int u = dsu.Find(x);
        int v = dsu.Find(y);
        if (u != v) {
            tree[x].push_back({y, e.first});
            tree[y].push_back({x, e.first});
            dsu.Union(u, v);
        }
    }

    Dfs(0, -1, -1);

    ll r = 0;
    for (int i = 0; i < ans.size() || r; ++i) {
        while (i >= ans.size()) {
            ans.push_back(0);
        }
        r += ans[i];
        ans[i] = r & 1;
        r >>= 1;
    }

    bool started = false;
    for (int i = ans.size() - 1; i >= 0; --i) {
        bool on = ans[i] > 0;
        if (on) started = true;
        if (started) {
            cout << (on ? '1' : '0');
        }
    }
    if (!started) {
        cout << "0";
    }
    cout << endl;

    return 0;
}
//Sample Input
/*
5 6
1 3 5
4 5 0
2 1 3
3 2 1
4 3 4
4 2 2
*/
//Sample Output
/*
 1000100
 */