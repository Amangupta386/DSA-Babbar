#include <bits/stdc++.h> 

void reverse(int i, string& str){
	if(i >= str.length()/2){
		return;
	}
	swap(str[i], str[str.length()-1-i]);
	reverse(i+1, str);
}

string reverseString(string str)
{
	reverse(0, str);
	return str;
}
