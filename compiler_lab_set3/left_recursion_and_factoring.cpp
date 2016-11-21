#include <iostream>
#include <string>
using namespace std;

int main(){

    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    string prod;
    while(n--){
        cin >> prod;

        if(prod[0] == prod[3]){
            cout << "Production is left recursive" << endl;

            // first
            string first;
            int i;
            for(i = 4; prod[i] != '|'; i++)
                first[i-4] = prod[i];
            

            //Without Recursion
            cout << prod[0] << "->";
            // second
            for(i = i + 1; i < prod.length(); i++)
                cout << prod[i];
            cout << prod[0] << '`' << endl;

            cout << prod[0] << "\'->";
            for(i = 4; prod[i] != '|'; i++)
                cout << prod[i];
            cout << prod[0] << "\'" << "|" << prod[0] << endl;
        }else{
            cout << "production is not left recursive" << endl;
        }

    }

    return 0;
}