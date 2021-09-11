#include "chineseremaindertheoremsolver.h"

unsigned int gcd(unsigned int m, unsigned int n)
{
	unsigned int res = 1;
	for(;;)
	{
		if(m == 0 || n == 0 || m == n)
		{
			return res * std::min(m, n);
		}
		if(m == 1 || n == 1)
		{
			return res;
		}
		if((m & 1) == 0)
		{
			if((n & 1) == 0)
			{
				res *= 2;
				m >>= 1;
				n >>= 1;
			}
			else
			{
				m >>= 1;
			}
		}
		else
		{
			if((n & 1) == 0)
			{
				n >>= 1;
			}
			else
			{
				if(n > m)
				{
					n = (n - m) >> 1;
				}
				if(m > n)
				{
					m = (m - n) >> 1;
				}
			}
		}
	}
	return res;
}

ChineseRemainderTheoremSolver::ChineseRemainderTheoremSolver()
{

}
