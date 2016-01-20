/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-20
**/
#include "chess_game.h"

#include "chess.h"

ChessGame::ChessGame()
{
  chesses_ =
  {
    Chess(kBlackChessNames[kChessSoldier]), Chess(kBlackChessNames[kChessSoldier]),   // 卒, 卒
    Chess(kBlackChessNames[kChessSoldier]), Chess(kBlackChessNames[kChessSoldier]),   // 卒, 卒
    Chess(kBlackChessNames[kChessSoldier]),                                           // 卒
    Chess(kBlackChessNames[kChessCannon]), Chess(kBlackChessNames[kChessCannon]),     // 包, 包
    Chess(kBlackChessNames[kChessHorse]), Chess(kBlackChessNames[kChessHorse]),       // 馬, 馬
    Chess(kBlackChessNames[kChessCar]), Chess(kBlackChessNames[kChessCar]),           // 車, 車
    Chess(kBlackChessNames[kChessElephant]), Chess(kBlackChessNames[kChessElephant]), // 象, 象
    Chess(kBlackChessNames[kChessWarrior]), Chess(kBlackChessNames[kChessWarrior]),   // 士, 士
    Chess(kBlackChessNames[kChessGeneral]),                                           // 將
    Chess(kRedChessNames[kChessSoldier]), Chess(kRedChessNames[kChessSoldier]),       // 兵, 兵
    Chess(kRedChessNames[kChessSoldier]), Chess(kRedChessNames[kChessSoldier]),       // 兵, 兵
    Chess(kRedChessNames[kChessSoldier]),                                             // 兵
    Chess(kRedChessNames[kChessCannon]), Chess(kRedChessNames[kChessCannon]),         // 炮, 炮
    Chess(kRedChessNames[kChessHorse]), Chess(kRedChessNames[kChessHorse]),           // 傌, 傌
    Chess(kRedChessNames[kChessCar]), Chess(kRedChessNames[kChessCar]),               // 俥, 俥
    Chess(kRedChessNames[kChessElephant]), Chess(kRedChessNames[kChessElephant]),     // 相, 相
    Chess(kRedChessNames[kChessWarrior]), Chess(kRedChessNames[kChessWarrior]),       // 仕, 仕
    Chess(kRedChessNames[kChessGeneral])                                              // 帥
  };
}

Chess * ChessGame::get_chess(int chess_number)
{
  if (chess_number < 0 || chess_number >= chesses_.size()) {
    return nullptr;
  } else {
    return &(chesses_[chess_number]);
  }
}
