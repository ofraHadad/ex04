# pragma once
#include "Guesser.hpp"
#include "calculate.hpp"

namespace bullpgia{
	
	class SmartGuesser: public Guesser{
	public:
	char wrong='9';
	string gg="9999";
	int index=0;
	int index2=0;
	string guess() override;
	void learn(string reply) override;

	int count=0;
	string theNumbers="";
	};
};