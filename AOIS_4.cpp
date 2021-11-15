#include "AOIS_4.h"

pair<bool, bool> summary_machine(vector<bool>& constituent)
{
    pair<bool, bool> result;
	int true_counter = 0;
	for (int i = 0; i < constituent.size(); i++)
	{
		if (constituent[i]) true_counter++;
	}
	if (true_counter == 0) {
		result.first = 0;
		result.second = 0;
	}
	else if (true_counter == 1) {
		result.first = 1;
		result.second = 0;
	}
	else if (true_counter == 2) {
		result.first = 0;
		result.second = 1;
	}
	else if (true_counter == 3) {
		result.first = 1;
		result.second = 1;
	}
	return result;
}
vector<pair<int, bool>> from_constituent_to_pair(vector<bool>&constituent)
{
	vector<pair<int, bool>> result;
	for (int i = 0; i < constituent.size(); i++)
	{
		pair<int, bool> example(i, constituent[i]);
		result.push_back(example);
	}
	return result;
}
vector<vector<pair<int, bool>>> from_set_of_constituents_to_implicants(vector<vector<bool>>& sdnfprotatype)
{
	vector<vector<pair<int, bool>>> result;
	for (int i = 0; i < sdnfprotatype.size(); i++)
	{
		result.push_back(from_constituent_to_pair(sdnfprotatype[i]));
	}
	return result;
}
pair<vector<vector<bool>>, vector<vector<bool>>> ODC_3_SDNF(vector<bool>& result_answers, vector<bool>& shift_answers)
{
	vector<vector<bool>> data{ {0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1} };
	vector<vector<bool>> result_of_function_sdnf, result_shift_sdnf;
	for (int i = 0; i < data.size(); i++)
	{
		pair<bool, bool> example = summary_machine(data[i]);
		if (example.first == 1) {
			result_of_function_sdnf.push_back(data[i]);
			result_answers.push_back(1);
		}
		else result_answers.push_back(0);
		if (example.second == 1) {
			result_shift_sdnf.push_back(data[i]);
			shift_answers.push_back(1);
		}
		else shift_answers.push_back(0);
	}
	pair<vector<vector<bool>>, vector<vector<bool>>> output(result_of_function_sdnf, result_shift_sdnf);
	return output;
}

