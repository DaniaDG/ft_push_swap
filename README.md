# Push Swap

Game rules:
* The game is composed of 2 stacks named a and b.
* To start with:  
◦ a contains a random number of either positive or negative numbers without
any duplicates.  
◦ b is empty
* The goal is to sort in ascending order numbers into stack a.
* To do this you have the following operations at your disposal:  
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).  
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).  
ss : sa and sb at the same time.  
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.  
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.  
ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.  
rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.  
rr : ra and rb at the same time.  
rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.  
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.  
rrr : rra and rrb at the same time.  

The “push_swap” program
* Push_swap programl receives as an argument
the stack a formatted as a list of integers. The first argument should be at the top
of the stack (be careful about the order).  
* The program displays the smallest list of instructions possible to sort the stack
a, the smallest number being at the top.  
* In case of error, the program displays Error on the standard error.  
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer, and/or there are duplicates.  

The “checker” program
* Checker program gets as an argument the
stack a formatted as a list of integers. The first argument should be at the top of
the stack (be careful about the order). If no argument is given checker stops and
displays nothing.  
* Checker will then wait and read instructions on the standard input, each instruction
will be followed by ’\n’. Once all the instructions have been read, checker will
execute them on the stack received as an argument.  
* If after executing those instructions, stack a is actually sorted and b is empty, then
checker must display "OK" on the standard output. In every
other case, checker must display "KO" on the standard output.  
* In case of error, checker must display Error on the standard error.  
Errors include for example: some arguments are not integers, some arguments are
bigger than an integer, there are duplicates, an instruction don’t exist and/or is
incorrectly formatted.  

The “visualizer” program
* Displays the stack’s status after each operation
* Works on MacOS only

How to run:
```
make  
./push_swap <set of numbers>
./push_swap <set of numbers> |./checker <set of numbers>
./push_swap <set of numbers> |./visualizer <set of numbers>
```
