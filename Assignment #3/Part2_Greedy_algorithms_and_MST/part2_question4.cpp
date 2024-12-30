#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

struct edge {
    int x,y, g, s;
};
class Sets {
public:
    vector<int> parent, rank;
    int n;

    Sets(int v){
        this->n=v;

        parent.resize(v,-1);
        rank.resize(v,1);
    }
    int find(int i){
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool unionf(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rank[y] > rank[x]) swap(x, y);

        rank[x] += rank[y];
        parent[y] = x;

        n--;
        return true;


    }
    bool connected(){return n==1;}

};

int main(){
    //n -> cities -> vertex
    //m -> roads -> edges
    fast
    int n, m, G, S , max_g=INT_MAX, max_s=0;
    ll result=LLONG_MAX;
    cin >> n >> m >> G >> S;
    vector<edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].x >> edges[i].y >> edges[i].g >> edges[i].s;

    }
    sort(edges.begin(), edges.end(), [](const edge& e1, const edge& e2) {
        return e1.g < e2.g;
    });
    //1. sort your edges based on gold (vector edge)
    //2. put the lowest edge with gold in your sub tree (vector sub)
    //3. sort your subtree edges based on silver (note that all these edges satisfy condition g<max_g since we push the edge that
    //satisfy condition in it first before sorting)
    //4. make a disjoint sets to be used later in the last point
    // 5. loop over the edges in your sub tree edges ( that already satisfy condition g<max_g )
    // 6. try to connect your sub tree vertecies and update max_s
    //if your subtree contains all the vertecies aka(rank of root == n) then update result
    vector<edge> sub;
    for(auto e: edges){

        Sets s(n+1);
        sub.push_back(e);
        sort(sub.begin(), sub.end(), [](const edge& e1, const edge& e2) {
            return e1.s < e2.s;
        });

        vector <edge> clone;
        max_s=0 ;
        for(auto i:sub){
            if (s.unionf(i.x, i.y)) {
                clone.push_back(i);
                max_s=max(max_s,i.s);
                if(s.connected()) break;
            }
        }
        sub=clone; // if it in the clone that is mean it satisfies the 2 constions
       int tr=s.rank[s.find(1)];
        if(tr==n){
            result=min(result,1LL*S*max_s+1LL*G*e.g);
        }



    }
    if(result==LLONG_MAX) cout<<-1;
    else cout<<result;

    return 0;
}
