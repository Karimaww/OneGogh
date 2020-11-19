#include <fstream>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	ifstream codeInput;
	ofstream codeOut;
	codeInput.open("gcode.txt");
	codeOut.open("gcodenew.txt");
	int n=0;
	while(!codeInput.eof())
	{
		string word;
		string buf;
		codeInput >> word;
		for(int i=0; i<word.length();i++)
		{
			if(word.substr(i,1)==";") n=i;
		}
		codeOut<<"draw("<<word.substr(0,n)<<"+10)*5,("<<word.substr(n+1, word.length()-n-3)<<"+10)*5);"<<endl<<"delay(500);"<<endl;
	}
}
