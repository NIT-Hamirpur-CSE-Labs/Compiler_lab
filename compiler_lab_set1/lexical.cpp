#include<iostream>
#include<string>
#include<fstream>

using namespace std;
int main(void)
{
	ofstream myfile,newfile;
	int p;
  	myfile.open ("example.txt");
 	myfile << "Writing this to a file.\n";
 	newfile.open("example2.txt");
 	while((p=getc(myfile))!=EOF)
    {
        fputc(p,newfile);
 
        // since the ascii code for a blank space is 32
        if (p==32) 
        {
            while((p=getc(myfile))==32)
            {
 
            }
            fputc(p,newfile);
        }
    }
  	myfile.close();
  	newfile.close();

  	
}
