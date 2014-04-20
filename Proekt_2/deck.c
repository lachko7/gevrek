#include<stdio.h>
#include "deck.h"
void init_deck(struct deck_t *player_deck) {
    player_deck->top = -1;
}

void push_card(card_t card_to_push, struct deck_t *player_deck) {
    int top_element_deck = player_deck->top;
    if (top_element_deck != DECK_SIZE - 1) {
        player_deck->deck[++player_deck->top] = card_to_push;
    }
}
void look_card(struct deck_t *player_deck) {
    printf("-Next card:\ncard NAME: %s\ncard DAMAGE: %d\ncard HP: %d\ncard MANA: %d\n",
            player_deck->deck[player_deck->top].card_name,
            player_deck->deck[player_deck->top].card_dmg,
            player_deck->deck[player_deck->top].card_hp,
            player_deck->deck[player_deck->top].card_mana);
}
void print_card(struct deck_t *player_deck){
    printf("-Played_card:\ncard NAME: %s\ncard DAMAGE: %d\ncard HP: %d\ncard MANA: %d\n",
            player_deck->deck[player_deck->top].card_name,
            player_deck->deck[player_deck->top].card_dmg,
            player_deck->deck[player_deck->top].card_hp,
            player_deck->deck[player_deck->top].card_mana);
    --player_deck->top;
}
void print_deck(struct deck_t player_deck) {
    int i;
    for (i = 0; i <= player_deck.top; i++) {
        printf("element %d ->  name: %s, %d, %d, %d\n", i, player_deck.deck[i].card_name, player_deck.deck[i].card_dmg,
                player_deck.deck[i].card_hp, player_deck.deck[i].card_mana);
    }
}

int main(){
    card_t attacker = {"Powerful card",3, 3, 20};
    card_t defender = {"Weak card", 3, 4, 20};
    struct deck_t player_deck;
    init_deck(&player_deck);
    push_card(attacker, &player_deck);
    push_card(defender, &player_deck);
    look_card(&player_deck);
    print_card(&player_deck);
    print_deck(player_deck);
    print_card(&player_deck);
    return 0;
}


