#ifndef CHECK_MATE_H
#define CHECK_MAKE_H
#include "tile.h"

extern Tile *tile[8][8];
extern int exp[60],max,wR,wC;

class check_mate
{
    int flag,retVal;

public:
    check_mate();
    bool black_king_status();
    bool white_king_status();
    bool check_if_valid_move_not_king(int tileNumber,int tileColour);
    bool check_if_valid_move(int tileNumber, int tileColour);
    int colsWhite[8][8][64];
    int colsBlack[8][8][64];
    int chooser(Tile *temp);
    int get_Cols_Black();
    int get_Cols_White();
    int validateBishop(Tile *temp);
    int validateQueen(Tile *temp);
    int validateKing(Tile *temp);
    int validateHorse(Tile *temp);
    int validateRook(Tile *temp);
    int validatePawn(Tile *temp);
    int check(Tile *temp);
    int checkIfChess2();
    void orange();
    void canHitKing();
    void pieces();
    void icolsTest(Tile *temp);
private:
    void add_possible_fields(int row, int col, int tile);
    void add_to_white(int row, int col, int tile);

};

#endif // CHECK_MATE_H
