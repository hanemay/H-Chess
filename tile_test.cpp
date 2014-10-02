#include "tile.h"
#include "tile_test.h"
#include <UnitTest++.h>
extern Tile *tile[8][8];
namespace{
    TEST(MyFirstTileTest){
        int countPieces = 0;
        for(int rows = 0; rows < 8; rows++){
            for(int columns = 0; columns <8; columns++){
                if(tile[rows][columns]->piece == 1){
                    if(tile[rows][columns]->pieceColor==0 || tile[rows][columns]->pieceColor==1){
                    countPieces += 1;
                    }
                }
            }
        }
        CHECK_EQUAL(16,countPieces/2);
    }
    TEST(MySecondTileTest){
        int tileNumber = 0;
        for(int rows = 0; rows < 8; rows++){
            for(int columns = 0; columns <8; columns++){
                if(tile[rows][columns]->piece == 1){
                    if(tile[rows][columns]->pieceColor==0 || tile[rows][columns]->pieceColor==1){
                    tileNumber = tile[rows][columns]->tileNum+1;
                    }
                }
            }
        }
        CHECK_EQUAL(64,tileNumber);
    }
    TEST(MyThirdTileTest){
        int pawn = 0;
        int king = 0;
        int queen = 0;
        int knight = 0;
        int rook = 0;
        int bishop = 0;
        for(int rows = 0; rows < 8; rows++){
            for(int columns = 0; columns <8; columns++){
                if(tile[rows][columns]->piece == 1){
                    if(tile[rows][columns]->pieceName == 'P'){
                        pawn += 1;
                    }
                    if(tile[rows][columns]->pieceName == 'R'){
                        rook += 1;
                    }
                    if(tile[rows][columns]->pieceName == 'H'){
                        knight += 1;
                    }
                    if(tile[rows][columns]->pieceName == 'K'){
                        king += 1;
                    }
                    if(tile[rows][columns]->pieceName == 'Q'){
                        queen += 1;
                    }
                    if(tile[rows][columns]->pieceName == 'B'){
                        bishop += 1;
                    }
                }
            }
        }
        CHECK_EQUAL(16,pawn);
        CHECK_EQUAL(2,king);
        CHECK_EQUAL(2,queen);
        CHECK_EQUAL(4,knight);
        CHECK_EQUAL(4,rook);
        CHECK_EQUAL(3,bishop);
    }
}
