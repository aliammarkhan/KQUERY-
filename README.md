# KQUERY
You are given an array of numbers, there can be n numbers where n is between (1 <= n <= 30000).
Each number is between (1 <= ai <= 109). You are also given “t” queries of the form qt ( i, j, k)
where ( 1 <= i <= j <=n) for each query you need to return the number of elements greater than k
in the sub-sequence ai, ai+1, ….., aj you need to process all t queries in the same fashion.

Input
The first line of the input file contains the size of the array “n”. the next n lines contain n integers
for the array. The next line contains the number of the queries that you need to process. Each next
line contains three integers representing left and right indexes of arrays and an integer k for which
you need to check how many numbers in between indexes are greater than k.

Output
The output contains the result of the queries per line. 

```bash
Input file
10
12
7
13
22
34
19
102
77
23
10
5
0 3 7
0 9 30
6 7 100
2 5 30
3 8 20 

Output file
2
3
1
1
5 
```
