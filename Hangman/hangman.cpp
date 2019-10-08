#include <iostream>
#include <string>

using namespace std;

void clear();
void delay();
void menu();
void modeMenu();
void infoMenu();
pair<string, int> selectInfo(int size);
int single(string fake, string word, int mode, int att);
int versus(string word1, string word2, string fake1, string fake2);
int choice(int op);
int loss();
int win();

/* TENTAR APLICAR OS SPRITES E MELHORAS O VISUAL DO JOGO / FAZER MAIS TESTES / RESOLVER PROBLEMA DAS STRINGS "DESTINY" COM ESPAÇOS/
   ADICIONAR MODO CHALLENGE COM ESCOLHA RANDOM DE PALAVRAS
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                                                                                                                                           */
int main()
{
	string auxOp;
	int op = 0;
	int decision;
	int decision2;
	string destiny;

	while(op != 5 && decision != 1 && decision2 != 2)
	{
		decision = 0;
		decision2 = 0;
		clear();
		menu();

		cin >> auxOp;

		while(auxOp != "1" && auxOp != "4" && auxOp != "2" && auxOp != "3" && auxOp != "5")
		{
			clear();
			cout << "Don't underestimate me boy..." << endl;
			delay();
			delay();
			clear();
			menu();
			cin >> auxOp;
		}

		if(auxOp == "1")
			op = 1;
		else if(auxOp == "2")
			op = 2;
		else if(auxOp == "3")
			op = 3;
		else if (auxOp == "4")
			op = 4;
		else
			op = 5;

		if(op == 1)
		{
			while(decision2 != 2 && decision != 1)
			{
				decision = 0;
				decision2 = 0;
				if(choice(op))
				{
					clear();
					decision2 = win();
				}
				else
				{
					clear();
					decision = loss();
				}
			}
		}

		if(op == 2)
		{
			int x = choice(op);
			while(x == 0)
			{
				x = choice(op);
			}
			
			if(x == 1)
			{
				clear();
				cout << "Player 1..." << endl; 
				delay();
				cout << "You were able to win your battle..." << endl;
				delay();
				cout << "Choose your opponent destiny..." << endl;
				delay();

				cin >> destiny;

				clear();
				cout << "Done!" << endl;
				delay();
			}
			else
			{
				clear();
				cout << "Player 2..." << endl; 
				delay();
				cout << "You were able to win your battle..." << endl;
				delay();
				cout << "Choose your opponent destiny..." << endl;
				delay();

				cin >> destiny;

				clear();
				cout << "Done!" << endl;
				delay();
			}
		}

		/*if(op == 3)
		{

		}*/

		if(op == 4)
		{
			string x;
			infoMenu();
			cin >> x;
			
			while(x != "1" && x != "2")
			{
				clear();
				cout << "Don't understimate me boy..." << endl;

				cout << "1 - I accept" << endl << "2 - ..." << endl;
				
				cin >> x;	
			}

			if(x == "2")
			{
				clear();
				cout << "Seems that you don't care about your life..." << endl;
				delay();
				delay();
				cout << "Me neither..." << endl;
				delay();
				clear();
				return 0;
			}
		}

		if(op == 5)
		{
			clear();
			cout << "You don't have the guts..." << endl;
			delay();
			clear();
			return 0;
		}
	}

	return 0;
}


void clear()
{
	system("clear");
}

void delay()
{
	for(int i = 0; i < 1000000000; i++);
}

void menu()
{
	cout << "Welcome to Hell's Hangman Game" << endl;
	cout << "Press 1 to Play alone" << endl;
	cout << "Press 2 to Play with your rival" << endl;
	cout << "Press 3 to Play Challenge Mode" << endl;
	cout << "Press 4 for info" << endl;
	cout << "Press 5 to leave the game" << endl;
}

void modeMenu()
{
	cout << "Choose the mode:" << endl << "1 - Noob" << endl << "2 - Mediocre" << endl << "3 - Respectable" << endl << "4 - GodMode" << endl;
}

