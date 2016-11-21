#include <iostream>
#include <string>
using namespace std;

int main(){


	// Step 1 : Input the string and substring
	string str, substr;
	getline(cin, str);
	getline(cin, substr);

	// Aim to find number of occurences in string of substring
	int count = 0;

	for(int i = 0, j = 0; i < str.length(); i++){
		if(str[i] == substr[j])
			j++;
		else
			j = 0;

		if(j == substr.length())
			count++, j = 0;
	}

	cout << "No. of Occurences: " << count << endl;

	return 0;
}	