void SDNF_vector_bool_output(vector<vector<bool>>& sdnfprototype)
{
	if (sdnfprototype.size() == 0) return;
	for (int i = 0; i < sdnfprototype.size(); i++)
	{
		cout << "(";
		for (int j = 0; j < sdnfprototype[i].size(); j++)
		{
			if (j == 0) {
				if (sdnfprototype[i][j] == 1) cout << "a";
				else cout << "!a";
			}
			if (j == 1) {
				if (sdnfprototype[i][j] == 1) cout << "b";
				else cout << "!b";
			}
			if (j == 2) {
				if (sdnfprototype[i][j] == 1) cout << "c";
				else cout << "!c";
			}
			if (j == 3) {
				if (sdnfprototype[i][j] == 1) cout << "d";
				else cout << "!d";
			}
			if (j == 4) {
				if (sdnfprototype[i][j] == 1) cout << "e";
				else cout << "!e";
			}
			if (j != sdnfprototype[i].size() - 1) cout << "*"; 
		}
		cout << ")";
		if (i != sdnfprototype.size() - 1) cout << "+";
	}
	cout << endl;
}
void SKNF_vector_bool_output(vector<vector<bool>>& sknfprototype)
{
	if (sknfprototype.size() == 0) return;
	for (int i = 0; i < sknfprototype.size(); i++)
	{
		cout << "(";
		for (int j = 0; j < sknfprototype[i].size(); j++)
		{
			if (j == 0) {
				if (sknfprototype[i][j] == 1) cout << "!a";
				else cout << "a";
			}
			if (j == 1) {
				if (sknfprototype[i][j] == 1) cout << "!b";
				else cout << "b";
			}
			if (j == 2) {
				if (sknfprototype[i][j] == 1) cout << "!c";
				else cout << "c";
			}
			if (j == 3) {
				if (sknfprototype[i][j] == 1) cout << "!d";
				else cout << "d";
			}
			if (j == 4) {
				if (sknfprototype[i][j] == 1) cout << "!e";
				else cout << "e";
			}
			if (j != sknfprototype[i].size() - 1) cout << "+";
		}
		cout << ")";
		if (i != sknfprototype.size() - 1) cout << "*";
	}
	cout << endl;
}
string SDNF_vector_pair_output (vector<vector<pair<int, bool>>>&sdnfprotatype)
{
	string output;
	for (int i = 0; i < sdnfprotatype.size(); i++)
	{
		output += '(';
		for (int j = 0; j < sdnfprotatype[i].size(); j++)
		{
			if (sdnfprotatype[i][j].first == 0) {
				if (sdnfprotatype[i][j].second == 0) output += "!a";
				else output += 'a';
			}
			else if (sdnfprotatype[i][j].first == 1)
			{
				if (sdnfprotatype[i][j].second == 0) output += "!b";
				else output += 'b';
			}
			else if (sdnfprotatype[i][j].first == 2)
			{
				if (sdnfprotatype[i][j].second == 0) output += "!c";
				else output += 'c';
			}
			else if (sdnfprotatype[i][j].first == 3)
			{
				if (sdnfprotatype[i][j].second == 0) output += "!d";
				else output += 'd';
			}
			else if (sdnfprotatype[i][j].first == 4)
			{
				if (sdnfprotatype[i][j].second == 0) output += "!e";
				else output += 'e';
			}
			if (j != sdnfprotatype[i].size() - 1) output += '*';
		}
		output += ')';
		if (i != sdnfprotatype.size() - 1) output += '+';
	}
	return output;
}
string SKNF_vector_pair_output(vector<vector<pair<int, bool>>>& sknfprotatype)
{
	string output;
	for (int i = 0; i < sknfprotatype.size(); i++)
	{
		output += '(';
		for (int j = 0; j < sknfprotatype[i].size(); j++)
		{
			if (sknfprotatype[i][j].first == 0) {
				if (sknfprotatype[i][j].second == 0) output += 'a';
				else output += "!a";
			}
			else if (sknfprotatype[i][j].first == 1)
			{
				if (sknfprotatype[i][j].second == 0) output += 'b';
				else output += "!b";
			}
			else if (sknfprotatype[i][j].first == 2)
			{
				if (sknfprotatype[i][j].second == 0) output += 'c';
				else output += "!c";
			}
			else if (sknfprotatype[i][j].first == 3)
			{
				if (sknfprotatype[i][j].second == 0) output += 'd';
				else output += "!d";
			}
			else if (sknfprotatype[i][j].first == 4)
			{
				if (sknfprotatype[i][j].second == 0) output += 'e';
				else output += "!e";
			}
			if (j != sknfprotatype[i].size() - 1) output += '+';
		}
		output += ')';
		if (i != sknfprotatype.size() - 1) output += '*';
	}
	return output;
}
void truthtable(vector<bool>& answerstofunction_one, vector<bool>& answerstofunction_two)
{
	cout << "Truth table : " << endl << "------------------------------------------" << endl
		<< "a      : | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |" << endl
		<< "b      : | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 |" << endl
		<< "c      : | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 |" << endl
		<< "------------------------------------------" << endl << "result : |";
	for (int i = 0; i < answerstofunction_one.size(); i++)
	{
		cout << " " << answerstofunction_one[i] << " |";
	}
	cout << endl << "shift  : |";
	for (int i = 0; i < answerstofunction_two.size(); i++)
	{
		cout << " " << answerstofunction_two[i] << " |";
	}
	cout << endl << "------------------------------------------" << endl;
}
void function_components_output_sdnf(vector<vector<pair<int, bool>>>& sdnf_result, vector<vector<pair<int, bool>>>& sdnf_shift)
{
	const int max_size_of_implicant = 4, min_size_of_imlicant = 1, max_size_of_sdnf = 16;
	int transistors = 0;
	map<int, bool> deny_counter;
	map<int, int> and_counter;
	map<int, int> or_counter;
	or_counter[sdnf_result.size()]++;
	or_counter[sdnf_shift.size()]++;
 	for (int i = 0; i < sdnf_result.size(); i++)
	{
		and_counter[sdnf_result[i].size()]++;
		for (int j = 0; j < sdnf_result[i].size(); j++)
		{
			if (!sdnf_result[i][j].second) deny_counter[sdnf_result[i][j].first] = true;
		}
	}
	for (int i = 0; i < sdnf_shift.size(); i++)
	{
		and_counter[sdnf_shift[i].size()]++;
		for (int j = 0; j < sdnf_shift[i].size(); j++)
		{
			if (!sdnf_shift[i][j].second) deny_counter[sdnf_shift[i][j].first] = true;
		}
	}
	cout << "There are : " << endl << deny_counter.size() << " NO schemes" << endl;
	transistors += deny_counter.size();
	for (int i = min_size_of_imlicant; i < max_size_of_implicant; i++)
	{
		if (and_counter[i] != 0) {
			cout << and_counter[i] << " AND schemes with " << i << " inputs" << endl;
			transistors += (and_counter[i] * i);
		}
	}
	for (int i = 0; i < max_size_of_sdnf; i++)
	{
		if (or_counter[i] != 0) {
			cout << or_counter[i] << " OR  schemes with " << i << " inputs" << endl;
			transistors += (or_counter[i] * i);
		}
	}
	cout << "Total transistors : " << transistors << endl;
}

