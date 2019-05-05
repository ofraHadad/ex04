# pragma once
#include <iostream> 
#include <sstream> 
#include <stdlib.h>
using namespace std; 

namespace bullpgia{
	
	class Guesser{
		
		public:
		int bull;
		int pgia;
			virtual string guess(){
				std::string r="";
				for (int i=0; i<this->length; ++i) {
				char c = '0' + (rand()%10);
				r += c;
				}
				return r;
			}
			int length;
			
			
			virtual void startNewGame(int l){
				length=l;
			}
			virtual void learn(string reply){
				int i;
				string b,p;
				
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
			}
	};
};