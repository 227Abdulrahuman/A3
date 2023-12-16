cmake_minimum_required(VERSION 3.23)
project(A3)

set(CMAKE_CXX_STANDARD 23)

add_executable(A3  Player.cpp RandomPlayer.cpp X_O_App.cpp X_O_Board.cpp GameManager.cpp FiveXFive_Board.cpp FiveXFive_Board.h FivexFIveAPP.cpp pyramid_X_O_Board.cpp pyramid_X_O_Board.h pyramid_APP.cpp Connect_Four_In_Row.cpp Connect_Four_In_Row.h ConnectFourtAPP.cpp AllGames.cpp)
