#ifndef CHINESEREMAINDERTHEOREMSOLVER_H
#define CHINESEREMAINDERTHEOREMSOLVER_H

#include <vector>
#include <limits>
#include <array>
#include <numeric>

unsigned int gcd(unsigned int m, unsigned int n);

class ChineseRemainderTheoremSolver
{
public:
	ChineseRemainderTheoremSolver();
	void setBasis(const std::vector<unsigned int> &basis)
	{
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

	int calculate(const std::vector<unsigned int> &sample) const
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
			for(int i = 0; i < s.size(); ++i)
			{
				if(s[i] == 0)
				{
					zeroCounter++;
				}
			}
			if(zeroCounter == s.size())
			{
				break;
			}

			unsigned int min = std::numeric_limits<unsigned int>::max();
			for(int i = 0; i < s.size(); ++i)
			{
				if(s[i] == 0)
				{
					s[i] = _basis[i];
				}
				if(s[i] < min)
				{
					min = s[i];
				}
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

	unsigned long limit()
	{
		return _limit;
	}

private:
	std::vector<unsigned int> _basis;
	unsigned long _limit;

};

#endif // CHINESEREMAINDERTHEOREMSOLVER_H
