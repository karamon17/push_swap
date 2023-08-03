# push_swap
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

## Bonus
A program named *checker* that takes as an argument a stack formatted as a list of integers, execute instructions read from the standard input and checks, if after executing those instructions, the stack is actually sorted.

## Usage
| command | info |
| ------- | ---- |
| `make` | compile *push_swap* |
| `make bonus` | compile *checker* |
| `make clean` | remove temporary files |
| `make fclean` | remove *push_swap* and temporary files |
| `make re` | execute `make fclean` and recompile *push_swap* |

### push_swap
```shell
./push_swap <arg1> <arg2> <...> <argn>
```
or

```shell
ARGS="..."; ./push_swap $ARGS
```
### checker
```shell
./checker <arg1> <arg2> <...> <argn>
```
or

```shell
ARGS="..."; ./checker $ARGS
```
### Instructions
| Instruction | aka | Description |
| - | - | - |
| sa | swap a | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
| sb | swap b | Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
| ss | | sa and sb at the same time. |
| pa | push a | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| pb | push b | Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| ra | rotate a | Shift up all elements of stack a by 1. The first element becomes the last one. |
| rb | rotate b | Shift up all elements of stack b by 1. The first element becomes the last one. |
| rr | | ra and rb at the same time. |
| rra | reverse rotate a | Shift down all elements of stack a by 1. The last element becomes the first one. |
| rrb | reverse rotate b | Shift down all elements of stack b by 1. The last element becomes the first one. |
| rrr | | rra and rrb at the same time. |
