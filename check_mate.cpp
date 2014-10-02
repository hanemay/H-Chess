#include "check_mate.h"
#include "validation.h"
#include <iostream>
int whiteKingTile = 4;
bool PE =false;
int blackKingTile = 60;
int whiteKingRow = 4;
int blackKingRow = 60;
int whiteKingCol = 4;
int blackKingCol = 60;
int colsWhite[8][8][64];
int colsBlack[8][8][64];
int aValidWhite[8][8][64];
int aValidBlack[8][8][64];
int cols[8][8][64];
int ROW;
int COL;
int whiteMax = 0;
int blackMax = 0;
int chessRowsWhite[16];
int chessColsWhite[16];
int chessRowsBlack[16];
int chessColsBlack[16];
bool white_king_in_chess = false;
bool black_king_in_chess = false;
extern Tile *tile[8][8];
int jj;
int cancelled_chess[16];
int tempCount = 0;
int tempTiles[16];
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
    canHitKing();
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
   if(black_king_in_chess==true&&tileColour!=1){
            if(tileColour==0){
                for(int i = 0; i<8; i++){
                    for(int j = 0; j<8; j++){

                        if(aValidBlack[i][j][tileNumber]==tileNumber){
                            std::cout<<" TILE colour: "<<tileColour <<" "<<colsBlack[blackKingCol][blackKingRow][tileNumber]<<std::endl;
                            return false;
                        }
                    }
                }
            }
        return true;
    }
    if(white_king_in_chess==true&&tileColour==1){
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
            if((tile[row][col]->pieceName!='P')||PE==true){
                colsBlack[row][col][tiles] = tiles;
            }
        }else{
            if((tile[row][col]->pieceName!='P')||PE==true){
                colsWhite[row][col][tiles] = tiles;
            }
        }
}
void check_mate::add_possible_fields_King(int row, int col, int tiles[]){
    for(int i = 0; i<16; i++){
        if(tile[row][col]->pieceColor==1){
            aValidBlack[row][col][tile[row][col]->tileNum] = tile[row][col]->tileNum;
            if((tile[row][col]->pieceName!='P'&&tile[row][col]->pieceName!='H')||PE==true){
                aValidBlack[row][col][tiles[i]] = tiles[i];
            }
        }else{
            aValidWhite[row][col][tile[row][col]->tileNum] = tile[row][col]->tileNum;
            if((tile[row][col]->pieceName!='P'&&tile[row][col]->pieceName!='H')||PE==true){
                aValidWhite[row][col][tiles[i]] = tiles[i];
            }
        }
    }
}
void check_mate::icolsTest(Tile *temp)
{
    for(int faketiles = 0; faketiles < 64; faketiles++){
        colsWhite[temp->row][temp->col][faketiles] = -1;
        colsBlack[temp->row][temp->col][faketiles] = -1;
        aValidBlack[temp->row][temp->col][faketiles] = -1;
        aValidWhite[temp->row][temp->col][faketiles] = -1;
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
    black_king_in_chess = false;
    white_king_in_chess = false;
    whiteMax = 0;
    blackMax = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j<8;j++){
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
    }
}