bool checker_for_coincidence(vector<pair<int, bool>>& term_one, vector<pair<int, bool>> & term_two, int size)
{
	if (!(term_one.size() == size && term_two.size() == size)) return false;
	int counter_of_coincidence = 0, neccesary_coincidence = term_one.size() - 1;
	for (int i = 0; i < term_one.size(); i++)
	{
		bool overlap = false;
		for (int j = 0; j < term_two.size(); j++)
		{
			if (term_one[i].first == term_two[j].first){
				overlap = true;
				if (term_one[i].second == term_two[i].second) counter_of_coincidence++;
				break;
			}
		}
		if (!overlap) return false;
	}
	if (counter_of_coincidence == neccesary_coincidence) return true;
	return false;
}
vector<pair<int, bool>> implicant(vector<pair<int, bool>>& term_one, vector<pair<int, bool>>& term_two)
{
	vector<pair<int, bool>> result;
	for (int i = 0; i < term_one.size(); i++)
	{
		for (int j = 0; j < term_two.size(); j++)
		{
			if (term_one[i].first == term_two[j].first && term_one[i].second == term_two[j].second)
			{
				pair<int, bool> example(term_one[i].first, term_one[i].second);
				result.push_back(example);
				break;
			}
		}
	}
	return result;
}
void gluing(vector<vector<pair<int, bool>>>& current_sdnf, int size)
{
	map<vector<pair<int, bool>>, bool> repeat;
	vector<vector<pair<int, bool>>> output;
	for (int i = 0; i < current_sdnf.size(); i++)
	{
		bool overlap = false;
		for (int j = 0; j < current_sdnf.size(); j++)
		{
			if (i == j) continue;
			if (checker_for_coincidence(current_sdnf[i], current_sdnf[j], size)) {
				overlap = true;
				vector<pair<int, bool>> implicant_ex = implicant(current_sdnf[i], current_sdnf[j]);
				if (!repeat[implicant_ex]) {
					repeat[implicant_ex] = true;
					output.push_back(implicant_ex);
				}
			}
		}
		if (!overlap) {
			output.push_back(current_sdnf[i]);
		}
	}
	current_sdnf = output;
}

