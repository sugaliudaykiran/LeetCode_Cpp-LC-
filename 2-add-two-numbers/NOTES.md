//  TC -> O(max(n1, n2))..  AS -> O(n)..
1) Create a dummy node to return the head and temp node pointing to dummy.. and carry = 0..
2) Sum = 0 while, the l1 or l2 or carry is Not Zero or Not NULL..
3) Update sum with l1 + l2 vals + carry..
4) where carry = sum/10.. and val particular node's sum is sum % 10..
5) when step 2 fails then stop..
​