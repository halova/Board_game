#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

class Card{
public :
    Card(int RANK, int SUIT) {
        rank = RANK;
        suit = SUIT;
    }
    void Print() const;
    string Get_Name() const;
private:
    int rank;
    int suit;
};
///////////////////////////////
void Card::Print() const {
    if (rank <11)
        cout << rank;
    else if (rank ==11)
        cout<<'J';
    else if (rank ==12)
        cout<<'Q';
    else if (rank ==13)
        cout<<'K';
    else if (rank ==14)
        cout<<'A';
    if (suit == 1)
        cout<<'S';
    else if (suit ==2)
        cout<<'C';
    else if (suit ==3)
        cout<<'D';
    else
        cout<<'H';
    cout<< " ";
}
string Card::Get_Name() const {
    string name;
    if (rank <11)
        name += to_string(rank);
    else if (rank ==11)
        name +='J';
    else if (rank ==12)
        name +='Q';
    else if (rank ==13)
        name +='K';
    else if (rank ==14)
        name +='A';
    if (suit == 1)
        name +='S';
    else if (suit ==2)
        name +='C';
    else if (suit ==3)
        name +='D';
    else
        name +='H';
    return name;
}

///////////////////////////////
class Deck{
public:
    Deck();
    void Shuffle();
    void Print();
    Card* Pop();
private:
    vector <Card*> deck;
};
///////////////////////////////
Deck::Deck() {
    // Construct whole deck un_sorted //
    for( int r =2;r <=14 ; r++)
    {
        for ( int s = 1; s <=4 ; s++)
            deck.push_back(new Card(r,s));
    }
}

void Deck::Shuffle() {
    srand(time(nullptr));
    random_shuffle(deck.begin(),deck.end() );
}
void Deck::Print() {
    cout << "Deck after shuffle:"<<endl;
    for ( Card* card :deck )
    {
        card->Print();
    }
    cout<< endl;
}

Card* Deck::Pop() {
    Card *temp = deck.front();
    deck.erase(deck.begin());
    return temp;
}
/////////////////////////////////
class GameBoard{
public:
    void printBoard() ;
    void place_card(Card *card, string team);
    bool CheckWin(string team);
private:
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
};
/////////////////////////////////
void GameBoard::printBoard() {
        cout <<"    ";
        for (int i = 0; i < 10; ++i)
        {
            cout << i <<"  ";
        }
        cout<<endl;
        for (int i = 0; i < 10; ++i) {
            cout <<i <<"  ";
            for (int j = 0; j < 10; ++j) {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
    cout << endl;
}
void endGame(string team) {
    cout << "Winner is Team " << team << endl;
    exit(-1);
}

void GameBoard::place_card(Card *card, string team) {

    string new_spot=team;
    string card_name = card->Get_Name();
    if ( card_name == "JS" || card_name=="JC"|| card_name=="JD"|| card_name=="JH")
    {
        // Insert rule here //
        cout << "You have the JACK. You can choose to place it at anywhere you want. "<< endl;
    }
    else {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (board[i][j] == card_name)
                    cout << "You can choose to place it at " << " Row = " << i << "; Column = " << j << endl;
            }
        }
    }
    int x,y;
    cout <<"Please enter the spot you want separate by a space. Like 4 5 for Row = 4, Column =5" <<endl;
    cin >>x>>y;
    board[x][y] =new_spot;
    cout << "Board after place the card:" <<endl;
    printBoard();
    if(CheckWin(team))endGame(team);
}

bool GameBoard::CheckWin(string team){ //if someone has won, returns true, otherwise returns false
    int number_of_set = 0;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            if(board[i][j] == team || board[i][j] == "**"){
                for(int y = 1; y < 5; ++y){
                    if(i < 0 || j+y < 0 || i > 9 || j+y > 9)break;
                    if(board[i][j+y] != team && board[i][j+y] != "**")break;
                    if(y == 4) number_of_set++;
                }
                for(int y = 1; y < 5; ++y){
                    if(i+y < 0 || j < 0|| i+y > 9 || j > 9)break;
                    if(board[i+y][j] != team && board[i+y][j] != "**")break;
                    if(y == 4) number_of_set++;
                }
                for(int y = 1; y < 5; ++y){
                    if(i+y < 0 || j+y < 0|| i+y > 9 || j+y > 9)break;
                    if(board[i+y][j+y] != team && board[i+y][j+y] != "**")break;
                    if(y == 4) number_of_set++;
                }
                for(int y = 1; y < 5; ++y){
                    if(i+y < 0 || j-y < 0|| i+y > 9 || j-y > 9)break;
                    if(board[i+y][j-y] != team && board[i+y][j-y] != "**")break;
                    if(y == 4) number_of_set++;
                }
            }

        }

    }

    if(number_of_set >= 2)return true;
    return false;

}

/////////////////////////////////////
class Player{
public:
    Player( string Name, string team) {name = Name; Team = team;};
    void Print();
    void Begin_deck(Deck &deck);
    void Play_card(Deck &deck,GameBoard &board, string player);
    string Team;
private:
    vector <Card*> player_deck;
    string name;

};
//////////////////////////////////
void Player::Print() {
    cout << "Player "<< name <<" has: ";
    for ( auto it = player_deck.begin();it != player_deck.end();it++)
        (*it)->Print();
    cout << endl;

}
void Player::Begin_deck(Deck &deck) {
    // It gets the whatever card in the front of deck_stack;
    // We call deck.Pop() so that card will also disappear in the deck.
    player_deck.push_back(deck.Pop());
}
void Player::Play_card(Deck &deck, GameBoard &board, string team) {
    cout << endl;
    Print();
    cout<< "Please choose the card you want to use. From 1 to 5 is the position of it in your deck" << endl;
    int numb;
    cin >>numb;
    numb--;
    cout << "You have choose: ";
    player_deck[numb]->Print();
    // We need to check is the card is valid here, do it later//
    cout << endl;
    // pass the player_deck[numb] which hold the card player choose
    board.place_card(player_deck[numb], team);
    // Now swap it new one from the deck//
    player_deck[numb]=deck.Pop();
    cout << "After play the card."<<endl;
    Print();
    cout << endl;
}

//////////////////////////////////
int main()
{
    // Create new Deck named deck //
    Deck deck;
    deck.Shuffle();
    deck.Print();
    // Create new Game board //
    GameBoard Main_board;

    int numb_players;
    vector <Player*> v;
    // Create vector hold pointer to Player class //
    // Each vector index will be a player //
    cout << "Enter number of players. Any their name separate by space. Like: 4 James John Joss Loss"<< endl;
    cin >> numb_players;
    for (int i = 0; i< numb_players; i++)
    {
        string tmp;
        string team;
        if(i%2)team = "--";
        else team = "&&";
        cin >> tmp;
        // For each name input, create new player and place it at the end of the vector //
        v.insert(v.end(),new Player (tmp, team));
    }
    // Each player has 5 cards for loop 5 times //
    for (int j = 0; j< 5; j++)
    {
        for (int i = 0; i< numb_players; i++)
        {
            v[i]->Begin_deck(deck);
        }

    }

    Main_board.printBoard();
    //This is where the auto playing starts
    for (int i = 0; i< numb_players; i++)
    {
        v[i]->Print();
    }
    for (int i = 0; i< 4; i++)
    {
        string team = v[i]->Team;
        v[i]->Play_card(deck,Main_board, team);
    }


    return 0;
}