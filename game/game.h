
typedef struct {
    int full_bet;
    int bet;
    Deck  *main_deck;
    Deck *dealer_deck;
    Deck *player_hand1;
    Deck *player_hand2;
}Round;

Round *newRound();


void Round_free(Round *self);