#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,i;
	cout<<"enter size";
	cin>>n;
	char str[n];
	char sr[10];
	cout<<"enter string";
	for(i=1;i<=n;i++)
	{
	cin>>str;
	}
	cout<<"enter word to search";
	cin>>sr;
	int c=0,j=0;
	while(str[c]='\0')
	{
		if(str[c]==sr[j] && sr[j]!='\0'&& str[c]!=' ')
		j++;
		else
		j=0;
		i++;
	}
	if(j==strlen(sr))
	cout<<"word is  present"<<endl;
	else
	cout<<" word is not  present"<<endl;
	

}

