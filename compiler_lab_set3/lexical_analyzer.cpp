#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

bool contain(string str, string substr){

	for(int i = 0, j = 0; i < str.length(); i++){
		if(str[i] == substr[j])
			j++;
		else
			j = 0;

		if(j == substr.length())
			return true;
	}

	return false;
}

bool isDeclaration(string line){

	vector<string> types;
	types.push_back("int ");
	types.push_back("char "); 
	types.push_back("double ");
	types.push_back("string ");
	types.push_back("float ");
	for(int i = 0; i < types.size(); i++)
		if(contain(line, types[i])){
			cout << types[i] << "Declaration" << endl;
			return true;
		}

	return false;
}

bool isStatement(string line){

	vector<string> stat;
	stat.push_back("for");
	stat.push_back("while");
	stat.push_back("do");
	stat.push_back("case");
	stat.push_back("break");
	stat.push_back("continue");
	stat.push_back("return");
	stat.push_back("namespace");
	stat.push_back("cout");
	for(int i = 0; i < stat.size(); i++)
		if(contain(line, stat[i])){
			cout << stat[i] << " Statement" << endl;
			return true;
		}

	return false;
}

bool isExpression(string line){

	vector<string> oper;
	oper.push_back("+");
	oper.push_back("*");
	oper.push_back("/");
	oper.push_back("=");
	for(int i = 0; i < oper.size(); i++)
		if(contain(line, oper[i])){
			cout << " Expression" << endl;
			return true;
		}

	return false;
}

bool isBlank(string line){
	for(int i = 0; i < line.length(); i++)
		if(line[i] >= 42 && line[i] <= 125)
			return false;

	return true;
}

int main(){

	ifstream input("input.cpp");
	ofstream output("output.cpp");
	string line;
	int count = 0;
	if (input.is_open()){
	    while ( getline(input, line) ){
			count++;
			if(isBlank(line)){
				continue;
			}	      
	    	// recognize comments - inline comments & block comments
	    	if(contain(line, "//")){
	    		cout << "Line " << count << ": " << "Comment" << endl;
	    		continue;
	    	}
	    	if(contain(line, "/*")){
	    		cout << "Line " << count << "-";
	    		while(!contain(line, "*/")){
	    			getline(input, line);
	    			count++;
	    		}
	    		cout << count << ": Block Comment" << endl;
	    		continue;
	    	}

	    	// recognize preprocessor 
	    	if(contain(line, "#")){
				output << line << endl;
				cout << "Line " << count << ": " << "PreProcessor Directive" << endl;
				continue;
	    	}

	    	// data type
	    	cout << "Line " << count << ": ";
	    	output << line << endl;
	    	if( isStatement(line) || isDeclaration(line) || isExpression(line)){
	    		continue;
	    	} 

	    	if(contain(line, "}"))
	    		cout << "brace" << endl;

	    }
	    input.close();
	    output.close();
	 }else
  		cout << "Error opening file" << endl;
}