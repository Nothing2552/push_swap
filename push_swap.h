/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaydilek <yaydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:38:41 by yaydilek          #+#    #+#             */
/*   Updated: 2026/08/24 16:40:41 by yaydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int value;
	int index;
	struct s_node *next;
} t_node;

typedef enum e_strategy
{
	STRATEGY_ADAPTIVE,
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX
} t_strategy;

typedef struct s_options
{
	t_strategy strategy;
	int bench;
} t_options;
typedef enum e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
} t_operation;
typedef struct s_benchmark
{
	long counts[OP_COUNT];
	long total;
	double disorder;
	t_strategy strategy;
} t_benchmark;

void sa(t_node **a);
void sb(t_node **b);
void ss(t_node **a, t_node **b);

void pa(t_node **a, t_node **b);
void pb(t_node **a, t_node **b);

void ra(t_node **a);
void rb(t_node **b);
void rr(t_node **a, t_node **b);

void rra(t_node **a);
void rrb(t_node **b);
void rrr(t_node **a, t_node **b);

int is_valid_input(int argc, char **argv);
void free_stack(t_node **stack);
void error_exit(t_node **a, t_node **b);

double compute_disorder(t_node *a);
int sort_simple(t_node **a, t_node **b);
void sort_medium(t_node **a, t_node **b);
void sort_complex(t_node **a, t_node **b);
void sort_adaptive(t_node **a, t_node **b);

int is_empty(t_node **a);
t_node *pop(t_node **a);
void push(t_node **a, t_node *node_to_push);
t_node *find_last_node(t_node **a);
int get_stack_size(t_node *a);
int assign_indexes(t_node *stack);
int radix_sort(t_node **stack_a, t_node **stack_b);

int parse_int(const char *str, int *result);
t_node *new_node(int value);
void add_node_back(t_node **stack, t_node *new);
int has_duplicate(t_node *stack, int value);
void init_stack(t_node **a, int argc, char **argv, int start);
int parse_options(int argc, char **argv, t_options *options);
void benchmark_init(t_benchmark *bench);
void benchmark_count(t_benchmark *bench, t_operation operation);
void benchmark_print(t_benchmark *bench);
void benchmark_print_disorder(double disorder);
void bench_putstr(char *str);
void bench_putnbr(long number);
void bench_put_metric(char *name, long value);

#endif
