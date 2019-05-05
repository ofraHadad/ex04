# pragma once
#include "Guesser.hpp"
#include "calculate.hpp"

namespace bullpgia{
	
	class SmartGuesser: public Guesser{
	public:
	char wrong='9';
	string gg="";
	int index=0;
	int index2=0;
	int count=0;
	string theNumbers="";
	string guess() override;
	void learn(string reply) override;
	void startNewGame(int l) override{
				wrong='9';
				length=l;
				gg="";
				index=0;
				index2=0;
				count=0;
				theNumbers="";
				bull=0;
				pgia=0;
				for(int i=0; i<length;i++)
					gg=gg+wrong;
	
		}

	
	};
};