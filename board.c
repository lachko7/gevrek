#include <stdio.h>
#include <string.h>
#include "board.h"
#include "card.h"
#include "deck.h"
#include "manapool.h"
#include "shuffle.h"

int can_play_card(board_t* board, int first_pl, int card, int num_lane){
	if (first_pl == 1){
		if(card > 0 && card <= 5){
			int card_index = card - 1;
			card_t card = board->player1.hand[card_index];
			if (can_put_card(card, &(board->player1.manapool))){
				int lane = num_lane - 1;
				if (board->cards_on_field_p1[lane].card_hp == 0){
					return 1;
				}
			}
		}
	} else if(first_pl==2) {
		if (card > 0 && card <= 5){
			int card_index = card - 1;
			card_t card = board->player2.hand[card_index];
			if (can_put_card(card, &(board->player2.manapool))){
				int lane = num_lane - 1;
				if (board->cards_on_field_p2[lane].card_hp == 0){
					return 1;
				}
			}
		}
	}

	return 0;
}

int play_card(board_t* board, int first_pl, int card, int num_lane){
	if (first_pl == 1){
		card_t card_to_play = play_card_from_hand(&board->player1,card);
		if (card_to_play.card_hp > 0){
			board->cards_on_field_p1[num_lane - 1] = card_to_play;
			return 0;
		}
	} else if (first_pl == 2){
		card_t card_to_play = play_card_from_hand(&board->player2, card);
		if (card_to_play.card_hp > 0){
			board->cards_on_field_p2[num_lane - 1] = card_to_play;
			return 0;
		}
	}

	return 1;
}

void turn_end(board_t* board, int first_pl){
	board->turn_p1 = !board->turn_p1;
	board->turn_p2 = !board->turn_p2;


	if (first_pl == 1){
		turn_begin(&board->player2);
	} else if (first_pl == 2){
		turn_begin(&board->player1);
	}
}

int who_wins(board_t* board){
	if (board->player1.health == 0){
		return 2;
	} else if (board->player2.health == 0){
		return 1;
	}
	return 0;
}

int is_game_over(board_t* board){
	int winner = who_wins(board);
	if (winner == 1){
		printf("Player1 wins!\n");
		return 1;
	}
	else if (winner == 2){
		printf("Player2 wins!\n");
		return 1;
	}
	
	return 0;
}

void visualize_board(board_t* board){
	char* lines = (char*)malloc(57);
	char* hashtags = (char*)malloc(57);

	memset(lines, '-', 56);
	memset(hashtags, '#', 56);
	lines[56] = '\n';
	hashtags[56] = '\n';

	lines[57] = 0;
	hashtags[57] = 0;

	char* cstring_board = (char*)malloc(570);
	memset(cstring_board, 0, 560);
	char* player1 = cstring_player(&board->player1);
		
	char* player2 = cstring_player(&board->player2);
		
	char* p1_hand = cstring_hand(board->player1.hand);
	char* p2_hand = cstring_hand(board->player2.hand);
	char* p1_half = cstring_board_half(board->cards_on_field_p1);
	char* p2_half = cstring_board_half(board->cards_on_field_p2);
	
	strcat(cstring_board, player1);
	strcat(cstring_board, lines);
	strcat(cstring_board, p1_hand);
	strcat(cstring_board, hashtags);
	strcat(cstring_board, p1_half);
	strcat(cstring_board, hashtags);
	strcat(cstring_board, p2_half);
	strcat(cstring_board, hashtags);
	strcat(cstring_board, p2_hand);
	strcat(cstring_board, lines);
	strcat(cstring_board, player2);


	printf(cstring_board);
	printf("\n");


}


//metod za "risuvane" na igracha
char* cstring_player(player_t* player){
	
	char* pdata = (char*)malloc(57);
	memset(pdata, 32, 57);
	pdata[56] = '\n';
	int name_size = 0;
	if(player->name)
	name_size = strlen(player->name);
	
	if(player->name){
		strcpy(pdata, "PLAYER:");	
		strcpy((pdata+7),player->name);
		pdata[name_size+7] = 32;
		pdata[name_size+8] = '(';
		char hp[4];
		sprintf(hp, "%dhp", player->health);
		hp[4] = 0;
		strcpy((pdata + name_size + 9), hp);
		pdata[name_size + 13] = ')';
	}
	pdata[name_size + 14] = ',';
	
	strcpy((pdata+name_size+15),"MANA ");
	char mana[5];
	sprintf(mana, "%d/10", player->manapool.current_mana);
	strcpy((pdata + name_size + 20), mana);

	if(player->manapool.current_mana == 10)
		pdata[name_size + 25] = 32;
	else pdata[name_size + 24] = 32;
	
	strcpy((pdata + name_size + 27), "TURN: ");
	char turn[2];
	sprintf(turn, "%d", player->turn);
	turn[2] = 0;
	strcpy((pdata + name_size + 33), turn);
	if(player->turn > 10)
		pdata[name_size + 35] = 32;
	else pdata[name_size + 34] = 32;	
	pdata[57] = 0;

	return pdata;

} 


//metod za "risuvane" na polovinata duska
char* cstring_board_half(card_t* cards){
	char* bdata = (char*)malloc(57);
	memset(bdata,32,57);
	bdata[57] = 0;
	bdata[56] = '\n';
	bdata[0] = '|' ;
	int i;
	int offset = 1;
	int card_len = 7;
	for(i = 0; i < 5; i++){
		if(cards[i].card_hp != 0){
			strcpy((bdata+offset),cstring_card(&cards[i]));
		}
		offset+=card_len;
		bdata[offset] = '|';
	}

	return bdata;


}

//metod za "risuvane" na rukata
char* cstring_hand(card_t* cards){
	char* hdata = (char*)malloc(57);
	memset(hdata,32,57);
	hdata[56] = '\n';
	hdata[57] = 0;
	hdata[0] = '|';
	int i;
	int offset = 1;
	const int card_len = 7;
	for(i = 0; i < 5; i++){
		if(cards[i].card_hp){
			strcpy((hdata+offset),cstring_card(&cards[i]));
		}	
		offset += card_len;
		hdata[offset] = '|';
	}

	return hdata;
}


//metod za "risuvane" na karti
char* cstring_card(card_t* card){
	char* card_string = (char*)malloc(9);
	memset(card_string,32,9);
	card_string[9] = 0;
	card_string[1] = '(';

	char attack[2];
	sprintf(attack,"%d",card->card_dmg);
	attack[2] = 0;
	strcpy((card_string+2),attack);

	card_string[4] = '|';

	char health[2];
	sprintf(health,"%d", card->card_hp);
	health[2] = 0;
	strcpy((card_string+5),health);
	card_string[7] = ')';


	return card_string;
}


int main(){
	board_t board;
	memset(&board,0,sizeof(board_t));
	board.player1.name = "Pesho";
	board.player1.health = 30;

	board.player2.name = "Gosho";
	board.player2.health = 30;
	visualize_board(&board);
	int i;
	for(i = 0; i < 30; i++){
		card_t card;
		card.card_hp = i+1;
		card.card_dmg = i;
		board.player1.deck.deck[i] = card;
	}		

	shuffle_deck(&board.player1.deck);

	for(i = 0; i < 30; i++){
		printf("(%d|%d)\n",board.player1.deck.deck[i].card_dmg,board.player1.deck.deck[i].card_hp);	
	}
	return 0;
}
