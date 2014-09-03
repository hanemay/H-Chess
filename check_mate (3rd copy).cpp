#include "check_mate.h"
#include "validation.h"
#include <iostream>
int whiteKingTile = 4;
int blackKingTile = 60;
int colsWhite[8][8][64];
int colsBlack[8][8][64];
int cols[8][8][64];
// row col tile
int wcols[64];
int ROW;
int COL;


extern Tile *tile[8][8];
check_mate::check_mate()
{

}
void check_mate::add_to_black(int row, int col, int tiles){
checkIfChess(tiles);
           /* if(tile[row][col]->piece!=1){
                for(int tiles = 0; tiles < 64; tiles){
                    colsWhite[row][col][tiles] = 000;
                    colsBlack[row][col][tiles] = 000;
                    //wcols[tiles] =-1;
                }
            }*/


    colsBlack[row][col][tiles] = tiles;
}
void check_mate::add_to_white(int row, int col, int tiles){
checkIfChess(tiles);
            /*if(tile[row][col]->piece!=1){
                for(int tiles = 0; tiles < 64; tiles){
                    colsWhite[row][col][tiles] = 000;
                    colsBlack[row][col][tiles] = 000;
                    wcols[tiles] =-1;
                }
            }*/

   colsWhite[row][col][tiles] = tiles;

}


void check_mate::icolsTest(Tile *temp)
{
    switch(temp->pieceName)
    {
    case 'P': flag=validatePawn(temp);
              break;

    case 'R': flag=validateRook(temp);
              break;

    case 'H': flag=validateHorse(temp);
              break;

    case 'K': flag=validateKing(temp);
              break;

    case 'Q': flag=validateQueen(temp);
              break;

    case 'B': flag=validateBishop(temp);
              break;

    }
  //  pieces();
}
void check_mate::canHitKing(){
//std::cout<<"CAN HIT KING TEST"<<std::endl;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j<8;j++){
            if(tile[i][j]->piece==1){
            //    std::cout<<tile[i][j]->pieceName;

                if(tile[i][j]->pieceName=='K'){
                    if(tile[i][j]->pieceColor==0){

                    blackKingTile =tile[i][j]->tileNum;
                    std::cout<<"BLACK KING CAN BE HIT AT "<<tile[i][j]->tileNum<<std::endl;
                    }else{
                    whiteKingTile=tile[i][j]->tileNum;
                    std::cout<<"WHITE KING CAN BE HIT AT "<<tile[i][j]->tileNum<<std::endl;
                    }
                }
                icolsTest(tile[i][j]);
                ROW = tile[i][j]->row;
                COL = tile[i][j]->col;
               // icols[64] = { NULL };

            }

            }
        }

    //std::cout<<"CAN HIT KING TEST ENDED"<<std::endl;
    for(int i = 0; i<8; i++){
        for(int j = 0; j <8; j++){
            for(int k = 0; k < 64; k++){

                if(cols[i][j][k]!=0){
                std::cout<<cols[i][j][k]<<" ";
                }
                if(blackKingTile == cols[i][j][k]){
                    std::cout<<"CHESSSSSSSS"<<std::endl;
                }
                if(whiteKingTile == cols[i][j][k]){
                    std::cout<<"CHESSSSSSSS"<<std::endl;
                }

            }
        }

    }
