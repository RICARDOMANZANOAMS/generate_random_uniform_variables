# generate_random_uniform_variables
This section shows how to generate uniform distributed variables between 0 and 1 
To generate a random variable uniformly distributed between [0,1]. It is necessary to know that each value generated has the same probability to appear in the experiment. It means that all the values are equally likely. 

To explain this it is necessary to understand what does it mean uniformly distributed. If we have numbers from 1 to 10. By definition, we know that the probability that one number appears has the same probability than another appears.

As we see in the figure below. The probability that number 1 appears is the same probability that number 2 appears. In this case we know that there are 10 equally likely states.
 	[1,2,3,4,5,6,7,8,9,10]
  
Probability	that every number appears 1/10	1/10	1/10	1/10	1/10	1/10	1/10	1/10	1/10	1/10

The probability of each number is a discrete probability

In the next part we will explain a uniform distribution continuous in order to find and expression which allow us generate random variables with uniform distribution
The probability density function of the uniform distribution is

![](https://latex.codecogs.com/gif.latex?f%28x%29%3D%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D%20%5Cfrac%7B1%7D%7Bb-a%7D%20%26%20a%5Cleq%20x%5Cleq%20b%5C%5C%200%20%26%20x%3C%20a%20%5C%2C%20%5C%2C%20x%3E%20b%20%5Cend%7Bmatrix%7D%5Cright.)

Where 1/(b-a) is the probability for all x between a and b.
The cumulative density distribution of the uniform distribution is 


![](https://latex.codecogs.com/gif.latex?f%28x%29%3D%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D%20%5Cfrac%7Bx-a%7D%7Bb-a%7D%20%26%20a%5Cleq%20x%5Cleq%20b%5C%5C%200%20%26%20x%3C%20a%20%5C%2C%20%5C%2C%20x%3E%20b%20%5Cend%7Bmatrix%7D%5Cright.)

We know that  F(x)=(x-a)/(b-a) is a variable uniformly distributed. Thus, in order to get values x uniformly distributed it is necessary to find the inverse of F(x).
y=(x-a)/(b-a)
x=y(b-a)+a
If we want to generate variables uniformly distributed between [0,1]. 
b=1 and a=0.
Therefore
x=y(1-0)+0
x=y
Where y has to be uniformly distribute between 0 and 1.Generally programs use pseudo-random algorithms in order to calculate values equally likely between 0 an 1.
The next algorithm is used for the majority of programs in order to calculate values with same probability

![](https://latex.codecogs.com/gif.latex?X_%7Bn&plus;1%7D%3D%28a*X_%7Bn%7D&plus;c%29%20%5C%2C%20mod%20%5C%2C%20m%5C%2C%20%5C%2C%20%5C%2C%20n%5Cgeq%200)

![](https://latex.codecogs.com/gif.latex?X_%7Bn&plus;1%7D) is the remainder which was obtained when ![](https://latex.codecogs.com/gif.latex?a*X_%7Bn%7D&plus;c)  is divided by m. Thus each [](https://latex.codecogs.com/gif.latex?X_%7Bn%7D)  is one of the values 0,1,2,….m-1, and the quantity [](https://latex.codecogs.com/gif.latex?X_%7Bn%7D)/m is taken as the random number. [](https://latex.codecogs.com/gif.latex?X_%7B0%7D) is the seed to generate the random variables. 
As an example:

If a=3, c=7 and m=23 with seed X_o=2 

X_1=(3*X_0+7)    mod  23=(3*2+7)    mod  23     =13 mod 23=13

X_2=(3*X_1+7)    mod  23= (3*13+7)    mod  23 =46 mod 23=0

X_3=(3*X_2+7)    mod  23= (3*46+7)    mod  23 =145 mod 23=7

X_4=(3*X_3+7)    mod  23= (3*145+7)    mod  23 =442 mod 23=5

Until to have the numbers necessary for the purpose. The pseudo random numbers obtained are 13/23,0/23,7/23,5/23…. Until X_(m-1).

C++ use a pseudo random algorithm with the function rand(). The values of this function are between 0 and RAND_MAX. If we consider m=RAND_MAX. We can find random numbers between 0 and 1 equally likely dividing 

![](https://latex.codecogs.com/gif.latex?Random%5C_variable%5C_equally%5C_likely%5B0%2C1%5D%3D%5Cfrac%7Brand%28%29%7D%7BRAND%5C_MAX%7D)

In order to generate 1000 random numbers equally likely we use the next algorithm in C++.
It is important to understand that Mean and Variance are arithmetic. Therefore, in the algorithm exposed below Mean and variance have been calculated with the next formulas:


![](https://latex.codecogs.com/gif.latex?Arithmetic%5C_Mean%3D%5Csum_%7Bn%7D%5E%7Bi%3D1%7DX_%7Bi%7D/n)

![](https://latex.codecogs.com/gif.latex?X_%7Bi%7D)  is the random variable generated between 0 to 1
n is the number of values generated

![](https://latex.codecogs.com/gif.latex?Arithmetic%5C_Variance%3D%5Cfrac%7B%5Csum_%7Bi%3D1%7D%5E%7Bn%7DX%5E%7B2%7D_%7Bi%7D%7D%7Bn%7D-mean%5E%7B2%7D)

