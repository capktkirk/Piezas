/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
#define fot(i,j) for(int i = 0, j = 0; j < BOARD_ROWS && i < BOARD_COLS; (i == BOARD_ROWS) ? i = 0, j++ : i++)
 
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

TEST(PiezasTest, constructor_test){
	Piezas board;
	ASSERT_TRUE(true);
}

TEST(PiezasTest, blank_test){
	Piezas board;
	fot(j, i){
		ASSERT_EQ(board.pieceAt(i,j), Blank);
	}
}
//Test singular X
TEST(PiezasTest, drop_X){
	Piezas board;
	Piece ret = board.dropPiece(0);
  	ASSERT_EQ(ret, X);
}
//Test singular O
TEST(PiezasTest, drop_O){
	Piezas board;
	Piece ret = board.dropPiece(0);
  	ASSERT_EQ(ret, O);
}
//Test reset of the 
TEST(PiezasTest, drop_O_X_reset){
	Piezas board;
	Piece ret = board.dropPiece(0);
  	ret = board.dropPiece(1);
  	board.reset();
  	fot(j, i){
  		ASSERT_EQ(board.pieceAt(i,j), Blank);
  	}
}

