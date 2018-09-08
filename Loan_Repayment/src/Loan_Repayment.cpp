//============================================================================
// Name        : LoanRepayment.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cmath>
using namespace std;
class Loan{
public:
	int i,paymentCount=0;
	float interest,balance,principal,totalInterest=0;
	void payment(float loanPrincipal,float interestRate,float monthlyPayment){
		paymentCount=0;
		balance = loanPrincipal ;
      cout <<"Payment\t\tAmount\t\t\t\tInterest\t\t\tPrincipal\t\t\tBalance"<<endl;
		while(balance>monthlyPayment){
			interest=((interestRate/12)*balance);
			totalInterest+=interest;
			principal=monthlyPayment-interest;
			balance=balance-principal;
			paymentCount++;
			cout<<paymentCount<<"\t\t"<<monthlyPayment<<"\t\t\t\t"<<interest<<"\t\t\t\t"<<principal<<"\t\t\t\t"<<balance<<endl;
		}
		if(balance<monthlyPayment && balance>0){
			monthlyPayment=balance;
			interest=((interestRate/12)*balance);
			totalInterest+=interest;
			principal=monthlyPayment-interest;
			balance=balance-principal;
			paymentCount++;
			cout<<paymentCount<<"\t\t"<<monthlyPayment<<"\t\t\t\t"<<interest<<"\t\t\t\t"<<principal<<"\t\t\t\t"<<balance<<endl;
			}
			cout<<"Total No.Of Payments:"<<paymentCount<<endl;
			cout<<"Total Interest paid: $"<<totalInterest<<endl<<endl;
	}
};
int main() {
	int i,n;
	Loan l;
	float loanPrincipal[20],interestRate[20],monthlyPayment[20];
	cout<<"enter no of schedules"<<endl;
	cin>>n;
	cout<<"enter loan amount,Annual interest rate,monthly Installment"<<endl;
	for(i=0;i<n;i++){
		cin>>loanPrincipal[i];
		cin>>interestRate[i];
		cin>>monthlyPayment[i];
	}

	for(i=0;i<n;i++){
		l.payment(loanPrincipal[i],interestRate[i],monthlyPayment[i]);
	}
}


