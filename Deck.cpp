#include "Card.cpp"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
bool isFibo(int n)
{
    if (n == 1 || n == 2 || n == 3|| n == 5|| n == 8|| n == 13
        || n == 21|| n == 34|| n == 55|| n == 89|| n == 144|| n == 233
        || n == 377|| n == 610)
            return true;
    else
        return false;


}
class Deck{
    Card cards[52];
    int top;
public:
    Deck(){
        top = 0;
        char suits[4] = {'S', 'H', 'D', 'C'};
        char ranks [13] = {'A', '2', '3', '4', '5', '6', '7', '8',
                          '9', 'T', 'J', 'Q', 'K'};

        int cardIndex = 0;
        for (char suits: suits) {
            for (char ranks: ranks){
                cards[cardIndex] = Card(suits, ranks);
                cardIndex++;
            }
        }
    }

    void display(){  // show all the cards in the deck: 13 columns and 4 rows.
        for(int i=0;i<52;i++)
                cards[i].display();
            cout<<endl;
            }

    void refreshDeck(){  // reset the deck so it looks like a new deck
        top = 0;
        char ranks [13] = {'A', '2', '3', '4', '5', '6', '7', '8',
                          '9', 'T', 'J', 'Q', 'K'};
        char suits[4] ={'S','H','D','C'};
        for(int i =0,total =0; i<4;i++)
            for(int j=0;j<13;j++)
                cards[total++]=Card(suits[i],ranks[j]);
    }

    Card deal(){ // deal a card from the top of the deck
        return cards[top++];
    }

    void shuffle(){ // shuffle the cards in the deck.

        int index = 0;
        int v1 = rand() % 52 + 1;

        for(int i = 0; i < 52; i++){
            index = i + (v1 - i);

            if(index != i){

                Card temp = cards[i];
                cards[i] = cards[index];
                cards[index] = temp;
            }
        }

        cout << "Cards Shuffled" << endl;

    }

    bool isEmpty(){  // true is deck is empty, false if the deck is not empty
        int checker = 52- top;
        if (checker>0){
            return false;
        }
        else{
            return true;
        }
    }

};
//menu-based gameplay in main
int main(){
    Deck deck = Deck();
    while(true){
        cout<<"Welcome to Solitaire Prime!"<<endl;
        cout<<"1) New Deck"<<endl;
        cout<<"2) Display Deck"<<endl;
        cout<<"3) Shuffle Deck"<<endl;
        cout<<"4) Play Solitaire Prime"<<endl;
        cout<<"5) Exit"<<endl;
        cout<<endl<<"Your Choice: ";
        int c;cin>>c;
        if(c==1){
            deck.refreshDeck();
            cout<<"The deck has been refresh!"<<endl;
        }
        else if (c==2){
            cout<<"Displaying deck: \n";
            deck.display();
        }
        else if (c==3){
            cout<<"Shuffling deck! \n";
            deck.shuffle();
        }
        else if (c==4){
            cout<<"Playing Fibonacci Solitaire!!!\n\n";
            int gamesPlayed = 0;
            gamesPlayed++;
            int piles = 0;
            while(deck.isEmpty()== false){
                int sum = 0;
                while(deck.isEmpty() == false && !isFibo(sum)){
                    Card top = deck.deal();
                    sum+= top.getValue();
                    top.display();
                }
                piles++;
                if(deck.isEmpty() == false && isFibo(sum))
                    cout<<"\b Fibo:"<<sum<<endl;
                if(deck.isEmpty()== true && isFibo(sum))
                    cout<<"Fibo:"<<sum<<endl<<endl<<"Winner in "<<piles<<" piles!"<<endl;
                if(deck.isEmpty()== true && !isFibo(sum))
                    cout<<"\nLoser in "<<piles<<" piles!"<<endl;

            }
        cout<<"Games played: "<<gamesPlayed<<endl;
        }
        else if (c==5)
            break;
        else
            cout<<"Invalid choice!!!"<<endl;
        cout<<endl;
    }
}
