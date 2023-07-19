#include <bits/stdc++.h> 
using namespace std;
// vector<char>

void sayDigit(char* arr[], int input){
    
    int duplicate = input;
    
        if(input==0) return;
        int digit = input % 10;
        input = input / 10;
            
        sayDigit(arr, input);
        cout<< arr[digit]   <<" ";    
}


int main() {
    char *arr[10] = {"zero", "one", "two", "three", "four", 
    "five", "six", "seven", "eight", "nine"};
    
    int input;
    cin>>input;
    // cout<<input;
    sayDigit(arr, input);
    
    return 0;
}
