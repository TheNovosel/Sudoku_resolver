#pragma once
#include<vector>
class Number
{
private:
	int m_ID;
	int m_value = 0;
	int m_x;
	int m_y;
	int m_quadrant;
	
	std::vector<int> m_candidate_Numbers_vec;
	std::vector<int> m_used_Numbers_vec;

	Number *Child = NULL;

	bool m_ischangable = true;
	bool m_hascheckedforcandidades = false;
	//bool m_isonlycandidate = false;
	//bool m_found_number = false;
	bool m_has_child= false;

public:
	Number();
	~Number();

	int getX();
	int getY();

	int getValue();
	int getID();
	int get_Quadrant();

	bool get_changeble();
	bool get_checked_for_candidades();

	std::vector<int> get_Candidate_Numbers_vec();
	std::vector<int> get_used_numbers_vec();

	void set_x(int x_position);
	void set_y(int y_position);
	void set_value(int value);
	void set_quadrant(int x, int y);
	void set_ID(int a_ID);
	
	void set_changeable(bool is_changeble);
	void set_to_checked(bool checked);

	void clear_used_number_vec();
	void add_Candidate_Number(int possible_candidate);
	void move_to_used_vec(int pos);
};

