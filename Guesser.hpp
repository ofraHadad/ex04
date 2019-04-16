# pragma once
#include <iostream>
using namespace std;

namespace bullpgia{
	
	class Guesser{
		
		public:
			virtual string guess(){
				string d="";
				return d;
			}
			int length;
			
			
			void startNewGame(int length){}
			void learn(string reply){}
	};
};