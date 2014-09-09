#include "check_mate.h"
#include "validation.h"
#include <iostream>
int whiteKingTile = 4;
int blackKingTile = 60;
int whiteKingRow = 4;
int blackKingRow = 60;
int whiteKingCol = 4;
int blackKingCol = 60;
int colsWhite[8][8][64];
int colsBlack[8][8][64];
int cols[8][8][64];
int ROW;
int COL;
bool white_king_in_chess = false;
bool black_king_in_chess = false;
extern Tile *tile[8][8];
int jj;
int cancelled_chess[16];
check_mate::check_mate()
{

}
bool check_mate::black_king_status(){
    return black_king_in_chess;
}
int check_mate::get_Cols_White(){
    return ***colsWhite;
}
int check_mate::get_Cols_Black(){
    return ***colsBlack;
}
bool check_mate::white_king_status(){
    return white_king_in_chess;
}
bool check_mate::check_if_valid_move(int tileNumber,int tileColour){
    for(int i = 0; i<8; i++){
        for(int j = 0; j < 8; j++){
            if(tileColour!=1){
                if(colsBlack[i][j][tileNumber]==tileNumber){
                    return false;
                }
            }else{
                if(colsWhite[i][j][tileNumber]==tileNumber){
                    return false;
                }
            }
        }
    }
    return true;
}
bool check_mate::check_if_valid_move_not_king(int row, int col,int tileNumber,int tileColour){
    if(black_king_in_chess==true){
        for(int j = 0; j < 64; j++){
            std::cout<<colsBlack[blackKingRow][blackKingCol][j] << " ";
            if(tileColour!=1){
                if(colsBlack[blackKingCol][blackKingRow][j]==tileNumber){
                    std::cout<<" TILE NUMBER: "<<tileNumber<<std::endl;
                    return false;
                }
            }
        }
        return true;
    }
    if(white_king_in_chess==true){
      //  for(int j = 0; j < 64; j++){
            if(tileColour==1){
                if(colsWhite[whiteKingCol][whiteKingRow][tileNumber]==tileNumber){
                    return false;
                }
            }
        //}
        return true;
    }
    return false;
}
void check_mate::add_possible_fields(int row, int col, int tiles){
    if(tile[row][col]->pieceColor==1){
        colsBlack[row][col][tiles] = tiles;
    }else{
        colsWhite[row][col][tiles] = tiles;
    }

}
void check_mate::icolsTest(Tile *temp)
{

    for(int faketiles = 0; faketiles < 64; faketiles++){

        colsWhite[temp->row][temp->col][faketiles] = -1;
        colsBlack[temp->row][temp->col][faketiles] = -1;
        if(temp->pieceName=='Q'){
           // std::cout <<colsBlack[temp->row][temp->col][faketiles]<<" ";
        }
    }
    switch(temp->pieceName)
    {
        case 'P': jj=validatePawn(temp);
                  break;

        case 'R': jj=validateRook(temp);
                  break;

        case 'H': jj=validateHorse(temp);
                  break;

        case 'K': jj=validateKing(temp);
                  break;

        case 'Q': jj=validateQueen(temp);
                  break;

        case 'B': jj=validateBishop(temp);
                  break;
    }
  //  pieces();
}
void check_mate::canHitKing(){
//std::cout<<"CAN HIT KING TEST"<<std::endl;
black_king_in_chess = false;
white_king_in_chess = false;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j<8;j++){
            //std::cout<<tile[i][j]->tileNum<<" ";
            if(tile[i][j]->piece==1){
                if(tile[i][j]->pieceName=='K'){
                    if(tile[i][j]->pieceColor!=1){
                        blackKingTile =tile[i][j]->tileNum;
                        blackKingRow = tile[i][j]->row;
                        blackKingCol = tile[i][j]->col;
                    //std::cout<<"BLACK KING CAN BE HIT AT "<<tile[i][j]->tileNum<<std::endl;
                    }else{
                        whiteKingRow = tile[i][j]->row;
                        whiteKingCol = tile[i][j]->col;
                        whiteKingTile=tile[i][j]->tileNum;
                   // std::cout<<"WHITE KING CAN BE HIT AT "<<tile[i][j]->tileNum<<std::endl;
                    }
                }
                icolsTest(tile[i][j]);
                ROW = tile[i][j]->row;
                COL = tile[i][j]->col;
            }else{
                for(int faketiles=0; faketiles < 64; faketiles++){
                            colsWhite[i][j][faketiles] = -1;
                            colsBlack[i][j][faketiles] = -1;
                }
            }

        }
            //std::cout<<std::endl;
    }
    //std::cout<<"CAN HIT KING TEST ENDED"<<std::endl;
}

