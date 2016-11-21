#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str,str2,str3;
	int count;
	cout<<"Enter the String"<<endl;
	getline(cin,str3);
	cout<<"Enter the substring"<<endl;
	getline(cin,str2);
	str=' '+str3+' ';
	
	//to find the occurance
	for(int i=0;i<str.length()-str2.length();i++)
	{	
		
		if(str[i]==str2[0])
		{	
			count=0;
			for(int j=i,k=0;j<str2.length()+i;j++,k++)
			{
				
				if(str[j]==str2[k])
				{
					count++;
					
				}
				if(count==str2.length())
				{	
					if((str[i-1]==' ')&&(str[i+str2.length()]==' '))
					{
						cout<<i-1<<endl;
					}
				}
			
			}
			
				
		}
	}
	
	
						
	
}
		
