/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Ricardo Manzano
 *
 * Created on February 13, 2018, 11:27 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    double x;              
    double n=1000;       //number of random variables required
    double sum=0;        //variable to calculate arithmetic mean. 
    double variance=0;   //variable to calculate arithmetic variance
    double total=0;      //variable to sum all the values generated to calculate the mean
    double total_variance=0; //variable to sum all the values generated to calculate the variance
    double random_variable;
    srand(time(NULL));
    for (x=0; x<=n;x++)
    {   random_variable= (double)rand()/(double)RAND_MAX;//Random variable generated
        printf ("Random Number: %lf\n", random_variable);  //Print the random variable generated
        variance=pow(random_variable,2);                   //Number generate pow to 2. It is necessary to calculate arithmetic Variance         
        total_variance=total_variance+variance;            //Sum to calculate arithmetic variance
        sum=sum+random_variable;                           //Sum to calculate arithmetic mean
    }
   total=sum/n;                                     //Formula to calculate mean
   total_variance=(total_variance/n)-pow(total,2);  //Formula to calculate variance
   printf ("Mean %lf, Variance %lf\n", total, total_variance ); //Print mean and variance
  return 0;
}

