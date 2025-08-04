# include <iostream>
# include <vector>
using namespace std;

void bubbleSort(vector<int>& arr){
    int n = arr.size();
    for (int i=n; i>0; i--){
        for (int j=1; j<i; j++){
            if (arr[j]<arr[j-1]){
                swap(arr[j], arr[j-1]);
            }
        }
    }
}


int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    bubbleSort(arr);

    cout << "sorted: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}