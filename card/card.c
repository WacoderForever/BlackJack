void SetCardSuit(Card *self,char *suit){

    if (self->suit){
        free(self->suit);
    }
    self->suit=strdup(suit);
}

void SetCardNumber(Card *self,char *number){

    if (self->number){
        free(self->number);
    }
    self->number=strdup(number);
}

Card *newCard(char *suit,char *number){

    Card *self=(Card*)malloc(sizeof(Card));
    *self=(Card){0};

    SetCardSuit(self,suit);
    SetCardNumber(self,number);

    return self;
}

char *GetCardSuit(Card *self){

    return self->suit;
}

char *GetCardNumber(Card *self){

    return self->number;
}

void FreeCard(Card *self){

    if(self){

        free(self->suit);
        free(self->number);
    }

    free(self);
}
