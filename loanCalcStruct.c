/*
 * loanCalcStruct.c
 *
 *  Created on: Nov 26, 2018
 *      Author: williamlyons
 */
#include<stdio.h>
#include<math.h>

double monthlypayment(double loan_amount, double apr, int num_payments){

	double x = pow((1+apr),num_payments);
	double monthly_payment = loan_amount*((apr * x)/(x - 1));
	return monthly_payment;
}
void amortization_schedule(double const mp, double balance, double apr, double num_payments){
	double interest, principle;
	int i,j,payment_num = 0, arraySize = (int)num_payments;
	printf("\n# \t Payment \t Principle \t Interest \t Balance");

	struct payment {
		double interest;
		double principle;
		double balance;
	};
	struct payment paymentArr[arraySize+1];

	paymentArr[0].interest = 0.0;
	paymentArr[0].principle = 0.0;
	paymentArr[0].balance = balance;

	for(i=1;i<=num_payments;i++){
		paymentArr[i].interest = paymentArr[i-1].balance*apr;
		paymentArr[i].principle = mp - paymentArr[i].interest;
		paymentArr[i].balance = paymentArr[i-1].balance - paymentArr[i].principle;
	}
	for(j = 0; j <= num_payments; j++){
		printf("\n%d \t %7.2lf \t %7.2lf \t %6.2lf \t %9.2lf",payment_num, mp, paymentArr[j].principle, paymentArr[j].interest, paymentArr[j].balance);
		payment_num++;
	}
}

int main(){
	int num_payments;
	double loan_amount, apr, mp;

	printf("Enter amount of loan : $");
	scanf("%lf",&loan_amount);
	printf("Enter Annual Interest Rate : %%");
	scanf("%lf",&apr);
	printf("Enter Number of Payments : ");
	scanf("%d",&num_payments);

	apr = (apr/12)/100;

	mp = monthlypayment(loan_amount, apr, num_payments);

	printf("\nMonthly Payment: $%.2lf\n",mp);

	amortization_schedule(mp,loan_amount,apr,num_payments);
}


