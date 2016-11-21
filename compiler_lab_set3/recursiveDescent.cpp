# include <bits/stdc++.h>
using namespace std;
vector < pair < char, vector < string >  > >  V;
int counter=1;
string inputString;
void parse(string a)
{
    char c=a[0];
    vector < string > container;
    for(int i=3;i<a.length();i++)
    {
        string temp="";
        int j=0;
        for(j=i;j<a.length();j++)
        {
            if(a[j]!='|')
                temp=temp+a[j];
            else
                break;
        }
        i=j;
        container.push_back(temp);
    }
    V.push_back(make_pair(c, container));
}


void display()
{
    cout<<" inside display\n"<<endl;
    printf("\n\n");
    for(int i=0;i<V.size();i++)
    {
        char var= V[i].first;
        printf("%c \n",var);
        vector< string > temp=V[i].second;
        for(int j=0; j<temp.size(); j++)
        {
            cout<<temp[j]<<" ";
        }
        cout<<endl<<endl;
    }
}

int findIndex(char a)
{
    for(int i=0;i<V.size();i++)
    {
        if(V[i].first==a)
            return i;
    }
}

int global = 0;
bool recursive(int index )
{
    int current = global;
    vector < string > prod = V[index].second;
    for(int i = 0; i < prod.size(); i++)
    {
        string currentProd = prod[i];
        int flag = 1;
        for(int j = 0; j < currentProd.length(); j++)
        {
            //printf("index = %d i = %d j = %d global = %d\n", index, i, j, global);
            //printf("inputString character =%c prod character = %c\n", inputString[global], currentProd[j]);
            //getchar();
            if(inputString[global] == currentProd[j])
                global++;
            else if((inputString[global] != currentProd[j]) && (currentProd[j] >= 97 && currentProd[j] <= 122))
            {
                flag = 0;
                global = current;
                break;
            }
            else
            {
                int prodIndex =  findIndex(currentProd[j]);
                bool temp = recursive(prodIndex);
                if(temp == -1)
                {
                    flag = 0;
                    global = current;
                    break;
                }
            }
        }
        if(index == 0 && global != inputString.length())
            continue;
        if(flag)
            return 1;
    }
    return 0;
}
    
int main(void)
{
    int n;
    //cout<<"Enter the no of productions\n";
    cin>>n;
    int orig=n;
    //cout<<"Enter name of the variable followed by its productions.Like A->Ab|Ac|E. Don't give any spaces within this string. E is for denoting the blank or the null symbol\n";
    while(n--)
    {
        //cout<<"Enter the production rule\n"<<endl;
        string s;
        cin>>s;
        parse(s);
        for(int i=0;i<V.size();i++)
        {
            char a=V[i].first;
            vector < string > temp = V[i].second;
            //cout<<a<<endl;
            for(int j=0;j<temp.size();j++)
            {
                //cout<<temp[j]<<" ";
            }
            //cout<<endl;
        }
    }
    //printf("Enter the string which is to be checked\n");
    cin>>inputString;
    bool answer = recursive(0);
    if(global == inputString.length())
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
