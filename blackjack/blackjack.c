
int GetBlackJackCardValue(Card  *card){

    if(card->value >= ACES && card->value <= CARD10){
        return card->value+1;
    }

    return 10;
}



int GetPoints(Deck *dek){

    int points=0;
    //counting values considering aces as 1
    for(int i=0;i<dek->size;i++){

        Card *card=dek->cards[i];

        points+= GetBlackJackCardValue(card);
    }
    //incrementing aces in 10 if dont fit 22
    for(int i=0;i<dek->size;i++){

        Card *card=dek->cards[i];
        if(card->value != ACES){
            continue;
        }
        int possible_pointes = points+10;
        if(possible_pointes> 21){
            break;
        }
        points = possible_pointes;

    }

    return points;
}

bool CanSplit(Deck *deck){

    Card * first = deck->cards[0];
    Card  *second = deck->cards[1];
    if(first->value==second->value) {
        return true;
    }
    return false;
}

void Winner(Round *round,Deck *playerhand,int *balance){

    int dealerpoints=GetPoints(round->dealer_deck);
    int playerpoints=GetPoints(playerhand);

    while(dealerpoints<17){

        TransferCards(round->main_deck,round->dealer_deck,1);
        dealerpoints=GetPoints(round->dealer_deck);
        show_interface(round,*balance);
        sleep(1);
    }
    show_interface(round,*balance);
    //natural
    if((playerpoints==21) && (dealerpoints != 21)){

        *balance+=round->bet*2;
        show_interface(round,*balance);
        printf("%sYou have won!!!!!!!!!!\n",CLI_BLUE);
        printf("Your balance is now %d\n",*balance);
        return;
    }

    //player burst
    else if(playerpoints>21){

        show_interface(round,*balance);
        printf("%sYou have lost!!!!!!!!!!\n",CLI_RED);
        printf("Your balance is now %d\n",*balance);
        return;
    }
    //dealer burst
    else if(dealerpoints>21){

        *balance+=round->bet*2;
        show_interface(round,*balance);
        printf("%sYou have won!!!!!!!!!!\n",CLI_BLUE);
        printf("Your balance is now %d\n",*balance);
        return;
        
    }
    //player has more points than dealer
    else if(playerpoints>dealerpoints){

        *balance+=round->bet*2;
        show_interface(round,*balance);
        printf("%sYou have won!!!!!!!!!!\n",CLI_BLUE);
        printf("Your balance is now %d\n",*balance);
        return;
    }
    //dealer has higher than player
    else if(playerpoints<dealerpoints){

        show_interface(round,*balance);
        printf("%sYou have lost!!!!!!!!!!\n",CLI_RED);
        printf("Your balance is now %d\n",*balance);
        return;
    }

    show_interface(round,*balance);
    printf("It is a push\n");
    printf("Your balance is still %d\n",*balance);
}

void Hit(Round *round,CliInterface interface,int *balance){

    while(true){

        if(GetPoints(round->player_hand1)>=21){

            break;
        }
        bool hit=interface.ask_option(&interface,"would you like to hit ?(yes,no)\n","  no|yes");
        if(!hit){
            break;
        }
        TransferCards(round->main_deck,round->player_hand1,1);
        show_interface(round,*balance);
    }

}