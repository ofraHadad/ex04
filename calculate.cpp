#include "calculate.hpp"
#include <sstream>
#include <string>
using namespace std;

string bullpgia :: calculateBullAndPgia(string choice,string guess){
	
	int bull=0;
	int pgia=0;
	string ans= "";
	string ch="";
	string gu="";
	
	
	for(int i=0; i<choice.length();i++)
	{
		if(choice.at(i)==guess.at(i))
		{
			bull++;
			
		}
		else
		{
			ch= ch+ choice.at(i);
			gu= gu+ guess.at(i);
		}
	}
	for(int i=0; i<ch.length();i++)
	{
		string temp="";
			for(int j=0; j<gu.length();j++)
			{	
				if(ch.at(i)==gu.at(j))
				{
					pgia++;
					temp= temp+gu.substr(j+1,gu.length()-1);
					break;
					
				}
				else
				{
					temp=temp+gu.at(j);
				}
			}
			
			gu=temp;
	}

	stringstream ss;
	ss << bull;
	string code = ss.str();
	stringstream sss;
	sss << pgia;
	string code2 = sss.str();
	ans=code+","+code2;
	return ans;
}


