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

int main(){
	card_t attacker = {"Powerful card",40, 3000, 20};
	card_t defender = {"Weak card", 320, 400, 20};
	 
	
	if (attack(&attacker, &defender) == 0){ 
		printf("Both cards are dead");
	}
	if (attack(&attacker, &defender) == 1){ 
		printf("Attacker won");
	}
	if (attack(&attacker, &defender) == 2){
		printf("Defender won");
	}
	if (attack(&attacker, &defender) == 3){ 
		printf("Both cards are alive");
	}
	
	return 0;
}
