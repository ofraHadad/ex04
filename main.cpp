#include <iostream>
using namespace std;

#include "play.cpp"
#include "DummyChoosers.cpp"
#include "DummyGuessers.cpp"
#include "SmartGuesser.cpp"
#include "play.hpp"
#include "Chooser.hpp"
#include "Guesser.hpp"
#include "SmartGuesser.hpp"
using namespace bullpgia;

int main() {
	ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
	
	SmartGuesser smarty;
	
		cout << play(c1234, smarty, 4, 100) << endl;  // smarty should always win in at most 10 turns!
	
	return 0;
}
