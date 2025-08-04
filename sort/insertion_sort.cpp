# include <iostream>
# include <vector>
using namespace std;

void insertionSort(vector<int>& arr){
    int n = arr.size();
    for (int i=1; i<n; i++){
        int j = i;
        while (j>0 && arr[j-1]>arr[j]){
            swap(arr[j], arr[j-1]);
            j--;
        }    
    }
}


int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    insertionSort(arr);

    cout << "sorted: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}