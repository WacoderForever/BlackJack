#include <stdlib.h>
#include "dependencies/decklib.h"
#include "dependencies/cliinput.h"
#include "game/game.h"
#include "blackjack/blackjack.h"
#include "interface/interface.h"
#include "blackjack/blackjack.c"
#include "interface/interface.c"
#include "game/game.c"

int main(){
    CliInterface  interface = newCliInterface();
    int balance = 10000;

    while (true){
        Round  *round = newRound();

        round->bet = ask_bet_amount(&interface,balance);
        balance-=round->bet;

        show_interface(round,balance);
        if(CanSplit(round->player_hand1)){
            bool split = interface.ask_option(&interface,"would you like to split ?(yes,no)\n","  no|yes");
            if(split){
                round->player_hand2 = DealCards(round->player_hand1,1);
            }
            balance-=round->bet;
            round->bet  = round->bet *2;

            show_interface(round,balance);
        }

        //implement the rest here

        printf("%s====================================\n",CLI_RED);
        bool again = interface.ask_option(&interface,"would you like yo play again ?","no | yes"); 

        if(!again){
            break;
        }
        printf("%s\n",CLI_WHITE);

    }



    return 0;
}