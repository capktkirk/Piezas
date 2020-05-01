/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
#define fot(i,j) for(int i = 0, j = 0; j <= 4 && i <= 3; (i == 3) ? i = 0, j++ : i++)
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
//Constructor Test

TEST(PiezasTest, make_blank){
	Piezas board;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			ASSERT_EQ(board.pieceAt(i,j), Blank);
		}
	}
}