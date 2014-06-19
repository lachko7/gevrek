#include <stdlib.h>
#include "deck.h"
#include "card.h"
#include "shuffle.h"

void shuffle_deck(deck_t* deck){
	int i,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 30; j++){
			int rand_num = random_in_range(0,30);
			if( rand_num == j ) rand_num = random_in_range(0,30);
			swap(&deck->deck[j],&deck->deck[rand_num]);
		}	
	}
}

void swap(card_t* card1, card_t* card2){
	card_t temp = *card1;
	*card1 = *card2;
	*card2 = temp;
}

int random_in_range (unsigned int min, unsigned int max)
{
  int base_random = rand(); 
  if (RAND_MAX == base_random) return random_in_range(min, max);
  int range       = max - min,
      remainder   = RAND_MAX % range,
      bucket      = RAND_MAX / range;
  if (base_random < RAND_MAX - remainder) {
    return min + base_random/bucket;
  } else {
    return random_in_range (min, max);
  }
}

