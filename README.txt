The bin packing problem (fitting x items with given weights into y boxes) is NP-complete.
The program is a greedy approximation algorithm, and illustrates how quicksorting first makes it more efficient.

Problem: 
In the bin packing problem, items of different weights/sizes must be packed into a finite
number of bins each with the capacity C in a way that minimizes the number of bins used. 
Solution:
Since this problem is NP-complete, this program compares two greedy approximation algorithms: 
"First Fit" and "First Fit Decreasing"
"First Fit Decreasing" simply quicksorts the items into decreasing order before running the algorithm.
"First Fit Decreasing" typically provides more efficient output because it avoids wasting space 
by placing larger items in the bins first.
Example Input (bin.txt): 
The first line is the number of test cases, followed by the capacity of bins for that test case, 
the number of items and then the weight of each item. We will assume that no weight of any single item 
exceeds the capacity of the standard bin for that problem.
Input File Contents:
---
2
10
6
5 10 2 5 4 4 
10
20 
4 4 4 4 4 4 4 4 4 4 6 6 6 6 6 6 6 6 6 6
---
Sample Output:
---
Test Case 1 First Fit: 4 - First Fit Decreasing: 3
Test Case 2 First Fit: 15 - First Fit Decreasing: 10
---

! There is also a PDF file with the original assignment prompt for reference.
