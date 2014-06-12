#ifndef BOARD_T_
#define BOARD_T_


#include <stdlib.h>
#include <string.h>

#include "manapool.h"
#include "player.h"
#include "card.h"
#include "deck.h"


typedef struct board_t{
	player_t player1;
	player_t player2;

	int turn_p1;
	int turn_p2;

	card_t cards_on_field_p1[5];
	card_t cards_on_field_p2[5];

} board_t;

int can_play_card(board_t* board, int first_pl, int card, int num_lane);

int play_card(board_t* board, int first_pl, int card, int num_lane);
void turn_end(board_t* board, int first_pl);

int who_wins(board_t* board);

int is_game_over(board_t* board);

void visualize_board(board_t* board);


//metod za "risuvane" na igracha
char* cstring_player(player_t* player);


//metod za "risuvane" na polovinata duska
char* cstring_board_half(card_t* cards);

//metod za "risuvane" na rukata
char* cstring_hand(card_t* cards);

//metod za "risuvane" na karti
char* cstring_card(card_t* card);
#endif
