#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
int high_card(int *cards){
	int high_val = cards [0];
	for(int i = 1; i <= 5; i++)
		if( cards[i] > high_val ) high_val = cards[i];
	return high_val;
}
int one_pair(int *cards){
	int max = - 1;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++)
			if(i != j && cards[i] == cards[j] && cards[i] > max) max = cards[i];
	}
	return max == -1 ? -1 : max;
}
int* two_pair(int *cards){
	int *results = new int[2];
	results[0] = -1;
	results[1] = -1;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(i != j && cards[i] == cards[j] && i != results[0]){
				if(results[0] == -1) results[0] = i;
				if(results[1] == -1) {
					results[1] = i;
					if(results[1] > results[0]) std::swap(results[1], results[0]);
					return results;
				}	
			}
		}
	}
}
int three_kind(int *cards){
	for(int i = 0; i <= 5; i++){
		bool onefound = false;
		for(int j = 0; j <= 5; j++){
			if(i != j && cards[i] == cards[j]){ 
				if( onefound )	return cards[i];	
				onefound = true;
			}
		}
	}
	return -1;
}
int straight(int *cards){
	std::sort( cards, cards + 5 );
	if(cards[0] + 5 == cards[4])	return cards[4];
	return -1;
}
int flush(char *suits, int *cards){
	std::sort(suits, suits + 5);
	if(suits[0] != suits[4]) return -1;
	std::sort(cards, cards + 5);
	return cards[4];
}
int* full_house(int *cards){
	int *results = new int[2];
	results[0] = -1;
	results[1] = -1;
	int pair =  one_pair(cards), three = three_kind(cards);
	results[0] = three;
	results[1] = pair;
	return results; 
}
int poker(int *cards){
	std::sort(cards, cards + 5);
	if(cards[0] == cards[3])	return cards[0];
	return -1;
}
int straight_flush(int *cards, char *suits){
	int flush_score = flush(suits, cards);
	if( straight(cards) != -1 && flush_score != -1)	return flush_score;
	return -1;	
}
bool royal_flush(int *cards, char *suits){
	return straight_flush( cards, suits) == 14;
}
int* score(int *cards, char *suits){
	for(int i = 0; i < 5; i++)	std::cout<<cards[i]<<"   "<<suits[i]<<"  ";
	int *score = new int[3];
	if(royal_flush(cards,suits)){
		score[0] = 10;
		return score;
	}
	int straight_flush_score = straight_flush(cards,suits);
	if(straight_flush_score != -1){
		score[0] = 9;
		score[1] = straight_flush_score;
		return score;
	}
	int poker_score = poker(cards);	
	if(poker_score != -1){
		score[0] = 8;
		score[1] = poker_score;
		return score;
	}
	int *full_house_score = full_house(cards);
	if(full_house_score[0] != -1){
		score[0] = 7;
		score[1] = full_house_score[0];
		score[2] = full_house_score[1];
		delete [] full_house_score;
		return score;
	}
	int flush_score = flush(suits, cards);
	if(flush_score != -1){
		score[0] = 6;
		score[1] = flush_score;
		return score;
	}
	int straight_score = straight(cards);
	if(straight_score != -1){
		score[0] = 5;
		score[1] = straight_score;
		return score;
	}
	int three_kind_scores = three_kind(cards);
	if(three_kind_scores != -1){
		score[0] = 4;
		score[1] = three_kind_scores;
		return score;
	}
	int *two_pair_scores = two_pair(cards);
	if(two_pair_scores[0] != -1){
		score[0] = 3;
		score[1] = two_pair_scores[0];
		score[2] = two_pair_scores[1];
		delete [] two_pair_scores;
		return score;
	}
	int one_pair_score = one_pair(cards);
	if(one_pair_score != -1){
		score[0] = 2;
		score[1] = one_pair_score;
		return score;
	}
	score[0] = 1;
	score[1] = high_card(cards);
	std::cout<<"HERE"<<std::endl;
	
	return score;
}
int main(){
	std::ifstream file ("poker.txt");
	std::string hands;
	int wins = 0;
	while(getline(file, hands)){
		std::stringstream handstream(hands);
		int *first_cards = new int[5];
		int *second_cards = new int[5];
		char *first_suits = new char[5];
		char *second_suits = new char[5];
		int *first_score = new int[3];
		int *second_score = new int[3];
		for(int i = 0; i < 5; i++){
			std::string temp;
			handstream >> temp;
			if(temp[0] == 'T') first_cards[i] = 10;
			else if(temp[0] == 'J')	first_cards[i] = 11;
			else if(temp[0] == 'Q')	first_cards[i] = 12;
			else if(temp[0] == 'K') first_cards[i] = 13;
			else if(temp[0] == 'A')	first_cards[i] = 14;
			else	first_cards[i] = int(temp[0] - '0');
			first_suits[i] = temp[1];
		}
		for(int i = 0; i < 5; i++){
			std::string temp;
			handstream >> temp;
			if(temp[0] == 'T') second_cards[i] = 10;
			else if(temp[0] == 'J')	second_cards[i] = 11;
			else if(temp[0] == 'Q')	second_cards[i] = 12;
			else if(temp[0] == 'K') second_cards[i] = 13;
			else if(temp[0] == 'A')	second_cards[i] = 14;
			else	second_cards[i] = int(temp[0] - '0');
			second_suits[i] = temp[1];
		}
		for(int i = 0; i < 5; i++)	std::cout<<first_cards[i]<<"   "<<first_suits[i]<<"  ";
		first_score = score(first_cards, first_suits);
		second_score = score(second_cards, second_suits);
		int i = 0;
		while(first_score[i] == second_score[i]) i++;
		if(first_score[i] > second_score[i])	wins++;
	}
	std::cout<< wins <<std::endl;
	return 0;
}