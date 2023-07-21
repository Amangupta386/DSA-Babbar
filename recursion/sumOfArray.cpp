#include <bits/stdc++.h> 
using namespace std;
// vector<char>

int findSum(int *arr, int size){
    
    if(size==0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }
    
    int ans = findSum(arr+1, size-1);
    int sum = arr[0] + ans;
    return sum;
    
}


int main() {
    int arr[4] = {1, 2, 5, 3};
    
    int ans = findSum(arr, 4);
    cout<<ans;
    
    return 0;
}
