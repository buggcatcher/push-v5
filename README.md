# push-v5
In this project, I'll be sorting data on a stack using a limited set of instructions. My goal is to use the fewest number of actions possible. To succeed, I'll need to manipulate various types of algorithms and carefully choose the most appropriate solution from many options to achieve optimized data sorting.

42-push_swap
Algorithmic project
!NOTE
Because of 42 School norm requirements:

    All variables are declared and aligned at the top of each function
    Each function can't have more then 25 lines of code
    C++ style code commenting is forbidden
    Project should be created just with allowed functions otherwise it's cheating.

Game rules

    The game is composed of 2 stacks named a and b.
    To start with:
    ◦ a contains a random number of either positive or negative numbers without any duplicates.
    ◦ b is empty
    The goal is to sort in ascending order numbers into stack a.
    To do this you have the following operations at your disposal:

Command 	Description
sa 	swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
sb 	swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
ss 	sa and sb at the same time.
pa 	push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb 	push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
ra 	rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
rb 	rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
rr 	ra and rb at the same time.
rra 	reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one.
rrb 	reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the first one.
rrr 	rra and rrb at the same time.
Sorting example

-------------------------------------------------------------------------------------------------------
Init a and b:
2
1
3
6
8
5
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec sa:
1
2
3
6
8
5
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b 
-------------------------------------------------------------------------------------------------------
This example sort integers from a in 12 instructions.

First I push everyting to stack_b according to the chunks belonging.
![Stack Visualizer](https://i.ibb.co/cXBYVL1/stack-visualizer.png)                
https://push-swap-visualizer.vercel.app/
        
The issue occurs when I push back to stack_a.      
The smallest combination I found that replicates the issue is:      
5 14 13 4 15 1 12 10 11 8 2 9 6 7 3
![Issue Visualized](https://raw.githubusercontent.com/buggcatcher/push-v5/main/issue_visualized.png)                
https://github.com/o-reo/push_swap_visualizer


