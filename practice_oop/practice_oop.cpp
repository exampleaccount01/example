// practice_oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <bitset> // std::bitset
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;
struct classifiedAssessmentGrade
{
	int grade;
	int maxGrade;
};

struct weightedAssessmentGrade
{
	double grade;
	double weighting;
};

class Grade
{
private:
protected:
public:

double calculateUnitScore(std::vector<struct classifiedAssessmentGrade>& data);
};

double Grade::calculateUnitScore(std::vector<struct classifiedAssessmentGrade>& data) {

	if (data.empty())
	{
		throw std::invalid_argument("invalid-argument");
	}

	else
	{
		//  { {6,12}, {12,24}, {24,24} }  {grade, maxgrade}
		double vgrade;
		int vmaxgrade;
		for (int i = 0; i < data.size(); i++)
		{
			// cout << "\nUPC: " << data[i].grade;
			// cout << data[i].maxGrade;

			if (i == 0)
			{
				vgrade = data[i].grade;
				vmaxgrade = data[i].maxGrade;
			}
			else
			{
				if ((data[i].grade < data[i].maxGrade) && (vgrade >= data[i].grade))
					//(12 < 24) and (6 >= 12)
				{
					vgrade = data[i].grade;
					vmaxgrade = data[i].maxGrade;
				}
				else
				{
					if ((data[i].grade == data[i].maxGrade) && (vgrade == vmaxgrade))
						//(24 = 24) and (6 = 12)
					{
						vgrade = data[i].grade;
						vmaxgrade = data[i].maxGrade;
					}
				}
			}
			// cout << "\nUPC: " << data[i].weighting;
			//  cout << "\nUPC: " << data[i].grade;
			//  sum += data[i].grade * data[i].maxgrade;
		};
		// cout << " -" << sum;
		return vgrade;
	}
}

int main()
{
	Grade grader;

	//unit score 1st 
	std::vector<std::vector<classifiedAssessmentGrade>> btecUnitAssessmentResults
	{
	{ {6,12}, {12,24}, {24,24} },
	{ {6,12}, {12,24}, {24,24} },
	{ {12,12}, {12,24}, {24,24} },
	{ {6,12}, {12,24}, {24,24} },
	{ {12,12}, {24,24}, {24,24} }, //if max is obtained eg 12, 12 in first set so no restriction and we can move to second set 24,24 again its max grade so we move to next set with max 24,24 again so it will final grade
	{ {6,12}, {12,24}, {12,24} }
	};

	std::vector<double> correctModuleMarks{ 6, 6, 12, 6, 24, 6 };

	double unitScore = 0;
	std::string progressMessage;

	// Grade validity checks
	for (std::size_t i = 0; i < correctModuleMarks.size(); i++) {
		//first time unitscore = 6 , i first value is 6
		unitScore = grader.calculateUnitScore(btecUnitAssessmentResults[i]);

		cout << correctModuleMarks[i] << "is equal " << unitScore << endl;
	}

	return 0;
    //std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
