#include<iostream.h>
#include<conio.h>

char a[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char t ='X';
int r ,c;
int d =0;

void display(char p1, char p2)
{
	clrscr();
	cout<<"\t\t\t\tT I C   T A C   T O E"<<endl;
	cout<<endl;
	cout<<"\t\t\t"<<p1<<"[X]"<<endl;
	cout<<"\t\t\t"<<p2<<"[O]"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t     |     |     "<<endl;
	cout<<"\t\t\t\t  "<<a[0][0]<<"  |  "<<a[0][1]<<"  |  "<<a[0][2]<<"  "<<endl;
	cout<<"\t\t\t\t_____|_____|_____"<<endl;
	cout<<"\t\t\t\t     |     |     "<<endl;
	cout<<"\t\t\t\t  "<<a[1][0]<<"  |  "<<a[1][1]<<"  |  "<<a[1][2]<<"   "<<endl;
	cout<<"\t\t\t\t_____|_____|_____"<<endl;
	cout<<"\t\t\t\t     |     |     "<<endl;
	cout<<"\t\t\t\t  "<<a[2][0]<<"  |  "<<a[2][1]<<"  |  "<<a[2][2]<<"   "<<endl;
	cout<<"\t\t\t\t     |     |     "<<endl;
}

void player(char p1,char p2)
{
	int n;
	if (t == 'X')
		cout<<"\n \t "<<p1<<"[X] turn:";
	if(t == 'O')
		cout<<"\n \t "<<p2<<"[O] turn:";
	cin>>n;
	switch(n)
	{
		case 1:
			r =0;
			c =0;
			break;
		case 2:
			r =0;
			c =1;
			break;
		case 3:
			r =0;
			c =2;
			break;
		case 4:
			r =1;
			c =0;
			break;
		case 5:
			r =1;
			c =1;
			break;
		case 6:
			r =1;
			c =2;
			break;
		case 7:
			r =2;
			c =0;
			break;
		case 8:
			r =2;
			c =1;
			break;
		case 9:
			r =2;
			c =2;
			break;
		default:
		cout<<"invalid no."<<endl;
			break;
	}

	if(t == 'X'&& a[r][c] != 'X' && a[r][c] !='O')
	{
		a[r][c] = 'X';
		t = 'O';
	}
	else
	if(t == 'O'&& a[r][c] != 'X' && a[r][c] !='O')
	{
		a[r][c] = 'O';
		t = 'X';
	}
	else
	{
		cout<<"BOX already filled"<<endl<<"pls... Try again"<<endl;
		player(p1,p2);
	 }

}


int result()
{
	//row and column winner decide
	for(int i =0; i<3; i++)
		{
			if(a[i][0] == a[i][1] && a[i][0] == a[i][2] || a[0][i] == a[1][i] && a[0][i] == a[2][i])
			{
				return 0;
			 }
		}

	//diagonally winner

	if(a[0][0]==a[1][1] && a[0][0]==a[2][2] || a[0][2]==a[1][1] && a[0][2]==a[2][0])
		{
			return 0;
		}
	//to check blank block
	for(i =0; i<3; i++)
		 {	for(int j =0; j<3; j++)
			 {	if(a[i][j] != 'X' && a[i][j] != 'O')
				return  1;
			 }
		 }
	d= 1;
	return 0;
}

void main()
{
	char p1,p2;

		cout<<"Enter Player1 Name: ";
		cin>>p1;
		cout<<endl<<"Enter Player2 Name: ";
		cin>>p2;
		cout<<endl;

	while(result())
	{
		display(p1,p2);
		player(p1,p2);
		display(p1,p2);
		result();
	}
	if(t == 'X'&& d==0)
		cout<<"\n\n\t\t\tWinner Winner Winner....\n\t\t\t"<<p2<<" is a Winner...CONGRATULATIONS...!!!"<<endl;
	else
	if(t == 'O'&& d==0)
		cout<<"\n\n\t\t\tWinner Winner Winner....\n\t\t\t"<<p1<<" is a Winner...CONGRATULATIONS...!!!"<<endl;
	else
		cout<<"\n\n\t\t\tGAME DRAW...!!!"<<endl;


getch();
}