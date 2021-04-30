#include "pch.h"
#include "Playboard.h"


Playboard::Playboard()
{


}


Playboard::~Playboard()
{
}

void Playboard::setupBoard()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			Number *newNumber = new Number;
			
			newNumber->set_x(j); 
			newNumber->set_y(i);
			newNumber->set_ID(number_ID); // eig nicht wichtig
			number_ID++;
			newNumber->set_quadrant(j, i);
			myPlayboard[i][j] = newNumber;
		}
	}
}

void Playboard::setNumber(int x_coordinate, int y_coordinate, int value, bool changable)
{
	myPlayboard[y_coordinate][x_coordinate]->set_value(value);
	myPlayboard[y_coordinate][x_coordinate]->set_changeable(changable);
}

void Playboard::findCandidates(int row, int col)
{
	int possible_candidate = 1;

	for (int guessedNumberCounter = 0; guessedNumberCounter < 9; guessedNumberCounter++)
	{
		bool b_horizontal_check = true;
		bool b_vertical_check = true;
		bool b_quadrant_check = true;


		for (int horizontal_check = 0; horizontal_check < 9; horizontal_check++)
		{
			if (myPlayboard[row][horizontal_check]->getValue() == possible_candidate && myPlayboard[row][horizontal_check]->get_changeble() == false)
			{
				b_horizontal_check = false;
				break;
			}
		}

		for (int vertical_check = 0; vertical_check < 9; vertical_check++)
		{
			if (myPlayboard[vertical_check][col]->getValue() == possible_candidate && myPlayboard[vertical_check][col]->get_changeble() == false)
			{
				b_horizontal_check = false;
				break;
			}
		}

		for (int quadrant_y = 0; quadrant_y < 9; quadrant_y++)
		{
			for (int quadrant_x = 0; quadrant_x < 9; quadrant_x++)
			{
				if (myPlayboard[row][col]->get_Quadrant() == myPlayboard[quadrant_y][quadrant_x]->get_Quadrant() && myPlayboard[quadrant_y][quadrant_x]->getValue() == possible_candidate && myPlayboard[quadrant_y][quadrant_x]->get_changeble() == false)
				{
					b_quadrant_check = false;
					break;
				}
			}
		}

		if (b_horizontal_check == true && b_vertical_check == true && b_quadrant_check == true)
		{
			myPlayboard[row][col]->add_Candidate_Number(possible_candidate);
			possible_candidate++;
			myPlayboard[row][col]->set_to_checked(true);
		}
		else
		{
			possible_candidate++;
		}
	}
	if (myPlayboard[row][col]->get_Candidate_Numbers_vec().size() == 1) add_number_with_only_one_candidate(myPlayboard[row][col]);
}

void Playboard::add_number_with_only_one_candidate(Number * number_with_one_candidate)
{
	m_Number_with_one_candidate_vec.push_back(number_with_one_candidate);
}

void Playboard::print_numbers_with_only_one_candidate()
{
	for (int i = 0; i < m_Number_with_one_candidate_vec.size(); i++)
	{
		std::cout << m_Number_with_one_candidate_vec.at(i)->getValue() << " (" << m_Number_with_one_candidate_vec.at(i)->getX() << "," << m_Number_with_one_candidate_vec.at(i)->getY() << ")  ";
	}
}

void Playboard::guessNumber(int row, int col)
{
	m_Number_vec.push_back(myPlayboard[row][col]);
	bool b_found_number = false;

	for (int i = 0; i < myPlayboard[row][col]->get_Candidate_Numbers_vec().size(); i++)
	{
		int possible_number = myPlayboard[row][col]->get_Candidate_Numbers_vec().at(i);

		bool is_available = NULL;
		is_available = checkNumber(row, col, possible_number);

		if(is_available == true)
		{
			myPlayboard[row][col]->set_value(possible_number);
			b_found_number = true;
			//showBoard();

			for (int i = 0; i < myPlayboard[row][col]->get_Candidate_Numbers_vec().size(); i++)
			{
				if (myPlayboard[row][col]->get_Candidate_Numbers_vec().at(i) == possible_number)
				{
					myPlayboard[row][col]->move_to_used_vec(i);
				}
			}
			break;
		}
	}

	if (b_found_number == false)
	{
		m_b_is_backtrack = true;
		m_Number_vec.pop_back();
	}
}


