# include <bits/stdc++.h>
using namespace std;
vector < pair < char, vector < string >  > >  V;
int counter=1;
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

bool checkNull[100];

vector < char >  first(int index)
{
    //getchar();
    //printf("index = %d\n",index);
    char a = V[index].first;
    vector < string > temp = V[index].second;
    vector < char > firstset;
    for(int i = 0; i < temp.size(); i++)
    {
        //printf("index=%d and production=%d\n",index,i);
        //getchar();
        string b = temp[i];
        if( b[0]>65 && b[0]<=90 )
        {
            for(int j = 0; j < b.length(); j++)
            {
                int flag = 0;
                for(int k = 0; k < V.size(); k++)
                {
                    if(V[k].first == b[j])
                    {
                        if(checkNull[k] == 1)
                            flag = 1;
                        vector < char > tempset = first(k);
                        for(int i = 0; i < tempset.size(); i++)
                            firstset.push_back(tempset[i]);
                        break;
                    }
                }
                if(flag == 0)
                    break;
            }
            //printf("index = %d and production=%d\n",index,i);
            /*for(int i = 0; i < firstset.size(); i++)
                printf("character = %c\n",firstset[i]);*/
        }
        else
        {
            firstset.push_back(b[0]);
            continue;
        }
    }
    return firstset;
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
                if(temp[j][0] == 'E')
                    checkNull[i]=1;
            }
            //cout<<endl;
        }
    }
    //display();
    for(int i=0; i<V.size(); i++)
    {
        char a = V[i].first;
        vector < char > First = first(i);
        cout<<"first of index "<<i<<" is"<<endl;
        for(int i = 0; i < First.size(); i++)
            cout<<First[i]<<" ";
        cout<<endl;
    }
    return 0;
}