pair<string,int> selectInfo(int size)
{
	switch(size)
	{
		case 4:
			return make_pair("casa",6);

		case 8:
			return make_pair("trabalho", 5);

		case 12:
			return make_pair("literalmente", 4);

		case 16:
			return make_pair("exponencialmente", 3);
	}
}


int single(string fake, string word, int mode, int att)
{
	char guess;
	string x;
	string answer;
	string tease = "You're alone in this... Good luck... You'll need";

	while(att > 0 && fake != word)
	{	
		clear();
		cout << tease << endl;
		delay();
		cout << "Word:" << fake << " (SIZE:" << mode*4 << ")" << endl; 
		cout << "Attempts counter: " << att << endl;
		cout << "Press 1 to take a guess or 2 to take your chances..." << endl;
		cin >> x;

		if(x == "1")
		{
			cout << "Your guess: ";
			cin >> guess;
			int cont = 0;

			for(int i = 0; i < mode*4; i++)
			{
				if(guess == word[i] || guess == word[i] - 32)
				{
					fake[i] = word[i];
					cont++;
				}
			}

			if(cont > 0)
				tease = "You got one... Don't get too excited...";
			else
			{
				tease = "Wrong guess... You're running out of chances...";
				att--;
			}
		}
		else
		{
			cout << "Give your answer: ";
			cin >> answer;

			if(answer != word)
			{
				clear();
				cout << "You'll pay for being so proud..." << endl;
				delay();
				//clear();
				att = 0;
			}
			else
			{
				fake = word;
			}
		}			
	}

	if(att == 0)
		return 0;
	else
		return 1;
}

int versus(string word1, string word2, string fake1, string fake2)
{
	int att = 1;
	string x, answer1, answer2;
	char guess1, guess2;
	string tease = "You're alone in this player 1... Good luck... You'll need";
	int v1 = 0;
	int v2 = 0;

	while(att > 0 && fake1 != word2)
	{	
		clear();
		cout << tease << endl;
		delay();
		cout << "Word:" << fake1 << " (SIZE:" << word2.size() << ")" << endl; 
		cout << "Attempts counter: " << att << endl;
		cout << "Press 1 to take a guess or 2 to take your chances..." << endl;
		cin >> x;

		if(x == "1")
		{
			cout << "Your guess:";
			cin >> guess1;

			int cont = 0;

			for(int i = 0; i < word2.size(); i++)
			{
				if(guess1 == word2[i] || guess1 == word2[i] - 32)
				{
					fake1[i] = word2[i];
					cont++;
				}
			}

			if(cont > 0)
				tease = "You got one... Don't get too excited player 1...";
			else
			{
				tease = "Wrong guess... You're running out of chances player 1...";
				att--;
			}
		}
		else
		{
			cout << "Give your answer: ";
			cin >> answer1;

			if(answer1 != word2)
			{
				clear();
				cout << "You'll pay for being so proud player 1..." << endl;
				delay();
				clear();
				att = 0;
			}
			else
			{
				clear();
				cout << "You're right... Pray for player 2 to be dumber than you..." << endl;
				delay();
				fake1 = word2;
			}
		}
	}

	if(att == 0)
		v1 = 0;
	else
		v1 = 1;

	tease = "You're alone in this player 2... Good luck... You'll need";
	att = 1;

	while(att > 0 && fake2 != word1)
	{	
		clear();
		cout << tease << endl;
		delay();
		cout << "Word:" << fake2 << " (SIZE:" << word1.size() << ")" << endl; 
		cout << "Attempts counter: " << att << endl;
		cout << "Press 1 to take a guess or 2 to take your chances..." << endl;
		cin >> x;

		if(x == "1")
		{
			cout << "Your guess:";
			cin >> guess2;
		
			int cont = 0;
	
			for(int i = 0; i < word1.size(); i++)
			{
				if(guess2 == word1[i] || guess2 == word1[i] - 32)
				{
					fake2[i] = word1[i];
					cont++;
				}
			}
	
			if(cont > 0)
				tease = "You got one... Don't get too excited player 2...";
			else
			{
				tease = "Wrong guess... You're running out of chances player 2...";
				att--;
			}
		}
		else
		{
			cout << "Give your answer: ";
			cin >> answer2;

			if(answer2 != word1)
			{
				clear();
				cout << "You'll pay for being so proud player 2..." << endl;
				delay();
				clear();
				att = 0;
			}
			else
				fake2 = word1;
		}
	}

	if(att == 0)
		v2 = 0;
	else
		v2 = 1;

	if(v1 == v2)
	{
		clear();
		cout << "You're both trying to lose... Someone needs to win..." << endl;
		delay();
		return 0;
	}	
	else
	{
		if(v1 > v2)
			return 1;
		else
			return 2;
	}
}

