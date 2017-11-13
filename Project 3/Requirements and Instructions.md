##Instructions##

Every input line must begin with a single character command. If the command is a binary
operator, then it must be followed by an unsigned or a signed integer. For unary commands,
the input line must begin and end with the command. Tabs and spaces can appear anywhere
in a command line, even within the input number. The command (q) ends the calculator
run. Finally, an empty command line repeats the previous command.

Here is the output produced by a sample run of the program:

```
1  Welcome to MegaCalculator
2  =========================
3 
4  Accumulator: +0
5  Enter input:    =    +    1   2   3
6
7  Accumulator: +123
8  Enter input: *-123456789012345678901234567890
9
10 Accumulator: -15185185048518518504851851850470
11 Enter input: /-123
12 
13 Accumulator: +123456789012345678901234567890
14 Enter input: =7
15
16 Accumulator: +7
17 Enter input: h
18 > +7
19 > +22
20 > +11
21 > +34
22 > +17
23 > +52
24 > +26
25 > +13
26 > +40
27 > +20
28 > +10
29 > +5
30 > +16
31 > +8
32 > +4
33 > +2 
34 > +1 
35 
36 length of the hailstone (+7) sequence: +17
37
38 Accumulator: +7
39 Enter input: -2 
40 
41 Accumulator: +5 
42 Enter input: f 
43 +1! = +1 
44 +2! = +2 
45 +3! = +6
46 +4! = +24 
47 +5! = +120
48 
49 Accumulator: +5 
50 Enter input: * 111 222 333 444 555 666 777 888 999
51
52 Accumulator: +556111667222778333889444995
53 Enter input: /5 
54 
55 Accumulator: +111222333444555666777888999
56 Enter input: q
```

The displayed resulting value is called the *accumulator*. The calculator always uses the accumulator as 
one of the operands in the next operation. Specifically, if the next operation is a binary operation then
the accumulator is used as the left operand in that operatin, and if the next operatin is a unary operation
then the accumulator is used as the only operand in that operation.


####Command list####

| Input | Command | Operand | Operation | Description |
| ---- | ---- | ----- | ---- | ---- |
|+*i* | + | *i* | *a*<- *a*+*i* | add |
|++*i* | + | +*i* | *a*<- *a*+*i* | add |
|+-*i* | + | -*i* | *a*<- *a*+(-*i*) | add |
|-*i* | - | *i* | *a*<- *a*-*i* | substract |
|-+*i* | - | +*i* | *a*<- *a*-*i* | substract |
|--*i* | - | -*i* | *a*<- *a*-(-*i*) | substract |
|\**i* | \* | *i* | *a*<- *a*\**i* | multiply |
|\*+*i* | \* | +*i* | *a*<- *a*\**i* | multiply |
|\*-*i* | \* | -*i* | *a*<- *a*\*(-*i*) | multiply |
|/*i* | / | *i* | *a*<- *a*/*i* | divide |
|/+*i* | / | +*i* | *a*<- *a*/*i* | divide |
|/-*i* | / | -*i* | *a*<- *a*/(-*i*) | divide |
|%*i* | % | *i* | *a*<- *a*%*i* | modulus |
|%+*i* | % | +*i* | *a*<- *a*%*i* | modulus |
|%-*i* | % | -*i* | *a*<- *a*%(-*i*) | modulus |
|=*i* | = | *i* | *a*<- *i* | reset *a* |
|=+*i* | = | +*i* | *a*<- *i* | reset *a* | 
|=-*i* | = | -*i* | *a*<- (-*i*) | reset *a* |
|*c* | *c* |  | *a*<- 0 | clear *a* |
|*n* | *n* |  | *a*<-  -*a* | negate *a* |
|*f* | *f* |  | *a*<- *a*! | factorial of *a* |
|*h* | *h* |  | *hailstone(a)*| prints hailstone(*a*), returns its length
|*q* | *q* |  |      | quit

* *a* denotes the accumulator value
* *i* denotes the input number, which may or may not be signed
* input lines like ?+*i* are effectively the same as ?i, where ? denotes a binary command

####Programming requirements####

- no dynamic storage allocation; that is, no use of the `new` or `delete` operators.
- no C-style raw arrays.
- must use one of the STL sequence containers to store the digits of the numbers.
- write a class named **MegaInt** to model arbitrary large integers using the sign-magnitude
notation. Equip **MegaInt** with the same operators supported by the built-in data types
such as **int**. The implementation does not have to be highly optimized, but it should
not be too inefficient either.

