# include <bits/stdc++.h>
using namespace std;

bool integerChecker(int index, string input,int last)
{
	if(index==last)
		return 1;
	if(input[index]>=48 && input[index]<=57)
		return integerChecker(index+1,input,last);
	else
		return 0;
}
	
	
int main(void)
{
	// there are four types of productions S- A| A.A | AeA | A.AeA
	cout<<"Enter the string which you want to check\n";
	string input;
	cin>>input;
	// now we have to check for the four possibilites and do it one by one and if any of them satisfy then output yes
	// S - A
	bool aa,b,c,d;
	aa=integerChecker(0,input,input.length());
	getchar();
	printf("aa=%d\n",aa);
	getchar();
	// S - A.A
	for(int i=0;i<input.length();i++)
	{
		if(input[i]=='.')
		{
			printf(". found at index %d\n",i);
			bool t1=integerChecker(0,input,i);
			bool t2=integerChecker(i+1,input,input.length());
			printf("t1=%d t2=%d\n",t1,t2);
			getchar();
			b= t1 && t2;
			break;
		}
	}
	// S - AeA
	for(int i=0;i<input.length();i++)
	{
		if(input[i]=='e')
		{
			printf("e found at index %d\n",i);
			bool t1=integerChecker(0,input,i);
			bool t2=integerChecker(i+1,input,input.length());
			printf("t1=%d and t2=%d\n",t1,t2);
			getchar();
			c= t1 && t2;
			break;
		}
	}
	// S - A.AeA
	for(int i=0;i<input.length();i++)
	{
		if(input[i]=='.')
		{
			printf(". found at index %d\n",i);
			bool t1,t2;
			t1=integerChecker(0,input,i);
			printf("t1=%d\n",t1);
			getchar();
			if(t1==1)
			{
				for(int j=i+1;j<input.length();j++)
				{
					if(input[j]=='e')
					{
						printf("e found at index %d\n",j);
						bool r1=integerChecker(i+1,input,j);
						bool r2=integerChecker(j+1,input,input.length());
						printf("r1=%d and r2=%d\n",r1,r2);
						getchar();
						t2= r1 && r2;
						break;
					}
				}
				d= t1 && t2;
			}
		}
	}
	bool ans = aa || b || c || d;
	if(ans==1)
	{
		printf("Yes. The string is consistent with the given grammar\n");
	}
	else
	{
		printf("Sorry. The string did not accepted\n");
	}
	return 0;
}	
