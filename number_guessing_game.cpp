#include <iostream>
#include <ctime>
#include <cstdlib>



class Player
{
	private:
		std::string name;
		int number=0;
		int wins=0;
		int losses=0;
	public:

		Player(std::string name) : name(name){}

		void setNum(int num){number =num;}


		int getNum(){return number;}
		
		std::string getName(){return name;}
		
		virtual void  chooseNumber() = 0; 
		
		
}; //end player class

class Human : public Player
{
	public:
		Human(std::string name) : Player(name){}
		
		virtual void  chooseNumber()
		{
			int number;
			
			std::cout<<"\nPlease enter a number 1-100: ";
			std::cin>>number;
			
			Player::setNum(number); 
		}
		
}; //end human class

class Computer: public Player
{
	public:
		Computer() : Player("Joshua"){}
		
		 virtual void chooseNumber()
		{
			srand(time(0));
		
			setNum((rand() % 100 )+1);
		}
		
		
}; //end compu class
void playGame(Player& player1,Player& player2);
int main()
{
	char again;
	int players;
	std::string name;
	
	std::cout<<"\nShall we play a game (Y/N)? ";
	std::cin>>again;
	
	while(again== 'Y'||again== 'y')
	{

		std::cout<<"\nChoose number of players 1 or 2: ";
		std::cin>>players;
		std::cin.ignore(1000,'\n');
		if(players == 1)
		{
			std::cout<<"\nEnter your name: ";
			getline(std::cin, name);
			
			Human player1(name);
			
			Computer player2;
			
			playGame(player1,player2);
			
		
		}
		else
		{
			std::cout<<"\nEnter your name for player 1: ";
			getline(std::cin, name);
			
			Human player1(name);
			
			std::cout<<"\nEnter your name for player 2: ";
			getline(std::cin, name);
			
			Human player2(name);
			
			playGame(player1,player2);
		}
		
		
		std::cout<<"\nWould you like to play again (Y/N)? ";
		std::cin>>again;
	}
	
	
	
	
	return 0;
}

void playGame(Player& player1,Player& player2)
{ 

	player1.chooseNumber();
	player2.chooseNumber();
	
	std::cout<<player1.getName()<<" selected "<<player1.getNum()<<std::endl;
	
	std::cout<<player2.getName()<<" selected "<<player2.getNum()<<std::endl;
	
	if(rand()%2)
	{
		std::cout<<"\nHighest Number wins!! ";
		
		if(player1.getNum()>player2.getNum())
		{
			std::cout<<player1.getName()<<" wins! :D";
			std::cout<<player2.getName()<<" loses! :C";
		}
		
		if(player1.getNum()<player2.getNum())
		{
			std::cout<<player2.getName()<<" wins! :D";
			std::cout<<player1.getName()<<" loses! :C";
		}
	}
	else
	{
		std::cout<<"\nLowest Number Wins!! ";
		
		if(player1.getNum()<player2.getNum())
		{
			std::cout<<player1.getName()<<" Wins! :D"<<std::endl;
			std::cout<<player2.getName()<<" loses! :C";

		}
		
		if(player1.getNum()>player2.getNum())

		{
			std::cout<<player2.getName()<<" Wins! :D";
			std::cout<<player1.getName()<<" loses! :C";
		}
	}

}
