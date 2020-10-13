#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>			//including cstd liberary for the random number generator.
#include <ctime>			//including to use time for the random number generator.

int balance_player = 100;   // the money balance of the player																						
int balance_house = 100;    // the money balance of the house
int bet = 0;                // the betting omount taken out of the fuction
struct playing_cards {      //struct for playing cards, number, sort, and the values of them.
	std::string sort;
	int number = 0;
	char number2 = ' ';
	int value_1 = 0;
	int value_2 = 0;
};
int random_number(int max) {		//random number generator
	std::srand(time(0));
	int rng = std::rand() % max;
	return rng;
}
void betting() {				//betting fuction, to take the bet and make sure its within the legal perameters
	bool bet_accept = false;
	std::cout << "How much would you like to bet? (minimum amount = 10)" << std::endl;
	do {
		std::cout << "Enter amount: ";
		std::cin >> bet;
		if (bet < 10) {
			std::cout << "your bet is under the minimum limit of 10$" << std::endl;
		}
		if (bet > balance_player) {
			std::cout << "you dont have enought money to make this bet" << std::endl;
		}
		if (bet > balance_house) {
			std::cout << "you cant bet more money than the house" << std::endl;
		}
		if (bet >= 10 && bet <= balance_player && bet <= balance_house) {
			bet_accept = true;
		}
	} while (bet_accept == false);
	std::cout << "Your bet: " << bet << "$" << std::endl;
}
void draw_card() {				// ment as a fuction for just draw cards, but kind of ended up as the main fucktion :)
	playing_cards playing_cards[52];		//an array of the struct
	for (int i = 0; i < 13; i++) {				//initialising the playing cards of spades
		playing_cards[i].number = i + 1;
		playing_cards[i].sort = "Spades  ";
		playing_cards[i].value_1 = i + 1;
		playing_cards[i].value_2 = i + 1;
		if (i == 10) {
			playing_cards[i].number2 = 'J';
			playing_cards[i].value_1 = 10;
			playing_cards[i].value_2 = 10;
			playing_cards[i].number = 0;
		}
		if (i == 11) {
			playing_cards[i].number2 = 'Q';
			playing_cards[i].value_1 = 10;
			playing_cards[i].value_2 = 10;
			playing_cards[i].number = 0;
		}
		if (i == 12) {
			playing_cards[i].number2 = 'K';
			playing_cards[i].value_1 = 10;
			playing_cards[i].value_2 = 10;
			playing_cards[i].number = 0;
		}
		if (i == 0) {
			playing_cards[i].number2 = 'A';
			playing_cards[i].value_1 = 1;
			playing_cards[i].value_2 = 11;
			playing_cards[i].number = 0;
		}
	}
	for (int i = 13; i < 26; i++) {			//initialising thr playing cards of hearts
		playing_cards[i].number = i - 12;
		playing_cards[i].sort = "Hearts  ";
		playing_cards[i].value_1 = i - 12;
		playing_cards[i].value_2 = i - 12;
		if (i == 23) {
			playing_cards[i].number2 = 'J';
			playing_cards[i].value_1 = 10;
			playing_cards[i].value_2 = 10;
			playing_cards[i].number = 0;
		}
		if (i == 24) {
			playing_cards[i].number2 = 'Q';
			playing_cards[i].value_1 = 10;
			playing_cards[i].value_2 = 10;
			playing_cards[i].number = 0;
		}
		if (i == 25) {
			playing_cards[i].number2 = 'K';
			playing_cards[i].value_1 = 10;
			playing_cards[i].value_2 = 10;
			playing_cards[i].number = 0;
		}
		if (i == 13) {
			playing_cards[i].number2 = 'A';
			playing_cards[i].value_1 = 1;
			playing_cards[i].value_2 = 11;
			playing_cards[i].number = 0;
		}
	}
	for (int i = 26; i < 39; i++) {		//initialising the playing cards of clubs
		playing_cards[i].number = i - 25;
		playing_cards[i].sort = "Clubs   ";
		playing_cards[i].value_1 = i - 25;
		playing_cards[i].value_2 = i - 25;
		if (i == 36) {
			playing_cards[i].number2 = 'J';
			playing_cards[i].value_1 = 10;
			playing_cards[i].value_2 = 10;
			playing_cards[i].number = 0;
		}
		if (i == 37) {
			playing_cards[i].number2 = 'Q';
			playing_cards[i].value_1 = 10;
			playing_cards[i].value_2 = 10;
			playing_cards[i].number = 0;
		}
		if (i == 38) {
			playing_cards[i].number2 = 'K';
			playing_cards[i].value_1 = 10;
			playing_cards[i].value_2 = 10;
			playing_cards[i].number = 0;
		}
		if (i == 26) {
			playing_cards[i].number2 = 'A';
			playing_cards[i].value_1 = 1;
			playing_cards[i].value_2 = 11;
			playing_cards[i].number = 0;
		}
	}
	for (int i = 39; i < 52; i++) {		//initialising the playing cards of diamonds
		playing_cards[i].number = i - 38;
		playing_cards[i].sort = "Diamonds";
		playing_cards[i].value_1 = i - 38;
		playing_cards[i].value_2 = i - 38;
		if (i == 49) {
			playing_cards[i].number2 = 'J';
			playing_cards[i].value_1 = 10;
			playing_cards[i].value_2 = 10;
			playing_cards[i].number = 0;
		}
		if (i == 50) {
			playing_cards[i].number2 = 'Q';
			playing_cards[i].value_1 = 10;
			playing_cards[i].value_2 = 10;
			playing_cards[i].number = 0;
		}
		if (i == 51) {
			playing_cards[i].number2 = 'K';
			playing_cards[i].value_1 = 10;
			playing_cards[i].value_2 = 10;
			playing_cards[i].number = 0;
		}
		if (i == 39) {
			playing_cards[i].number2 = 'A';
			playing_cards[i].value_1 = 1;
			playing_cards[i].value_2 = 11;
			playing_cards[i].number = 0;
		}
	}
	std::cout << "Your cards are:" << std::endl;
	int playing_cards_in_use[52];     // an array of the cards taken out of the deck, and giving it a value of 1. 
	for (int i = 0; i < 52; i++) {
		playing_cards_in_use[i] = 1;
	}
	std::vector<int> your_hand(21);	  //vector for the cards on your hand
	do {
		random_number(52);
		your_hand[0] = random_number(52);			//getting random number and finding a card for it 
		playing_cards_in_use[your_hand[0]] = 0;		//to make sure i dont draw it twice
		random_number(52);
		your_hand[1] = random_number(52);
		playing_cards_in_use[your_hand[1]] = 0;
	} while (your_hand[0] == your_hand[1]);			//making sure they are noe the same card
	playing_cards_in_use[your_hand[0]] = 0;			//setting value to 0 to later check if it is in use 
	playing_cards_in_use[your_hand[1]] = 0;
	int value_1 = 0;
	int value_2 = 0;
	int ace = 0;
	if (playing_cards[your_hand[0]].number == 0) {				//prints out your cards in consol 
		std::cout << playing_cards[your_hand[0]].number2 << " of " << playing_cards[your_hand[0]].sort << std::endl;
	}
	else {
		std::cout << playing_cards[your_hand[0]].number << " of " << playing_cards[your_hand[0]].sort << std::endl;
	}
	if (playing_cards[your_hand[1]].number == 0) {
		std::cout << playing_cards[your_hand[1]].number2 << " of " << playing_cards[your_hand[1]].sort << std::endl;
	}
	else {
		std::cout << playing_cards[your_hand[1]].number << " of " << playing_cards[your_hand[1]].sort << std::endl;
	}
	if (playing_cards[your_hand[0]].value_1 == 1 && playing_cards[your_hand[1]].value_1 == 1) {				//prints out the value of the cards in consol 
		std::cout << "Your values are eather: " << playing_cards[your_hand[0]].value_1 + playing_cards[your_hand[1]].value_1 << " or: " << playing_cards[your_hand[0]].value_2 + playing_cards[your_hand[1]].value_1 << std::endl;
		value_1 = playing_cards[your_hand[0]].value_1 + playing_cards[your_hand[1]].value_1;
		value_2 = playing_cards[your_hand[0]].value_2 + playing_cards[your_hand[1]].value_1;
		int ace = 1;
	}
	else if (playing_cards[your_hand[0]].value_1 == 1 || playing_cards[your_hand[1]].value_1 == 1) {
		std::cout << "Your values are eather: " << playing_cards[your_hand[0]].value_1 + playing_cards[your_hand[1]].value_1 << " or: " << playing_cards[your_hand[0]].value_2 + playing_cards[your_hand[1]].value_2 << std::endl;
		value_1 = playing_cards[your_hand[0]].value_1 + playing_cards[your_hand[1]].value_1;
		value_2 = playing_cards[your_hand[0]].value_2 + playing_cards[your_hand[1]].value_2;
		int ace = 1;
	}
	else {
		std::cout << "Your value is: " << playing_cards[your_hand[0]].value_1 + playing_cards[your_hand[1]].value_1 << std::endl;
		value_1 = playing_cards[your_hand[0]].value_1 + playing_cards[your_hand[1]].value_1;
	}
	betting();				//takes the bett of the player
	bool draw_again = true;
	int i = 2;				//to give the next value to the 3. card
	do {
		std::cout << "Would you like to draw another card?" << std::endl;
		std::cout << "For YES enter: 1    For NO enter: 2" << std::endl;
		int draw_again_1 = 0;
		std::cin >> draw_again_1;
		if (draw_again_1 == 1) {
			do {
				random_number(52);			//gets random number and gives it a card, while making sure its not yet been taken out of the deck
			} while (playing_cards_in_use[random_number(52)] == 0);
			your_hand[i] = random_number(52);
			playing_cards_in_use[your_hand[i]] = 0;
			for (int j = 0; j < (i + 1); j++) {				//for-loop to print out your cards
				if (playing_cards[your_hand[j]].number == 0) {
					std::cout << playing_cards[your_hand[j]].number2 << " of " << playing_cards[your_hand[j]].sort << std::endl;
				}
				else {
					std::cout << playing_cards[your_hand[j]].number << " of " << playing_cards[your_hand[j]].sort << std::endl;
				}
			}
			if (playing_cards[your_hand[i]].value_1 == 1) {		//prints out the different values you hand can have
				value_2 = value_2 + playing_cards[your_hand[i]].value_2;
				value_1 = value_1 + playing_cards[your_hand[i]].value_1;
				int ace = 1;
				std::cout << "Your values are eather: " << value_1 << " or: " << value_2 << std::endl;
			}
			else if (playing_cards[your_hand[i]].value_1 != 1 && ace == 0) {
				value_1 = value_1 + playing_cards[your_hand[i]].value_1;
				std::cout << "Your value is: " << value_1 << std::endl;
			}
			else {
				value_1 = value_1 + playing_cards[your_hand[i]].value_1;
				value_1 = value_2 + playing_cards[your_hand[i]].value_1;
				std::cout << "Your values are eather: " << value_1 << " or: " << value_2 << std::endl;
			}
			if (value_1 > 21 && value_2 > 21) {				//checks if you are over the limit of 21, and if you are it will exit the loop
				std::cout << "You went over the limit of 21" << std::endl;
				draw_again = false;
			}
			if (value_1 > 21 && value_2 == 0) {
				std::cout << "You went over the limit of 21" << std::endl;
				draw_again = false;
			}
			i++;
		}
		else if (draw_again_1 == 2) {
			draw_again = false;
		}
	} while (draw_again == true);		//do -while loop, for drawing cards.
	int player_value = 0;
	int house_value = 0;
	int hvalue_1 = 0;
	int hvalue_2 = 0;
	int house_hand[21];
	if (value_2 > value_1 && value_1 < 21) {		//finds the best value to use based on ace value
		player_value = value_2;
	}
	else {
		player_value = value_1;
	}
	i = 0;
	do {
		do {										//finds cards for the house untill it beats the other player, or the other player went over 21. 
			random_number(52);
		} while (playing_cards_in_use[random_number(52)] == 0);
		house_hand[i] = random_number(52);
		playing_cards_in_use[house_hand[i]] = 0;
		if (playing_cards[house_hand[i]].value_1 == 1) {
			hvalue_1 = hvalue_1 + 1;
			hvalue_2 = hvalue_2 + 11;
		}
		else {
			hvalue_1 = hvalue_1 + playing_cards[house_hand[i]].value_1;
		}
		if (hvalue_2 > hvalue_1 && hvalue_2 < 21) {
			house_value = hvalue_2;
		}
		else {
			house_value = hvalue_1;
		}
	} while (player_value <= 21 && house_value < player_value);
	std::cout << "Your value: " << player_value << std::endl;
	std::cout << "Value of the House: " << house_value << std::endl;
	if (player_value < 21 && house_value > 21) {
		std::cout << "Congratulation you have won!" << std::endl;			//finds outcome of the round, eather win, draw or lose.
		balance_player = balance_player + bet;								//also corrects the money balance of the players based on the bet.
		balance_house = balance_house - bet;
	}
	else if (player_value == house_value) {
		std::cout << "the round ended as a draw" << std::endl;
	}
	else {
		std::cout << "You have lost to the house" << std::endl;
		balance_player = balance_player - bet;
		balance_house = balance_house + bet;
	}
}
int main() {
	do {		//to make sure you can play until any of the sides are out of money.
		std::cout << "---------- Welcome to blackjack ----------" << std::endl;
		std::cout << "Your balance: " << balance_player << "$    Houses balance: " << balance_house << "$" << std::endl;
		draw_card();		//calls the draw_card fuction, witch basiccly is the main function :)
	} while (balance_house > 0 && balance_player > 0);
	if (balance_player == 0) {				//checks if any of the players are out of money, and of so exits the program. 
		std::cout << "You are out of money" << std::endl;
	}
	if (balance_house == 0) {
		std::cout << "The house is out of money, you are the best!" << std::endl;
	}
	std::cout << "Your balance: " << balance_player << "$    Houses balance: " << balance_house << "$" << std::endl;
	return 0;
}