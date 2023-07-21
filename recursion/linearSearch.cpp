#include <bits/stdc++.h> 
using namespace std;
// vector<char>

bool linearSearch(int *arr, int size, int key){
  
    if(size==0){
        return false;
    }
    
    if(arr[0] == key){
        return true;
    }
    else{
        int remainingPart = linearSearch(arr+1, size-1, key);
        return remainingPart;
    }
}


int main() {
    int arr[4] = {1, 2, 5, 3};
    
    bool ans = linearSearch(arr, 4, 4);
    cout<<ans;
    
    return 0;
}
