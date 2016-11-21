#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){

	string word;
	cin >> word;
	ifstream myfile("input.txt");
	
	char ch;
	int count = 0;
	if (myfile.is_open()){
		int i = 0;
	    while ( myfile >> noskipws >> ch ){
	      if(ch == word[i])
	      	i++;
	      else
	      	i = 0;
	      if(i == word.length()){
	      	count++;
	      	i = 0;
	      }
	    }
	    myfile.close();
  	}else
  		cout << "Error opening file" << endl;
  	
  	cout << "No. of occurences: " << count << endl;
}