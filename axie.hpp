#include <vector>
using namespace ::std;
enum property{SPEED, MORAL, ATTACK};
enum axieStatus{DEAD, ALIVE, LASTTURN};
class Buff{
    public:
    property type;
    float percent;
    bool stackable;
    unsigned int turnsleft;
};

class Debuff{
    public:
    property type;
    float percent;
    bool stackable;
    unsigned int turnsleft;
};
class Card
{   public:
    char cls;
    unsigned int id;
    unsigned int part;
    Debuff *dbuff;
    Buff *buff;
    unsigned int dmg;
    unsigned int shield;
    unsigned int energy;
};

class Property
{
    public:
    unsigned int hp;
    unsigned int moral;
    unsigned int skill;
    unsigned int speed;
};
class Location
{
    unsigned int xloc;
    unsigned int yloc;
};

class  Axie
{   
    public:
    char cls;
    unsigned int id;
    unsigned int shield;
    Property original;
    Property current;
    axieStatus status;
    vector<Card> cards;
    vector<Card> cardsToUse;
    vector <Buff> buff; 
    vector <Debuff> debuff;
};

class Player
{
    public:
    vector<Axie> axies;
    unsigned int energy;
    vector<Card> cards;
    vector<Card> cardsCanUse;

};

class Game
{
    public:
    Player *player1;
    Player *opponent;
    vector <Axie> order;
    unsigned int turn;
};

Axie *initAxie(char cls, unsigned int hp, unsigned int speed, unsigned int moral, unsigned int skill)
{
    Axie *axie = new Axie();
    axie->cls = cls;
    axie->original.hp = hp;
    axie->original.moral = moral;
    axie->original.skill = skill;
    axie->original.speed = speed;
    axie->current.hp = hp;
    axie->current.speed = speed;
    axie->current.moral = moral;
    axie->current.skill = skill;
    axie->status = ALIVE;
    return axie;
}
Axie* getCloseAxie()
{   

    return NULL;
}
void dealDamage(Axie from, Axie to, float ratio)
{

}

float classBonus(Axie from, Axie to, float ratio)
{
    if(from.cls =='E' || from.cls =='A' || from.cls == 'G')
    {
        if(to.cls == 'B' || to.cls == 'F' || to.cls == 'I')
            return ratio - 0.15;
        else if(to.cls == 'D' || to.cls == 'C' || to.cls == 'H')
            return ratio + 0.15;
        else
            return ratio;
    }
    if(from.cls =='B' || from.cls =='F' || from.cls == 'I')
    {
        if(to.cls == 'D' || to.cls == 'C' || to.cls == 'H')
            return ratio - 0.15;
        else if(to.cls == 'E' || to.cls == 'A' || to.cls == 'G')
            return ratio + 0.15;
        else
            return ratio;
    }
    if(from.cls =='D' || from.cls =='C' || from.cls == 'H')
    {
        if(to.cls == 'E' || to.cls == 'A' || to.cls == 'G')
            return ratio - 0.15;
        else if(to.cls == 'B' || to.cls == 'F' || to.cls == 'I')
            return ratio + 0.15;
        else
            return ratio;
    }
    return ratio;
}

void applycard(Card* card, Axie* attacker, Player* axieOwner, Player* otherplayer)
{
    switch (card->id)
    {
    case 3:
        Axie *enemy = getCloseAxie();
        break;
    
    default:
        break;
    }
}
// add cards to the player or opponent after running out of cards or at the beginning of the game 
void addCards(Player player)
{
    for (Axie axie : player.axies)
    {
        for (Card card : axie.cards)
        {
            player.cards.push_back(card);
            player.cards.push_back(card);
        }
    }
}

void fillCardInfo(Card *card)
{
    switch (card->id)
    {
    case 3:
        card->cls = 'A';
        card->part=2;
        card->energy = 1; 
        card->dmg = 30;
        card->shield = 50;
        break;
    case 4:
        card->cls = 'A';
        card->part=4;
        card->energy = 1;
        card->dmg = 80;
        card->shield = 40;
    case 5:
        card->cls = 'A';
        card->part=1;
        card->dmg = 110;
        card->shield = 20;
        card->energy = 1;
    case 6:
        card->cls = 'A';
        card->part=1;
        card->dmg = 0;
        card->shield = 40;
        card->energy = 1;
        
    case 3:
        card->cls = 'A';
        card->part=2;
        card->energy = 1; 
        card->dmg = 30;
        card->shield = 50;
        break;
    default:
        break;
    }
}





