





int GetBlackJackCardValue(Card *card);

int GetPoints(Deck *deck);

bool CanSplit(Deck *deck);

void Winner(Round *round,Deck *playerhand,int balance);

void Hit(Round *round,CliInterface interface,int balance);