//PAWN
}
int check_mate::checkIfChess(int tileNumb){
    for(int i = 0; i<8; i++){
        for(int j = 0; j <8; j++){
            for(int k = 0; k < 64; k++){

                if(cols[i][j][k]!=0){
               // std::cout<<cols[i][j][k]<<" ";
                }
                if(blackKingTile == cols[i][j][k]){
                    std::cout<<"CHESSSSSSSS"<<std::endl;
                }
                if(whiteKingTile == cols[i][j][k]){
                    std::cout<<"CHESSSSSSSS"<<std::endl;
                }

            }
        }

    }
                return tileNumb;
}
int check_mate::checkIfChess2(){
    std::cout<<"check if chess2"<<std::endl;
    for(int i = 0; i<8; i++){
        for(int j = 0; j <8; j++){
            for(int k = 0; k < 64; k++){
               // std::cout<<colsWhite[i][j][k]<<" ";
                if(colsBlack[i][j][k]!=0){
                if(blackKingTile == k){
                    std::cout<<"CHESSSSSSSS NY ALGO SORT KONGE "<< tile[i][j]->pieceName<<std::endl;
                }
                if(whiteKingTile == k){
                    std::cout<<"CHESSSSSSSS NY ALGO"<<std::endl;
                }
                }


            }
        }

    }
                return 22;
}
int check_mate::validatePawn(Tile *temp)
{
    int row,col;

    row=temp->row;
    col=temp->col;
    retVal=0;
    /**std::cout<<tile[row][col]->pieceColor<< " PIECE COLOR"<<std::endl;
    std::cout<<tile[row][col]->pieceColor<< " PIECE COLOR"<<std::endl;
    std::cout<<tile[row][col]->pieceColor<< " PIECE COLOR"<<std::endl;
    std::cout<<tile[row][col]->pieceColor<< " PIECE COLOR"<<std::endl;*/
    //White Pawn
    if(temp->pieceColor)
    {
        if(row-1>=0 && !tile[row-1][col]->piece)
        {
            if(tile[row][col]->pieceColor!='1'){
                add_to_black(row,col,tile[row-1][col]->tileNum);
            }else{
                add_to_white(row,col,tile[row-1][col]->tileNum);
            }
            //checkIfChess(tile[row-1][col]->tileNum);
           // cols[ROW][COL][tile[row-1][col]->tileNum]=tile[row-1][col]->tileNum;
            //std::cout<<cols[ROW][COL][tile[row-1][col]->tileNum]<<" ";
            retVal=1;
        }

        if(row==6 && !tile[5][col]->piece && !tile[4][col]->piece)
        {
            if(tile[row][col]->pieceColor!='1'){
                std::cout<<"add to black"<<std::endl;
                add_to_black(row,col,tile[row-2][col]->tileNum);
            }else{
                add_to_white(row,col,tile[row-2][col]->tileNum);
            }
           /* checkIfChess(tile[row-2][col]->tileNum);
            cols[ROW][COL][tile[row-2][col]->tileNum]=tile[row-2][col]->tileNum;
            std::cout<<cols[ROW][COL][tile[row-2][col]->tileNum]<<" ";*/
            retVal=1;
        }

        if(row-1>=0 && col-1>=0)
        {

            if(tile[row-1][col-1]->pieceColor!=temp->pieceColor && tile[row-1][col-1]->piece)
            {
            if(tile[row][col]->pieceColor!='1'){
                 std::cout<<"add to black"<<std::endl;
                add_to_black(row,col,tile[row-1][col-1]->tileNum);
            }else{
                add_to_white(row,col,tile[row-1][col-1]->tileNum);
            }
            /*checkIfChess(tile[row-1][col-1]->tileNum);
            cols[ROW][COL][tile[row-1][col-1]->tileNum]=tile[row-1][col-1]->tileNum;
            std::cout<<tile[row-1][col-1]->tileNum<<" ";*/
            retVal=1;
            }
        }

        if(row-1>=0 && col+1<=7)
        {

            if(tile[row-1][col+1]->pieceColor!=temp->pieceColor && tile[row-1][col+1]->piece)
            {
            if(tile[row][col]->pieceColor!='1'){
                 std::cout<<"add to black"<<std::endl;
                add_to_black(row,col,tile[row-1][col+1]->tileNum);
            }else{
                add_to_white(row,col,tile[row-1][col+1]->tileNum);
            }
               /** checkIfChess(tile[row-1][col+1]->tileNum);
                cols[ROW][COL][tile[row-1][col+1]->tileNum]=tile[row-1][col+1]->tileNum;
                std::cout<<tile[row-1][col+1]->tileNum<<" ";*/
                retVal=1;
            }
        }
    }
    else
    {
        if(row+1<=7 && !tile[row+1][col]->piece)
        {
            if(tile[row][col]->pieceColor!='1'){
                 std::cout<<"add to black"<<std::endl;
                add_to_black(row,col,tile[row+1][col]->tileNum);
            }else{
                add_to_white(row,col,tile[row+1][col]->tileNum);
            }
           /* checkIfChess(tile[row+1][col]->tileNum);
            cols[ROW][COL][tile[row+1][col]->tileNum]=tile[row+1][col]->tileNum;
            std::cout<<tile[row+1][col]->tileNum<<" ";*/
            retVal=1;
        }

        if(row==1 && !tile[2][col]->piece && !tile[3][col]->piece)
        {
            if(tile[row][col]->pieceColor!='1'){
                 std::cout<<"add to black"<<std::endl;
                add_to_black(row,col,tile[row+2][col]->tileNum);
            }else{
                add_to_white(row,col,tile[row+2][col]->tileNum);
            }
           /** checkIfChess(tile[row+2][col]->tileNum);
            cols[ROW][COL][tile[row+2][col]->tileNum]=tile[row+2][col]->tileNum;
            std::cout<<tile[row+2][col]->tileNum<<" ";*/
            retVal=1;
        }

        if(row+1<=7 && col-1>=0)
        {
            if(tile[row+1][col-1]->pieceColor!=temp->pieceColor && tile[row+1][col-1]->piece)
            {
            if(tile[row][col]->pieceColor!='1'){
                 std::cout<<"add to black"<<std::endl;
                add_to_black(row,col,tile[row+1][col-1]->tileNum);
            }else{
                add_to_white(row,col,tile[row+1][col-1]->tileNum);
            }
                /**checkIfChess(tile[row+1][col-1]->tileNum);
                cols[ROW][COL][tile[row+1][col-1]->tileNum]=tile[row+1][col-1]->tileNum;
                std::cout<<tile[row+1][col-1]->tileNum<<" ";*/
                retVal=1;
            }
        }

        if(row+1<=7 && col+1<=7)
        {
            if(tile[row+1][col+1]->pieceColor!=temp->pieceColor && tile[row+1][col+1]->piece)
            {
            if(tile[row][col]->pieceColor!='1'){
                 std::cout<<"add to black"<<std::endl;
                add_to_black(row,col,tile[row+1][col+1]->tileNum);
            }else{
                add_to_white(row,col,tile[row+1][col+1]->tileNum);
            }
               /** checkIfChess(tile[row+1][col+1]->tileNum);
                cols[ROW][COL][tile[row+1][col+1]->tileNum]=tile[row+1][col+1]->tileNum;
                std::cout<<tile[row+1][col+1]->tileNum<<" ";*/
                retVal=1;
            }
        }
    }
    return retVal;
}