int check_mate::checkIfChess2(){
    std::cout<<"check if chess2"<<std::endl;
    for(int i = 0; i<8; i++){
        for(int j = 0; j <8; j++){
            for(int k = 0; k < 64; k++){
              // std::cout<<colsWhite[i][j][k]<<" ";
               /* if(tile[i][j]->pieceName=='K'){
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
    int r,c;
    tempCount = 0;
    int row=temp->row;
    int col=temp->col;
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    //White Pawn
    if(temp->pieceColor)
    {
        if(row-1>=0 && !tile[row-1][col]->piece)
        {
            add_possible_fields(row,col,tile[row-1][col]->tileNum);
            retVal=1;
        }

        if(row==6 && !tile[5][col]->piece && !tile[4][col]->piece)
        {
            add_possible_fields(row,col,tile[row-2][col]->tileNum);
            retVal=1;
        }

        if(row-1>=0 && col-1>=0)
        {

            if(PE==false)
            {
                PE = true;
                add_possible_fields(row,col,tile[row-1][col-1]->tileNum);
                PE = false;
                tempTiles[tempCount]=tile[row-1][col-1]->tileNum;
                if(tile[row-1][col-1]->pieceName == 'K'&&tile[row-1][col-1]->pieceColor!=temp->pieceColor ){
                    add_possible_fields_King(temp->row,temp->col,tempTiles);;
                }
                tempCount++;
            }
        }

        if(row-1>=0 && col+1<=7)
        {

            if(PE==false)
            {
                PE = true;
                add_possible_fields(row,col,tile[row-1][col+1]->tileNum);
                PE = false;
                tempTiles[tempCount]=tile[row-1][col+1]->tileNum;
                if(tile[row-1][col+1]->pieceName == 'K'&&tile[row-1][col+1]->pieceColor!=temp->pieceColor ){
                    add_possible_fields_King(temp->row,temp->col,tempTiles);;
                }
                tempCount++;
            }
        }
    }
    else
    {
        if(row+1<=7 && !tile[row+1][col]->piece)
        {
            add_possible_fields(row,col,tile[row+1][col]->tileNum);
            retVal=1;
        }

        if(row==1 && !tile[2][col]->piece && !tile[3][col]->piece)
        {
            add_possible_fields(row,col,tile[row+2][col]->tileNum);
            retVal=1;
        }

        if(row+1<=7 && col-1>=0)
        {
            if(PE==false)
            {
                PE = true;
                add_possible_fields(row,col,tile[row+1][col-1]->tileNum);
                PE = false;
                tempTiles[tempCount]=tile[row+1][col-1]->tileNum;
                if(tile[row+1][col-1]->pieceName == 'K'&&tile[row+1][col+1]->pieceColor!=temp->pieceColor ){
                    add_possible_fields_King(temp->row,temp->col,tempTiles);;
                }
                tempCount++;
            }
        }

        if(row+1<=7 && col+1<=7)
        {
            if(PE==false)
            {
                PE = true;
                add_possible_fields(row,col,tile[row+1][col+1]->tileNum);
                PE = false;
                tempTiles[tempCount]=tile[row+1][col+1]->tileNum;
                if(tile[row+1][col+1]->pieceName == 'K'&&tile[row+1][col+1]->pieceColor!=temp->pieceColor ){
                    add_possible_fields_King(temp->row,temp->col,tempTiles);;
                }
                tempCount++;
            }
        }
    }
    return 0;
}


//ROOK
int check_mate::validateRook(Tile *temp){
    int r,c;
    tempCount = 0;
    r=temp->row;
    c=temp->col;
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    while(r-->0)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor || tile[r][c]->pieceName =='K')
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
            break;
        }
    }
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    tempCount=0;
    r=temp->row;
    c=temp->col;
    while(r++<7)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor || tile[r][c]->pieceName =='K')
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum || tile[r][c]->pieceName =='K');
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
            break;
        }
    }
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    tempCount=0;
    r=temp->row;
    c=temp->col;
    while(c++<7)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor || tile[r][c]->pieceName =='K')
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
            break;
        }
    }
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    tempCount=0;
    r=temp->row;
    c=temp->col;
    while(c-->0)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor || tile[r][c]->pieceName =='K')
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
            break;
        }
    }


    return -1;
}


//HORSE
int check_mate::validateHorse(Tile *temp){
    int r,c;
    tempCount = 0;
    r=temp->row;
    c=temp->col;
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    if(r-2>=0 && c-1>=0)
    {
        if(tile[r-2][c-1]->pieceColor!=temp->pieceColor || !tile[r-2][c-1]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r-2][c-1]->tileNum);
            tempTiles[tempCount]=tile[r-2][c-1]->tileNum;
            if(tile[r-2][c-1]->pieceName == 'K'&&tile[r-2][c-1]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);
                tempCount++;
            }

        }
    }

    if(r-2>=0 && c+1<=7)
    {
        if(tile[r-2][c+1]->pieceColor!=temp->pieceColor || !tile[r-2][c+1]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r-2][c+1]->tileNum);
            tempTiles[tempCount]=tile[r-2][c+1]->tileNum;
            if(tile[r-2][c+1]->pieceName == 'K'&&tile[r-2][c+1]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);
                tempCount++;
            }

        }
    }

    if(r-1>=0 && c-2>=0)
    {
        if(tile[r-1][c-2]->pieceColor!=temp->pieceColor || !tile[r-1][c-2]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r-1][c-2]->tileNum);
            tempTiles[tempCount]=tile[r-1][c-2]->tileNum;
            if(tile[r-1][c-2]->pieceName == 'K'&&tile[r-1][c-2]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);
                tempCount++;
            }

        }
    }

    if(r-1>=0 && c+2<=7)
    {
        if(tile[r-1][c+2]->pieceColor!=temp->pieceColor || !tile[r-1][c+2]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r-1][c+2]->tileNum);
            tempTiles[tempCount]=tile[r-1][c+2]->tileNum;
            if(tile[r-1][c+2]->pieceName == 'K'&&tile[r-1][c+2]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);
                tempCount++;
            }
        }
    }

    if(r+2<=7 && c+1<=7)
    {
        if(tile[r+2][c+1]->pieceColor!=temp->pieceColor || !tile[r+2][c+1]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r+2][c+1]->tileNum);
            tempTiles[tempCount]=tile[r+2][c+1]->tileNum;
            if(tile[r+2][c+1]->pieceName == 'K'&&tile[r+2][c+1]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);
                tempCount++;
            }
        }
    }

    if(r+2<=7 && c-1>=0)
    {
        if(tile[r+2][c-1]->pieceColor!=temp->pieceColor || !tile[r+2][c-1]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r+2][c-1]->tileNum);
            tempTiles[tempCount]=tile[r+2][c-1]->tileNum;
            if(tile[r+2][c-1]->pieceName == 'K'&&tile[r+2][c-1]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);
                tempCount++;
            }
        }
    }

    if(r+1<=7 && c-2>=0)
    {
        if(tile[r+1][c-2]->pieceColor!=temp->pieceColor || !tile[r+1][c-2]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r+1][c-2]->tileNum);
            tempTiles[tempCount]=tile[r+1][c-2]->tileNum;
            if(tile[r+1][c-2]->pieceName == 'K'&&tile[r+1][c-2]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);
                tempCount++;
            }
        }
    }

    if(r+1<=7 && c+2<=7)
    {
        if(tile[r+1][c+2]->pieceColor!=temp->pieceColor || !tile[r+1][c+2]->piece)
        {
            add_possible_fields(temp->row,temp->col,tile[r+1][c+2]->tileNum);
            tempTiles[tempCount]=tile[r+1][c+2]->tileNum;
            if(tile[r+1][c+2]->pieceName == 'K'&&tile[r+1][c+2]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);
                tempCount++;
            }
        }
    }

    return -1;
}


//KING
int check_mate::validateKing(Tile *temp)
{
    int r,c;
    tempCount = 0;
    r=temp->row;
    c=temp->col;
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    if(r-1>=0)
    {
        if(!tile[r-1][c]->piece || tile[r-1][c]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r-1][c]->tileNum);
        }
    }

    if(r+1<=7)
    {
        if(!tile[r+1][c]->piece || tile[r+1][c]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r+1][c]->tileNum);
        }
    }

    if(c-1>=0)
    {
        if(!tile[r][c-1]->piece || tile[r][c-1]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r][c-1]->tileNum);
        }
    }

    if(c+1<=7)
    {
        if(!tile[r][c+1]->piece || tile[r][c+1]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r][c+1]->tileNum);
        }
    }

    if(r-1>=0 && c-1>=0)
    {
        if(!tile[r-1][c-1]->piece || tile[r-1][c-1]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r-1][c-1]->tileNum);
        }
    }

    if(r-1>=0 && c+1<=7)
    {
        if(!tile[r-1][c+1]->piece || tile[r-1][c+1]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r-1][c+1]->tileNum);
        }
    }

    if(r+1<=7 && c-1>=0)
    {
        if(!tile[r+1][c-1]->piece || tile[r+1][c-1]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r+1][c-1]->tileNum);
        }
    }

    if(r+1<=7 && c+1<=7)
    {
        if(!tile[r+1][c+1]->piece || tile[r+1][c+1]->pieceColor!=temp->pieceColor)
        {
            add_possible_fields(temp->row,temp->col,tile[r+1][c+1]->tileNum);
        }
    }

    return -1;
}


//QUEEN
int check_mate::validateQueen(Tile *temp)
{
    int r,c;
    tempCount = 0;
    r=temp->row;
    c=temp->col;
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    /**
    Checks rows from starting row to 0 if a tile doesnt have a piece or the if the king is there the while loop will be continuing if there.
    **/
    while(r-->0)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor){
            break;
        }

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'){
                std::cout<<"KING FOUND !!!!"<<std::endl;
                add_possible_fields_King(temp->row,temp->col,tempTiles);
            }
            break;
        }
    }
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    tempCount=0;
    r=temp->row;
    c=temp->col;
    while(r++<7)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor){
            break;
        }

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName=='K'){
                add_possible_fields_King(temp->row,temp->col,tempTiles);
            }
            break;
        }
    }
        for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
        for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    tempCount=0;
    r=temp->row;
    c=temp->col;
    while(c++<7)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor){
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'){
                add_possible_fields_King(temp->row,temp->col,tempTiles);
            }
            break;
        }

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'){
                add_possible_fields_King(temp->row,temp->col,tempTiles);
            }
            break;
        }
    }
        for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    tempCount = 0;
    r=temp->row;
    c=temp->col;
    while(c-->0)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor){
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'){
                std::cout<<"KING FOUND !!!!"<<std::endl;
                add_possible_fields_King(temp->row,temp->col,tempTiles);
            }
            break;
        }

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'){
                std::cout<<"KING FOUND !!!!"<<std::endl;
                add_possible_fields_King(temp->row,temp->col,tempTiles);
            }
            break;
        }
    }
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    tempCount=0;
    r=temp->row;
    c=temp->col;
    while(r-->0 && c++<7)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor){
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName=='K'){
                std::cout<<"KING FOUND !!!!"<<std::endl;
                add_possible_fields_King(temp->row,temp->col,tempTiles);
            }
            break;
        }

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'){
                std::cout<<"KING FOUND !!!!"<<std::endl;
                add_possible_fields_King(temp->row,temp->col,tempTiles);
            }
            break;
        }
    }
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    tempCount=0;
    r=temp->row;
    c=temp->col;
    while(r-->0 && c-->0)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor){
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'){
                std::cout<<"KING FOUND !!!!"<<std::endl;
                add_possible_fields_King(temp->row,temp->col,tempTiles);
            }
            break;
        }

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'){
                std::cout<<"KING FOUND !!!!"<<std::endl;
                add_possible_fields_King(temp->row,temp->col,tempTiles);
            }
            break;
        }
    }
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    tempCount=0;
    r=temp->row;
    c=temp->col;
    while(r++<7 && c++<7)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor){
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'){
                std::cout<<"KING FOUND !!!!"<<std::endl;
                add_possible_fields_King(temp->row,temp->col,tempTiles);
            }
            break;
        }

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {

            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'){
                std::cout<<"KING FOUND !!!!"<<std::endl;
                add_possible_fields_King(temp->row,temp->col,tempTiles);
            }
            break;
        }
    }
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    tempCount=0;
    r=temp->row;
    c=temp->col;
    while(r++<7 && c-->0)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor){
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'){
                std::cout<<"KING FOUND !!!!"<<std::endl;
                add_possible_fields_King(temp->row,temp->col,tempTiles);
            }
            break;
        }

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'){
                std::cout<<"KING FOUND !!!!"<<std::endl;
                add_possible_fields_King(temp->row,temp->col,tempTiles);
            }
            break;
        }
    }


    return -1;
}

