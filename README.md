*This project has been created as part of the 42 curriculum by buehara.*

# 42_Push_Swap

42's Project Push Swap

## Description

### Overview

This is the 42's project of sorting numbers. We have two stacks available (stack A and stack B) to sort an N amount of numbers, within the range of an int in C, and some movements available to sort them between the two stacks in a way that the numbers end up sorted from smaller to biggest on the stack A.

Stack A that contains unique negative and/or positive integers.

Stack B is empty.


Available operations:

	- sa (swap a) = Swap the first 2 elements at top of stack A.
	
	- sb (swap b) = Swap the first 2 elements at top of stack B.
	
	- ss = Do sa and sb at the same time.
	
	- pa (push a) = Take the first element at the top of B and put it at the top of A.
	
	- pb (push b) = Take the first element at the top of A and put it at the top of B.
	
	- ra (rotate a) = Shift up all elements of stack A by 1.
	
	- rb (rotate b) = Shift up all elements of stack B by 1.
	
	- rr = ra and rb at the same time.
	
	- rra (reverse rotate a) = Shift down all elements of stack A by 1.
	
	- rrb (reverse rotate b) = Shift down all elements of stack B by 1.
	
	- rrr = rra and rrb at the same time.

### Goal

Learn more about sorting algorithmns, about algorithms efficiency, and have a sorted stack A by the end, with the least amount of movements possible.


## Instructions

To install this project on Linux systems just run the code on the terminal:

`git clone https://github.com/kBruna/42_Push_Swap.git push_swap && cd push_swap && make`

The Makefile will take care of the push_swap's basic installation.

To run this program follow the following command structure:

`./push_swap <numbers-to-sort>`

The numbers can be separated with spaces as unique arguments:

`./push_swap 5 4 3 2 1`

Or they can be parsed as a single string:

`./push_swap "5 4 3 2 1"`

The expected output will be the movement used to sort the numbers using the two stacks, like this:

```pb
sa
ra
sa
rra
sa
rra
sa
pa
ra
sa```

If any argument is not a digit, or it is improprially formatted, the program will only return an error.

`Error`

## Resources

Here is some of the links and references used in this project, along with some comentaries about the usage if AI in this project:

[https://push-swap42-visualizer.vercel.app/]
- This is the visualizer program used to check if the program returned the correct movements to organize the stack. It does provides some utilities more than the visualizer provided on the project. And I think its prettier.

[https://www.geeksforgeeks.org/dsa/sorting-algorithms/]
- The GeeksforGeeks page about sorting algorithms. Along with its pages about bubble sort, quick sort, and several others.

[https://www.youtube.com/watch?v=kPRA0W1kECg]
- This comparison video. It shows different algorithms working. Really cool to watch.

[https://www.geeksforgeeks.org/dsa/backtracking-algorithms/]
- Geeks for Geeks again, but this time to check the backtracking algorithm. ( Just to make sure: I did the backtracking sorting algorithm and I cannot recommend enough that you stay away from it. Be warned. )

About AI:
Yes, I used AI. Mostly to make sure my crazy idea had any base in reality. ChatGPT was actually relutant to agree, but after some time it warmed up to the idea.
After that, I used to make sure that my calculations were right, to understand some concepts more deeply, and debate some decisions while development was happening.


## Auxiliary functions 

```void	ft_print_array(t_carray *stack, char *c)
{
	int	i;
	int start;

	i = 0;
	start = stack->start;
	ft_printf("\nStart\n");
	ft_printf("== Operation : %s ==\n", c);
	while (i < stack->len)
	{
		ft_printf("N : %d\n", stack->stack[start]);
		i++;
		start = (i + stack->start) % stack->max;
	}
	ft_printf("End\n\n");
}

void	ft_print_list(t_carray *stack, int len)
{
	int	i;
	int start;

	i = 0;
	ft_printf("List = [");
	start = stack->start;
	while (len > i)
	{
		ft_printf("%d", stack->stack[start]);
		i++;
		start = (stack->start + i) % stack->max;
		if (i < len)
			ft_printf(" ");
	}
	ft_printf("]\n");
} ```
