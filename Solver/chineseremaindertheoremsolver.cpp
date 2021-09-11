#include "chineseremaindertheoremsolver.h"

ChineseRemainderTheoremSolver::ChineseRemainderTheoremSolver()
{

}

void ChineseRemainderTheoremSolver::setBasis(const std::vector<unsigned int> &basis)
{
	//TODO: check that basis[i] > 1
	_basis = basis;
	unsigned long limit = _basis[0];
	unsigned long gcd = _basis[0];

	for(int i = 1; i < _basis.size(); ++i)
	{
		limit *= _basis[i];
		gcd = std::gcd(gcd, _basis[i]);
	}
	_limit = limit / gcd;
}

int ChineseRemainderTheoremSolver::calculate(const std::vector<unsigned int> &sample) const
{
	if(sample.size() != _basis.size())
	{
		return -1;
	}

	for(int i = 0; i < _basis.size(); ++i)
	{
		if(_basis[i] < sample[i])
		{
			return -1;
		}
	}
	long res = 0;
	std::vector<unsigned int> s = sample;

	for(;;)
	{
		int zeroCounter = 0;
		unsigned int min = std::numeric_limits<unsigned int>::max();
		for(int i = 0; i < s.size(); ++i)
		{
			if(s[i] == 0)
			{
				zeroCounter++;
				s[i] = _basis[i];
			}
			if(s[i] < min)
			{
				min = s[i];
			}
		}
		if(zeroCounter == s.size())
		{
			break;
		}
		res += min;
		if(res > _limit)
		{
			return -1;
		}
		for(int i = 0; i < s.size(); ++i)
		{
			s[i] -= min;
		}
	}

	return res;
}
