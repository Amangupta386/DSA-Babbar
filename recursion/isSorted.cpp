#include <bits/stdc++.h> 
using namespace std;
// vector<char>

bool isSorted(int arr[], int size){
    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool result = isSorted(arr+1, size-1);
        return result;
    }
    
}


int main() {
    int arr[4] = {1, 2, 5, 3};
    
    // int input;
    // cin>>input;
    // cout<<input;
    bool ans = isSorted(arr, 4);
    cout<<ans;
    
    return 0;
}
