#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

bool isPossible(vector<int>& cowsPlaces, int numCows, int mid) {
    int lastPos = cowsPlaces[0];
    int cowCount = 1;
    int n = cowsPlaces.size();
  
    
    for(int i = 0; i<n; i++) {
        if(cowsPlaces[i] - lastPos >= mid) {
            cowCount++;
            if( cowCount == numCows)
            {
                return true;
            }
            lastPos = cowsPlaces[i];
        }
       
    }
    return false;
}

int aggressiveCows(vector<int>& cowsPlaces, int numCows, int left, int right) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (isPossible(cowsPlaces, numCows, mid)) {
        int ans = mid;
        int leftResult = aggressiveCows(cowsPlaces, numCows, mid+1, right);
        if (leftResult != -1) {
            return leftResult;
        } else {
            return ans;
        }
    } else {
        return aggressiveCows(cowsPlaces, numCows, left, mid-1);
    }
}


int main() {
    int numCows=4;

    vector<int> cowsPlaces = {0, 3, 4, 7, 10, 9};
    
    int n = cowsPlaces.size();
    int minValue = *std::min_element(cowsPlaces.begin(), cowsPlaces.end());
    int maxValue = *std::max_element(cowsPlaces.begin(), cowsPlaces.end());
    sort(cowsPlaces.begin(), cowsPlaces.end());
    
    int result = aggressiveCows(cowsPlaces, numCows, 0, maxValue-minValue);
    cout << "Minimum number of pages a student needs to read: " << result << endl;

    return 0;
}
