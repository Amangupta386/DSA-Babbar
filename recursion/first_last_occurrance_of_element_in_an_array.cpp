#include <iostream>
#include <vector>

using namespace std;

int find_first_occurrence(const vector<int>& arr, int target, int low, int high) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        if (mid == low || arr[mid - 1] < target)
            return mid;
        else
            return find_first_occurrence(arr, target, low, mid - 1);
    } else if (arr[mid] < target) {
        return find_first_occurrence(arr, target, mid + 1, high);
    } else {
        return find_first_occurrence(arr, target, low, mid - 1);
    }
}

int find_last_occurrence(const vector<int>& arr, int target, int low, int high) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        if (mid == high || arr[mid + 1] > target)
            return mid;
        else
            return find_last_occurrence(arr, target, mid + 1, high);
    } else if (arr[mid] < target) {
        return find_last_occurrence(arr, target, mid + 1, high);
    } else {
        return find_last_occurrence(arr, target, low, mid - 1);
    }
}

pair<int, int> find_first_and_last_occurrence(const vector<int>& arr, int target) {
    int first_occurrence = find_first_occurrence(arr, target, 0, arr.size() - 1);
    int last_occurrence = find_last_occurrence(arr, target, 0, arr.size() - 1);
    return make_pair(first_occurrence, last_occurrence);
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 4, 5, 5, 5, 5, 6};
    int target = 5;
    pair<int, int> result = find_first_and_last_occurrence(arr, target);

    if (result.first != -1 && result.second != -1) {
        cout << "First occurrence of " << target << " is at index: " << result.first << endl;
        cout << "Last occurrence of " << target << " is at index: " << result.second << endl;
    } else {
        cout << target << " is not found in the array." << endl;
    }

    return 0;
}
