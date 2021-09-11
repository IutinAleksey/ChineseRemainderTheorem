#ifndef CHINESEREMAINDERTHEOREMSOLVER_H
#define CHINESEREMAINDERTHEOREMSOLVER_H

#include <vector>
#include <limits>
#include <array>
#include <numeric>

class ChineseRemainderTheoremSolver
{
public:
	ChineseRemainderTheoremSolver();
	void setBasis(const std::vector<unsigned int> &basis);

	int calculate(const std::vector<unsigned int> &sample) const;

	unsigned long limit()
	{
		return _limit;
	}

private:
	std::vector<unsigned int> _basis;
	unsigned long _limit;

};

#endif // CHINESEREMAINDERTHEOREMSOLVER_H
