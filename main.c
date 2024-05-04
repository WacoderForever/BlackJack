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

        for(int i =0; i <main_deck->size; i++){
            printf("%s\n", GetCardString(main_deck->cards[i]));
        }

        Deck  *dealer = DealCards(main_deck, 2);
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
        bool exit = interface.ask_option(&interface,"would you like to exit ?","no | yes");
        FreeDeck(main_deck);
        FreeDeck(dealer);
        FreeDeck(player_hand_1);
        if(player_hand2){
            FreeDeck(player_hand2);
        }
        if(exit){
            break;
        }
    }



    return 0;
}