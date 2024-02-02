#include<iostream>
using namespace std;
char arr[8][8];
char player = 'B';
bool wh = false;
void menu()
{
	cout << endl;
	cout << endl;
	cout << "                                             1.Press 1 to Play!\n";
	cout << "                                             2.Press 2 for Credit.\n";
	cout << "                                             3.Press 3 INSTRUCTION.\n";
	cout << "                                             4.Press 4 to EXIT.\n";
}
void credit()
{

	cout << " ________________  \n";
	cout << " |Made by Nayyar Maqsood Abbasi & Umair Afzal| \n";
	cout << " -------------------------------------------- \n";
}
void instruction()
{
	cout << " First turn is for Player A and Second turn is for Player B.\n";
	cout << " If you connect your coin Vertically 4, Horizanty 4 or Diagonally 4 then player Win the game.\n";
	cout << " If both the player will not win the game then game will Draw.\n ";
}
void Initialize()
{
	for (int i = 0; i < 8; i++) // Print the 8*8  grid in which game will be played
	{
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = '*';
		}
	}
}
void Shape() {
	// prints for the first time
	//prints column numbers
	for (int i = 0; i < 8; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	//prints the number of 8*8 array
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
void Set()
{
	if (player == 'A')
	{
		player = 'B';
	}
	else
	{
		player = 'A';
	}
	int column;
	cout << "Enter column = ";
	cin >> column; // input th column in which we want to take 
	for (int i = 7; i >= 0; i--)
	{
		if (arr[i][column] == '*')
		{
			arr[i][column] = player;
			return;
		}
	}
}
void Win()// In this function all the condition are defined  
{
	int Sum = 0;//horizontal sum condition of the horizantal sum
				//horizontal and the sum is 4 in horizantal the player will win the game 
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == player)
			{
				Sum++;
				if (Sum == 4)
				{
					wh = true;
					Sum = 0;
					return;
				}
			}
			else
				Sum = 0;
		}
	}
	// Vertical if the coin of player sitting next to each other vertically
	// and the sum is 4 in vertically the player will win the game 
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) {
			if (arr[j][i] == player)
			{
				Sum++;
				if (Sum == 4)
				{
					wh = true;
					Sum = 0;
					break;
				}
			}
			else {
				Sum = 0;
			}
		}
	}
	/* Diagonal_1 if the coin of the player match diagonally in
	one direction and sum is equal to 4 then player will win the game */

	for (int i = 0; i < 8; i++)
	{
		if (arr[i][i] == player)
		{
			Sum++;
			if (Sum == 4)
			{
				wh = true;
				Sum = 0;
				break;
			}
		}
		else
		{
			Sum = 0;
		}
	}
	/*Diagonal_2 if the coin of the player match diagonally in one
	direction and sum is equal to 4 then player will win the game */
	for (int i = 7, k = 0; i >= 0; i--, k++)
	{
		for (int j = k; j <= k; j++)
		{
			if (arr[i][j] == player)
			{
				Sum++;
				if (Sum == 4) // if sum is equal to 4 the it will break the loop
				{
					wh = true;
					Sum = 0;
					break;
				}
			}
			else {
				Sum = 0;
			}
		}
	}
}
int main()
{

	int select = 0;
	char ch; // player A and B
	do {
		system("cls");
		menu();
		cout << endl << endl << "                                             Enter option from menu: ";
		cin >> select;
		if (select == 1)// if the input is 1 then game will play
		{
			Initialize();
			while (true)
			{
				system("cls");
				Shape();
				Set();
				Win();
				if (wh)
				{
					system("cls");
					Shape();
					cout << "Player " << player << " won the game!" << endl;
				}
				if (wh)
				{
					break;
				}
			}
			cout << endl << "Enter any key to go back to menu: ";
			cin >> ch;
		}
		else if (select == 2) // If input is 2 the credit will show
		{
			system("cls");
			credit();
			cout << endl << "Enter any key to go back to menu: ";
			cin >> ch;
		}
		else if (select == 3) // If player will input 3 the instruction show
		{
			system("cls");
			instruction();
			cout << endl << "Enter any key to go back to menu: ";
			cin >> ch;
		}
	} while (select != 4);// if player will input 4 the game will exit
	system("pause");
	return 0;
}