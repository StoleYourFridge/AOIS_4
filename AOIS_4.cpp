#include <iostream>
#include <vector>
#include <map>

using namespace std;

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
pair<vector<vector<pair<int, bool>>>, vector<vector<pair<int, bool>>>> ODC_3_SDNF()
{
	vector<vector<bool>> data{ {0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1} };
	vector<vector<pair<int, bool>>> result_of_function_sdnf, result_shift_sdnf;
	for (int i = 0; i < data.size(); i++)
	{
		pair<bool, bool> example = summary_machine(data[i]);
		if (example.first == 1) result_of_function_sdnf.push_back(from_constituent_to_pair(data[i]));
		if (example.second == 1) result_shift_sdnf.push_back(from_constituent_to_pair(data[i]));
	}
	pair<vector<vector<pair<int, bool>>>, vector<vector<pair<int, bool>>>> output(result_of_function_sdnf, result_shift_sdnf);
	return output;
}

void SDNF_output (vector<vector<pair<int, bool>>>&sdnfprotatype)
{
	cout << "F(sdnf)(a,b,c) = ";
	for (int i = 0; i < sdnfprotatype.size(); i++)
	{
		cout << "(";
		for (int j = 0; j < sdnfprotatype[i].size(); j++)
		{
			if (sdnfprotatype[i][j].first = 0) {
				if (sdnfprotatype[i][j].second = 0) cout << "!a";
				else cout << "a";
			}
			else if (sdnfprotatype[i][j].first = 1)
			{
				if (sdnfprotatype[i][j].second = 0) cout << "!b";
				else cout << "b";
			}
			else if (sdnfprotatype[i][j].first = 2)
			{
				if (sdnfprotatype[i][j].second = 0) cout << "!c";
				else cout << "c";
			}
			else if (sdnfprotatype[i][j].first = 3)
			{
				if (sdnfprotatype[i][j].second = 0) cout << "!d";
				else cout << "d";
			}
			if (j != sdnfprotatype[i].size() - 1) cout << "*";
		}
		cout << ")";
		if (i != sdnfprotatype.size() - 1) cout << "+";
	}
}
string from_implicants_to_sdnf_string(vector<vector<pair<int, bool>>>& sdnf_implicants)
{
	string output;
	for (int i = 0; i < sdnf_implicants.size(); i++)
	{
		output += "(";
		for (int j = 0; j < sdnf_implicants[i].size(); j++)
		{
			if (sdnf_implicants[i][j].first == 0) {
				if (sdnf_implicants[i][j].second) output += "a";
				else output += "!a";
			}
			else if (sdnf_implicants[i][j].first == 1) {
				if (sdnf_implicants[i][j].second) output += "b";
				else output += "!b";
			}
			else if (sdnf_implicants[i][j].first == 2) {
				if (sdnf_implicants[i][j].second) output += "c";
				else output += "!c";
			}
			if (j != sdnf_implicants[i].size() - 1) output += "*";
		}
		output += ")";
		if (i != sdnf_implicants.size() - 1) output += "+";
	}
	return output;
}
string from_implicants_to_sknf_string(vector<vector<pair<int, bool>>>& sknf_implicants)
{
	string output;
	for (int i = 0; i < sknf_implicants.size(); i++)
	{
		output += "(";
		for (int j = 0; j < sknf_implicants[i].size(); j++)
		{
			if (sknf_implicants[i][j].first == 0) {
				if (sknf_implicants[i][j].second) output += "!a";
				else output += "a";
			}
			else if (sknf_implicants[i][j].first == 1) {
				if (sknf_implicants[i][j].second) output += "!b";
				else output += "b";
			}
			else if (sknf_implicants[i][j].first == 2) {
				if (sknf_implicants[i][j].second) output += "!c";
				else output += "c";
			}
			if (j != sknf_implicants[i].size() - 1) output += "+";
		}
		output += ")";
		if (i != sknf_implicants.size() - 1) output += "*";
	}
	return output;
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
			if (term_one[i].first = term_two[j].first){
				overlap = true;
				if (term_one[i].second == term_two[i].second) counter_of_coincidence++;
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



int main()
{
    return 0;
}