bool checker_for_implicant_and_constituent(vector<bool>& constituent, vector<pair<int, bool>>& implicant)
{
	int counter = 0;
	for (int i = 0; i < implicant.size(); i++)
	{
		if (implicant[i].second == constituent[implicant[i].first]) counter++;
	}
	if (counter == implicant.size()) return true;
	else return false;
}
pair<vector<vector<bool>>, vector<int>> table_of_crosses(vector<vector<bool>>& sdnfprototype, vector<vector<pair<int, bool>>>& implicants)
{
	vector<vector<bool>> result;
	vector<int> future_result_of_operation;
	for (int i = 0; i < sdnfprototype.size(); i++)
	{
		vector<bool> line_for_constituent;
		int summary_for_the_line = 0, unique_implicant;
		for (int j = 0; j < implicants.size(); j++)
		{
			bool result_for_comparison = checker_for_implicant_and_constituent(sdnfprototype[i], implicants[j]);
			if (result_for_comparison) unique_implicant = j;
			line_for_constituent.push_back(result_for_comparison);
			summary_for_the_line += result_for_comparison;
		}
		if (summary_for_the_line == 1) future_result_of_operation.push_back(unique_implicant);
		else result.push_back(line_for_constituent);
	}
	pair<vector<vector<bool>>, vector<int>> future_result_and_table(result, future_result_of_operation);
	return future_result_and_table;
}
void one_line_deleting(vector<vector<bool>>& table, int line, int& current_amount_of_cleaning_crosses)
{
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i][line]) {
			current_amount_of_cleaning_crosses++;
			table[i][line] = 0;
		}
	}
}
bool table_checker(vector<vector<bool>> table)
{
	for (int i = 0; i < table.size(); i++)
	{
		bool zero_sign = false;
		for (int j = 0; j < table[i].size(); j++)
		{
			if (table[i][j]) {
				zero_sign = true;
				break;
			}
		}
		if (!zero_sign) {
			return false;
		}
	}
	return true;
}
void creator_for_set_of_exceptions(map<int, bool>visited, vector<vector<bool>> table, int number_of_cleaning_line, vector<int>& main_line_for_result, vector<int>current_line_for_result, int& main_amount_of_crosses, int current_amount_of_crosses)
{
	one_line_deleting(table, number_of_cleaning_line, current_amount_of_crosses);
	if (table_checker(table)) {
		visited[number_of_cleaning_line] = true;
		current_line_for_result.push_back(number_of_cleaning_line);
		if ((main_line_for_result.size() < current_line_for_result.size()) && (main_amount_of_crosses < current_amount_of_crosses)) {
			main_line_for_result = current_line_for_result;
			main_amount_of_crosses = current_amount_of_crosses;
		}
		for (int i = 0; i < table[0].size(); i++)
		{
			if (!visited[i]) creator_for_set_of_exceptions(visited, table, i, main_line_for_result, current_line_for_result, main_amount_of_crosses, current_amount_of_crosses);
		}
	}
	else return;
}
vector<int> set_of_exceptions(vector<vector<bool>> table, int number_of_start_implicant, map<int, bool> visited)
{
	vector<int>main_line, current_line;
	int current_amount_of_cleanning_crosses = 0, main_amount_of_cleanning_crosses = 0;
	creator_for_set_of_exceptions(visited, table, number_of_start_implicant, main_line, current_line, main_amount_of_cleanning_crosses, current_amount_of_cleanning_crosses);
	return main_line;
}
vector<int> result_exeption(vector<vector<bool>> table, vector<int> numbers_of_correct_implicants)
{
	vector<int> result;
	map<int, bool> visited;
	for (int i = 0; i < numbers_of_correct_implicants.size(); i++)
	{
		visited[numbers_of_correct_implicants[i]] = true;
	}
	if (table.size() != 0) {
		for (int i = 0; i < table[0].size(); i++)
		{
			if (!visited[i]) {
				vector<int> current_result = set_of_exceptions(table, i, visited);
				if (current_result.size() > result.size()) result = current_result;
			}
		}
	}
	return result;
}
void exceptioned_implicants(vector<vector<pair<int, bool>>>& implicants, vector<int> exception)
{
	vector<vector<pair<int, bool>>> result_implicants;
	for (int i = 0; i < implicants.size(); i++)
	{
		bool sign = true;
		for (int j = 0; j < exception.size(); j++)
		{
			if (i == exception[j]) sign = false;
		}
		if (sign) result_implicants.push_back(implicants[i]);
	}
	implicants = result_implicants;
}
vector<vector<pair<int, bool>>> minimization(vector<vector<bool>>& sdnfprotatype)
{
	vector<vector<pair<int, bool>>> result_implicants = from_set_of_constituents_to_implicants(sdnfprotatype);
	if (result_implicants.size() == 0) return result_implicants;
	int size = sdnfprotatype[0].size();
	while (size > 1)
	{
		gluing(result_implicants, size);
		size--;
	}
	pair<vector<vector<bool>>, vector<int>> table_and_one_cross_implicants_sdnf = table_of_crosses(sdnfprotatype, result_implicants);
	vector<int> exception_sdnf = result_exeption(table_and_one_cross_implicants_sdnf.first, table_and_one_cross_implicants_sdnf.second);
	exceptioned_implicants(result_implicants, exception_sdnf);
	return result_implicants;
}

