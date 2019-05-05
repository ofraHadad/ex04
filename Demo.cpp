#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
using namespace bullpgia;

int main() {
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"},c8856{"0123456789"};
	
	SmartGuesser smarty;
	cout << play(c8856, smarty, 10, 100) << endl;  // smarty should always win in at most 10 turns!
	
	return 0;
}
