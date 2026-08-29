*This project has been created as part of the 42 curriculum by aryaprak, yaydilek.*

# push_swap

## Description

`push_swap` is a C program that sorts a list of unique integers using two stacks
and a limited set of operations. Instead of printing the sorted numbers, it
writes the operations required to sort stack A in ascending order to `stdout`.

The goal is not only to sort correctly, but also to select an appropriate
algorithm for different input configurations, examine the generated operation
count, and evaluate complexity within the Push_swap operation model.

Initially, stack A contains the command-line numbers, with the first number at
the top, and stack B is empty. At the end, A must be sorted in ascending order
and B must be empty.

## Operations

| Operation | Description |
|---|---|
| `sa`, `sb` | Swap the first two elements of the corresponding stack. |
| `ss` | Perform `sa` and `sb` simultaneously. |
| `pa` | Move the top element of B to the top of A. |
| `pb` | Move the top element of A to the top of B. |
| `ra`, `rb` | Move the first element of the corresponding stack to the bottom. |
| `rr` | Perform `ra` and `rb` simultaneously. |
| `rra`, `rrb` | Move the last element of the corresponding stack to the top. |
| `rrr` | Perform `rra` and `rrb` simultaneously. |

Operations are written to `stdout`, one per line. Errors and benchmark
information are sent to `stderr`.

## Data structure and indexing

Stacks A and B are represented as singly linked lists. Each node stores its
original value, sorted index, and the address of the next node.

```text
Values:   40 -> -5 -> 12 -> 100
Indexes:   2 ->  0 ->  1 ->   3
```

During indexing, values are copied into a temporary array and sorted with bubble
sort. Each value's rank is then found with binary search and assigned to the
corresponding node. This does not change the linked-list order or generate any
Push_swap operations.

## Algorithms

The program provides four selectable strategies.

### Simple — selection sort adaptation, O(n²)

The simple strategy finds the minimum element in A. If it is in the upper half,
it is moved to the top with `ra`; otherwise, `rra` is used to take the shorter
path. It is then pushed to B with `pb`. After the small remaining part of A is
sorted separately, all elements are returned to A with `pa`.

The remaining stack is scanned for the minimum on every pass until only a few
elements remain. Its upper bound is therefore O(n²). It was selected as a clear
baseline algorithm.

### Medium — square-root chunk strategy, O(n√n) target

The medium strategy processes indexes through a moving window approximately
`√n` wide. Nodes in the active range are sent to B with `pb`, while smaller
indexes are moved closer to the bottom of B with `rb`. Elements outside the
range are rotated with `ra` until the next candidate is reached.

Once A is empty, the largest index in B is located. The shorter direction,
`rb` or `rrb`, is selected based on its position, and the node is returned to A
with `pa`. Returning the largest indexes first builds A in ascending order. The
target Push_swap operation complexity is O(n√n).

### Complex — binary LSD radix sort, O(n log n)

The complex strategy processes the bits of indexes in the `0..n-1` range,
starting with the least significant bit:

- If the current bit is `0`, the node is sent to B with `pb`.
- If the current bit is `1`, the node is kept in A through `ra`.
- After each bit pass, all nodes in B are returned to A with `pa`.

Each bit pass generates O(n) operations, and O(log n) bits are required, giving
an overall upper bound of O(n log n). Radix sort provides predictable performance
for highly disordered inputs.

### Adaptive strategy

Disorder is the ratio of inverted pairs to all possible pairs in the stack:

```text
disorder = inversion_count / total_pair_count
```

It ranges from `0` to `1`. A sorted stack has a disorder of `0`, while a fully
reverse-sorted stack has a disorder of `1`. It is calculated before any operation
is performed.

| Disorder | Selected method | Target complexity |
|---:|---|---:|
| `< 0.2` | Simple | O(n²) |
| `0.2 <= disorder < 0.5` | Medium | O(n√n) |
| `>= 0.5` | Complex | O(n log n) |

