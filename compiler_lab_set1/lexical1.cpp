#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
bool keyword(string);
int constants(string);
bool oprator(string);
int id(string);
int idd(char);
int num(char);
int main(){
string data;

ifstream in;
in.open("abc.cpp");

getline(in,data);

cout<<"original statement "<<data<<"\n";
if(keyword(data))
	{
		cout<<"ok";
	}
else
{
cout<<"not ok";

}



in.close();



return 0;

	}



	bool keyword(string s1)  //keyword check
	{  
		int i=0,flag=0;;
	string key[5]={"int","float","string","char","double"};

 while(i<5)
 {
 	if(s1.find(key[i]))
 flag=1;
 
  i++;
}

if (flag==1)

return true;
else return false;
	}


	bool oprator(string s1)   //operator check

	{
int i=0,flag=0;
	string op[5]={"+","-","*","/",";"};
 while(i<5)
 {
 	if(s1.find(op[i]))
 flag=1;
 
  i++;
}
if (flag==1)

return true;


else
 return false;

}

int num(char c)
{
  if(c>=48&&c<=57)
  	return 1;
  else 
  	return 0;


}

	int constants(string s1)   //constants check
	
	{

int flag=0;
for(int i=0;i<s1.length();i++)
{

	if(num(s1[i]))
	{

		flag=1;

	}
if(flag ==1)
	return 1;
else 
	return 0;
}



	}


int idd(char c)	  
{

if(c>=65&&c<=90 ||  c>=98&&c<=122)
{
return 1;


}
else 
	return 0;
}


int id(string s1)  //identifier check

{

int flag =0;
for(int i=0;i<s1.length();i++)
{

	if(idd(s1[i]))
		{

			flag =1;

		}
if (flag==1)
{

return 1;

}
else 
	return 0;
}

}