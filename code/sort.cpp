#include <iostream>
#include <vector>


using namespace std;

void insertion_sort(vector<int>& v) {
    int j = 0;     
    for(int i=1; i<v.size(); i++) {
        int current = v[i];
        // we traverse the sorted subarray from bottom to top, shifiting each element to the right at the same time, and stop when we find
        // the suitable place for our insertion
        
        for(j=i; j!=0 && v[j-1] > current; j--) {
            v[j] = v[j-1]; 
        }
        v[j] = current;
    }
}

void selection_sort(vector<int>& v) {

    for(int i=0; i<v.size(); i++) {
        int minNum = 1e9;
        int minIdx = 0;

        for(int j=i; j<v.size(); j++) {
            if (v[j] < minNum) {
                minNum = v[j];
                minIdx = j;
            }
        }
        swap(v[i], v[minIdx]);
    }
}

bool isSorted(const vector<int>& v) {
    for(int i=0; i<v.size()-1; i++) {
        if (v[i+1] < v[i]) {
            return false;
        }
    }

    return true;
}

void bubble_sort(vector<int>& v) {
    while(!isSorted(v)) {
        for(int i=0; i<v.size()-1; i++) {
            if (v[i+1] < v[i]) {
                swap(v[i+1], v[i]);
            }
        }
    }
}

// Best Case complexity: O(n)
// Worst Case complexity: O(n^2)
void bubble_sort2(vector<int>& v) {
    bool swapped = false;
    for(int i=0; i<v.size()-1; i++) {
        for(int j=v.size()-1; j != i; j--) {
            if (v[j] < v[j-1]) {
                swap(v[j], v[j-1]);
                swapped = true;
            }
        }
        if (!swapped) {break;}
    }
}

int main() {

    vector <int> v1 = {5, 3, 2, 7, 4, 25, 1, 16};
    bubble_sort2(v1);
    for (auto& x : v1) {
        cout << x <<" "; 
    }
    cout << endl;
    return 0;
} 