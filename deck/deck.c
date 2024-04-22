Deck *newDeck(){

    Deck *self=(Deck*)malloc(sizeof(Deck));
    *self=(Deck){0};
    self->cards=(Card**)malloc(0);

    return self;

}

int SearchCardInDeck(Deck *self,Card *card){

    int result=0;
    for(int i=0;i<self->size;i++){

        if((self->cards[i])==card){

            result=1;
            break;
        }
    }

    return result;
}

void AddCardToDeck(Deck *self,Card *card){

    int exists=SearchCardInDeck(self,card);

    if(exists==0){

        self->cards=(Card**)realloc(self->cards,(self->size+1)*sizeof(Deck));
        self->cards[self->size]=card;
        self->size++;
    }
}

void UpdateDeckAfterCardRemoval(Deck *self,int pos){
    
    for(pos;pos<self->size;++pos){

        self->cards[pos]=self->cards[pos+1];
    }

    self->size--;
}

void RemoveCardFromDeck(Deck *self,Card *card){

    int exists=SearchCardInDeck(self,card);
    if(exists==0){

        exit(1);
    }

    for(int i=0;i<self->size;i++){

        if(card==self->cards[i]){

            FreeCard(card);
            UpdateDeckAfterCardRemoval(self,i);
            break;
        }
    }

}

void ShuffleDeck(Deck *self){

    int rand1=30+rand()%2;

    for(int i=0;i<rand1;i++){
        int rand2=rand();
        Card *temp=self->cards[i];
        self->cards[i]=self->cards[rand2%51];
        self->cards[rand2%51]=temp;
    }


}

Deck *DealCards(Deck *self){

    Deck *mycards=newDeck();
    ShuffleDeck(self);

    for(int i=0;i<4;i++){

        Card *card=self->cards[i]; //pick top card
        AddCardToDeck(mycards,card); //give selected card to player
        RemoveCardFromDeck(self,card);  //remove card from the main deck
        ShuffleDeck(self);
    }

    return mycards;
}

void FreeDeck(Deck *self){

    if(self){

        for(int i=0;i<self->size;i++){

            Card *card=self->cards[i];
            FreeCard(card);
        }
    }

    free(self);
}