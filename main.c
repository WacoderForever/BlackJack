#include <stdlib.h>
#include "dependencies/decklib.h"
#include "dependencies/cliinput.h"
#include "round/round.h"
#include "blackjack/blackjack.h"
#include "interface/interface.h"
#include "blackjack/blackjack.c"
#include "interface/interface.c"
#include "round/round.c"

int main(){
    CliInterface  interface = newCliInterface();
    int balance = 10000;

    while (true){
        Round  *round = newRound();

        round->bet = ask_bet_amount(&interface,balance);
        balance-=round->bet;

        show_interface(round,balance);
        bool split;
        if(CanSplit(round->player_hand1)){
            split = interface.ask_option(&interface,"would you like to split ?(yes,no)\n","  no|yes");
            if(split){

                round->player_hand2 = DealCards(round->player_hand1,1);
                balance-=round->bet;
                round->bet = round->bet *2;
                TransferCards(round->main_deck,round->player_hand1,1);
                TransferCards(round->main_deck,round->player_hand2,1);
                show_interface(round,balance);
            }
            
        }

        //implement the rest here
        if(!split){
            
            Hit(round,interface,&balance);
        }


       Winner(round,round->player_hand1,&balance);

        if(split){

           Winner(round,round->player_hand2,&balance);
        }

        printf("%s====================================\n",CLI_RED);
        bool again = interface.ask_option(&interface,"would you like to play again ?","no | yes"); 
        Round_free(round);

        if(!again){
            break;
        }
        printf("%s\n",CLI_WHITE);

    }



    return 0;
}