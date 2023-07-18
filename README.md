[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/6moZA-SV)
# Operating Systems
## Banker's Algorithm
## Due: April 17, 2023 by 23:59:59

## Objective
The purpose of this programming project is to explore a resource allocation algorithm.  This can be achieved by implementing the banker's algorithm as described in our textbook and discussed in class.

## Project Specifications
### Input
Review the banker's algorithm discussed in our textbook and notes.  Your executable program must be named `banker` and will read the allocation, max, available, and request vectors from a file.  The name of the input file will be passed to your program as a command line argument.  The input file format is the following:

- number of processes and number of resource types: n m
- 1 x m resource vector
- 1 x m available vector 
- n x m maximum matrix 
- n x m allocation matrix 
- i : 1 x m request vector 

Data contraints and validation:
- There can be at most 26 resource types.  Each resource type has an implied label using a single alphabetic letter (uppercase).
- There can be at most 1024 processes.
- Each test case (file) will be correctly formated.
- Each numeric value in the input file will be an integer.  Negative integers are not allowed.  No input file will ever have negative numbers.  
- The request vector is delimited by a colon (:).  The number to the left of the colon is the id of the process making the request.  The numbers to the right of the colon is the amount of each resource type being requested.  See example below.

### Output
Your program will output the following in a standardized format.  See example below.

1.	Echo the number of processes and resource types.
2.	Echo the resource vector.  Label the resource types.
3.	Echo the available vector.  Label the resource types.
4.	Echo the max matrix.  Label the processes and resource types (see sample output). 
5.	Echo the allocation matrix.  Label the processes and resource types (see sample output). 
6.	Compute and print the need matrix.  Label the processes and resource types (see sample output). 
7.	Determine if the system is in a safe state.  If not, display a message indicating the system is not in a safe state and properly exit your program.  If the system *is* in a safe state, continue with the next step.
8.	Echo the request vector.  Label the process making the request and resource types (see sample output). 
9.	Determine if the request can be granted.  If the request cannot be granted, then display a message indicating so and properly exit your program.  If the request can be granted, then allocate the request and display the new system state.


## Examples
### Example 1
#### Input
```text
4 3

9 3 6

1 1 2

3 3 2
6 3 3
3 3 4
4 3 2

1 0 0
5 1 1
2 1 1
0 0 2

0:1 0 1 
```
#### Output
```text
There are 4 processes and 3 resource types in the system.

The Resource Vector is:
A B C
9 3 6

The Available Vector is:
A B C
1 1 2

The Max Matrix is:
   A B C 
0: 3 3 2 
1: 6 3 3
2: 3 3 4
3: 4 3 2

The Allocation Matrix is:
   A B C
0: 1 0 0
1: 5 1 1
2: 2 1 1
3: 0 0 2

The Need Matrix is:
   A B C
0: 2 3 2
1: 1 2 2
2: 1 2 3
3: 4 3 0

THE SYSTEM IS NOT IN A SAFE STATE
```

### Example 2
#### Input
```text
4 3

9 3 6

1 1 2

3 2 2
6 1 3
3 1 4
4 2 2

1 0 0
5 1 1
2 1 1
0 0 2

0:1 0 1 
```
#### Output
```text
There are 4 processes and 3 resource types in the system.

The Resource Vector is:
A B C
9 3 6

The Available Vector is:
A B C
1 1 2

The Max Matrix is:
   A B C 
0: 3 2 2 
1: 6 1 3
2: 3 1 4
3: 4 2 2

The Allocation Matrix is:
   A B C
0: 1 0 0
1: 5 1 1
2: 2 1 1
3: 0 0 2

The Need Matrix is:
   A B C
0: 2 2 2
1: 1 0 2
2: 1 0 3
3: 4 2 0

THE SYSTEM IS IN A SAFE STATE

The Request Vector is:
  A B C
0:1 0 1

THE REQUEST CANNOT BE GRANTED
```
### Example 3
#### Input
```text
4 3

9 3 6

1 1 2

3 2 2
6 1 3
3 1 4
4 2 2

1 0 0
5 1 1
2 1 1
0 0 2

1:1 0 1 
```
#### Output
```text
There are 4 processes and 3 resource types in the system.

The Resource Vector is...
A B C
9 3 6

The Available Vector is...
A B C
1 1 2

The Max Matrix is...
   A B C 
0: 3 2 2 
1: 6 1 3
2: 3 1 4
3: 4 2 2

The Allocation Matrix is...
   A B C
0: 1 0 0
1: 5 1 1
2: 2 1 1
3: 0 0 2

The Need Matrix is...
   A B C
0: 2 2 2
1: 1 0 2
2: 1 0 3
3: 4 2 0

THE SYSTEM IS IN A SAFE STATE

The Request Vector is...
  A B C
1:1 0 1

THE REQUEST CAN BE GRANTED: NEW STATE FOLLOWS

The Resource Vector is...
A B C
9 3 6

The Available Vector is...
A B C
0 1 1

The Max Matrix is...
   A B C 
0: 3 2 2 
1: 6 1 3
2: 3 1 4
3: 4 2 2

The Allocation Matrix is...
   A B C
0: 1 0 0
1: 6 1 2
2: 2 1 1
3: 0 0 2

The Need Matrix is...
   A B C
0: 2 2 2
1: 0 0 1
2: 1 0 3
3: 4 2 0
```
