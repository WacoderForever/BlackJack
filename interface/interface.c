

int ask_bet_amount(CliInterface *interface, int balance)
{
    while (true)
    {
        long value = interface->ask_long(interface, "type the amount of bet");
        if (value > balance)
        {
            interface->warning(interface, "you cannnot bet higher than %d balance\n", balance);
            continue;
        }
        return (int)value;
    }
}
void print_card(Card *card)
{
    if (card->suit == DIAMONDS)
    {
        printf("%s", CLI_YELLOW);
    }
    if (card->suit == HEARTS)
    {
        printf("%s", CLI_YELLOW);
    }
    if (card->suit == CLUBS)
    {
        printf("%s", CLI_GREEN);
    }
    if (card->suit == SPADES)
    {
        printf("%s", CLI_RED);
    }
    printf("%s ", GetCardValueString(card));
}

void print_deck(Deck *deck)
{
    for (int i = 0; i < deck->size; i++)
    {
        Card *current = deck->cards[i];
        print_card(current);
    }
    printf("%s(%d)", CLI_BLUE, GetPoints(deck));
    printf("%s\n", CLI_WHITE);
}
void show_interface(Round *current_round, int balance)
{
    system("clear");
    printf("cards remaning:%s%d\n", CLI_GREEN, current_round->main_deck->size);
    printf("balance:%s%d\n", CLI_GREEN, balance);
    printf("%s", CLI_WHITE);
    printf("bet:%s%d\n", CLI_GREEN, current_round->bet);
    printf("%s", CLI_WHITE);

    printf("dealer:");
    // means it must mock first card
    if (current_round->dealer_deck->size == 2)
    {
        printf("X ");
        Card *first = current_round->dealer_deck->cards[0];
        RemoveCardReferenceByIndex(current_round->dealer_deck, 0);
        print_deck(current_round->dealer_deck);
        AddCardToDeck(current_round->dealer_deck, first);
        // return the order
        Card *second = current_round->dealer_deck->cards[0];
        RemoveCardReferenceByIndex(current_round->dealer_deck, 0);
        AddCardToDeck(current_round->dealer_deck,second);
    }
    else
    {
        print_deck(current_round->dealer_deck);
    }

    printf("hand1:");
    print_deck(current_round->player_hand1);

    if (current_round->player_hand2)
    {
        printf("hand2:");
        print_deck(current_round->player_hand2);
    }
}