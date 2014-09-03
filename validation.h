#ifndef VALIDATION_H
#define VALIDATION_H
#include "tile.h"

extern Tile *tile[8][8];
extern int exp[60],max,wR,wC;

class validation
{
    int flag,retVal;

public:
    validation();
    void canHitKing();
    int chooser(Tile *temp);
    int validateBishop(Tile *temp);
    int validateQueen(Tile *temp);
    int validateKing(Tile *temp);
    int validateHorse(Tile *temp);
    int validateRook(Tile *temp);
    int validatePawn(Tile *temp);
    void orange();
    void pieces();
    void icolsTest(Tile *temp);
    int check(Tile *temp);
};

#endif // VALIDATION_H