//BISHOP
int check_mate::validateBishop(Tile *temp)
{
    int r,c;
    tempCount=0;
    r=temp->row;
    c=temp->col;
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    while(r-->0 && c++<7)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor || tile[r][c]->pieceName =='K')
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
            break;
        }
    }
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    tempCount=0;
    r=temp->row;
    c=temp->col;
    while(r-->0 && c-->0)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor || tile[r][c]->pieceName =='K')
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
            break;
        }
    }
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    tempCount=0;
    r=temp->row;
    c=temp->col;
    while(r++<7 && c++<7)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor || tile[r][c]->pieceName =='K')
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
            break;
        }
    }
    for(int i = 0; i <16; i++){
        tempTiles[i]=-1;
    }
    tempCount=0;
    r=temp->row;
    c=temp->col;
    while(r++<7 && c-->0)
    {
        if(!tile[r][c]->piece || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
        }

        else if(tile[r][c]->pieceColor==temp->pieceColor || tile[r][c]->pieceName =='K')
            break;

        else if(tile[r][c]->pieceColor!=temp->pieceColor || tile[r][c]->pieceName =='K')
        {
            add_possible_fields(temp->row,temp->col,tile[r][c]->tileNum);
            tempTiles[tempCount]=tile[r][c]->tileNum;
            if(tile[r][c]->pieceName == 'K'&&tile[r][c]->pieceColor!=temp->pieceColor ){
                add_possible_fields_King(temp->row,temp->col,tempTiles);;
            }
            tempCount++;
            break;
        }
    }

    return -1;
}


