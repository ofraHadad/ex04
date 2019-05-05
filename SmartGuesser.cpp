#include "SmartGuesser.hpp"

using namespace bullpgia;

string SmartGuesser:: guess()
{
	char x=('0'+count);
	if(theNumbers.length()<this->length)
	{
		string ans="";
		for(int i=0; i<this->length;i++)
			ans=ans +x;
		count++;
		return ans;
	}
	else
	{
		cout<< gg<<endl;
		return gg;
	}
	
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
	
	if(theNumbers.length()<this->length)
	{
		for(int j=0; j<this->bull; j++)
		{
			theNumbers=theNumbers+x;
		}
		if(bull==0&& gg.at(0)=='9')
		{
			string temp="";
			wrong='0'+count-1;
			for(int j=0; j<this->length; j++)
				temp=temp+wrong;
			gg=temp;
		}
		
		
	}
	else
	{
	
		if(bull==index+1)
		{
			index++;
			cout<<"ssdsd"<<bull<<endl;
			index2=0;
		}
		if(index2!=0)
		{
			
			gg=gg.substr(0,index2-1)+wrong + gg.substr(index2,gg.length()-1);
			
		}
		while(gg.at(index2)!=wrong)
		{
			cout<<"gggg"<<endl;
			index2++;
			cout<<index2<<endl;
		}
		if(index2==0)
			gg=theNumbers.at(index)+gg.substr(index2+1,gg.length()-1);
		
		else if(index2==gg.length()-1)
				gg=gg.substr(0,index2)+theNumbers.at(index);
		else
			gg=gg.substr(0,index2)+theNumbers.at(index)+gg.substr(index2+1,gg.length()-1);
		index2++;

	}
		
}
