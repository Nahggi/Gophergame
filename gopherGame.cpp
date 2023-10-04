//Nagendra Chaudhary
//11-14-2021

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int cols = 10;
const int rows = 10;

void print(int [rows][cols], int[rows][cols]);
int count(int [rows][cols], int, int);

int main(){
   
   int gophers[rows][cols];
   int guess[rows][cols];
   srand(time(0)); // 'seed' the random number generator with current time
   cout << "Welcome to the adventure of Zombies"<<endl;
   cout << "*******************************************"<<endl;
   cout << "The ZOmbies are sleeping and you have to clear and if you fall in the trap then you are dead"<< endl;
   cout << "Press Enter to continue"<<endl;
   cin.ignore();
   cout << "If you have Played Minesweeper then this is similar to that but with the twist of Zombies"<<endl;
   cout << "Just guess the Tiles and enjoy The GAME"<< endl;
   cout << "press Eneter to continue!!"<<endl;
   cin.ignore();
   cout << "The unexplored areas are represented by '+' in the board"<<endl;
   cout << "If you land on MInes or any other traps then you are finished\n so Be careful when guessing the TIles"<<endl;
   cout << "Now if you are read then press enter to enjoy the game"<<endl;
   cin.ignore();
   for(int r = 0; r < rows; r++){
      for(int c = 0; c < cols; c++){
         if(rand()%10 < 1){
            gophers[r][c] = 1;
         } else {
            gophers[r][c] = 0;
         }
         guess[r][c] = 1;
      }
   }
   guess[1][3] = 1;
   print(gophers, guess);
   // add gophers  
   

   char  board_game[rows][cols];
 for (int r=0;r<rows;r++)
 {
  for(int j=0;j<cols;j++)
  {
   board_game[r][j]= '+';
   cout<< board_game[r][j]<<" ";
   }
  cout<<endl;
}
        
   // add fog of war
  int x=-1,y=-1;
  bool game = true;
  do{
   //while((x<0) || x>(cols-1))
   // {
     cout<<"Provide the x-cordinate to move the player(0 to 10): "<<endl;
     cin>>x;
   // } 
    // while((y<0) || y>(rows-1))
    //{
      cout<<"Provide the y-cordinates to move the player(0 to 10): "<<endl;
      cin>>y;
   // }
     if(gophers[y][x]==1)
      { 
       cout << "Damn! you fell right into the LandMine"<<endl;
       cout << "You are DEAD!"<<endl;
       cout<<"Your Game Is Over ";
       game=false;
        }
     else
      {
        board_game[y][x]= count(gophers,y,x)+ '0';
        for (int r=0;r<rows;r++)
        {
           for(int j=0;j<cols;j++)
           {
              cout<< board_game[r][j]<<" ";
           }
           cout<<endl;
        }
      }
  
 }
   while(game);
   // print instructions 
   // print board
   // game loop
   //   player guesses
   //   if gopher lose
   //   print board
   // end game loop
   for(int row = 0; row < rows; row++){
      for(int column = 0; column < cols; column++){
         if(rand()%10 < 1){
            gophers[row][column] = 1;
         } else {
            gophers[row][column] = 0;
         }
         guess[row][column] = 1;
      }
   }

}
int count(int a[rows][cols], int r, int c){
   int count = 0;
   if(r > 0 && c > 0){
     if(a[r-1][c-1] == 1){  
        count++;
     }
   }
   if(r > 0){
      if(a[r-1][c] == 1){   
        count++;
      }
   }
   if(r > 0 && c < (cols-1)){
      if(a[r-1][c+1] == 1){
        count++;
    }
   }
 if(  c < (cols-1)){
      if(a[r][c+1] == 1){
        count++;
    }
   }
if(  r < (rows-1)){
      if(a[r+1][c] == 1){
        count++;
    }
   }
 if(c > 0){
      if(a[r][c-1] == 1){
        count++;
    }
   }
 if(r < (rows-1) && c > 0){
      if(a[r+1][c-1] == 1){
        count++;
    }
   }
 if(r < (rows-1) && c < (cols-1)){
      if(a[r+1][c+1] == 1){
        count++;
    }
   }

   return count;
}

void print(int a[rows][cols], int guessed[rows][cols]){
   for(int row = 0; row < rows; row++){
      for(int column = 0; column < cols; column++){
         if(a[row][column] == 1){ 
            cout << "g";
         } else {
           if(guessed[row][column]){
              cout << count(a,row,column);
           } else { 
              cout << "X";
           }
        }
      }
      cout << endl;
   }
}

