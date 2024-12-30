#include <iostream>
#include <vector>

using namespace std;
template <typename T>
int sequential_search(vector <T> &v, T target) {
    int found = -1;
    for (auto i : v){
        found ++;
        if(i==target) return found;
    }
    return -1;
}
template <typename T>

int recursive_sequential_search(vector <T> &v, T target , int current){
    if(current==v.size()) return -1;
    if(v[current]==target) return current;
    return recursive_sequential_search(v,target,current+1);
}
template <typename T>

int binary_search(vector <T> &v, T target){
    int left = 0 , right  = v.size() -1, mid;
    while(right>=left){
        mid = left+(right-left) /2;
        if(target == v[mid]){
            return mid;
        }else if(target > v[mid]) left = mid+1;
        else right = mid -1;
    }
    return -1;
}
template <typename T>

int recursive_binary_search(vector <T> &v, T target, int left, int right){
    if(right < left ) return -1;
    int mid;
    mid = left+(right-left) /2;
    if(target == v[mid]){
        return mid;
    }else if(target > v[mid]) return recursive_binary_search(v, target, mid+1 ,right);
    else return recursive_binary_search(v, target, left ,mid-1);


}

template <typename T>
void run_search() {
    vector<T> l;
    int size, chosen;
    T target;
    int index;

    cout << "How many items do you want to enter? \n";
    cin >> size;

    cout << "Enter the elements:\n";
    for (int i = 0; i < size; i++) {
        T element;
        cin >> element;
        l.push_back(element);
    }

    cout << "What item do you want to find? \n";
    cin >> target;

    cout << "Which search method do you want to use?\n (1) Sequential search \n (2) Recursive sequential search \n (3) Binary search (sorted input) \n (4) Recursive binary search (sorted input) \n";
    cin >> chosen;

    if (chosen == 1) {
        index = sequential_search(l, target);
    } else if (chosen == 2) {
        index = recursive_sequential_search(l, target, 0);
    } else if (chosen == 3) {
        index = binary_search(l, target);
    } else {
        index = recursive_binary_search(l, target, 0, size - 1);
    }

    if (index < 0) cout << "Not found\n";
    else cout << "Found at index " << index << " (0-indexed)\n";
}

int main() {
    int type_choice;

    cout << "Choose the data type for elements:\n (1) int \n (2) float \n (3) double \n (4) string\n";
    cin >> type_choice;

    switch (type_choice) {
        case 1:
            run_search<int>();
            break;
        case 2:
            run_search<float>();
            break;
        case 3:
            run_search<double>();
            break;
        case 4:
            run_search<string>();
            break;
        default:
            cout << "Invalid choice\n";
    }

    return 0;
}