void first_task()
{
	vector<bool> result_answers, shift_answers;
	pair<vector<vector<bool>>, vector<vector<bool>>> odc_3_output = ODC_3_SDNF(result_answers, shift_answers);
	truthtable(result_answers, shift_answers);
	vector<vector<bool>> result_sdnf = odc_3_output.first, shift_sdnf = odc_3_output.second;
	cout << "F(bi+1)(SDNF)(a,b,c)   = ";
	SDNF_vector_bool_output(result_sdnf);
	cout << "F(di)(SDNF)(a,b,c)     = ";
	SDNF_vector_bool_output(shift_sdnf);
	vector<vector<pair<int, bool>>> result_implicants = minimization(result_sdnf);
	vector<vector<pair<int, bool>>> shift_implicants = minimization(shift_sdnf);
	cout << "Minimized (bi+1)(SDNF) = " << SDNF_vector_pair_output(result_implicants) << endl;
	cout << "Minimized (di)(SDNF)   = " << SDNF_vector_pair_output(shift_implicants) << endl;
	function_components_output_sdnf(result_implicants, shift_implicants);
}
void second_task()
{
	vector<vector<bool>> function_one  { {0,1,0,1}, {0,1,1,0}, {1,0,0,0}, {0,1,1,1}, {1,0,0,1} };
	vector<vector<bool>> function_two  { {0,0,0,1}, {0,0,1,0}, {0,0,1,1}, {0,1,0,0}, {1,0,0,1} };
	vector<vector<bool>> function_three{ {0,0,0,0}, {0,0,1,1}, {0,1,0,0}, {0,1,1,1}, {1,0,0,0} };
	vector<vector<bool>> function_four { {0,0,0,0}, {0,0,1,0}, {0,1,0,0}, {0,1,1,0}, {1,0,0,0} };
	cout << "y1(SDNF) : ";
	SDNF_vector_bool_output(function_one);
	cout << "y2(SDNF) : ";
	SDNF_vector_bool_output(function_two);
	cout << "y3(SDNF) : ";
	SDNF_vector_bool_output(function_three);
	cout << "y4(SDNF) : ";
	SDNF_vector_bool_output(function_four);
	vector<vector<pair<int, bool>>> minimized = minimization(function_one);
	cout << "Minimized y1 : " << SDNF_vector_pair_output(minimized) << endl;
	minimized = minimization(function_two);
	cout << "Minimized y2 : " << SDNF_vector_pair_output(minimized) << endl;
	minimized = minimization(function_three);
	cout << "Minimized y3 : " << SDNF_vector_pair_output(minimized) << endl;
	minimized = minimization(function_four);
	cout << "Minimized y4 : " << SDNF_vector_pair_output(minimized) << endl;
}

