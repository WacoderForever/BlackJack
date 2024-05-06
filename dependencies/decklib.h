

#ifndef DeckLib_H
#define DeckLib_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define DECK_LIB_SEED 23423492323
#define DECK_LIB_TOTAL_SHUFFLE 10000

enum {
    SPADES,
    DIAMONDS,
    CLUBS,
    HEARTS
};

enum{
     ACES,
     CARD2,
     CARD3,
     CARD4,
     CARD5,
     CARD6,
     CARD7,
     CARD8,
     CARD9,
     CARD10,
     JACKS,
     QUEEN,
     KING
};



typedef struct Card{

    int value;
    int suit;

}Card;

void SetCardValue(Card *self,int value);

void SetCardSuit(Card *self,int suit);

Card *newCard(int value, int suit);

const char * GetCardString(Card *self);

const char * GetCardValueString(Card *self);

const char * GetCardSuitString(Card *self);

Card *copyCard(Card *self);

int GetCardValue(Card *self);

int GetCardSuit(Card *self);

void FreeCard(Card *self);


unsigned long TOTAL_ITERATIONS = 0;
unsigned long DECKLIB_DEBUG_SEED = 0;
unsigned  long DECK_LIB_STARTED_SEED = 0;
typedef struct Deck{

    Card **cards;
    int size;

}Deck;

Deck *newDeck();

void AddCardToDeck(Deck *self, Card *card);

void LoadFullDeck(Deck *self);

int SearchCardIndexInDeck(Deck *self, Card *card);

Card  *GetCardByIndex(Deck *self,int index);

void TransferCards(Deck *src,Deck *dest,int number);

void RemoveCardByIndex(Deck *self,int index);

void RemoveCardReferenceByIndex(Deck *self,int index);

void RemoveCardFromDeck(Deck *self,Card *card);

int privateDeck_lib_get_random_card_index(Deck *self);

void ShuffleDeck(Deck *self);

Deck * DealCards(Deck *self,int size);

void FreeDeck(Deck *self);



Card *newCard(int value, int suit){

    Card *self=(Card*)malloc(sizeof(Card));
    *self=(Card){0};

    SetCardValue(self,value);
    SetCardSuit(self,suit);

    return self;
}

void SetCardValue(Card *self,int value){
    self->value=value;
}

void SetCardSuit(Card *self,int suit){
    self->suit= suit;
}

int  GetCardValue(Card *self){
    return self->value;
}

int GetCardSuit(Card *self){
    return self->suit;
}

void FreeCard(Card *self){
    free(self);
}
const char * GetCardValueString(Card *self){
    if(self->value == ACES){
        return "Aces";
    }
    if(self->value == CARD2){
        return "2";
    }
    if(self->value == CARD3){
        return "3";
    }
    if(self->value == CARD4){
        return "4";
    }
    if(self->value == CARD5){
        return "5";
    }
    if(self->value == CARD6){
        return "6";
    }
    if(self->value == CARD7){
        return "7";
    }
    if(self->value == CARD8){
        return "8";
    }
    if(self->value == CARD9){
        return "9";
    }
    if(self->value == CARD10){
        return "10";
    }
    if(self->value == JACKS){
        return "Jack";
    }
    if(self->value == QUEEN){
        return "Queen";
    }
    if(self->value == KING){
        return "King";
    }
    return  NULL;

}
const char * GetCardSuitString(Card *self){
    if(self->suit == HEARTS){
        return "Hearts";
    }
    if(self->suit == SPADES){
        return "Spades";
    }
    if(self->suit == CLUBS){
        return "Clubs";
    }
    if(self->suit == DIAMONDS){
        return "Diamonds";
    }
    return  NULL;
}

Card *copyCard(Card *self){
    return newCard(self->value,self->suit);
}




//
// Created by mateusmoutinho on 26/04/24.
//

