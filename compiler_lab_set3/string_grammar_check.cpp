#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
	int flag,count=0;

	cout << "The grammar is: S->aS, S->Sb, S->ab" << endl;
	cout << "Enter the string to be checked:" << endl;
	getline(cin, str);

	if(str[0]=='a') {
		flag=0;
		for (count=1; count < str.length(); count++) {
			if(str[count]=='b') {
				flag=1;
				continue;
			} else if((flag==1)&&(str[count]=='a')) {
				cout << "The string does not belong to the specified grammar" << endl;
				break;
			} else if(str[count]=='a')	continue;
			else {
				cout << "str not accepted" << endl;
			}
		}
		if( flag==1 && count == str.length()) {
			cout << "string accepted…..!!!!" << endl;
		} 
	}else{
		cout << "The string does not belong to the specified grammar" << endl;
	}

	return 0;
}