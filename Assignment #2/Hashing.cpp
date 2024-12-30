#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <utility>
#define ll unsigned long long
using namespace std;
enum state{
    deleted=-1,
    empty=0,
    occupied=1
};


void show_menu(){
    cout << "Choose an operation:\n";
    cout << "1. Add\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. Print\n";
    cout << "5. Exit\n";
}

struct node{
    int value;
    node* next;
    node(): value(-1),next(nullptr){}
};
class hashing {
public:
    virtual ~hashing() = default;
    virtual void add(int x)=0;
    virtual ll search(int x)=0;
    virtual void delete_x(int x)=0;
    virtual void print()=0;
};


class division_method : public hashing {
private:
    vector<int> v;
public:
    explicit division_method(int size) : v(size, -1) {}

    void add(int x) override{
        if(v[x%v.size()]==-1) v[x%v.size()]=x;
        else cout<<"collision happened\n";
    }
    ll search(int x) override{
        if(v[x%v.size()]!=-1) { cout << "found at index " << x % v.size() << '\n';
            return x%v.size();}
        else cout<<"not found\n";
        return -1;

    }
    void delete_x(int x) override{
        if(v[x%v.size()]!=x) cout<<"not found\n";
        else v[x%v.size()]=-1;
    }
    void print() override{
        for(int i=0;i<v.size();i++){
            cout<<i<<" : ";
            v[i]==-1? cout<<"empty" : cout<<v[i];
            cout<<"\n";
        }
    }

};

