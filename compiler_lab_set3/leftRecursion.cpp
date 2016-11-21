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

    
int findIndex(char a)
{
    for(int i=0;i<V.size();i++)
    {
        if(V[i].first==a)
            return i;
    }
}

char  curChar='K';
void removeLeftRecursion(int index)
{
    // now remove the left recursion
    for(int i=0;i<V.size();i++)
    {
        if(index==i)
        {
            // mark the productions having the same letter as the
            // variable and mark those who don't . Then apply the rule 
            // of left recursion to it.
            printf("\n\n");
            char var = V[i].first;
            cout<<"current variable "<<var<<endl;
            vector < string > prod;
            prod = V[i].second;
            vector < string > temp;
            vector < string > newprod;
            for(int j = 0; j < prod.size(); j++)
            {
                if(prod[j][0]==var)
                {
                    // left recursion found
                    cout<<"Left recursion found. "<<prod[j]<<endl; 
                    string newtemp="";
                    for(int k=1;k<prod[j].length();k++)
                    {
                        newtemp += prod[j][k];
                    }
                    cout<<"this is newtemp\n"<<newtemp<<endl;
                    temp.push_back(newtemp);
                }
            }
            if(temp.size()!=0)
            {
                for(int j=0;j<prod.size();j++)
                {
                    if(prod[j][0]==var)
                        continue;
                    else
                    {
                        newprod.push_back(prod[j]);
                        newprod.push_back(prod[j]+curChar);
                    }
                }
                vector < string > newprod2;
                for(int j=0;j<temp.size();j++)
                {
                    newprod2.push_back(temp[j]+curChar);
                }
                V[i].second=newprod;
                V.push_back(make_pair( curChar, newprod2) );
                curChar++;
            }
            break;
        }
    }
}


void makeChanges(int i, int j)
{
    cout<<" inside make changes\n"<<endl;
    vector < string > prod= V[i].second;
    vector < string > newprod = V[j].second;
    vector < string > finalprod;
    for ( int k=0; k<prod.size(); k++)
    {
        if ( V[j].first == prod[k][0] )
        {
            printf("k=%d\n",k);
            string temp="";
            for ( int p=1; p< prod[k].length(); p++)
            {
                temp = temp + prod[k][p];
            }
            for ( int p=0; p<newprod.size(); p++)
            {
                string temp2="";
                temp2 = newprod[p] + temp;
                finalprod.push_back(temp2);
            }
        }
        else
            finalprod.push_back(prod[k]);
    }
    V[i].second = finalprod;
}



int main(void)
{
    int n;
    cout<<"Enter the no of productions\n";
    cin>>n;
    int orig=n;
    cout<<"Enter name of the variable followed by its productions.Like A->Ab|Ac|E. Don't give any spaces within this string. E is for denoting the blank or the null symbol\n";
    while(n--)
    {
        cout<<"Enter the production rule\n"<<endl;
        string s;
        cin>>s;
        parse(s);
        for(int i=0;i<V.size();i++)
        {
            char a=V[i].first;
            vector < string > temp = V[i].second;
            cout<<a<<endl;
            for(int j=0;j<temp.size();j++)
            {
                cout<<temp[j]<<" ";
            }
            cout<<endl;
        }
    }
    for ( int i=0; i<orig; i++)
    {
        for(int j=0; j<orig; j++)
        {
            
            if (i == j)
                continue;
            printf("i=%d and j=%d\n",i,j);
            cout<<" making changes\n"<<endl;
            makeChanges(i,j);
            display();
            cout<<" removing left recursion from "<<i<<" "<<endl;
            removeLeftRecursion(i);
            display();
        }
    }
    cout<<" this is the final answer \n\n\n"<<endl;
    display();
    return 0;
}
