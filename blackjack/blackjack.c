int GetAceBlackJackValue(int currentpoints){

    int tot=11+currentpoints;
    if(tot>21){

        return 1;
    }

    return 11;
}

int GetBlackJackValue(const char *cardvalue,int points){

    if(!strcmp(cardvalue,"2")){
        return 2;
    }
    if(!strcmp(cardvalue,"3")){
        return 3;
    }
    if(!strcmp(cardvalue,"4")){
        return 4;
    }
    if(!strcmp(cardvalue,"5")){
        return 5;
    }
    if(!strcmp(cardvalue,"6")){
        return 6;
    }
    if(!strcmp(cardvalue,"7")){
        return 7;
    }
    if(!strcmp(cardvalue,"8")){
        return 8;
    }
    if(!strcmp(cardvalue,"9")){
        return 9;
    }
    if(!strcmp(cardvalue,"10")){
        return 10;
    }
    if(!strcmp(cardvalue,"King")){
        return 10;
    }
    if(!strcmp(cardvalue,"Jack")){
        return 10;
    }
    if(!strcmp(cardvalue,"Queen")){
        return 10;
    }

    else{

        GetAceBlackJackValue(points);
    }
}



int GetPoints(Deck *self){

    int points=0;

    for(int i=0;i<self->size;i++){
        
        Card *temp=self->cards[i];
        const char *cardvalue=GetCardValueString(temp);
        points+=GetBlackJackValue(cardvalue,points);
    }

    return points;
}

int CanSplit(Deck *self){

    int ans=0;
    int k=0;

    do{
        Card *temp=self->cards[k];
        const char *ini=GetCardValueString(temp);

        for(int i=k+1;i<self->size;i++){

            Card *temp2=self->cards[i];
            const char *next=GetCardValueString(temp2);

            if(!strcmp(ini,next)){

                ans=1;
                break;
            }
        }
        k++;
    }
    while(k<self->size-1);

    return ans;
}