bool Test1()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0}, {0,1,0}, {1,0,0}, {1,1,0} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!c)";
	if (our_result == real_result)
	{
		cout << "Test1 correct!" << endl;
		return true;
	}
	else cout << "Test1 incorrect!" << endl;
	return false;
}
bool Test2()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,1}, {0,1,1}, {1,0,1}, {1,1,1} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(c)";
	if (our_result == real_result)
	{
		cout << "Test2 correct!" << endl;
		return true;
	}
	else cout << "Test2 incorrect!" << endl;
	return false;
}
bool Test3()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0}, {1,0,1}, {0,1,1}, {1,1,0} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!a*!b*!c)+(a*!b*c)+(!a*b*c)+(a*b*!c)";
	if (our_result == real_result)
	{
		cout << "Test3 correct!" << endl;
		return true;
	}
	else cout << "Test3 incorrect!" << endl;
	return false;
}
bool Test4()
{
	vector<vector<bool>> sdnfprotatype{ {1,0,0}, {1,0,1}, {1,1,0}, {1,1,1} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(a)";
	if (our_result == real_result)
	{
		cout << "Test4 correct!" << endl;
		return true;
	}
	else cout << "Test4 incorrect!" << endl;
	return false;
}
bool Test5()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0}, {0,0,1}, {0,1,1}, {1,0,0}, {1,1,0}, {1,1,1} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!b*!c)+(!a*c)+(a*b)";
	if (our_result == real_result)
	{
		cout << "Test5 correct!" << endl;
		return true;
	}
	else cout << "Test5 incorrect!" << endl;
	return false;
}
bool Test6()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0}, {0,1,0}, {0,1,1}, {1,0,0}, {1,0,1}, {1,1,1} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!b*!c)+(!a*b)+(a*c)";
	if (our_result == real_result)
	{
		cout << "Test6 correct!" << endl;
		return true;
	}
	else cout << "Test6 incorrect!" << endl;
	return false;
}
bool Test7()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0,0}, {0,0,1,0}, {0,1,0,0}, {0,1,1,0}, {1,0,0,0}, {1,0,1,0}, {1,1,0,0}, {1,1,1,0} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!d)";
	if (our_result == real_result)
	{
		cout << "Test7 correct!" << endl;
		return true;
	}
	else cout << "Test7 incorrect!" << endl;
	return false;
}
bool Test8()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0,1}, {0,0,1,1}, {0,1,0,1}, {0,1,1,1}, {1,0,0,1}, {1,0,1,1}, {1,1,0,1}, {1,1,1,1} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(d)";
	if (our_result == real_result)
	{
		cout << "Test8 correct!" << endl;
		return true;
	}
	else cout << "Test8 incorrect!" << endl;
	return false;
}
bool Test9()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0,0}, {0,0,0,1}, {0,0,1,0}, {0,0,1,1}, {0,1,0,0}, {1,0,1,1}, {1,1,0,0}, {1,1,0,1}, {1,1,1,0}, {1,1,1,1} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!a*!b)+(b*!c*!d)+(a*c*d)+(a*b)";
	if (our_result == real_result)
	{
		cout << "Test9 correct!" << endl;
		return true;
	}
	else cout << "Test9 incorrect!" << endl;
	return false;
}
bool Test10()
{
	vector<vector<bool>> sdnfprotatype{ {0,1,0,0}, {0,1,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,0,0}, {1,0,0,1}, {1,0,1,0}, {1,0,1,1} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!a*b)+(a*!b)";
	if (our_result == real_result)
	{
		cout << "Test10 correct!" << endl;
		return true;
	}
	else cout << "Test10 incorrect!" << endl;
	return false;
}
bool Test11()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0,0}, {0,1,0,0}, {1,1,0,1}, {1,0,0,1}, {0,0,1,1}, {0,1,1,1}, {1,1,1,0}, {1,0,1,0} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!a*!c*!d)+(a*!c*d)+(!a*c*d)+(a*c*!d)";
	if (our_result == real_result)
	{
		cout << "Test11 correct!" << endl;
		return true;
	}
	else cout << "Test11 incorrect!" << endl;
	return false;
}
bool Test12()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0,0}, {1,0,0,0}, {0,1,0,1}, {1,1,0,1}, {0,1,1,1}, {1,1,1,1}, {0,0,1,0}, {1,0,1,0} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!b*!d)+(b*d)";
	if (our_result == real_result)
	{
		cout << "Test12 correct!" << endl;
		return true;
	}
	else cout << "Test12 incorrect!" << endl;
	return false;
}
void tests()
{
	int correct_counter = 0;
	correct_counter += Test1();
	correct_counter += Test2();
	correct_counter += Test3();
	correct_counter += Test4();
	correct_counter += Test5();
	correct_counter += Test6();
	correct_counter += Test7();
	correct_counter += Test8();
	correct_counter += Test9();
	correct_counter += Test10();
	correct_counter += Test11();
	correct_counter += Test12();
	if (correct_counter == 12) cout << "All tests passed correctly!" << endl;
}
void Lab_tasks()
{
	cout << "                      ::: First task ::: " << endl << endl;
	first_task();
	cout << endl << "                      ::: Second task ::: " << endl << endl;
	second_task();
}
