

Round *newRound(){
    Round  *self = (Round*) malloc(sizeof(Round));
    *self = (Round){0};
    self->main_deck = newDeck();
    LoadFullDeck(self->main_deck);
    ShuffleDeck(self->main_deck);

    self->dealer_deck = DealCards(self->main_deck, 2);
    self->player_hand1 = DealCards(self->main_deck,2);

    return self;
}
void Round_free(Round *self){
    FreeDeck(self->main_deck);
    FreeDeck(self->dealer_deck);
    FreeDeck(self->player_hand1);
    if(self->player_hand2){
        FreeDeck(self->player_hand2);
    }
    free(self);
}