int check_mate::checkIfChess2(){
    std::cout<<"check if chess2"<<std::endl;
    for(int i = 0; i<8; i++){
        for(int j = 0; j <8; j++){
            for(int k = 0; k < 64; k++){
               // std::cout<<colsWhite[i][j][k]<<" ";
              /*  if(tile[i][j]->pieceName=='Q'){
                    std::cout<<colsBlack[i][j][k]<<" ";
                }*/
                if(colsBlack[i][j][k]!=-1){
                    if(blackKingTile == k){
                        if(tile[i][j]->piece!=0){
                            std::cout<<"CHESSSSSSSS NY ALGO SORT KONGE "<< tile[i][j]->pieceName<<tile[i][j]->tileNum<<std::endl;
                            black_king_in_chess = true;
                        }
                    }
               }
               if(colsWhite[i][j][k]!=-1){
                    if(whiteKingTile == k){
                        if(tile[i][j]->piece!=0){
                            white_king_in_chess = true;
                            std::cout<<"CHESSSSSSSS NY ALGO"<<std::endl;
                        }
                    }
                }
            }
        }
    }
    std::cout<<"WHITE IS " <<white_king_in_chess<<std::endl;
    std::cout<<"BLACk IS " <<black_king_in_chess<<std::endl;
    return 22;
}
//PAWN
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
            //if(tile[row][col]->pieceColor!='1'){
                add_possible_fields(row,col,tile[row-1][col]->tileNum);
           /* }else{
                add_to_white(row,col,tile[row-1][col]->tileNum);
            }*/
            //checkIfChess(tile[row-1][col]->tileNum);
           // cols[ROW][COL][tile[row-1][col]->tileNum]=tile[row-1][col]->tileNum;
            //std::cout<<cols[ROW][COL][tile[row-1][col]->tileNum]<<" ";
            retVal=1;
        }

        if(row==6 && !tile[5][col]->piece && !tile[4][col]->piece)
        {
            //if(tile[row][col]->pieceColor!='1'){
             //   std::cout<<"add to black"<<std::endl;
                add_possible_fields(row,col,tile[row-2][col]->tileNum);
           /* }else{
                add_to_white(row,col,tile[row-2][col]->tileNum);
            }*/
           /* checkIfChess(tile[row-2][col]->tileNum);
            cols[ROW][COL][tile[row-2][col]->tileNum]=tile[row-2][col]->tileNum;
            std::cout<<cols[ROW][COL][tile[row-2][col]->tileNum]<<" ";*/
            retVal=1;
        }

        if(row-1>=0 && col-1>=0)
        {

            if(tile[row-1][col-1]->pieceColor!=temp->pieceColor && tile[row-1][col-1]->piece)
            {
            //if(tile[row][col]->pieceColor!='1'){
                 //std::cout<<"add to black"<<std::endl;
                add_possible_fields(row,col,tile[row-1][col-1]->tileNum);
           /* }else{
                add_to_white(row,col,tile[row-1][col-1]->tileNum);
            }*/
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
            //if(tile[row][col]->pieceColor!='1'){
                 //std::cout<<"add to black"<<std::endl;
                add_possible_fields(row,col,tile[row-1][col+1]->tileNum);
            /**}else{
                add_to_white(row,col,tile[row-1][col+1]->tileNum);
            }*/
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
            //if(tile[row][col]->pieceColor!='1'){
                 //std::cout<<"add to black"<<std::endl;
                add_possible_fields(row,col,tile[row+1][col]->tileNum);
            /*}else{
                add_to_white(row,col,tile[row+1][col]->tileNum);
            }*/
           /* checkIfChess(tile[row+1][col]->tileNum);
            cols[ROW][COL][tile[row+1][col]->tileNum]=tile[row+1][col]->tileNum;
            std::cout<<tile[row+1][col]->tileNum<<" ";*/
            retVal=1;
        }

        if(row==1 && !tile[2][col]->piece && !tile[3][col]->piece)
        {
           // if(tile[row][col]->pieceColor!='1'){
                 //std::cout<<"add to black"<<std::endl;
                add_possible_fields(row,col,tile[row+2][col]->tileNum);
            /**}else{
                add_to_white(row,col,tile[row+2][col]->tileNum);
            }*/
           /** checkIfChess(tile[row+2][col]->tileNum);
            cols[ROW][COL][tile[row+2][col]->tileNum]=tile[row+2][col]->tileNum;
            std::cout<<tile[row+2][col]->tileNum<<" ";*/
            retVal=1;
        }

        if(row+1<=7 && col-1>=0)
        {
            if(tile[row+1][col-1]->pieceColor!=temp->pieceColor && tile[row+1][col-1]->piece)
            {
            //if(tile[row][col]->pieceColor!='1'){
                 //std::cout<<"add to black"<<std::endl;
                add_possible_fields(row,col,tile[row+1][col-1]->tileNum);
           /** }else{
                add_to_white(row,col,tile[row+1][col-1]->tileNum);
            }*/
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
           // if(tile[row][col]->pieceColor!='1'){
                 //std::cout<<"add to black"<<std::endl;
                add_possible_fields(row,col,tile[row+1][col+1]->tileNum);
           /** }else{
                add_to_white(row,col,tile[row+1][col+1]->tileNum);
            }*/
               /** checkIfChess(tile[row+1][col+1]->tileNum);
                cols[ROW][COL][tile[row+1][col+1]->tileNum]=tile[row+1][col+1]->tileNum;
                std::cout<<tile[row+1][col+1]->tileNum<<" ";*/
                retVal=1;
            }
        }
    }
    return 0;
}


