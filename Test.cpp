/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"},c8856{"8856"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};
		g1234.learn(calculateBullAndPgia("1234","1234"));
		g12345.learn(calculateBullAndPgia("1234","1122"));
		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1114","4421"), "0,2")       // 0 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4411"), "0,2")       // 0 bull, 2 pgia
		
		.CHECK_EQUAL(g1234.bull,4)//the bull in the guesser
		.CHECK_EQUAL(g1234.pgia,0)//the pgia in the guesser
		.CHECK_EQUAL(g12345.bull,1)//the bull in the guesser
		.CHECK_EQUAL(g12345.pgia,1)//the pgia in the guesser
		
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(smarty.length,4);
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);// smarty should always win in at most 10 turns! 
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=20, true);//our algoritem shuld work after 20 times
			
		}
		
		play(c8856,smarty,4,20);
		testcase.setname("Play with smart guesser 2")
		.CHECK_EQUAL(smarty.theNumbers=="8856",false)
		.CHECK_EQUAL(smarty.theNumbers=="5688",true)//the numbers of the chooser need to be 5688
		.CHECK_EQUAL(smarty.bull,0)//the bull in the guesser
		.CHECK_EQUAL(smarty.pgia,4)//the pgia in the guesser
		.CHECK_EQUAL(play(c1234,smarty,4,20),6) //in 6 turns the guesser win
		.CHECK_EQUAL(smarty.theNumbers=="1234",true)//the numbers of the chooser need to be 5688
		.CHECK_EQUAL(smarty.bull,4)//the bull in the guesser
		.CHECK_EQUAL(smarty.pgia,0);//the pgia in the guesser

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}