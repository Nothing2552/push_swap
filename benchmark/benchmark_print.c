#include "push_swap.h"

static void print_simple_strategy(void)
{
	bench_putstr("Strategy: simple\n");
	bench_putstr("Complexity: O(n^2)\n");
}

static void print_strategy(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		print_simple_strategy();
	else if (strategy == STRATEGY_MEDIUM)
	{
		bench_putstr("Strategy: medium\n");
		bench_putstr("Complexity: O(n*sqrt(n))\n");
	}
	else if (strategy == STRATEGY_COMPLEX)
	{
		bench_putstr("Strategy: complex\n");
		bench_putstr("Complexity: O(n log n)\n");
	}
	else
		bench_putstr("Strategy: adaptive\n");
}

static void print_operation_counts(t_benchmark *bench)
{
	bench_put_metric("sa: ", bench->counts[OP_SA]);
	bench_put_metric("sb: ", bench->counts[OP_SB]);
	bench_put_metric("ss: ", bench->counts[OP_SS]);
	bench_put_metric("pa: ", bench->counts[OP_PA]);
	bench_put_metric("pb: ", bench->counts[OP_PB]);
	bench_put_metric("ra: ", bench->counts[OP_RA]);
	bench_put_metric("rb: ", bench->counts[OP_RB]);
	bench_put_metric("rr: ", bench->counts[OP_RR]);
	bench_put_metric("rra: ", bench->counts[OP_RRA]);
	bench_put_metric("rrb: ", bench->counts[OP_RRB]);
	bench_put_metric("rrr: ", bench->counts[OP_RRR]);
}

void benchmark_print(t_benchmark *bench)
{
	if (!bench)
		return;
	benchmark_print_disorder(bench->disorder);
	print_strategy(bench->strategy);
	bench_put_metric("Total operations: ", bench->total);
	print_operation_counts(bench);
}