//ROOK
int check_mate::validateRook(Tile *temp)
{
    int r,c;

    retVal=0;

    r=temp->row;
    c=temp->col;
    while(r-->0)
    {
        if(!tile[r][c]->piece)
        {
            if(tile[r][c]->pieceColor!='1'){
                add_to_black(r,c,tile[r][c]->tileNum);
            }else{
                add_to_white(r,c,tile[r][c]->tileNum);
            }
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            if(tile[r][c]->pieceColor!='1'){
                add_to_black(r,c,tile[r][c]->tileNum);
            }else{
                add_to_white(r,c,tile[r][c]->tileNum);
            }
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7)
    {
        if(!tile[r][c]->piece)
        {
            if(tile[r][c]->pieceColor!='1'){
                add_to_black(r,c,tile[r][c]->tileNum);
            }else{
                add_to_white(r,c,tile[r][c]->tileNum);
            }
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            if(tile[r][c]->pieceColor!='1'){
                add_to_black(r,c,tile[r][c]->tileNum);
            }else{
                add_to_white(r,c,tile[r][c]->tileNum);
            }
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(c++<7)
    {
        if(!tile[r][c]->piece)
        {
            if(tile[r][c]->pieceColor!='1'){
                add_to_black(r,c,tile[r][c]->tileNum);
            }else{
                add_to_white(r,c,tile[r][c]->tileNum);
            }
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            if(tile[r][c]->pieceColor!='1'){
                add_to_black(r,c,tile[r][c]->tileNum);
            }else{
                add_to_white(r,c,tile[r][c]->tileNum);
            }
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(c-->0)
    {
        if(!tile[r][c]->piece)
        {
            if(tile[r][c]->pieceColor!='1'){
                add_to_black(r,c,tile[r][c]->tileNum);
            }else{
                add_to_white(r,c,tile[r][c]->tileNum);
            }
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            if(tile[r][c]->pieceColor!='1'){
                add_to_black(r,c,tile[r][c]->tileNum);
            }else{
                add_to_white(r,c,tile[r][c]->tileNum);
            }
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }


    return retVal;
}


//HORSE
int check_mate::validateHorse(Tile *temp)
{
    int r,c;
    retVal=0;

    r=temp->row;
    c=temp->col;

    if(r-2>=0 && c-1>=0)
    {
        if(tile[r-2][c-1]->pieceColor!=temp->pieceColor || !tile[r-2][c-1]->piece)
        {
            exp[max++]=tile[r-2][c-1]->tileNum;
            retVal=1;
        }
    }

    if(r-2>=0 && c+1<=7)
    {
        if(tile[r-2][c+1]->pieceColor!=temp->pieceColor || !tile[r-2][c+1]->piece)
        {
            exp[max++]=tile[r-2][c+1]->tileNum;
            retVal=1;
        }
    }

    if(r-1>=0 && c-2>=0)
    {
        if(tile[r-1][c-2]->pieceColor!=temp->pieceColor || !tile[r-1][c-2]->piece)
        {
            exp[max++]=tile[r-1][c-2]->tileNum;
            retVal=1;
        }
    }

    if(r-1>=0 && c+2<=7)
    {
        if(tile[r-1][c+2]->pieceColor!=temp->pieceColor || !tile[r-1][c+2]->piece)
        {
            exp[max++]=tile[r-1][c+2]->tileNum;
            retVal=1;
        }
    }

    if(r+2<=7 && c+1<=7)
    {
        if(tile[r+2][c+1]->pieceColor!=temp->pieceColor || !tile[r+2][c+1]->piece)
        {
            exp[max++]=tile[r+2][c+1]->tileNum;
            retVal=1;
        }
    }

    if(r+2<=7 && c-1>=0)
    {
        if(tile[r+2][c-1]->pieceColor!=temp->pieceColor || !tile[r+2][c-1]->piece)
        {
            exp[max++]=tile[r+2][c-1]->tileNum;
            retVal=1;
        }
    }

    if(r+1<=7 && c-2>=0)
    {
        if(tile[r+1][c-2]->pieceColor!=temp->pieceColor || !tile[r+1][c-2]->piece)
        {
            exp[max++]=tile[r+1][c-2]->tileNum;
            retVal=1;
        }
    }

    if(r+1<=7 && c+2<=7)
    {
        if(tile[r+1][c+2]->pieceColor!=temp->pieceColor || !tile[r+1][c+2]->piece)
        {
            exp[max++]=tile[r+1][c+2]->tileNum;
            retVal=1;
        }
    }

    return retVal;
}


//KING
int check_mate::validateKing(Tile *temp)
{
    int r,c;
    retVal=0;

    r=temp->row;
    c=temp->col;

    if(r-1>=0)
    {
        if(!tile[r-1][c]->piece || tile[r-1][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r-1][c]->tileNum;
            retVal=1;
        }
    }

    if(r+1<=7)
    {
        if(!tile[r+1][c]->piece || tile[r+1][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r+1][c]->tileNum;
            retVal=1;
        }
    }

    if(c-1>=0)
    {
        if(!tile[r][c-1]->piece || tile[r][c-1]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c-1]->tileNum;
            retVal=1;
        }
    }

    if(c+1<=7)
    {
        if(!tile[r][c+1]->piece || tile[r][c+1]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c+1]->tileNum;
            retVal=1;
        }
    }

    if(r-1>=0 && c-1>=0)
    {
        if(!tile[r-1][c-1]->piece || tile[r-1][c-1]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r-1][c-1]->tileNum;
            retVal=1;
        }
    }

    if(r-1>=0 && c+1<=7)
    {
        if(!tile[r-1][c+1]->piece || tile[r-1][c+1]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r-1][c+1]->tileNum;
            retVal=1;
        }
    }

    if(r+1<=7 && c-1>=0)
    {
        if(!tile[r+1][c-1]->piece || tile[r+1][c-1]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r+1][c-1]->tileNum;
            retVal=1;
        }
    }

    if(r+1<=7 && c+1<=7)
    {
        if(!tile[r+1][c+1]->piece || tile[r+1][c+1]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r+1][c+1]->tileNum;
            retVal=1;
        }
    }

    return retVal;
}


