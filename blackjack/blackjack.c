
int GetBlackJackCardValue(Card  *card){

    if(card->value >= ACES && card->value <= CARD10){
        return card->value+1;
    }

    return 10;
}



int GetPoints(Deck *dek){

    int points=0;
    //counting values considering aces as 1
    for(int i=0;i<dek->size;i++){

        Card *card=dek->cards[i];

        points+= GetBlackJackCardValue(card);
    }
    //incrementing aces in 10 if dont fit 22
    for(int i=0;i<dek->size;i++){

        Card *card=dek->cards[i];
        if(card->value != ACES){
            continue;
        }
        int possible_pointes = points+10;
        if(possible_pointes> 21){
            break;
        }
        points = possible_pointes;

    }

    return points;
}

bool CanSplit(Deck *deck){

    Card * first = deck->cards[0];
    Card  *second = deck->cards[1];
    if(first->value == second->value) {
        return true;
    }
    return false;
}