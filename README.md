# Mills_Primes
Mills' Primes (PRPs) series extensions.

Mills' constant can be defined as the least theta such that f(n) = floor( theta ^ {3^n} ) is prime for all positive integers n (Caldwell and Cheng 2005).

The first few f(n) for n=1, 2, ... are 2, 11, 1361, 2521008887, ... (OEIS A051254). They can be represented more compactly through b_n as f(1)=2 and
 f(n+1)=f(n)^3+b_n. 
Caldwell and Cheng (2005) calculated the first 10 Mills primes. 13 were known as of Jul. 2013, with the first few b_n for n=1, 2, ... being 3, 30, 6, 80, 12, 450, 894, 3636, 70756, 97220, 66768, 300840, ... (OEIS A108739). 

b(12) and b(13) generate only probable prime numbers, as well as being conditional on f(11) and f(12) being proved primes. Minimality of b(12)-b(13) is exhaustively tested by Serge Batalov, Aug 06 2013.
b(14) = 8436308 is found by Ryan Propper and Serge Batalov, Apr 29 2024. Minimality of b(14) was exhaustively tested by Ryan Propper and Serge Batalov, May 24 2024.

Minimality reports (all factors and/or RES64) are attached.

References:
- Caldwell, C. K. and Cheng, Y. Determining Mills' Constant and a Note on Honaker's Problem. J. Integer Sequences 8, Article 05.4.1, 1-9, 2005. http://www.cs.uwaterloo.ca/journals/JIS/VOL8/Caldwell/caldwell78.html
- https://mathworld.wolfram.com/MillsPrime.html
- https://oeis.org/A108739
- https://oeis.org/A051254
- http://factordb.com/index.php?id=1100000007022314636
