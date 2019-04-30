# pragma once
#include "Guesser.hpp"
#include "calculate.hpp"

namespace bullpgia{
	
	class SmartGuesser: public Guesser{
	public:
	string guess() override;
	void learn(string reply) override;

	int count=0;
	string theNumbers="";
	};
};