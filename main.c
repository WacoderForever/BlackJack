#include <stdlib.h>
#include<unistd.h>
#include "dependencies/cclientry.h"
#include "dependencies/decklib.h"
#include "dependencies/cliinput.h"
#include "round/round.h"
#include "blackjack/blackjack.h"
#include "interface/interface.h"
#include "blackjack/blackjack.c"
#include "interface/interface.c"
#include "round/round.c"

int main(int argc,char *argv[]){
    int balance = 10000;

    CliNamespace cli = newCliNamespace();

    CliInterface  interface = newCliInterface();

    CliEntry *entry = newCliEntry(argc,argv);

    //get the flag
    CliFlag *balance_flag = cli.entry.get_flag(entry,"b | balance ",CLI_NOT_CASE_SENSITIVE);
    bool is_balance_num = cli.flag.is_numeric(balance_flag,0);
    if(is_balance_num){
        balance = (int)cli.flag.get_long(balance_flag,0);
    }

    CliFlag * seed_flag = cli.entry.get_flag(entry,"seed | s",CLI_NOT_CASE_SENSITIVE);
    bool is_seed_num = cli.flag.is_numeric(seed_flag,0);
    if(is_seed_num){
        DECKLIB_DEBUG_SEED = cli.flag.get_long(seed_flag,0);
    }

    cli.entry.free(entry);


    while (true){
        Round  *round = newRound();

        round->bet = ask_bet_amount(&interface,balance);
        balance-=round->bet;

        show_interface(round,balance);
        bool split;
        if(CanSplit(round->player_hand1)){
            split = interface.ask_option(&interface,"would you like to split ?(yes,no)\n","  no|yes ");
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
            printf(CLI_YELLOW"seed: %ld\n",DECK_LIB_STARTED_SEED);
            break;
        }

    }
        printf("%s\n",CLI_WHITE);



    return 0;
}