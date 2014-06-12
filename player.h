#ifndef PLAYER_H_
#define PLAYER_H_
#include "deck.h"
#include "manapool.h"
#include "card.h"


#define HAND_LENGTH 5

typedef struct{
	char* name;
	int health;
	struct manapool_t manapool	;
	int turn;
	card_t hand[HAND_LENGTH];
	deck_t deck;
}player_t;

int change_hp(player_t* player, int hp);
card_t play_card_from_hand(player_t* player, int card);
void turn_begin(player_t* player);


#endif