//multipliacation method is h(K) = n* floor(ka mod 1)
class multiplication_method :public hashing{
private:
    vector<int> v;
    double a = 0.618033;
public:
    explicit multiplication_method(int size) : v(size, -1) {}
    void add(int x) override{
        int pos = floor(v.size() * fmod(x * a, 1.0));
        if(v[pos]==-1) v[pos]=x;
        else cout<<"collisioni happened\n";
    }
    ll search(int x) override{
        int pos = floor(v.size() * fmod(x * a, 1.0));
        if(v[pos]!=-1) { cout << "found at index " << pos << '\n'; return pos; }
        else cout<<"not found\n";
        return -1;

    }
    void delete_x(int x) override{
        int pos = floor(v.size() * fmod(x * a, 1.0));
        if(v[pos]!=x) cout<<"not found\n";
        else v[pos]=-1;
    }
    void print() override{
        for(int i=0;i<v.size();i++){
            cout<<i<<" : ";
            v[i]==-1? cout<<"empty" : cout<<v[i];
            cout<<"\n";
        }
    }

};
//mid square method is squaring the key and then take the mid-part of it mod size
class mid_method: public hashing {
private:
    vector<int> v;
public:
    explicit mid_method(int size) : v(size, -1) {}
    ll pos(int x){
        ll x2 = pow(x, 2);
        string s = to_string(x2);
        ll size_of_vector = to_string(v.size() - 1).size();
        ll d=s.size();
        ll begin = (d - size_of_vector) ;
        if(begin%2==0) begin /=2;
        else begin = (d - size_of_vector+1) / 2;
        string mid_str = s.substr(begin, size_of_vector);
        ll posi = stoi(mid_str);
        return posi % v.size();  // ensure

    }
    void add(int x) override{
        ll pos = this->pos(x);
        if(v[pos]==-1) v[pos]=x;
        else cout<<"collisioni happened\n";
    }
    ll search(int x) override{
        ll pos = this->pos(x);
        if(v[pos]!=-1) { cout << "found at index " << pos << '\n'; return pos; }
        else cout<<"not found\n";
        return -1;

    }
    void delete_x(int x) override{
        ll pos = this->pos(x);
        if(v[pos]!=x) cout<<"not found\n";
        else v[pos]=-1;
    }
    void print() override{
        for(int i=0;i<v.size();i++){
            cout<<i<<" : ";
            v[i]==-1? cout<<"empty" : cout<<v[i];
            cout<<"\n";
        }
    }

};
//fold shifiting method is dividing the number into subsequence of the size of number of digits in table size, then either sum them together
class fold_shifting_method : public hashing{
private:
    vector<int> v;
public:
    explicit fold_shifting_method(int size) : v(size, -1) {}
    ll pos(int x){
        string int_to_string = to_string(x);
        ll final_pos=0,i=0;
        ll size_of_x=int_to_string.size();
        ll sv = to_string(v.size() - 1).size();
        while (i<size_of_x ){
            ll n=sv, result=0 ;
            if(size_of_x-i<n) n=size_of_x-i;
            while(n>=1&&i<size_of_x ) { //condition to not get overflow
                result+=((int_to_string[i]-'0')*pow(10,n-1));
                n--;
                i++;
            }

            final_pos+=result;
        }

        return final_pos%v.size();  // ensure

    }
    void add(int x) override{
        ll pos = this->pos(x);
        if(v[pos]==-1) v[pos]=x;
        else cout<<"collisioni happened\n";
    }
    ll search(int x) override{
        ll pos = this->pos(x);
        if(v[pos]!=-1) { cout << "found at index " << pos << '\n'; return pos;}
        else cout<<"not found\n";
        return -1;

    }
    void delete_x(int x) override{
        ll pos = this->pos(x);
        if(v[pos]!=x) cout<<"not found\n";
        else v[pos]=-1;
    }
    void print() override{
        for(int i=0;i<v.size();i++){
            cout<<i<<" : ";
            v[i]==-1? cout<<"empty" : cout<<v[i];
            cout<<"\n";
        }
    }

};
// fold boundary is linke fold shifiting but first swap the digits of the boundaries
class fold_boundary_method  : public hashing{
private:
    vector<int> v;
public:
    explicit fold_boundary_method(int size) : v(size, -1) {}
    ll pos(int x){
        string int_to_string = to_string(x);
        ll final_pos=0,i=0;
        ll size_of_x=int_to_string.size();
        ll sv = to_string(v.size() - 1).size();
        if(size_of_x>1)swap(int_to_string[0],int_to_string[1]);
        if(size_of_x>=4)swap(int_to_string[size_of_x-1],int_to_string[size_of_x-2]);
        while (i<size_of_x ){
            ll n=sv, result=0 ;
            if(size_of_x-i<n) n=size_of_x-i;
            while(n>=1&&i<size_of_x ) { //condition to not get overflow
                result+=((int_to_string[i]-'0')*pow(10,n-1));
                n--;
                i++;
            }

            final_pos+=result;
        }

        return final_pos%v.size();  // ensure

    }
    void add(int x) override{
        ll pos = this->pos(x);
        if(v[pos]==-1) v[pos]=x;
        else cout<<"collisioni happened\n";
    }
    ll search(int x) override{
        ll pos = this->pos(x);
        if(v[pos]!=-1) {
            cout << "found at index " << pos << '\n';
            return pos;
        }
        else { cout<<"not found" ; return -1; }

    }
    void delete_x(int x) override{
        ll pos = this->pos(x);
        if(v[pos]!=x) cout<<"not found\n";
        else v[pos]=-1;
    }
    void print()override{
        for(int i=0;i<v.size();i++){
            cout<<i<<" : ";
            v[i]==-1? cout<<"empty" : cout<<v[i];
            cout<<"\n";
        }
    }

};
//now we will talk about collision handling techniques
//1. chaning method , it is better when you do not know the exact number of elements you want to add and it less affected by load factor
class chaining_method{
    vector<node*> v;
public:
    explicit chaining_method(int size) : v(size,nullptr) {}
    void add(int x){
        node* n=new node();
        n->value=x;
        n->next=v[x%v.size()];
        v[x%v.size()]=n;
    }
    void delete_x(int x){
        node*& head = v[x % v.size()];
        node* iterate= head;
        node* prev=nullptr;
        while(iterate!= nullptr&&iterate->value != x) {
            prev=iterate;
           iterate=iterate->next;

        }
        if(iterate== nullptr) { cout << "not found\n"; return;}
        if (prev == nullptr) { //if iterate is the head
            head = iterate->next;
        } else if (iterate->next != nullptr) //if iterate is the middle
            prev->next = iterate->next;
        else prev->next = nullptr; //if iterate is the final
        delete iterate;

    }
    bool is_found(int x){
        node*& head = v[x % v.size()];
        node* iterate= head;
        node* prev=nullptr;
        while(iterate!= nullptr&&iterate->value != x) {
            prev=iterate;
            iterate=iterate->next;

        }
        if(iterate== nullptr) { cout <<x<< " not found\n"; return false;}
        else cout<<x<<" found at index "<<x%v.size()<<" \n";
        return true;


    }
    void print(){
        for(int i=0;i<v.size();i++){
            node* iterate =v[i];
            cout<<"at index i : "<<i<<" :";
            while(iterate!= nullptr) {
                cout<<iterate->value<<" -> ";
                iterate=iterate->next;
            }
            cout<<"null\n";
        }
    }
};

// 2. open method it is better in space because there is no links like in chaining method and it has 3 ways
class open_method{

public:

    virtual int hashing_method(int x, int i, int vsize)=0;
    virtual ~open_method() = default; // Virtual destructor


};

//a.linear probing but it suffers from primary clustering
class single :public open_method{

public:
    int  hashing_method(int x, int i ,int vsize) override{
        return (x+i)%vsize;
    }
};
//b. quadratic probing but it suffers from secondary clustering
class quadratic :public open_method{
public:
    int  hashing_method(int x, int i,int vsize) override{
        return (x + i * i) % vsize;
    }
};

