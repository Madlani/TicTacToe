/*
 * main.cpp
 *
 *  Created on: Dec 29, 2018
 *      Author: Marwane
 */

#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

char matrix [3][3] = {'1','2','3','4','5','6','7','8','9'}; //Will represent tic tac toe board as 3x3 matrix of #s

char playerTurn = 'X'; //X starts out the game first

int numChars; //represents number of characters on board, when = 9, if no winner, there's a draw

void createBoard(){
	system("cls");
	cout <<"Simple Tic Tac Toe, press any #1-9 that isn't in use!"<<endl;
	for (int i = 0; i<3; i++){
		for (int j = 0; j<3 ; j++){
			cout <<matrix[i][j]<< " "; //prints out the board
		}
		cout<<endl; //adds a line to only print 3 values per line
	}
}

void userInput(){
	int readIn;
	//cout<<"Press the number representing the location that you want to place your symbol at";
	cin >>readIn;

	//if a player chooses to place their value at readIn, then their symbol will be placed there
	//can probably concatenate these to make it smaller somehow
	if (readIn == 1){
		if (matrix [0][0] == '1'){
			matrix [0][0] = playerTurn;
		}
		else {
			cout <<"This location is already occupied. Please try again!"<<endl;
			userInput();
		}
	}

	else if (readIn == 2){
		if (matrix [0][1] == '2'){
				matrix [0][1] = playerTurn;
			}
			else{
				cout <<"This location is already occupied. Please try again!"<<endl;
				userInput();
			}	}

	else if (readIn == 3){
		if (matrix [0][2] == '3'){
				matrix [0][2] = playerTurn;
			}
			else{
				cout <<"This location is already occupied. Please try again!"<<endl;
				userInput();
			}	}

	else if (readIn == 4){
		if (matrix [1][0] == '4'){
				matrix [1][0] = playerTurn;
			}
			else{
				cout <<"This location is already occupied. Please try again!"<<endl;
				userInput();
			}	}

	else if (readIn == 5){
		if (matrix [1][1] == '5'){
				matrix [1][1] = playerTurn;
			}
			else{
				cout <<"This location is already occupied. Please try again!"<<endl;
				userInput();
			}	}

	else if (readIn == 6){
		if (matrix [1][2] == '6'){
				matrix [1][2] = playerTurn;
			}
			else{
				cout <<"This location is already occupied. Please try again!"<<endl;
				userInput();
			}	}

	else if (readIn == 7){
		if (matrix [2][0] == '7'){
				matrix [2][0] = playerTurn;
			}
			else{
				cout <<"This location is already occupied. Please try again!"<<endl;
				userInput();
			}	}

	else if (readIn == 8){
		if (matrix [2][1] == '8'){
				matrix [2][1] = playerTurn;
			}
			else{
				cout <<"This location is already occupied. Please try again!"<<endl;
				userInput();
			}	}

	else if (readIn == 9){
		if (matrix [2][2] == '9'){
			matrix [2][2] = playerTurn;
		}
		else{
			cout <<"This location is already occupied. Please try again!"<<endl;
			userInput();
		}
	}
}

void changeTurn(){ //call this function once a player goes, it simply changes the turn to the other players turn
	if (playerTurn == 'X'){
		playerTurn = 'O';
	}
	else{
		playerTurn = 'X';
	}
}

char Win(){

	/*if (((matrix [0][0]) == 'X')&&((matrix [0][1])  == 'X') &&((matrix [0][2]) == 'X')){//might just be able to compare both x and o same line
	}
	*/

	//tests case if top 3 are same
	if (((matrix [0][0]) == (matrix [0][1]) &&((matrix [0][1]) == matrix[0][2]))){
		return matrix[0][0]; //works same as cout, just returns the X or O
		//cout <<matrix[0][0]<< " has won!"; //regardless of if it's 3 x or 3 o up top, this will print the winner
	}

	//tests case if left columns are same
	if (((matrix [0][0]) == (matrix [1][0]) &&((matrix [1][0]) == matrix[2][0]))){
			return matrix[0][0]; //works same as cout, just returns the X or O
		}

	//tests case if middle columns are same
	if (((matrix [0][1]) == (matrix [1][1]) &&((matrix [1][1]) == matrix[2][1]))){
				return matrix[0][1]; //works same as cout, just returns the X or O
			}

	//tests case if right columns are same
	if (((matrix [0][2]) == (matrix [1][2]) &&((matrix [1][2]) == matrix[2][2]))){
				return matrix[0][2]; //works same as cout, just returns the X or O
			}

	//tests case if bottom left to top right corners are same
	if (((matrix [2][0]) == (matrix [1][1]) &&((matrix [1][1]) == matrix[0][2]))){
				return matrix[0][2]; //works same as cout, just returns the X or O
			}

	//tests case if bottom right to top left are same
	if (((matrix [2][2]) == (matrix [1][1]) &&((matrix [1][1]) == matrix[0][0]))){
				return matrix[0][0]; //works same as cout, just returns the X or O
			}

	return 'Z';
}

int main(){

	numChars = 0;

	createBoard();
	while (true){
		numChars++;
		userInput();
		system("cls");
		createBoard();
		if (Win() == 'X'){
			cout<<"Player X wins!"<<endl;
			break;
		}
		else if (Win() == 'O'){
			cout<<"Player O wins!"<<endl;
			break;
		}
		else if (Win() == 'Z' && numChars == 9){
			cout <<"The game is a draw"<<endl;
		}
		changeTurn();
	}

	return 0;
}
