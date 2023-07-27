#include <iostream>
#include <vector>

using namespace std;

int pivotElementRotatedArray(const vector<int>& arr, int s, int e) {
    
    if(s == e){
        
        return s;
    }
    int mid = s + (e-s)/2;
    
    
    if(arr[mid] >= arr[0]){
        return pivotElementRotatedArray(arr, mid + 1, e);
    }
    else{
       return pivotElementRotatedArray(arr, s, mid);
    }
}

int searchRotatedSortedArray(const vector<int>& arr, int s, int e, int key){
    
    if(s>e){
        return -1;
    }
    
    int mid = s + (e-s)/2;
    
        if(arr[mid] == key){
            return mid;
        }
        else if( arr[mid] < key){
            // s = mid + 1;
            return searchRotatedSortedArray(arr, mid+1, e, key);
        }
        else{
            return searchRotatedSortedArray(arr, s, mid-1, key);
            // e = mid - 1;
        }
        // mid = s + (e-s)/2;
}

int main() {
    vector<int> arr = {4, 5, 6, 1, 2, 3};
    int target = 2;

    int pivot = pivotElementRotatedArray(arr, 0, 5);
    int ans = 0;

    if(target >= arr[pivot] && target <= arr[arr.size()-1]){
        ans = searchRotatedSortedArray(arr, pivot, arr.size()-1, target);
    }
    else{
        ans = searchRotatedSortedArray(arr, 0, pivot-1, target);
    }

    cout <<ans;
    return 0;
}
