# include <iostream>
# include <vector>
using namespace std;

void selectionSort(vector<int>& arr){
    int n = arr.size();
    for (int i=0; i<n; i++){
        int minIndex = i;
        for (int j=i; j<n; j++){
            if (arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}


int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    selectionSort(arr);

    cout << "sorted: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}