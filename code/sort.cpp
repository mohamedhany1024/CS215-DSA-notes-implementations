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

int median_of_three(int l, int r, vector<int>& v) {
    /*int min = v[l];
    int minIdx = l;
    vector<int> v2 = {v[l], v[(l+r)/2], v[r]};

    for(int i=0; i<v2.size(); i++) {
        if (v2[i] < min) {
            min = v2[i];
            minIdx = i;
        }
    }
    return minIdx+l;*/
    vector<pair<int, int>> v2 = {{v[l], l}, {v[(l+r)/2], (l+r)/2}, {v[r], r}};
    int minIdx = 0;
    int maxIdx = 2;
    int min = v[l];
    int max = v[r];

    for (int i=0; i<v2.size(); i++)
    {
        if (v2[i].first < min)
        {
            min = v2[i].first;
            minIdx = i;
        }

        if (v2[i].first > max)
        {
            max = v2[i].first;
            maxIdx = i;
        }
    }

    swap(v2[maxIdx], v2[2]);
    swap(v2[minIdx], v2[0]);


    return v2[1].second;
}

int partition(int l, int r, vector<int>& v) {
    int pivotIdx = median_of_three(l, r, v);
    int pivot = v[pivotIdx];
    //int pivotIdx = l;
    //int pivot = v[pivotIdx];

    //ensure our chosen pivot from the method is at the left.
    swap(v[l], v[pivotIdx]);
    pivotIdx = l;

    int i=l, j=r;
    while (i < j) {

        while (v[i] <= pivot && i <= r) {
            i++;
        }

        while (v[j] >= pivot && j > l) {
            j--;
        }

        if (i < j) {
            swap(v[i], v[j]);
        }
        
    }
    v[pivotIdx] = v[j];
    v[j] = pivot;
    return j;
}

void quick_sort(int l, int r, vector<int>& v) {
    if (l<r){
        int mid = partition(l, r, v);

        quick_sort(l, mid-1, v);
        quick_sort(mid+1, r, v);
    } else {
        return;
    }
}

void merge(int l, int r, vector<int>& a) {
    int mid = (l+r)/2;
    int i=l, j=mid+1;
    vector<int> b;
    b.reserve((r-l)+1);
   
    //loop that does initial merging
    while(i<=mid && j<=r) {
        if (a[i]<=a[j]) {
            b.push_back(a[i]);
            i++;
            continue;
        } 

        if (a[j] <= a[i]) {
            b.push_back(a[j]);
            j++;
            continue;
        }
    }
    //if one of the subarrays is finished before the other
    // we need to add the rest of the other to our result 'b'
    while(i<=mid) {
        b.push_back(a[i]);
        i++;
    }

    while (j<=r) {
        b.push_back(a[j]);
        j++;
    }

    //set the range l : r in 'a' to 'b'
    i=0;
    int k = 0;
    for(int k=l; k<=r; k++) {
        a[k] = b[i];
        i++;
    }
}

void merge_sort(int l, int r, vector<int>& a) {
    if (l>=r) {
        return;
    } else if (r-l == 1)
    {
        if (a[l] > a[r])
        {
            swap(a[l], a[r]);
        }
        return;
    }

    int mid = (l+r) / 2;
    merge_sort(l, mid, a);
    merge_sort(mid+1, r, a);
    merge(l, r, a);
}



vector <int> count_sort(vector<int> A) {
   
    vector<int> B(A.size());
    int maxNum = A[0];
    for(int i=1; i<B.size(); i++) {
        maxNum = max(maxNum, A[i]);
    }

    vector<int> C(maxNum+1, 0);
   
    for(int i=0; i<A.size(); i++) {
        C[A[i]]++;
    }
    for(int i=1; i<C.size(); i++) {
        C[i] = C[i] + C[i-1];
    }
    for(int i=A.size()-1; i>=0; i--) {
        // we used B[C[A[i]]-1] because of zero-based indexing
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }

    return B;

}

int main() {

    vector <int> v1 = {5, 3, 2, 7, 4, 25, 1, 16};
    vector <int> v2= {15, 31, 52, 64, 17, 43, 27, 19, 68, 41, 63, 2, 78, 14, 12, 67, 7, 98, 54, 39, 59, 73, 79, 87, 61, 36, 74, 66, 44, 92, 38, 34, 6, 83, 51, 57, 69, 33, 13, 49, 4, 90, 99, 1, 18, 89, 42, 97, 82, 40, 46, 48, 93, 62, 50, 53, 29, 8, 30, 94, 9, 5, 100, 25, 72, 24, 45, 86, 26, 35, 32, 37, 11, 60, 55, 80, 76, 77, 81, 47, 95, 58, 85, 10, 28, 65, 16, 20, 91, 75, 70, 56, 84, 3, 88, 96, 71, 21, 22, 23};
    merge_sort(0, v2.size()-1, v2);
    //v2 = count_sort(v2);
    for (auto& x : v2) {
        cout << x <<" "; 
    }
    cout  <<  endl;
    cout << isSorted(v2) << endl;
    return 0;
}