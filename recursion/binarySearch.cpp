#include <bits/stdc++.h> 
using namespace std;
// vector<char>

bool binarySearch(int *arr, int s, int e, int key){
    
    int mid = s + (e-s)/2;
     
  if(s>e){
    return false;
  }
  
  if(arr[mid] == key){
      return true;
  }
  
 
  
  if( arr[mid] < key){
    return binarySearch(arr, mid+1, e, key);
    // s = mid + 1;
  }
  else{
    return binarySearch(arr, s, mid-1, key);
    // e = mid - 1;
  }
  
}

int main() {
    int arr[4] = {1, 2, 4, 5};
    
    bool ans = binarySearch(arr, 0, 3, 3);
    cout<<ans;
    
    return 0;
}
