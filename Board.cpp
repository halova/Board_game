#include <random>
#include <iostream>
#include <utility>
#include <vector>
#include "Queue.h"
using namespace std;

class player{
public:
    int playernumber;
    int team;
    vector<string> hand;
    player(int n, int t, vector<string> h){
        playernumber = n;
        team = t;
        hand = h;
    }
};


class GameBoard{
public:
    vector<vector<string>> board {
            {"**", "AC", "KC", "QC", "TC", "9C", "8C", "7C", "6C", "**"},   //Row1
            {"AD", "7S", "8S", "9S", "TS", "QS", "KS", "AS", "5C", "2S"},   //Row2
            {"KD", "6S", "TC", "9C", "8C", "7C", "6C", "2D", "4C", "3S"},   //Row3
            {"QD", "5S", "QC", "8H", "7H", "6H", "5C", "3D", "3C", "4S"},   //Row4
            {"TD", "4S", "KC", "9H", "2H", "5H", "4C", "4D", "2C", "5S"},   //Row5
            {"9D", "3S", "AC", "TH", "3H", "4H", "3C", "5D", "AH", "6S"},   //Row6
            {"8D", "2S", "AD", "QH", "KH", "AH", "2C", "6D", "KH", "7S"},   //Row7
            {"7D", "2H", "KD", "QD", "TD", "9D", "8D", "7D", "QH", "8S"},   //Row8
            {"6D", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "TH", "9S"},   //Row9
            {"**", "5D", "4D", "3D", "2D", "AS", "KS", "QS", "TS", "**"}    //Row10
    };
    Queue deck;
    int numberplayers;

    void printBoard() {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
    }
    void checkwin(){
        return;

    }

    int place(player l,int row, int column, string spot){//current players turn, row and column to place, card to cover
        string newspot;
        if(l.team)newspot = "--"; //if team 1, cover with --
        else newspot = "&&";    //if team 2, cover with &&
        if(spot != board[row][column])return -1;    //if what they want to cover isnt at that spot, return -1
        board[row][column] = newspot;   //else place the peice
        checkwin(); //check if there is a win after every turn
        return 1;
    }
};



vector<vector<string>>referenceboard {
{"**", "AC", "KC", "QC", "TC", "9C", "8C", "7C", "6C", "**"},   //Row1
{"AD", "7S", "8S", "9S", "TS", "QS", "KS", "AS", "5C", "2S"},   //Row2
{"KD", "6S", "TC", "9C", "8C", "7C", "6C", "2D", "4C", "3S"},   //Row3
{"QD", "5S", "QC", "8H", "7H", "6H", "5C", "3D", "3C", "4S"},   //Row4
{"TD", "4S", "KC", "9H", "2H", "5H", "4C", "4D", "2C", "5S"},   //Row5
{"9D", "3S", "AC", "TH", "3H", "4H", "3C", "5D", "AH", "6S"},   //Row6
{"8D", "2S", "AD", "QH", "KH", "AH", "2C", "6D", "KH", "7S"},   //Row7
{"7D", "2H", "KD", "QD", "TD", "9D", "8D", "7D", "QH", "8S"},   //Row8
{"6D", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "TH", "9S"},   //Row9
{"**", "5D", "4D", "3D", "2D", "AS", "KS", "QS", "TS", "**"}    //Row10
};

int main()
{
    GameBoard board;
    vector<string> v {"3C", "2C"};
    player first(1, 1, v);
    board.printBoard();
    board.place(first, 4, 8, "2C");
    board.printBoard();
    return -1;
}
