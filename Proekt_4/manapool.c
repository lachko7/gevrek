#include<stdio.h>
#include "card.h" 
#include "manapool.h"
//#include "manapool.h"
void can_put_card(card_t card_to_put, manapool_t *pool){
        pool->current_mana -= card_to_put.card_mana;
    if(pool->current_mana > 0 ){
        printf("You can put the card\n");
        
    }
    else{
        printf("You can't put the card\n");
    }
}
void manipulate_mana(manapool_t *pool, int mana_to_manipulate, int modifier){
    if(modifier == 1){
        pool->current_mana += mana_to_manipulate;
    }
    else if(modifier == 0){
        pool->current_mana -= mana_to_manipulate;
    }
}