int choice(int op)
{
	switch(op)
	{
		case 1:
		{
			clear();
			string mode;
			int aux;
			modeMenu();
			cin >> mode;
			while(mode != "1" && mode != "4" && mode != "2" && mode != "3")
			{
				clear();
				cout << "Don't underestimate me boy..." << endl;
				delay();
				delay();
				clear();
				modeMenu();
				cin >> mode;
			}

			if(mode == "1")
				aux = 1;
			else if(mode == "2")
				aux = 2;
			else if(mode == "3")
				aux = 3;
			else
				aux = 4;

			pair<string,int> info = selectInfo(aux*4);
			string fake;

			for(int i = 0; i < aux*4; i++)
			{
				fake += "_";
			}

			return single(fake, info.first, aux, info.second);
		}

		case 2:
		{
			string word1, word2, fake1, fake2;

			clear();

			cout << "Player 1... Challenge your opponent: ";
			cin >> word1;

			for(int i = 0; i < word1.size(); i++)
			{
				fake2 += "_";
			}

			clear();

			cout << "Player 2... Challenge your opponent: ";
			cin >> word2;

			for(int i = 0; i < word2.size(); i++)
			{
				fake1 += "_";
			}

			return versus(word1, word2, fake1, fake2);
		}
	}
}

int loss()
{
	int op;

	do
	{
		cout << "You're a loser... "<< endl;
		delay();
		cout << "You gave up already ?..." << endl;
		delay();
		cout << "Or want to go deeper ?" << endl;
		delay();
		cout << "1 - I give up" << endl << "2 - I want to go deeper" << endl;

		cin >> op;

		if(op != 1 && op != 2)
		{
			clear();
			cout << "Don't underestimate me boy..." << endl;
			delay();		
			delay();
			clear();
		}

	}while(op != 1 && op != 2);

	clear();

	return op;
}

int win()
{

	int op;

	do
	{
		cout << "You're leaving with the joy today..." << endl;
		delay();
		cout << "Do you want more glory ?..." << endl;
		delay(); 
		cout << "Or want to be just one more ?..." << endl;
		delay();
		cout << "1 - Give me more" << endl << "2 - I'm done" << endl;

		cin >> op;

		if(op != 1 && op != 2)
		{
			clear();
			cout << "Don't underestimate me boy..." << endl;
			delay();
			delay();
			clear();
		}

	}while(op != 1 && op != 2);	

	clear();

	return op;
}

void infoMenu()
{
	clear();
	cout << "That's a road without end..." << endl;
	delay();
	delay();
	cout << "Don't rely on luck... There's no such thing..." << endl;
	delay();
	delay();
	cout << "Only the winners will come back..." << endl;
	delay();
	delay();
	cout << "No mercy for losers..." << endl;
	delay();
	delay();
	cout << "Accept the challenge or suffer with the consequences" << endl;
	delay();
	delay();
	cout << "1 - I accept" << endl << "2 - ..." << endl;
}