#include "pch.h"
#include "Number.h"


Number::Number()
{
}


Number::~Number()
{
}

int Number::getX()
{
	return m_x;
}

int Number::getY()
{
	return m_y;
}

int Number::getValue()
{
	return m_value;
}

int Number::getID()
{
	return m_ID;
}

int Number::get_Quadrant()
{
	return m_quadrant;
}

bool Number::get_changeble()
{
	return m_ischangable;
}

bool Number::get_checked_for_candidades()
{
	return m_hascheckedforcandidades;
}

std::vector<int> Number::get_Candidate_Numbers_vec()
{
	return m_candidate_Numbers_vec;
}

std::vector<int> Number::get_used_numbers_vec()
{
	return m_used_Numbers_vec;
}

void Number::set_x(int x_position)
{
	m_x = x_position;
}

void Number::set_y(int y_position)
{
	m_y = y_position;
}

void Number::set_value(int value)
{
	m_value = value;
}

void Number::set_quadrant(int x, int y)
{
	int x_quadrant = x / 3;
	int y_quadrant = y / 3;

	if (x_quadrant == 0 && y_quadrant == 0) m_quadrant = 0;
	if (x_quadrant == 1 && y_quadrant == 0) m_quadrant = 1;
	if (x_quadrant == 2 && y_quadrant == 0) m_quadrant = 2;
	if (x_quadrant == 0 && y_quadrant == 1) m_quadrant = 3;
	if (x_quadrant == 1 && y_quadrant == 1) m_quadrant = 4;
	if (x_quadrant == 2 && y_quadrant == 1) m_quadrant = 5;
	if (x_quadrant == 0 && y_quadrant == 2) m_quadrant = 6;
	if (x_quadrant == 1 && y_quadrant == 2) m_quadrant = 7;
	if (x_quadrant == 2 && y_quadrant == 2) m_quadrant = 8;

}

void Number::set_ID(int a_ID)
{
	m_ID = a_ID;
}

void Number::set_changeable(bool is_changeble)
{
	m_ischangable = is_changeble;
}

void Number::set_to_checked(bool checked)
{
	m_hascheckedforcandidades = checked;
}

void Number::clear_used_number_vec()
{
	m_used_Numbers_vec.clear();
}

void Number::add_Candidate_Number(int possible_candidate)
{
	m_candidate_Numbers_vec.push_back(possible_candidate);
}

void Number::move_to_used_vec(int pos)
{
	m_used_Numbers_vec.push_back(m_candidate_Numbers_vec.at(pos));
}

