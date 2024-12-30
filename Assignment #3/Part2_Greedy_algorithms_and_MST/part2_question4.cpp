//#include <iostream>
//#include <vector>
//#include <climits>
//using namespace std;
//#define ll long long
//#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sets {
    vector<int> parent;
public:
    Sets(int v){
        parent.resize(v);
        for(int i=0 ;i<v ;i++){
            parent[i]=i;
        }
    }
    int find(int i){
        if(parent[i]==i) return i;
        else return find(parent[i]);
    }
    void unionf (int i, int j){
        int pi = find(i);
        int pj = find(j);
        parent[pi]=pj;
    }

};
class kruskal_graph{
    vector<vector<int>> vers;
    int costg=-1;
    int costs=-1;
    int edges;
public:
    kruskal_graph(vector<vector<int>>& vertcies,int edges) {
        this->vers=vertcies;
        this->edges=edges;

    }
    void play(){
        sort(vers.begin(),vers.end()); //sort based on the weight
        Sets s(edges+1);
        for(auto ver : vers){
            if(s.find(ver[3])!=s.find(ver[4])){
                s.unionf(ver[3],ver[4]);
                costg=max(costg,ver[1]);
                costs=max(costs,ver[2]);
            }
        }
    }
    int get_cost() const{
        if(costg==-1&&costs==-1) return -1;
        else return costg+costs;
    }

};

int main() {
    int n_city;
    int n_roads;
    int x,y,s,g,cs,cg;
    vector<vector<int>> roads;
    cin>>n_city>>n_roads;
    cin>>cg>>cs;
    while(n_roads--){
        cin>>x>>y>>g>>s;
        roads.push_back({(cg*g)+(cs*s),(cg*g),(cs*s),x,y});
    }
    kruskal_graph kg(roads,n_city);
    kg.play();
    cout<<kg.get_cost();

}
/*
3 3
2 1
1 2 10 15
1 2 4 20
1 3 5 1
 */