#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "card.h"
#include "manapool.h"
#include "deck.h"


//tuka se podava otr hp stoinost ako priema dmg
//ili + stoinost ako se lekuva
int change_hp(player_t* player, int hp){
	player->health += hp;
}


//vru6ta se karta ot rukata

card_t play_card_from_hand(player_t* player, int card){
	int card_num = card - 1;		
	card_t card_to_return = player->hand[card_num];
	memset(&(player->hand[card_num]),0,sizeof(card_t));
	manipulate_mana(&player->manapool,card_to_return.card_mana,0);
	return card_to_return;
}

void turn_begin(player_t* player){
	player->turn++;
	int i;		
	static int dmg = 0;
	for(i = 0; i < 5; i++){
		if(player->hand[i].card_hp == 0){
			if(player->deck.top > 0){
				int topdeck = player->deck.top;
				player->hand[i] = player->deck.deck[topdeck];
				memset(&(player->deck.deck[topdeck]),0,sizeof(card_t));
				player->deck.top--;
				break;					
			} else {
				change_hp(player,-(dmg++));
				break;
			}
		}	
	}
	manipulate_mana(&player->manapool,1,1);
		
}

