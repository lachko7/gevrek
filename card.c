#include <stdio.h>
#include "card.h"

int attack (card_t *attacker, card_t *defender){	
	if(attacker -> card_dmg >= defender -> card_hp && defender -> card_dmg >= attacker -> card_hp  ){
		return 0;
		//Both cards are dead
	}
	if(attacker -> card_dmg >= defender -> card_hp && defender -> card_dmg < attacker -> card_hp){
		return 1;
		//Attacker wins
	}
	if(attacker -> card_dmg < defender -> card_hp && defender -> card_dmg >= attacker -> card_hp){
		return 2;
		//Defender wins
	}
	if(attacker -> card_dmg < defender -> card_hp && defender -> card_dmg < attacker -> card_hp){
		return 3;
		//Both cards are alive
	}
}
