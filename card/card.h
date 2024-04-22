
typedef struct Card{

    char *suit;
    char *number;

}Card;

//constructor
Card *newCard(char *suit,char* number);

//setters
void SetCardSuit(Card *self,char *suit);
void SetCardNumber(Card *self,char *number);

//getters
char *GetCardSuit(Card *self);
char *GetCardNumber(Card *self);

void FreeCard(Card *self);


