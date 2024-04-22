typedef struct Deck{

    Card **cards;
    int size;

}Deck;

Deck *newDeck();

void AddCardToDeck(Deck *self,Card *card);

void RemoveCardFromDeck(Deck *self,Card *card);

void ShuffleDeck(Deck *self);

Deck *DealCards(Deck *self);

void FreeDeck(Deck *self);

