/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/

TEST(GuesserTest, correctGuess1)
{
	Guesser my_guess("wonderful");
	bool actual = my_guess.match("wonderful");
	ASSERT_EQ(true, actual);
}

TEST(GuesserTest, correctGuess2)
{
	Guesser my_guess("wonderful");
	bool actual = my_guess.match("wonderf");
	actual = my_guess.match("wonderful");
	ASSERT_EQ(true, actual);
}

TEST(GuesserTest, correctGuess3)
{
	Guesser my_guess("wonderful");
	bool actual = my_guess.match("wondering");
	actual = my_guess.match("wonderrr");
	actual = my_guess.match("wonderful");
	ASSERT_EQ(true, actual);
}

TEST(GuesserTest, outOfGuesses)
{
	Guesser my_guess("wonderful");
	bool actual = my_guess.match("wonderf");
	actual = my_guess.match("wonderfu");
	actual = my_guess.match("wonderfi");
	actual = my_guess.match("wonderful");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, wrongGuess)
{
	Guesser my_guess("wonderful");
	bool actual = my_guess.match("butterfly");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, bruteTestShort)
{
	Guesser my_guess("wonderful");
	bool actual = my_guess.match("won");
	actual = my_guess.match("wonderful");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, bruteTestLong)
{
	Guesser my_guess("wonderful");
	bool actual = my_guess.match("runonsentence");
	actual = my_guess.match("wonderful");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, distanceTestLow)
{
	Guesser my_guess("wonderful");
	bool actual = my_guess.match("wonderfully");
	actual = my_guess.match("wonderful");
	ASSERT_EQ(true, actual);
}

TEST(GuesserTest, distanceTestHigh)
{
	Guesser my_guess("wonderful");
	bool actual = my_guess.match("superduper");
	actual = my_guess.match("wonderful");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, emptyGuessWrong)
{
	Guesser my_guess("wonderful");
	bool actual = my_guess.match("");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, emptyGuessRight)
{
	Guesser my_guess("");
	bool actual = my_guess.match("");
	ASSERT_EQ(true, actual);
}

TEST(GuesserTest, emptyString)
{
	Guesser my_guess("");
	bool actual = my_guess.match("wonderful");
	ASSERT_EQ(false, actual);
}
