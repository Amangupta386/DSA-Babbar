#include <iostream>
#include <vector>

using namespace std;

int peakMountain(const vector<int>& arr, int s, int e) {
    
    if(s == e){
        
        return s;
    }
    int mid = s + (e-s)/2;
    
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
        return mid; // The middle element is the peak.
    }
    
    else if(arr[mid] < arr[mid] + 1){
        return peakMountain(arr, mid + 1, e);
    }
    else{
       return peakMountain(arr, s, mid);
    }
}


int main() {
    vector<int> arr = {2, 3, 4, 2, 1};
    int result = peakMountain(arr, 0, 4);
    cout <<result;
    return 0;
}
