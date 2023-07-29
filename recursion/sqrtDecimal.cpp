#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int squareRoot(const vector<int>& arr, int s, int e, int value) {
    int ans = -1;
    if(s>e) return ans;
    
    long long int mid = s + (e-s)/2;
    
    if(mid*mid == value){
        
        return mid;
    }
    
    if(mid * mid < value){
         ans = mid;
        return squareRoot(arr, mid + 1, e, value);
    }
    else{
       return squareRoot(arr, s, mid-1, value );
    }
}

double morePrecision(int n, int precision, int tempSol) {
    
    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++) {
        factor = factor/10;

        for(double j=ans; j*j<n; j= j+factor ){
            ans = j;
        }
    }
    return ans;
}

int main() {
    int n = 2;

    vector<int> vec(n + 1); // +1 to 
    iota(vec.begin(), vec.end(), 0);

    int tempSol = squareRoot(vec, 0, n-1, n);
cout <<" Answer is " << morePrecision(n, 3, tempSol) << endl;
    return 0;
}
