#include <iostream>
#include <map>
using namespace std;


class Card{
    char suits;
    char ranks;
public:


    Card(){ // create a “default” card
        this->ranks = ranks;
        this->suits = suits;
    }

    Card(char s, char r){ // constructor to create a card, setting the rank and suit
        ranks = r;
        suits = s;
    }

    void setCard(char r, char s){ //set existing card to new values
        ranks = r;
        suits = s;
    }

    int getValue(){  // return the point value of the card. Ace = 1,...
        map<char,int> value = {{'A',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7}, {'8',8},{'9',9},{'T',10},{'J',10},{'Q',10},{'K',10}};
            return value[ranks];
    }

    void display(){  // display the card using 2 fields… Ace of Spade:AS
        cout<<ranks<<suits<<", ";

    }
};
