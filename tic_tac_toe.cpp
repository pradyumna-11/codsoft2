#include<iostream>
using namespace std;

void display_board(char g[][3]) {
	
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			cout<<g[i][j]<<" | ";
		}
		cout<<"\n------------\n";
	}
}

void display_game_rules(int a[][3]){
	cout<<"\nGame rules for selecting position"<<endl;
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			cout<<a[i][j]<<" | ";
		}
		cout<<"\n------------\n";
	}
	cout<<"\nWhenever you want to choose a position select the position number as mentioned above position numbers"<<endl;
	cout<<"\'E\' represents position is not occupied by any player\n\n";
}

bool check_row(char g[][3],int rno,char c) {
	if(g[rno][0]==c&&g[rno][1]==c&&g[rno][2]==c) {
		return true;
	}
	return false;
}

bool check_col(char g[][3],int cno,char c) {
	if(g[0][cno]==c&&g[1][cno]==c&&g[2][cno]==c) {
		return true;
	}
	return false;
}

bool check_diagonal(char g[][3],char c) {
	if(g[0][0]==c&&g[1][1]==c&&g[2][2]==c) {
		return true;
	}

	if(g[0][2]==c&&g[1][1]==c&&g[2][0]==c) {
		return true;
	}

	return false;
}



int get_rno(int a[][3],int no) {
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			if(a[i][j]==no) {
				return i;
			}
		}
	}
	return -1;
}

int get_cno(int a[][3],int no) {
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			if(a[i][j]==no) {
				return j;
			}
		}
	}
	return -1;
}

int main() {
	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}},t=1,xin,oin,rno,cno;
	char g[3][3] = {'E','E','E','E','E','E','E','E','E'},option;
	bool is_won = false;
	display_game_rules(a);
	do {
			while(t<=9) {
		for(int i=0;i<3;i++) {
			if(check_row(g,i,'x')||check_col(g,i,'x')||check_diagonal(g,'x')) {
				display_board(g);
				cout<<"X won the game";
				is_won = true;
				break;
			}
			else if(check_row(g,i,'o')||check_col(g,i,'o')||check_diagonal(g,'o')) {
				display_board(g);
				cout<<"O won the game";
				is_won= true;
				break;
			}
		}
		if(is_won) {
			break;
		}
				display_board(g);
				if(t%2==0) {
					cout<<"\nx turn enter a number b/w 1 to 9 which are availabe from board to replace choice : ";
					cin>>xin;
					rno = get_rno(a,xin);
					cno = get_cno(a,xin);
					
					if(xin<=9 && rno!=-1 && cno!=-1) {
						if(g[rno][cno]=='E') {
							g[rno][cno] = 'x';
							t+=1;
						}
						else{
							cout<<"\nPlace already occupied";
						}
					}
					else{
						cout<<"\nEnter a valid input\n";
					}
				}
				else{
					cout<<"\no turn enter a number b/w 1 to 9 which are availabe from board to replace choice : ";
					cin>>oin;
					rno = get_rno(a,oin);
					cno = get_cno(a,oin);
					if(oin<=9 && rno!=-1 && cno!=-1) {
						if(g[rno][cno]=='E') {
							g[rno][cno] = 'o';
							t+=1;
						}
						else{
							cout<<"\nPlace already occupied";
						}
					}
					else{
						cout<<"\nEnter a valid number\n";
					}
				}
			
			}
			if(!is_won) {
				display_board(g);
				cout<<"\nGame Over and the match is draw";
			}
			cout<<"\nPress y to play another match and n to exit : ";
			cin>>option;
			if(option=='y') {
				is_won = false;
				t=1;
				display_game_rules(a);
				for(int i=0;i<3;i++) {
					for(int j=0;j<3;j++) {
						g[i][j] = 'E';
					}
				}
			}
	}while(option!='n');

	
	return 0;
}
