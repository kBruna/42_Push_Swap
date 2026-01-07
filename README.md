*This project has been created as part of the 42 curriculum by buehara.*

# 42_Push_Swap

42's Project Push Swap

## Description

### Overview

This is 42's number sorting project. We have two stacks available (stack A and stack B) to sort N numbers within the range of an int in C, using specific operations to sort them between the two stacks so that the numbers end up sorted from smallest to largest on stack A.

Stack A contains unique negative and/or positive integers.

Stack B is empty.

Available operations:

- sa (swap a) = Swap the first 2 elements at the top of stack A.
- sb (swap b) = Swap the first 2 elements at the top of stack B.
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

Learn more about sorting algorithms, algorithm efficiency, and achieve a sorted stack A with the least number of moves possible.

## Instructions

To install this project on Linux systems, run the following command in the terminal:
```bash
git clone https://github.com/kBruna/42_Push_Swap.git push_swap && cd push_swap && make
```

The Makefile will handle the basic installation of push_swap.

To run this program, follow this command structure:
```bash
./push_swap <numbers-to-sort>
```

The numbers can be separated with spaces as individual arguments:
```bash
./push_swap 5 4 3 2 1
```

Or they can be passed as a single string:
```bash
./push_swap "5 4 3 2 1"
```

The expected output will be the movements used to sort the numbers using the two stacks, like this:
```
pb
sa
ra
sa
rra
sa
rra
sa
pa
ra
sa
```

If any argument is not a digit or is improperly formatted, the program will return an error:
```
Error
```

## Resources

Here are some of the links and references used in this project, along with some comments about the use of AI:

- [Push Swap Visualizer](https://push-swap42-visualizer.vercel.app/)
  - This visualizer was used to check if the program returned the correct movements to organize the stack. It provides more utilities than the visualizer provided in the project, and I think it's prettier.

- [GeeksforGeeks - Sorting Algorithms](https://www.geeksforgeeks.org/dsa/sorting-algorithms/)
  - The GeeksforGeeks page about sorting algorithms, along with pages about bubble sort, quick sort, and several others.

- [Sorting Algorithms Comparison Video](https://www.youtube.com/watch?v=kPRA0W1kECg)
  - This comparison video shows different algorithms in action. Really cool to watch.

- [GeeksforGeeks - Backtracking Algorithms](https://www.geeksforgeeks.org/dsa/backtracking-algorithms/)
  - GeeksforGeeks again, but this time to check the backtracking algorithm. (Just to make sure: I implemented the backtracking sorting algorithm and I cannot recommend enough that you stay away from it. Be warned.)

### About AI

Yes, I used AI, mostly to ensure my ideas had some basis in reality. ChatGPT was initially reluctant to agree, but eventually warmed up to the concept. After that, I used it to verify my calculations, understand some concepts more deeply, and debate decisions during development.


## Auxiliary functions 

```
void	ft_print_array(t_carray *stack, char *c)
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
}
```
