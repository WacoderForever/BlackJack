#include <stdlib.h>
#include "dependencies/decklib.h"
#include "dependencies/cliinput.h"

#include "blackjack/blackjack.h"
#include "interface/interface.h"
#include "blackjack/blackjack.c"
#include "interface/interface.c"

int main(){
    CliInterface  interface = newCliInterface();
    int balance = 10000;

    while (true){
        int bet = ask_bet_amount(&interface,balance);
        balance-=bet;
        Deck  * main_deck = newDeck();
        LoadFullDeck(main_deck);
        ShuffleDeck(main_deck);

       

        Deck  *dealer = DealCards(main_deck, 1);
        Deck  *player_hand_1 = DealCards(main_deck,2);
        Deck *player_hand2 = NULL;

        show_interface(balance, bet, dealer,player_hand_1,player_hand2);
        if(CanSplit(player_hand_1)){
            bool split = interface.ask_option(&interface,"would you like to split ?(yes,no)\n","  no|yes");
            if(split){
                player_hand2 = DealCards(player_hand_1,1);
            }
        }
        //implement the rest here


        FreeDeck(main_deck);
        FreeDeck(dealer);
        FreeDeck(player_hand_1);
        if(player_hand2){
            FreeDeck(player_hand2);
        }



        bool again = interface.ask_option(&interface,"would you like yo play again ?","no | yes");
 

        if(!again){
            break;
        }
        printf("%s=====================================\n",CLI_RED);

    }



    return 0;
}