# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

void bucketSort(vector<int>& arr){
    if (arr.empty()) return;
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    int bucketCount = maxVal - maxVal + 1;
    vector<vector<int>> buckets(bucketCount);
    for (int num: arr){
        buckets[num - minVal].push_back(num);
    }

    int index = 0;
    for (auto& bucket: buckets){
        for (int num: bucket) {
            arr[index++] = num;
        }
    }
}


int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    bucketSort(arr);

    cout << "sorted: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}