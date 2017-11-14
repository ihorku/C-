The project is divided into two parts. In the first part we implement the class hierarchy where Shape and 
Triangle denote abstract classes, and Rectangle, Isosceles, Right triangle and Rhombus denote concrete classes.
The program creates shapes, prints them and give all the information about them.


In the second part we desing and implement a class to model a simple slot machine, using the geomentric shapes
created in the first part as visual symbols. This slot machine has three reels, each with 4 symbols, and each 
symbol in 25 available sizes. Thus each reel can display a total of 100 distinct shapes.

In its **run()** function, **slot_machine** repeatedlly performs the following algorithm until the user runs
out of tokens or decides to stop playing:
1. Prompt for and read a bet
2. For each reel *r*, *r* = 0, 1, 2
   - 2.1 let reel *r* point to a newly created shape object of random type and random sizes
3. Display the  reels
4. Report outcome, payout, and tokens left
5. Free dynamic memory consumed by the reels

Step 2.1 expands to these steps:
* generate a random integer *n*, 0<=*n*<=3
* generate a random width *w*, 1<=*w*<=25
* if *n* = 0 then let reel *r* point to a **Rhombus** object of width *w*.
* if *n* = 1 then let reel *r* point to a **Isosceles** object of width *w*
* if *n* = 2 then let reel *r* point to a **RightTrinagle** object of width *w*
* if *n* = 3 then
  i.  generate a random height *h*, 1<=*h*<=25
  ii. let reel *r* point to a **Rectange** object of width *w* and height *h*