const char * GetCardString(Card *self){
    if(self->suit == SPADES){
        if(self->value == ACES){
            return "Ace of Spades";
        }
        if(self->value == CARD2){
            return "2 of Spades";
        }
        if(self->value == CARD3){
            return "3 of Spades";
        }
        if(self->value == CARD4){
            return "4 of Spades";
        }
        if(self->value == CARD5){
            return "5 of Spades";
        }
        if(self->value == CARD6){
            return "6 of Spades";
        }
        if(self->value == CARD7){
            return "7 of Spades";
        }
        if(self->value == CARD8){
            return "8 of Spades";
        }
        if(self->value == CARD9){
            return "9 of Spades";
        }
        if(self->value == CARD10){
            return "10 of Spades";
        }
        if(self->value == JACKS){
            return "Jack of Spades";
        }
        if(self->value == QUEEN){
            return "Queen of Spades";
        }
        if(self->value == KING){
            return "King of Spades";
        }


    }

    if(self->suit == DIAMONDS){
        if(self->value == ACES){
            return "Ace of Diamonds";
        }
        if(self->value == CARD2){
            return "2 of Diamonds";
        }
        if(self->value == CARD3){
            return "3 of Diamonds";
        }
        if(self->value == CARD4){
            return "4 of Diamonds";
        }
        if(self->value == CARD5){
            return "5 of Diamonds";
        }
        if(self->value == CARD6){
            return "6 of Diamonds";
        }
        if(self->value == CARD7){
            return "7 of Diamonds";
        }
        if(self->value == CARD8){
            return "8 of Diamonds";
        }
        if(self->value == CARD9){
            return "9 of Diamonds";
        }
        if(self->value == CARD10){
            return "10 of Diamonds";
        }
        if(self->value == JACKS){
            return "Jack of Diamonds";
        }
        if(self->value == QUEEN){
            return "Queen of Diamonds";
        }
        if(self->value == KING){
            return "King of Diamonds";
        }

    }
    if(self->suit == CLUBS){
        if(self->value == ACES){
            return "Ace of Clubs";
        }
        if(self->value == CARD2){
            return "2 of Clubs";
        }
        if(self->value == CARD3){
            return "3 of Clubs";
        }
        if(self->value == CARD4){
            return "4 of Clubs";
        }
        if(self->value == CARD5){
            return "5 of Clubs";
        }
        if(self->value == CARD6){
            return "6 of Clubs";
        }
        if(self->value == CARD7){
            return "7 of Clubs";
        }
        if(self->value == CARD8){
            return "8 of Clubs";
        }
        if(self->value == CARD9){
            return "9 of Clubs";
        }
        if(self->value == CARD10){
            return "10 of Clubs";
        }
        if(self->value == JACKS){
            return "Jack of Clubs";
        }
        if(self->value == QUEEN){
            return "Queen of Clubs";
        }
        if(self->value == KING){
            return "King of Clubs";
        }
    }
    if(self->suit == HEARTS){
        if(self->value == ACES){
            return "Ace of Hearts";
        }
        if(self->value == CARD2){
            return "2 of Hearts";
        }
        if(self->value == CARD3){
            return "3 of Hearts";
        }
        if(self->value == CARD4){
            return "4 of Hearts";
        }
        if(self->value == CARD5){
            return "5 of Hearts";
        }
        if(self->value == CARD6){
            return "6 of Hearts";
        }
        if(self->value == CARD7){
            return "7 of Hearts";
        }
        if(self->value == CARD8){
            return "8 of Hearts";
        }
        if(self->value == CARD9){
            return "9 of Hearts";
        }
        if(self->value == CARD10){
            return "10 of Hearts";
        }
        if(self->value == JACKS){
            return "Jack of Hearts";
        }
        if(self->value == QUEEN){
            return "Queen of Hearts";
        }
        if(self->value == KING){
            return "King of Hearts";
        }

    }

    return NULL;



}


Deck *newDeck(){

    Deck *self=(Deck*)malloc(sizeof(Deck));
    *self=(Deck){0};
    self->cards=(Card**)malloc(0);

    return self;

}

