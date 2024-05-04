#include "dependencies/decklib.h"
#include "blackjack/blackjack.h"
#include "blackjack/blackjack.c"

int main(){

    Card *card1=newCard(ACES,DIAMONDS);
    Card *card2=newCard(CARD10,SPADES);

    Deck *deck=newDeck();
    AddCardToDeck(deck,card1);
    AddCardToDeck(deck,card2);
    printf("points on the deck is:%d\n",GetPoints(deck));
    printf("Can it be split:%d\n",CanSplit(deck));

    return 0;
}