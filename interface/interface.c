

int ask_bet_amount(CliInterface *interface,int balance){
    while (true){
        long value = interface->ask_long(interface,"type the amount of bet");
        if(value > balance){
            interface->warning(interface,"you cannnot bet higher than %d balance\n",balance);
            continue;
        }
        return (int)value;
    }

}
void print_card(Card *card){
    if(card->suit == DIAMONDS){
        printf("%s",CLI_YELLOW);
    }
    if(card->suit == HEARTS){
        printf("%s",CLI_YELLOW);
    }
    if(card->suit == CLUBS){
        printf("%s",CLI_GREEN);
    }
    if(card->suit == SPADES){
        printf("%s",CLI_RED);
    }
    printf("%s ",GetCardValueString(card));
}

void print_deck(Deck *deck){
    for(int i = 0;  i < deck->size; i++){
        Card  *current = deck->cards[i];
        print_card(current);
    }
    printf("%s(%d)",CLI_BLUE, GetPoints(deck));
    printf("%s\n",CLI_WHITE);

}
void show_interface(int balance,int bet,Deck *dealer_deck,Deck *player_hand1,Deck *player_hand2){

    printf("balance:%s%d\n",CLI_GREEN,balance);
    printf("%s",CLI_WHITE);
    printf("bet:%s%d\n",CLI_GREEN,bet);
    printf("%s",CLI_WHITE);

    printf("delaer:");
    //means it must hide the first dealker card
    if(dealer_deck->size == 2){
        printf("X ");
        Card  *last_card = dealer_deck->cards[1];
        print_card(last_card);
        printf("%s(%d)",CLI_BLUE, GetBlackJackCardValue(last_card));
        printf("%s\n",CLI_WHITE);
    }
    else{
        print_deck(dealer_deck);

    }

    printf("hand1:");
    print_deck(player_hand1);

    if(player_hand2){
        printf("hand2:");
        print_deck(player_hand2);
    }

}