std::pair<int, int> Playboard::backtrack()
{
	std::pair<int, int> new_coordinates = {10, 10};
	bool is_used = false;
	bool b_found_number = false;

	for (int i = 0; i < m_Number_vec.back()->get_Candidate_Numbers_vec().size(); i++)
	{
		for (int j = 0; j < m_Number_vec.back()->get_used_numbers_vec().size(); j++)
		{	
			int i_candidate = m_Number_vec.back()->get_Candidate_Numbers_vec().at(i);
			int i_used_number = m_Number_vec.back()->get_used_numbers_vec().at(j);
			
			if (i_candidate == i_used_number)
			{
				is_used = true;
			}

		}

		if (is_used == false)
		{
			int i_guess = m_Number_vec.back()->get_Candidate_Numbers_vec().at(i);
			int i_row = m_Number_vec.back()->getY();
			int i_col = m_Number_vec.back()->getX();

			bool is_available = NULL;
			is_available = checkNumber(i_row, i_col, i_guess);

			if (is_available == true)
			{
				m_b_is_backtrack = false;
				b_found_number = true;

				m_Number_vec.back()->set_value(i_guess);
				m_Number_vec.back()->move_to_used_vec(i);

				new_coordinates.first = m_Number_vec.back()->getX();
				new_coordinates.second = m_Number_vec.back()->getY();

				break;
			}
		}
		is_used = false;
	}
	if(b_found_number == false)
	{
		m_Number_vec.back()->clear_used_number_vec();
		m_Number_vec.back()->set_value(0);
		m_Number_vec.pop_back();
	}
	
	return new_coordinates;
}

bool Playboard::checkNumber(int i_x, int i_y, int i_guessedNumber)
{
	bool b_horizontal_check = true;
	bool b_vertical_check = true;
	bool b_quadrant_check = true;


	for (int horizontal_check = 0; horizontal_check < 9; horizontal_check++)
	{
		if (myPlayboard[i_x][horizontal_check]->getValue() == i_guessedNumber)
		{
			return false;
		}
	}

	for (int vertical_check = 0; vertical_check < 9; vertical_check++)
	{
		if (myPlayboard[vertical_check][i_y]->getValue() == i_guessedNumber)
		{
			return false;
		}
	}

	for (int quadrant_y = 0; quadrant_y < 9; quadrant_y++)
	{
		for (int quadrant_x = 0; quadrant_x < 9; quadrant_x++)
		{
			if (myPlayboard[i_x][i_y]->get_Quadrant() == myPlayboard[quadrant_y][quadrant_x]->get_Quadrant() && myPlayboard[quadrant_y][quadrant_x]->getValue() == i_guessedNumber)
			{
				return false;
			}
		}
	}

	if (b_horizontal_check == true && b_vertical_check == true && b_quadrant_check == true)
	{
		return true; 
	}
}

void Playboard::solveSudoku()
{
	for (int i_row = 0; i_row < 9; i_row++)
	{
		for (int i_col = 0; i_col < 9; i_col++)
		{
			if (myPlayboard[i_row][i_col]->get_changeble() == true)
			{
				if(myPlayboard[i_row][i_col]->get_checked_for_candidades() == false)
				{
					findCandidates(i_row, i_col);
				}

				guessNumber(i_row, i_col);
				
				while (m_b_is_backtrack == true)
				{
					std::pair<int, int> pair_new_coordinates = backtrack();
					if (pair_new_coordinates.first != 10) // geht iwie nicht wenn ich PAIR mit NULL teste .. drum kleiner workarround xD
					{
						i_col = pair_new_coordinates.first;
						i_row = pair_new_coordinates.second;
					}
				}
				
			}
		}
	}
}

void Playboard::showBoard()
{
	system("CLS");

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cout << myPlayboard[i][j]->getValue() <<  " ";
		}
		std::cout << std::endl;
	}
}
