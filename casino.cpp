#include<iostream>
#include<stdlib.h>
using namespace std;

class Casino
{
	int deposit;
	char name[40];
	public:
	void input()
	{
		cout<<"Enter your Name : ";
		cin.getline(name,40);
		cout<<"Enter Deposit amount to play game : $";
		cin>>deposit;	
	}	
	char* getName()
	{
 		return name;	
	}
	int getDeposit()
	{
		return deposit;	
	}
	int Random()
	{
		int n=rand()%10+0;
		return n;
	}
	void add(int a)
	{
    	deposit+=a;	
	}
	void sub(int a)
	{
		deposit-=a;
	}
};
	int main()
	{
		Casino user;
		cout<<"___________________________________________________"<<endl;
		cout<<"\n\n\t\t$CASINO GAME$\n\n";
		cout<<"___________________________________________________"<<endl;
		user.input();
		system("cls");  
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<<"\t\t\tRULES OF THE GAME"<<endl;
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<<"\t1. Choose any number between 1 to 10\n\t2. If you win you will get 10 times of money you bet\n\t3. If you bet on wrong number you will loose your betting amount\n\n"<<endl;
		cout<<"-------------------------------------------------------------------------"<<endl;
	    char ch='y';
		do
	    {
	    int bet,guess,wn;
	    cout<<"Your current balance is $ "<<user.getDeposit()<<endl;
		cout<<user.getName()<<", enter money to bet : ";
		cin>>bet;
		if(bet<=user.getDeposit()&& bet>0)
		{	
		cout<<"Guess your number to bet between 1 to 10 :";
		cin>>guess;
		wn=user.Random();
		if(guess==wn)
		{
			user.add(10*bet);
			cout<<"\tCONGRATULATIONS!! \nYOU WON $"<<bet*10<<endl;
		}
			else
			{
			user.sub(bet);
			cout<<"Bad luck this time!! You lost $"<<bet<<endl;
			cout<<endl<<"The winning number was : "<<wn<<endl;
		    }
		cout<<user.getName()<<", You have $"<<user.getDeposit();
	    }
	    else
	    {
	    	cout<<endl<<"The amount entered cannot be bet"<<endl;
		}
		cout<<endl<<endl<<"-->Do you want to play again(y/n)?";
		fflush(stdin);
		cin>>ch;
		}while(ch!='n');
		cout<<"\tThanks for playing "<<endl;
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<<user.getName()<<", your balance is: "<<user.getDeposit();
		cout<<endl<<"-------------------------------------------------------------------------"<<endl;
		
	}