//ROOK
int check_mate::validateRook(Tile *temp){
    int r,c;
    retVal=0;
    r=temp->row;
    c=temp->col;
    while(r-->0)
    {
        if(!tile[r][c]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
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
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
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
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
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
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
            break;
        }
    }


    return retVal;
}


//HORSE
int check_mate::validateHorse(Tile *temp){
    int r,c;
    retVal=0;
    r=temp->row;
    c=temp->col;

    if(r-2>=0 && c-1>=0)
    {
        if(tile[r-2][c-1]->pieceColor!=temp->pieceColor || !tile[r-2][c-1]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r-2][c-1]->tileNum);
            retVal=1;
        }
    }

    if(r-2>=0 && c+1<=7)
    {
        if(tile[r-2][c+1]->pieceColor!=temp->pieceColor || !tile[r-2][c+1]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r-2][c+1]->tileNum);
            retVal=1;
        }
    }

    if(r-1>=0 && c-2>=0)
    {
        if(tile[r-1][c-2]->pieceColor!=temp->pieceColor || !tile[r-1][c-2]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r-1][c-2]->tileNum);
            retVal=1;
        }
    }

    if(r-1>=0 && c+2<=7)
    {
        if(tile[r-1][c+2]->pieceColor!=temp->pieceColor || !tile[r-1][c+2]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r-1][c+2]->tileNum);
            retVal=1;
        }
    }

    if(r+2<=7 && c+1<=7)
    {
        if(tile[r+2][c+1]->pieceColor!=temp->pieceColor || !tile[r+2][c+1]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r+2][c+1]->tileNum);
            retVal=1;
        }
    }

    if(r+2<=7 && c-1>=0)
    {
        if(tile[r+2][c-1]->pieceColor!=temp->pieceColor || !tile[r+2][c-1]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r+2][c-1]->tileNum);
            retVal=1;
        }
    }

    if(r+1<=7 && c-2>=0)
    {
        if(tile[r+1][c-2]->pieceColor!=temp->pieceColor || !tile[r+1][c-2]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r+1][c-2]->tileNum);
            retVal=1;
        }
    }

    if(r+1<=7 && c+2<=7)
    {
        if(tile[r+1][c+2]->pieceColor!=temp->pieceColor || !tile[r+1][c+2]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r+1][c+2]->tileNum);
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
            add_possible_fields(temp->row,temp->col,tile[r-1][c]->tileNum);
            retVal=1;
        }
    }

    if(r+1<=7)
    {
        if(!tile[r+1][c]->piece || tile[r+1][c]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r+1][c]->tileNum);
            retVal=1;
        }
    }

    if(c-1>=0)
    {
        if(!tile[r][c-1]->piece || tile[r][c-1]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r][c-1]->tileNum);
            retVal=1;
        }
    }

    if(c+1<=7)
    {
        if(!tile[r][c+1]->piece || tile[r][c+1]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r][c+1]->tileNum);
            retVal=1;
        }
    }

    if(r-1>=0 && c-1>=0)
    {
        if(!tile[r-1][c-1]->piece || tile[r-1][c-1]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r-1][c-1]->tileNum);
            retVal=1;
        }
    }

    if(r-1>=0 && c+1<=7)
    {
        if(!tile[r-1][c+1]->piece || tile[r-1][c+1]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r-1][c+1]->tileNum);
            retVal=1;
        }
    }

    if(r+1<=7 && c-1>=0)
    {
        if(!tile[r+1][c-1]->piece || tile[r+1][c-1]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r+1][c-1]->tileNum);
            retVal=1;
        }
    }

    if(r+1<=7 && c+1<=7)
    {
        if(!tile[r+1][c+1]->piece || tile[r+1][c+1]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r+1][c+1]->tileNum);
            retVal=1;
        }
    }

    return -1;
}


//QUEEN
int check_mate::validateQueen(Tile *temp)
{
    int r,c;

    r=temp->row;
    c=temp->col;
    while(r-->0)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor || tile[r][c]->pieceName =='K')
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);

        }

        else if(tile[r][c]->pieceColor==temp->pieceColor )
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(c++<7)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(c-->0)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor )
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r-->0 && c++<7)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor )
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r-->0 && c-->0)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor )
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);

            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7 && c++<7)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7 && c-->0)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
            break;
        }
    }


    return -1;
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
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
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
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
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
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
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
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            retVal=1;
            break;
        }
    }

    return -1;
}


