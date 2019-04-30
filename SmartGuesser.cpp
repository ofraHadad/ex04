#include "SmartGuesser.hpp"

using namespace bullpgia;

string SmartGuesser:: guess()
{
	char x=('0'+count);
	if(theNumbers.length()<=this->length)
	{
		string ans="";
		for(int i=0; i<this->length;i++)
			ans=ans +x;
		count++;
		return ans;
	}
	return "";
}

void SmartGuesser:: learn(string reply)
{
	int i;
	string b,p;
	char x=('0'+count-1);
				
	for(i=0; i<reply.length();i++)
	{
		if(reply.at(i)==',')
			break;
	}
	b= reply.substr(0,i);
	
	p= reply.substr(i+1,reply.length()-1);
	
	stringstream geek(b); 
	stringstream geek2(p); 
	geek >> bull;
	geek2>> pgia;
	
	if(theNumbers.length()<=this->length)
	{
		for(int j=0; j<this->bull; j++)
		{
			theNumbers=theNumbers+x;
		}
	}
}
