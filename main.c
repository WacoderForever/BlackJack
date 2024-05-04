#include "dependencies/decklib.h"
#include "blackjack/blackjack.h"
#include "blackjack/blackjack.c"

void test_split(){
    //testing can splic
    Card *card1=newCard(KING,DIAMONDS);
    Card *card2=newCard(KING,CLUBS);
    Deck  *deck1 = newDeck();
    AddCardToDeck(deck1,card1);
    AddCardToDeck(deck1,card2);
    printf("deck1 can split: %d\n", CanSplit(deck1));
    FreeDeck(deck1);
}
void test_not_split(){
    //testing can splic
    Card *card1=newCard(KING,DIAMONDS);
    Card *card2=newCard(ACES,CLUBS);
    Deck  *deck1 = newDeck();
    AddCardToDeck(deck1,card1);
    AddCardToDeck(deck1,card2);
    printf("deck2 can split: %d\n", CanSplit(deck1));
    FreeDeck(deck1);
}
void test_pontuation(){
    Card *card1=newCard(KING,DIAMONDS);
    Card *card2=newCard(ACES,CLUBS);
    Card *card3=newCard(CARD5,CLUBS);

    Deck  *deck1 = newDeck();
    AddCardToDeck(deck1,card1);
    AddCardToDeck(deck1,card2);
    AddCardToDeck(deck1,card3);

    printf("deck1 pontuation: %d\n", GetPoints(deck1));
    FreeDeck(deck1);
}
void test_pontuation2(){
    Card *card1=newCard(KING,DIAMONDS);
    Card *card2=newCard(ACES,CLUBS);

    Deck  *deck1 = newDeck();
    AddCardToDeck(deck1,card1);
    AddCardToDeck(deck1,card2);

    printf("deck2 pontuation: %d\n", GetPoints(deck1));
    FreeDeck(deck1);
}
int main(){

    test_split();
    test_not_split();
    test_pontuation();
    test_pontuation2();



    return 0;
}