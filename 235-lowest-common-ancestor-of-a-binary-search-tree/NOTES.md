LCA of Binary Tree (Part 1) :-
Introduction to LCA (Lowest Common Ancestor) problem and a O(n) solution to the problem.
Ex :-                    10
/    \
20     30
/    \
40    50
/     /   \
60   70     80
​
Were given, a binary tree and n1 = 60 and n2 = 70.. and we need to find the lowest common ancestor
ancestor means for example..  60 has 60, 40, 30, 10..  70 has 70, 50, 30, 10.. are ancestor..
common ancestor of 60 and 70 is 10, 30.. and we need to find the LCA then 30 is the LCA..
More ex:-
1) LCA(20, 80)  ->  10
2) LCA(80, 30)  ->  30
3) LCA(70, 80)  ->  50
Navie Solution :-          TC -> 0(n)..      and takes 3 traversal.. to find..
1) First we fill the path of both n1 and n2..
2) Now check lowest commom one among it..
n1 = 70,  n2  = 80
path_1 = [10, 30, 50, 70]