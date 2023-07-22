// Array must be sorted
// TC : O(log)n

#include <bits/stdc++.h> 
using namespace std;
// vector<char>

int BinarySearch(int *arr, int size, int key){
    int s = 0; 
    int e = size - 1;
    
    int mid = s + (e-s)/2;
    
    while(s<=e){
        if(arr[mid] == key){
            return mid;
        }
        else if( arr[mid] < key){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}


int main() {
    int arr[4] = {1, 2, 3, 5};
    
    int ans = BinarySearch(arr, 4, 5);
    cout<<ans;
    
    return 0;
}