//c. double probing
class doubl :public open_method{
public:
    int  hashing_method(int x, int i,int vsize) override{
        return ((x%vsize)+i*(7-(x%7)))%vsize;
    }
};
class open_addressing{
    vector<pair<int,string>> v; //false mean deleted
    open_method& hf;
public:
     open_addressing(int size,open_method& h) : v(size, make_pair(-1,"empty")), hf(h) {}
    int add(int x) {
        int i = 0;
        while (v[hf.hashing_method(x, i, v.size())].second == "occupied" && i < v.size()) i++;

        if (i >= v.size()) {
            this->rehash(x);
            return this->add(x);  // Retry adding after rehashing
        }

        int idx = hf.hashing_method(x, i, v.size());
        v[idx].first = x;
        v[idx].second = "occupied";
        return idx;
    }

    void rehash(int x) {
        vector<pair<int, string>> v2(v.size() * 2, make_pair(-1, "empty"));
        vector<pair<int, string>> place_holder = v;
        v = v2;

        for (int i = 0; i < place_holder.size(); i++) {
            if (place_holder[i].second == "occupied")
                this->add(place_holder[i].first); // Reinsert elements after resizing
        }

    }
    void delete_x(int x){
        int i=0;
        while(v[hf.hashing_method(x,i,v.size())].first!=x&&i<v.size()) i++;
        if(v[hf.hashing_method(x,i,v.size())].first==x)v[hf.hashing_method(x,i,v.size())].second="deleted";
        else cout<<x<<" is not found to be deleted\n";

    }
    int search(int x){
        int i=0;
        while(v[hf.hashing_method(x,i,v.size())].second!="empty"&& v[hf.hashing_method(x, i, v.size())].first != x) i++;
        if(v[hf.hashing_method(x,i,v.size())].first==x) return hf.hashing_method(x,i,v.size());
        else {
            cout<<"not found"; return -1;
        }
    }
    void print(){
        for(int i=0;i<v.size();i++){
            cout<<i<<" : ";
            if(v[i].second=="empty") cout<<"empty\n";
            if(v[i].second=="deleted") cout<<"deleted\n";
            if(v[i].second=="occupied") cout<<v[i].first<<"\n";
        }
    }

};

hashing* choose(int x, int size){
    switch(x){
        case 1:
            return new division_method(size);
            break;
        case 2:
            return new multiplication_method(size);
            break;
        case 3:
            return new mid_method(size);
            break;
        case 4:
            return new fold_shifting_method(size);
            break;
        case 5:
            return new fold_boundary_method(size);
            break;
        default:
            throw runtime_error("in valid choise");
    }
}
open_method* chose_method(int x){
    switch(x){
        case 1:
            return new single;
        case 2:
            return new quadratic;
        case 3:
            return new doubl;
        default:
            throw runtime_error("in valid choise");
    }
}
int main() {
    int choice,c,x,size,element;
    cout << "What technique do you want to try?\n"
         << "1) Hashing technique\n"
         << "2) Collision resolution technique\n";
    cin >> choice;
    if(choice==1){
        cout << "What method do you want to use?\n"
             << "1) Division method\n"
             << "2) Multiplication method\n"
             << "3) Mid-square method\n"
             << "4) Fold shifting method\n"
             << "5) Fold boundary method\n"
                "and then eneter the size\n";
        cin>>x>>size;
        hashing* hash = choose(x,size);
        while(true){
            show_menu();
            cin>>c;
            switch(c){
                case 1:
                    cin>>element;
                    hash->add(element);
                    break;
                case 2:
                    cin>>element;
                    hash->delete_x(element);
                    break;
                case 3:
                    cin>>element;
                    hash->search(element);
                    break;
                case 4:
                    hash->print();
                    break;
                default:
                   return 0;
            }

        }
    }else if(choice==2){
        cout<<"What method do you wnat to use"
              "\n0. chaining method "
              "\n1. linear probing"
              "\n2. quadratic probing"
              "\n3. double hashing "
              "\nand then enter the size";
        cin>>x>>size;
        if(x==0){
            chaining_method ch(size);
            while(true) {
                show_menu();
                cin>>c;
                switch (c) {
                    case 1:
                        cin >> element;
                        ch.add(element);
                        break;
                    case 2:
                        cin >> element;
                        ch.delete_x(element);
                        break;
                    case 3:
                        cin >> element;
                        ch.is_found(element);
                        break;
                    case 4:
                        ch.print();
                        break;
                    default:
                        return 0;
                }
            }
        }else {
            open_method *op_method = chose_method(x);
            open_addressing op_addressing(size, *op_method);

            while (true) {
                show_menu();
                cin >> c;
                switch (c) {
                    case 1:
                        cin >> element;
                        op_addressing.add(element);
                        break;
                    case 2:
                        cin >> element;
                        op_addressing.delete_x(element);
                        break;
                    case 3:
                        cin >> element;
                        if(op_addressing.search(element)==-1){
                            cout<<"not found";
                        }else cout<<"found at index "<<op_addressing.search(element)<<"\n";
                        break;
                    case 4:
                        op_addressing.print();
                        break;
                    default:
                        return 0;
                }
            }
        }
    }
    return 0;

    }