For low disorder, the simple method can benefit from the existing order. At a
medium level, the chunk approach targets fewer operations than quadratic minimum
extraction. For high disorder, radix sort provides a predictable upper bound
independent of the initial arrangement.

## Parsing and errors

The program rejects:

- Non-integer arguments
- Values outside the `INT_MIN..INT_MAX` range
- Duplicate values
- Unknown or repeated options
- Multiple strategy selectors
- Missing numbers after the options

On error, `Error\n` is written to `stderr`, and allocated stack memory is freed.
Numbers may be provided as separate arguments or as one quoted string.

## Instructions

### Compilation

```bash
make
```

The project is compiled with `cc -Wall -Wextra -Werror`, producing `push_swap`.

```bash
make clean    # Remove object files
make fclean   # Remove object files and the executable
make re       # Rebuild the project from scratch
```

### Usage

The adaptive strategy is used by default:

```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```

To force a specific strategy:

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

Benchmark mode:

```bash
./push_swap --bench --complex 4 67 3 87 23
```

The benchmark report displays the initial disorder percentage, the strategy and
its complexity, the total operation count, and each individual operation count
on `stderr`.

To display only the total operation count:

```bash
./push_swap --complex 4 67 3 87 23 | wc -l
```

### Verification with the checker

```bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG
```

The expected result is `OK`. If the checker is in another directory, use its
full path:

```bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG \
	| /home/aryaprak/Downloads/checker_linux $ARG
```

To save the benchmark report separately while piping operations to the checker:

```bash
ARG="4 67 3 87 23"
./push_swap --bench --complex $ARG 2>benchmark.txt \
	| ./checker_linux $ARG
```

### Performance testing

```bash
ARG="$(shuf -i 0-9999 -n 100)"
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l

ARG="$(shuf -i 0-9999 -n 500)"
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l
```

| Size | Minimum pass | Good | Excellent |
|---:|---:|---:|---:|
| 100 | `< 2000` | `< 1500` | `< 700` |
| 500 | `< 12000` | `< 8000` | `< 5500` |

Along with meeting the operation-count target, the checker result must be `OK`.

## Project structure

```text
.
├── algorithms/     # Simple, medium, complex, and disorder calculation
├── benchmark/      # Operation counters and stderr report
├── operations/     # All Push_swap operations
├── parsing/        # Option, integer, overflow, and duplicate validation
├── utils/          # Helpers for parsing, stacks, and sorting
├── main.c          # Parsing, strategy selection, and program lifecycle
├── push_swap.h     # Data types and function prototypes
└── Makefile
```

## Team contributions

- `aryaprak`: `algorithms/disorder.c`, `algorithms/medium.c`, all files in
  `benchmark/`, all files in `parsing/` except `parsing/new_argv.c`, and
  `utils/error.c`.
- `yaydilek`: `algorithms/simple.c`, `algorithms/complex.c`, all files in
  `operations/`, `parsing/new_argv.c`, and all files in `utils/` except
  `utils/error.c`.
- Jointly developed: `main.c`, `push_swap.h`, all other files not specifically
  assigned above, the Makefile, tests, and documentation.

Both team members reviewed all four strategies and the complete program flow and
are responsible for being able to explain the entire project.

## Resources

- The `en.subject_push_swap.pdf` supplied with the project
- [C language reference](https://en.cppreference.com/w/c)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)
- [Linked list](https://en.wikipedia.org/wiki/Linked_list)
- [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Binary search](https://en.wikipedia.org/wiki/Binary_search_algorithm)

### Use of AI

AI was used as an assistive tool to clarify subject requirements, review
command-line parsing and stack operations, suggest edge-case tests, discuss the
selection, chunk, and radix algorithms, explain the separation of benchmark
output between `stdout` and `stderr`, and help structure the README.

AI output was not treated as proof of correctness. Suggestions were read by the
team, compared against the code, and considered for validation with the compiler,
Norminette, randomized tests, and the provided checker. The team members remain
responsible for understanding and defending the submitted code.