int SearchCardIndexInDeck(Deck *self, Card *card){

    int result=-1;
    for(int i=0;i<self->size;i++){
        Card  *current = self->cards[i];
        if(current->value == card->value && current->suit == card->suit){
            return i;
        }
    }

    return result;
}
Card  *GetCardByIndex(Deck *self,int index){
    //these allows -1 iterations
    if(index < 0){
        index  = self->size - index;
    }

    if(index >= self->size ){
        return NULL;
    }

    return  self->cards[index];
}

void AddCardToDeck(Deck *self,Card *card){

    self->cards=(Card**)realloc(self->cards,(self->size+1) * sizeof(Deck));
    self->cards[self->size]=card;

    self->size++;

}

void LoadFullDeck(Deck *self){

    for(int i=0;i<4;i++){

        for(int j=0;j<13;j++){

            Card *temp=newCard(j,i);
            AddCardToDeck(self,temp);
        }
    }
}

void TransferCards(Deck *src,Deck *dest,int number){

    if(src->size < number){
        printf("Source deck has less cards\n");
        return;
    }

   // ShuffleDeck(src);
    for(int i=0;i<number;i++){
        Card *card=src->cards[0]; //pick top card
        AddCardToDeck(dest,card);
        RemoveCardReferenceByIndex(src,0);
    }

}

void RemoveCardByIndex(Deck *self,int index){


    //these allows -1 iterations
    if(index < 0){
        index  = self->size - index;
    }
    if(index >= self->size ){
        return;
    }

    FreeCard(self->cards[index]); // remove the found card
    self->size--;
    for(int i=index ; i < self->size; i++){
        self->cards[i] = self->cards[i+1];
    }

}

void RemoveCardReferenceByIndex(Deck *self,int index){

    //these allows -1 iterations
    if(index < 0){
        index  = self->size - index;
    }
    if(index >= self->size ){
        return;
    }

    self->size--;
    for(int i=index ; i < self->size; i++){
        self->cards[i] = self->cards[i+1];
    }

}

void  RemoveCardFromDeck(Deck *self,Card *card){
    //these its important because it avoids null refes
    Card  *copy = copyCard(card);
    while (true){
        int index = SearchCardIndexInDeck(self,copy);
        if(index == -1){
            break;
        }
        RemoveCardByIndex(self,index);
    }
    FreeCard(copy);

}
int privateDeck_lib_get_random_card_index(Deck *self){
    unsigned  long current_seed = DECKLIB_DEBUG_SEED +TOTAL_ITERATIONS;
    if(!DECKLIB_DEBUG_SEED){
        current_seed = time(NULL) + DECK_LIB_SEED + TOTAL_ITERATIONS;
    }
    if(!DECK_LIB_STARTED_SEED){
        DECK_LIB_STARTED_SEED = current_seed;
    }

    TOTAL_ITERATIONS+=1;
    srand(current_seed);
    return rand() %( self->size-1);

}
void ShuffleDeck(Deck *self){

    for(int i = 0; i < DECK_LIB_TOTAL_SHUFFLE; i++){
        int card_index = privateDeck_lib_get_random_card_index(self);
        int index_to_swap = privateDeck_lib_get_random_card_index(self);

        if(card_index == index_to_swap){
            continue;
        }
        Card  *temp =  self->cards[card_index];
        self->cards[card_index] = self->cards[index_to_swap];
        self->cards[index_to_swap] = temp;
    }

}

Deck * DealCards(Deck *self,int size){
    if(self->size < size){
        printf("Source deck has less cards\n");
        return NULL;
   }

    ShuffleDeck(self);
    Deck  *sub_deck  = newDeck();

    for(int i=0;i<size;i++){
        Card *card=self->cards[0]; //pick top card
        AddCardToDeck(sub_deck,card);
        RemoveCardReferenceByIndex(self,0);

    }
    return sub_deck;
}

void FreeDeck(Deck *self){
    if(!self){
        return;
    }

    for(int i=0;i<self->size;i++){
        Card *card=self->cards[i];
        FreeCard(card);
    }
    free(self->cards);
    free(self);
}

#endif 
