#include<iostream>
using namespace std;

int E(string str);
int Ee(string str);
int T(string str);
int Te(string str);
int F(string str);

int i=0;
int main()
{
		string str;
		//int flag=0;
		cout<<"enter an airthmetic expression:  ";
		cin>>str;
		/*for(int j=0;j<str.length();j++)
		{
			if(str[j]=='a'||str[j]==')'||str[j]=='('||str[j]=='+'||str[j]=='*')
				flag=1;
			else
				{
					flag=0;
					break;
				}
		}
*/
//		if(flag=1)
			if(E(str)==1)
			{
				
				if(i==str.length())
					cout<<"String gets accepted";
				else 
				cout<<"string gets rejected";
			}
			else 
				cout<<"string gets rejected";
		/*}
		else
			cout<<"string gets rejected";	
			return(0);*/
}

int E(string str)
{
		if(T(str))
			if(Ee(str))
				{
					cout<<" E ";
					return(1);
				}
		else
			return(0);
}

int Ee(string str)
{
		if(str[i]=='+')
			{
				i++;
				if(T(str))
					{
						if(Ee(str))
						{
							cout<<" Ee ";
							return(1);
						}
					}
			}
		else
		{
			cout<<" Ee ";
			return (1);
		} 
		
}

int T(string str)
{
		if(F(str))
			{if(Te(str))
				{

					cout<<" T ";
					return(1);
				}
			}
		else
			return(0);
}

int Te(string str)
{
		if(str[i]=='*')
		{
			i++;
			if(F(str))
				{
						if(Te(str))
						{
							cout<<" Te ";
							return(1);
						}
				}
		}
		else
		{
			cout<<" Te ";
			return (1);
		}    
}

int F(string str)
{
		if(str[i]=='(')
		{
			i++;
			if(E(str))
				{
					if(str[i]==')')
					{
						i++;
						cout<<" F ";
						return(1);
					}
				}
		}
		else if(str[i]=='a')
		{
			i++;
			cout<<" F ";
			return(1);
		}
		else
			return(0);
}