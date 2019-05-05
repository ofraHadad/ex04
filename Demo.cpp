#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
using namespace bullpgia;

int main() {
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9"},c8856{"0"};
	
	RandomChooser randy;
		SmartGuesser smarty;
				cout<<play(c9999, smarty, 1, 100)<<endl;  // smarty should always win in at most 10 turns!

			cout<<play(c8856, smarty, 1, 100)<<endl;  // smarty should always win in at most 10 turns!
// smarty should always win in at most 10 turns!
	
	return 0;
}
