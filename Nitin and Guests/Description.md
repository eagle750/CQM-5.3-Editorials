Question No-4 https://www.hackerrank.com/contests/cqm-5-3/challenges/nitin-and-guests

The approach to the problem involves Binary Search. To check if Nitin can have x sweets or more we need to calculate the least amount of 
sweets we need to give to all the guests and compare it to y(number of sweets).

The number of sweets is minimized if we give m - 1 sweets to Nitin's neighbors, m - 2 pillows to the guests at the distance 2 from Nitin
and so on, until we have 1 sweet or until we reach an end of row. The total amount of sweet on one side of Nitin can be calculated using
a formula.

Suppose there are n beds on one side of Nitin. There are two cases: if n > m - 1, then the total number of pillows is ((m-1)*m)/2+n-(m-1)
, otherwise the total number of pillows is ((m-1)+(m-n))*n/2.
