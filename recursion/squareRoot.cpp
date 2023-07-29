#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int squareRoot(const vector<int>& arr, int s, int e, int value) {
    
    int mid = s + (e-s)/2;
    
    if(mid*mid == value){
        
        return mid;
    }
    
    if(mid * mid < value){
        int ans = mid;
        return squareRoot(arr, mid + 1, e, value);
    }
    else{
       return squareRoot(arr, s, mid-1, value );
    }
}



int main() {
    int n = 64;

    vector<int> vec(n + 1); // +1 to include the value 'n' in the vector

    // Fill the vector with values from 0 to 'n'
    iota(vec.begin(), vec.end(), 0);

    int result = squareRoot(vec, 0, n-1, n);

    cout <<result;
    return 0;
}
