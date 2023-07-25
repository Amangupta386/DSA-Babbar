#include <iostream>
#include <vector>

using namespace std;

int pivotElementRotaedArray(const vector<int>& arr, int s, int e) {
    
    if(s == e){
        
        return s;
    }
    int mid = s + (e-s)/2;
    
    
    if(arr[mid] >= arr[0]){
        return pivotElementRotaedArray(arr, mid + 1, e);
    }
    else{
       return pivotElementRotaedArray(arr, s, mid);
    }
}


int main() {
    vector<int> arr = {4, 5, 6, 1, 2, 3};
    int result = pivotElementRotaedArray(arr, 0, 4);
    cout <<result;
    return 0;
}
