#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

//funkcje
// int funkcja(int **&board,int wymiar_x,int wymiar_y, int x,int y)
// 	{
//         int w = 0;
		//wskaznik na wskaznik
		//int x = 1, y = 1;
		//for (int i = wymiar_x * wymiar_y; i > 0; i--)
		//{
			// if (board[x + 1][y] = 1) w ++;
			// if (board[x + 1][y + 1] = 1) w ++;
			// if (board[x][y+1] = 1) w ++;
			// if (board[x-1][y+1] = 1) w ++;
			// if (board[x - 1][y] = 1) w ++;
			// if (board[x - 1][y-1] = 1) w ++;
			// if (board[x][y-1] = 1) w ++;
			// if (board[x+1][y-1] = 1) w ++;
			// if (x < wymiar_x-1)x++;
			// else x = 0 y++;
			// //w is total amount of neighbours
			// return w;
        //}
	// 	for (int i = 8; i < 0; i--)
	// 	{
	// 		if (board[x + 1][y] = 1) w ++;
	// 		if (board[x + 1][y + 1] = 1) w ++;
	// 		if (board[x][y+1] = 1) w ++;
	// 		if (board[x-1][y+1] = 1) w ++;
	// 		if (board[x - 1][y] = 1) w ++;
	// 		if (board[x - 1][y-1] = 1) w ++;
	// 		if (board[x][y-1] = 1) w ++;
	// 		if (board[x+1][y-1] = 1) w ++;
	// 		if (x < wymiar_x-1)x++;
	// 		else x = 0 ;y++;
	// 		//w is total amount of neighbours
		
			
	// 	}	
	// 	return w;
    // }

void goDie(int **&base, int x, int y)
{
    base[x][y]=0;
}
void Born(int **&base,int x, int y)
{
    base[x][y]=1;
}

int Check(int **&board,int x, int y)
{
  
    return board[x + 1][y]+board[x + 1][y + 1]+board[x][y+1] +board[x-1][y+1] +board[x - 1][y]+board[x - 1][y-1] +board[x][y-1]+board[x+1][y-1];
}    


int main(int argc, char const *argv[])
{


    int wymiar_x, wymiar_y, ilosc_na_start;
    cout<<"Wpisz wymiar x tablicy: ";
    cin>>wymiar_x;
    cout<<"Wpisz wymiar y tablicy: ";
    cin>>wymiar_y;
    cout<<"Wpisz ilosc punktow na start: ";
    cin>>ilosc_na_start;
    int start[ilosc_na_start][2];
    wymiar_x=wymiar_x+1;
    wymiar_y=wymiar_y+1;

    int ** board = new int * [wymiar_x];
    for(int i = 0; i<wymiar_x;i++)
    {
        board[i] = new int[wymiar_y];
    }


    cout<<"Czas podać koordynaty:"<<endl;
    for (int i = 0; i < ilosc_na_start; i++)
    {
        int tempx=0;
        int tempy = 0;
        cout<<"Koordynat x"<<i<<": "<<endl;
        cin>>tempx;
        cout<<"Koordynat y"<<i<<": "<<endl;
        cin>>tempy;
        //tempx=tempx+1;
        //tempy=tempy+1;
        board[tempx][tempy]=1;
    }
    // cout<<funkcja(board,wymiar_x,wymiar_y,1,1)<<endl;
//
//
// cout<<"##########PRZED:#################"<<endl;

// for (int i = 1; i < wymiar_x; i++)
// {
//    for (int j = 1; j < wymiar_y; j++)
//    {
//        cout<<board[i][j];
//    }
//    cout<<"1"<<endl;
// }

// TODO: tablicę jako matrycę
// cout<<"############################"<<endl;

    for (;;)
    {
        int ** basescreen = new int * [wymiar_x];
    for(int i = 0; i<wymiar_x;i++)
    {
        basescreen[i] = new int[wymiar_y];
    }
        for (int i = 0; i < wymiar_x; i++)
    {
        for (int j = 0; j < wymiar_y; j++)
        {
            basescreen[i][j]=board[i][j];
        }
        
    }
        for (int i = 1; i < wymiar_x-1; i++)
        {
        // cout<<"1"<<endl;
            for (int j = 1; j < wymiar_y-1; j++)
            {
            // cout<<"2"<<endl;
                int neighbours = Check(board,i,j);
                if (neighbours<2)
                {
                // cout<<"2.1"<<endl;
                    goDie(basescreen,i,j);
                }
                else if (neighbours == 3)
                {
                // cout<<"2.2"<<endl;
                    Born(basescreen,i,j);
                }
                else if (neighbours>3)
                {
                    goDie(basescreen,i,j);
                }
                // if (neighbours == 2)
                // {
                    // basescreen[i][j] =1;
                // }
            }
        }
    for (int i = 0; i < wymiar_x; i++)
    {
        for (int j = 0; j < wymiar_y; j++)
        {
            board[i][j]=basescreen[i][j];
        }
        
    }
    delete[] basescreen;
    for (int k = 0; k<=10; k++)
    {
        system("clear");
        for (int i = 1; i < wymiar_x; i++)
        {
            for (int j = 1; j < wymiar_y; j++)
            {
                cout<<board[i][j];
            }
            cout<<endl; 
        }
        this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}






//
// cout<<"##########PO:#################"<<endl;

// for (int i = 1; i < wymiar_x; i++)
// {
//    for (int j = 1; j < wymiar_y; j++)
//    {
//        cout<<board[i][j];
//    }
//    cout<<endl;
// }


// cout<<"############################"<<endl;
    return 0;
}
