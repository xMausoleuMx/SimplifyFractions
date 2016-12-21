#include <iostream>
#include <vector>

using namespace std;

struct fraction { long parameters[2]; };
void simplify(std::vector<fraction>*);

int main()
{
	int numerator, denominator;
	char cont;
	std::vector<fraction> fractions;
	std::cout << "Enter the fractions you wish to simplify, enter a non-integer to quit";
	//gets however many fractions the user wants to simplify
	do
	{
		std::cout << "\nEnter the numerator for your fraction\n";
		std::cin >> numerator;
		std::cout << "\nEnter the denominator\n";
		std::cin >> denominator;
		fraction holder = { numerator, denominator};
		fractions.push_back(holder);
		std::cout << "\nEnter another fraction? \n y/n \n";
		std::cin >> cont;
	} while(cont == 'y');
	simplify(&fractions);
	//output all reduced fractions
	for (int x = 0; x < fractions.size(); x++)
	{
		std::cout << fractions[x].parameters[0] << "/" << fractions[x].parameters[1] << endl;
	}
	std::cout << "Goodbye";
}

void simplify(std::vector<fraction>* fraclist)
{
	for (int x = 0; x < (*fraclist).size(); x++)
	{
		for (long divisor = (*fraclist)[x].parameters[0] < (*fraclist)[x].parameters[1] ? (*fraclist)[x].parameters[0] : (*fraclist)[x].parameters[1]; divisor >= 1; divisor--)
		{
			if ((*fraclist)[x].parameters[0] % divisor == 0 && (*fraclist)[x].parameters[1] % divisor == 0)
			{
				(*fraclist)[x].parameters[1] /= divisor;
				(*fraclist)[x].parameters[0] /= divisor;
				break;
			}
		}
	}
}