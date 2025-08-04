# include <iostream>
# include <vector>
using namespace std;


int partition(vector<int>& arr, int left, int right){
    int pivot = arr[right];
    int i = left-1;
    for (int j=left; j<right; j++){
        if (arr[j]<pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[right]);
    return i+1;
}

void quickSort(vector<int>& arr, int left, int right){
    if (left>=right) return;
    int pi = partition(arr, left, right);
    quickSort(arr, left, pi-1);
    quickSort(arr, pi+1, right);
}


int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    quickSort(arr, 0, arr.size()-1);

    cout << "sorted: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}