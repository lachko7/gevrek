#ifndef DECK_H
#define	DECK_H
#define DECK_SIZE 30
#include "card.h"   

typedef struct deck_t {
    int top;
    card_t deck [DECK_SIZE];
} deck_t;
void init_deck(struct deck_t *player_deck);
void print_card(struct deck_t *player_deck);
void push_card(card_t card_to_push, struct deck_t *player_deck);
void look_card(struct deck_t *player_deck);
void print_deck(struct deck_t player_deck);
#endif



