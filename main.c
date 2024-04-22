#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "card/card.h"
#include "deck/deck.h"

#include "card/card.c"
#include "deck/deck.c"

int main(){

    srand(time(NULL));

    Card *card1=newCard("Spade","Ace");
    Card *card2=newCard("Diamond","2");
    Card *card3=newCard("Clubs","3");
    Card *card4=newCard("Hearts","4");
    Card *card5=newCard("Spade","5");
    Card *card6=newCard("Spade","Ace");

    Deck *maindeck=newDeck();
    AddCardToDeck(maindeck,card1);
    AddCardToDeck(maindeck,card2);
    AddCardToDeck(maindeck,card3);
    AddCardToDeck(maindeck,card4);
    AddCardToDeck(maindeck,card5);

    printf("Printing cards added to the deck:\n");
    for(int i=0;i<maindeck->size;i++){

        Card *temp=maindeck->cards[i];
        printf("%7s     %s\n",GetCardSuit(temp),GetCardNumber(temp));
    }

    ShuffleDeck(maindeck);

    printf("Shuffled deck:\n");
    for(int i=0;i<maindeck->size;i++){

        Card *temp=maindeck->cards[i];
        printf("%7s     %s\n",GetCardSuit(temp),GetCardNumber(temp));
    }
    FreeDeck(maindeck);
    return 0;
}