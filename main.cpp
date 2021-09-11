#include <iostream>
#include "Solver/chineseremaindertheoremsolver.h"

ChineseRemainderTheoremSolver tmp;

int main()
{
	tmp.setBasis({5, 4, 3});
	for(unsigned int i = 0; i < tmp.limit(); ++i)
	{
		std::vector<unsigned int> sample = {i % 5, i % 4, i % 3};
		std::cout << "{ ";
		for(const auto &item: sample)
		{
			std::cout << item << " ";
		}
		std::cout << "} ";
		std::cout << tmp.calculate(sample) << std::endl;
	}
	tmp.setBasis({3, 6});
	for(unsigned int i = 0; i < tmp.limit(); ++i)
	{
		std::vector<unsigned int> sample = {i % 3, i % 6};
		std::cout << "{ ";
		for(const auto &item: sample)
		{
			std::cout << item << " ";
		}
		std::cout << "} ";
		std::cout << tmp.calculate(sample) << std::endl;
	}
	tmp.setBasis({5, 4, 3, 7});
	for(unsigned int i = 0; i < tmp.limit(); ++i)
	{
		std::vector<unsigned int> sample = {i % 5, i % 4, i % 3, i % 7};
		std::cout << "{ ";
		for(const auto &item: sample)
		{
			std::cout << item << " ";
		}
		std::cout << "} ";
		std::cout << tmp.calculate(sample) << std::endl;
	}

	return 0;
}
