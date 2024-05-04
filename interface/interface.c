

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
    printf("%s",GetCardValueString(card));
}

void print_deck(Deck *deck){
    for(int i = 0;  i < deck->size; i++){
        Card  *current = deck->cards[i];
        print_card(current);
    }
}
void show_interface(int balance,int bet,Deck *dealer_deck,Deck *player_hand1,Deck *player_hand2){
    system("clear"); // these clear the terminal

    printf("balance:%s%d\n",CLI_GREEN,balance);
    printf("%s",CLI_WHITE);
    printf("bet:%s%d\n",CLI_GREEN,bet);
    printf("%s",CLI_WHITE);

    printf("delaer:");
    //means it must hide the first dealker card
    if(dealer_deck->size == 2){
        printf("X");
        print_card(dealer_deck->cards[1]);
    }
    else{
        print_deck(dealer_deck);
    }
    printf("\n");
    printf("%s",CLI_WHITE);

    printf("hand1:");
    print_deck(player_hand1);
    printf("\n");
    printf("%s",CLI_WHITE);

    if(player_hand2){
        printf("hand2:");
        print_deck(player_hand2);
        printf("\n");
    }

}