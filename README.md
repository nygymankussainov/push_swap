# push_swap

	The Push_swap project is a very simple and highly effective algorithm project: a stack
	of int values have to be sorted using one extra empty stack and particular set of instructions.

# Goal of the project

	The goal of this project is to write two programs, one called push_swap, which sorts
	a stack of int values and returns a set of instructions that it used to sort it, and checker, which
	checks if a return value of push_swap is correct.

# Instructions

	sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
	sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
	ss : sa and sb at the same time.
	pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
	pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
	ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
	rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
	rr : ra and rb at the same time.
	rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
	rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
	rrr : rra and rrb at the same time.