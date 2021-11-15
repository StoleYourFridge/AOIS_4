#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

pair<bool, bool> summary_machine(vector<bool>& constituent);
vector<pair<int, bool>> from_constituent_to_pair(vector<bool>& constituent);
vector<vector<pair<int, bool>>> from_set_of_constituents_to_implicants(vector<vector<bool>>& sdnfprotatype);
pair<vector<vector<bool>>, vector<vector<bool>>> ODC_3_SDNF(vector<bool>& result_answers, vector<bool>& shift_answers);

void SDNF_vector_bool_output(vector<vector<bool>>& sdnfprototype);
void SKNF_vector_bool_output(vector<vector<bool>>& sknfprototype);
string SDNF_vector_pair_output(vector<vector<pair<int, bool>>>& sdnfprotatype);
string SKNF_vector_pair_output(vector<vector<pair<int, bool>>>& sknfprotatype);
void truthtable(vector<bool>& answerstofunction_one, vector<bool>& answerstofunction_two);
void function_components_output_sdnf(vector<vector<pair<int, bool>>>& sdnf_result, vector<vector<pair<int, bool>>>& sdnf_shift);

bool checker_for_coincidence(vector<pair<int, bool>>& term_one, vector<pair<int, bool>>& term_two, int size);
vector<pair<int, bool>> implicant(vector<pair<int, bool>>& term_one, vector<pair<int, bool>>& term_two);
void gluing(vector<vector<pair<int, bool>>>& current_sdnf, int size);

bool checker_for_implicant_and_constituent(vector<bool>& constituent, vector<pair<int, bool>>& implicant);
pair<vector<vector<bool>>, vector<int>> table_of_crosses(vector<vector<bool>>& sdnfprototype, vector<vector<pair<int, bool>>>& implicants);
void one_line_deleting(vector<vector<bool>>& table, int line, int& current_amount_of_cleaning_crosses);
bool table_checker(vector<vector<bool>> table);
void creator_for_set_of_exceptions(map<int, bool>visited, vector<vector<bool>> table, int number_of_cleaning_line, vector<int>& main_line_for_result, vector<int>current_line_for_result, int& main_amount_of_crosses, int current_amount_of_crosses);
vector<int> set_of_exceptions(vector<vector<bool>> table, int number_of_start_implicant, map<int, bool> visited);
vector<int> result_exeption(vector<vector<bool>> table, vector<int> numbers_of_correct_implicants);
void exceptioned_implicants(vector<vector<pair<int, bool>>>& implicants, vector<int> exception);
vector<vector<pair<int, bool>>> minimization(vector<vector<bool>>& sdnfprotatype);

void first_task();
void second_task();
bool Test1();
bool Test2();
bool Test3();
bool Test4();
bool Test5();
bool Test6();
bool Test7();
bool Test8();
bool Test9();
bool Test10();
bool Test11();
bool Test12();
void tests();
void Lab_tasks();