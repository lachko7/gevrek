#ifndef MANAPOOL_H
#define	MANAPOOL_H
#include "card.h"


typedef struct manapool_t{
    int mana;
    int current_mana;
}manapool_t;

int can_put_card(card_t card_to_put, manapool_t *pool);
void manipulate_mana(manapool_t* pool,int mana_to_manipulate, int modifier);

#endif	/* MANAPOOL_H */

