#pragma once
#include "Number.h"
#include <vector>
#include <utility>
#include <iostream>

class Playboard
{
private:
	Number *myPlayboard[9][9];
	std::vector<Number*> m_Number_vec;
	std::vector<Number*> m_Number_with_one_candidate_vec;

	bool m_b_is_backtrack = false;
	int number_ID = 0;

public:
	Playboard();
	~Playboard();

	std::pair<int, int> backtrack(); //Backtrackfunktion

	bool checkNumber(int _x, int _y, int guessedNumber); // horizontal, vertical + quadrant check funktion

	void setupBoard(); //initialisiert das spielfeld mit Nummern
	void setNumber(int x_coordinate, int y_coordinate, int value, bool changable); // Gibt Nummern werte
	void findCandidates(int row, int col); // Checkt mögliche Kandidaten abhänig von den nicht veränderbaren Nummern
	void add_number_with_only_one_candidate(Number *number_with_one_candidate);
	void print_numbers_with_only_one_candidate();
	void guessNumber(int row, int col); //Checkt Kandidaten im gesamten Kontext (veränderbare + unveränderbare Nummern)
	void solveSudoku(); //main methode
	void showBoard(); // print board
};

