#include <iostream>

using namespace std;

bool someoneWon=false;

char const BLANK = '.';
char board [9] = {BLANK,BLANK,BLANK,
				  BLANK,BLANK,BLANK,			
			      BLANK,BLANK,BLANK};
			
char const HUMAN_PLAYER_SYM = 'X'; 
char const CPU_PLAYER_SYM = 'O';
char start;

void intro() { //welcomes user to the game
			
	cout << "Welcome to Tic-Tac-Toe vs a computer!\n";
	cout << "[Press x to continue]"<<endl;			
	cin >> start;	
	
}				
void displayBoard() {
	cout << endl;			
	cout << board[0] << "  | " << board[1] << " |  " << board[2] <<endl;
	cout << "--" << " | " << "-" << " | " << "--" <<endl;
	cout << board[3] << "  | " << board[4] << " |  " << board[5] <<endl ;
	cout << "--" << " | " << "-" << " | " << "--" <<endl;
	cout << board[6] << "  | " << board[7] << " |  " << board[8] <<endl ;
	cout << "  " << " | " << " " << " | " << "  " <<endl;
	
}
void usersTurn(){ //user = X
	
	int usersChoice;
	do {
			cout << "It is your turn, enter your X (0-8): "<<endl;
			cin>>usersChoice;
		} 
		while (board[usersChoice]!=BLANK); //if the spot is not empty, allow the human user to continue going
		board[usersChoice]=HUMAN_PLAYER_SYM;
		cout <<"You chose spot "<<usersChoice<<endl;	

}

void computersTurn() {
	int computersChoice;
do { //allows the computer to pick a random spot
		srand((unsigned) time(0));
		computersChoice = 1 + (rand() % 9);
	} 
	while (board[computersChoice]!=BLANK); //if the spot is not empty, this allows the computer to continue picking a spot
	board[computersChoice]=CPU_PLAYER_SYM; //once it is determined that the chosen spot is blank, it is set with an 'O'
	cout <<"The computer chose spot "<<computersChoice<<endl;	
}	

void CheckForWinner(){ //checks for winners 
	if ((board[0]==HUMAN_PLAYER_SYM)&&(board[1]==HUMAN_PLAYER_SYM)&&(board[2]==HUMAN_PLAYER_SYM)||(board[3]==HUMAN_PLAYER_SYM)&&(board[4]==HUMAN_PLAYER_SYM)&&(board[5]==HUMAN_PLAYER_SYM)||(board[6]==HUMAN_PLAYER_SYM)&&(board[7]==HUMAN_PLAYER_SYM)&&(board[8]==HUMAN_PLAYER_SYM)||(board[0]==HUMAN_PLAYER_SYM)&&(board[3]==HUMAN_PLAYER_SYM)&&(board[6]==HUMAN_PLAYER_SYM)||(board[1]==HUMAN_PLAYER_SYM)&&(board[4]==HUMAN_PLAYER_SYM)&&(board[7]==HUMAN_PLAYER_SYM)||(board[2]==HUMAN_PLAYER_SYM)&&(board[5]==HUMAN_PLAYER_SYM)&&(board[8]==HUMAN_PLAYER_SYM)||(board[0]==HUMAN_PLAYER_SYM)&&(board[4]==HUMAN_PLAYER_SYM)&&(board[8]==HUMAN_PLAYER_SYM)||(board[6]==HUMAN_PLAYER_SYM)&&(board[4]==HUMAN_PLAYER_SYM)&&(board[2]==HUMAN_PLAYER_SYM)){
		cout<<endl;
		cout<<"You won!"<<endl;
		someoneWon=true;
	}
	if ((board[0]==CPU_PLAYER_SYM)&&(board[1]==CPU_PLAYER_SYM)&&(board[2]==CPU_PLAYER_SYM)||(board[3]==CPU_PLAYER_SYM)&&(board[4]==CPU_PLAYER_SYM)&&(board[5]==CPU_PLAYER_SYM)||(board[6]==CPU_PLAYER_SYM)&&(board[7]==CPU_PLAYER_SYM)&&(board[8]==CPU_PLAYER_SYM)||(board[0]==CPU_PLAYER_SYM)&&(board[3]==CPU_PLAYER_SYM)&&(board[6]==CPU_PLAYER_SYM)||(board[1]==CPU_PLAYER_SYM)&&(board[4]==CPU_PLAYER_SYM)&&(board[7]==CPU_PLAYER_SYM)||(board[2]==CPU_PLAYER_SYM)&&(board[5]==CPU_PLAYER_SYM)&&(board[8]==CPU_PLAYER_SYM)||(board[0]==CPU_PLAYER_SYM)&&(board[4]==CPU_PLAYER_SYM)&&(board[8]==CPU_PLAYER_SYM)||(board[6]==CPU_PLAYER_SYM)&&(board[4]==CPU_PLAYER_SYM)&&(board[2]==CPU_PLAYER_SYM)){						cout<<endl;
			cout<<"The computer won!"<<endl;
			someoneWon=true;
	}
	
}
void PlayAgain(){
	cout << "[Press x to reset the board and play again!]"<<endl;			
	cin >> start;
	if (start=='x'||start=='X') {
		someoneWon=false;
		for (int i = 0; i < 9; i++)
			board[i] = BLANK;         //resets all spots to blank

	}
}

int main(){
	intro();
	while(start=='x' || start=='X') {
	while(someoneWon==false){
		usersTurn();
		displayBoard(); //display board after human user's pick
		CheckForWinner();
		if(someoneWon==true){ //if the human player happens to win, the while loop will end midway w/o continuing
			break;
		}
		computersTurn(); 
		displayBoard();//display board after computers's pick
		CheckForWinner();
	}
		PlayAgain();
	}

}



/*
Tic-Tac-Toe game between a human and the computer.

Place the Tac-Tac-Toe board in an array of char (e.g., char board[9] ) and use functions to create "operations" from which you can build a game (see class notes, for example: reset(), Go(), display(), etc.... avoid an over used of global variables, use constants instead of pure numbers or characters, provide comments for other programmers to see how your code works.
*/