//QUEEN
int check_mate::validateQueen(Tile *temp)
{
    int r,c;

    retVal=0;

    r=temp->row;
    c=temp->col;
    while(r-->0)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(c++<7)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(c-->0)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r-->0 && c++<7)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r-->0 && c-->0)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7 && c++<7)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7 && c-->0)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }


    return retVal;
}

//BISHOP
int check_mate::validateBishop(Tile *temp)
{
    int r,c;
    retVal=0;

    r=temp->row;
    c=temp->col;
    while(r-->0 && c++<7)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;

            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r-->0 && c-->0)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7 && c++<7)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7 && c-->0)
    {
        if(!tile[r][c]->piece)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            exp[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    return retVal;
}

int check_mate::check(Tile *temp)
{
    int r,c,flag;
    retVal=0;

    return retVal;
}


void check_mate::pieces()
{
    int i,n;

    for(i=0;i<max;i++){
      //  icols[i]=tile[exp[i]/8][exp[i]%8]->tileNum;
      if(tile[exp[i]/8][exp[i]%8]->piece==1){
        if(tile[exp[i]/8][exp[i]%8]->tileNum == blackKingTile){
            std::cout<<"KING IN CHESS";
        }
      }
       // std::cout<<tile[exp[i]/8][exp[i]%8]->tileNum<<std::endl;
    }
}
