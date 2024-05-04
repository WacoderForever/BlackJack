#include "decklib.h"
#include "blackjack.h"
#include "blackjack.c"

int main(){

    Card *card1=newCard(ACES,DIAMONDS);
    Card *card2=newCard(ACES,SPADES);

    Deck *deck=newDeck();
    AddCardToDeck(deck,card1);
    AddCardToDeck(deck,card2);
    printf("points on the deck is:%d\n",GetPoints(deck));
    printf("Can it be split:%d\n",CanSplit(deck));

    return 0;
}