
#include "push_swap.h"

void	benchmark_init(t_benchmark *bench)
{
	int	i;

	i = 0;
	while (i < OP_COUNT)
	{
		bench->counts[i] = 0;
		i++;
	}
	bench->total = 0;
	bench->disorder = 0.0;
	bench->strategy = STRATEGY_ADAPTIVE;
}

void	benchmark_count(t_benchmark *bench, t_operation operation)
{
	if (!bench)
		return ;
	bench->counts[operation]++;
	bench->total++;
}