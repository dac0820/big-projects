#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
//game board
char board[3][3];
int a,b,p,q;

//random computer choice
struct random
{   
  
    int i = rand()%3;
    int j = rand()%3;
};
void random_gen(){
    srand(time(0));
    struct random r;
    ::p=r.i,::q=r.j;
}
//conveter to user to board
int converter(int a){
    if(a == 1){
      board[0][0] ='x';
    return 0;}
    else if(a == 2){
      board[0][1]='x';
      return 0;}
    else if(a == 3){
      board[0][2]='x';
      return 0;}  
    else if(a == 4){
      board[1][0]='x';
      return 1;}
    else if(a == 5){
      board[1][1]='x';
      return 1;}
    else if(a == 6){
      board[1][2]='x';
      return 1;}
    else if(a == 7){
      board[2][0]='x';
      return 2;}
    else if(a == 8){
      board[2][1]='x';
      return 2;}
    else if(a == 9){
      board[2][2]='x';
      return 2;}
    else{
        printf("invalid choice");
        return 0;
    }
} 

int computer_user(int temp){
    if(temp<4){return 0;}
    else if(temp<7){return 1;}
    else{return 2;}
}
int comp_converter(int a,int b){
    if(a == 0 && b == 0){
    return 0;}
    else if(a == 0 && b == 1){
    return 1;}
    else if(a == 0 && b == 2){
    return 2;}
    else if(a == 1 && b == 0){
    return 3;}
    else if(a == 1 && b == 1){
    return 4;}
    else if(a == 1 && b == 2){
    return 5;}
    else if(a == 2 && b == 0){
    return 6;}                
    else if(a == 2 && b == 1){
    return 7;}    
    else {
    return 8;}
} 
int loop_limit(int *arr){
  int sum=0;
  for (int i = 0; i < 9; i++)
    {
      sum=sum+arr[i];
    }
  if (sum==0){
    return 0;
  }
  else{
    return 1;
  }  
}
void display(){
        cout<<"+-"<<"-"<<"-+-"<<"-"<<"-+-"<<"-"<<"-+ "<<endl;
        cout<<"| "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" | "<<endl;
        cout<<"+-"<<"-"<<"-+-"<<"-"<<"-+-"<<"-"<<"-+ "<<endl;
        cout<<"| "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" | "<<endl;
        cout<<"+-"<<"-"<<"-+-"<<"-"<<"-+-"<<"-"<<"-+ "<<endl;
        cout<<"| "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" | "<<endl;
        cout<<"+-"<<"-"<<"-+-"<<"-"<<"-+-"<<"-"<<"-+ "<<endl;
}
int winner(int key){
  for (int i = key; i < 3; i++)
  {
    if (board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][2]!=NULL)
    {
      cout<<"--------------------------------------------"<<endl;
      cout<<board[i][0]<<" is winner horizontal"<<endl;
      return 0;
    }
    else if (board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[2][i]!=NULL)
    {
      cout<<"--------------------------------------------"<<endl;
      cout<<board[0][i]<<" is winner vertical"<<endl;
      return 0;
    }
    else if (board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[2][2]!=NULL)
    {
      cout<<"--------------------------------------------"<<endl;
      cout<<board[0][0]<<" is winner diagonal"<<endl;
      return 0;
    }
    else {
      return 1;
    }
  }
  
}
int easy(int a,int b){
    again:
    a=::a,b=::b;
    if(a<3){
        if(board[a][b]==NULL){
            board[a][b]='o';
        } 
        else{
            random_gen();
            ::a=::p,::b=::q;
            goto again;
        }
    }
}
int medium(int a,int b){
    again:
    a=::a,b=::b;
    if(a<3){
        if(board[a][b]==NULL){
            board[a][b]='o';
            return 0;
        } 
        else if (board[a][b+1]==NULL && b+1<3)
        {
            board[a][b+1]='o';
            return 0;
        }
        else if (board[a][b-1]==NULL && b+1>=0)
        {
            board[a][b-1]='o';
            return 0;
        }
        else{
            random_gen();
            ::a=::p,::b=::q;
            goto again;
        }
    }
}
int hard(int a,int b){
    again:
    a=::a,b=::b;
    if(a<3){
        if(board[a][b]==NULL){
            board[a][b]='o'; 
            return 0;
        }
        else if(a==b && a>=0 && a<3 ){
            if(board[a+1][b+1]==NULL){
                board[a+1][b+1]='o';
                ::a=a+1,::b=b+1;
            }
            if(board[a-1][b-1]==NULL){
                board[a-1][b-1]='o';
                ::a=a-1,::b=b-1;
            }
        }
        else if (board[a+1][b]==NULL && a+1<3)
        {
            board[a+1][b]='o';
            ::a=a+1;
            return 0;
        }
        else if (board[a-1][b]==NULL && a-1>=0)
        {
            board[a-1][b]='o';
            
            ::a=-1;
            return 0;
        }  
        else if (board[a][b+1]==NULL && b+1<3)
        {
            board[a][b+1]='o';
          
            ::b=b+1;
            return 0;
        }
        else if (board[a][b-1]==NULL && b+1>=0)
        {
            board[a][b-1]='o';
            
            ::b=b+1;
            return 0;
        }
        else{
            random_gen();
            ::a=::p,::b=::q;
            goto again;
        }
    }
}
int main(){
  //declare section
    int user_choice,choice,stop=1,ans,fill[9],count=0,key,fill_key,pointer=0,flag=0;
   
    random_gen();
    ::a=::p,::b=::q;
    //game board intizializtion
    for(int i=0;i<3;i++){
        for (int j = 0; j < 3; j++)
        {
            board[i][j]=0;
            
        }
    }
    for (int i = 0; i < 9; i++)
    {
      fill[i]=1;
    }
    cout<<"Enter game mode\n1.easy\n2.meduim\n3.hard\nchoice:-";
    cin>>choice;
while(stop==1){
    //printer
    display();
    //user choice
    user_repeat:
    cout<<"Enter choice in box:-";
    cin>>user_choice;
    if(fill[user_choice-1]==1){
      key = converter(user_choice);
      fill[user_choice-1]=0;
    }
    
    else{
      cout<<"Enter correct box"<<endl;
      goto user_repeat;
    }
    //winner
    ans=winner(key);
      if(ans==0){
    break;
    }
    //fill array initialize
    stop=loop_limit(fill);
    if(stop==0){
      break;
    }
    //dividing game mode
    switch (choice){
      case 1:
      //easy computer choice
        easy(::a,::b);
        break;
      case 2:
      //medium computer choice
        medium(::a,::b);
        break;
      case 3:
      //hard computer choice
        hard(::a,::b);
        break;
      default:
        cout<<"invalid choice";
        break;
    }
    int temp = comp_converter(::a,::b);
    key = computer_user(temp);
    //winner 
    ans=winner(key);
      if(ans==0){
    break;
    }
    //fill array initialize
    fill_key=comp_converter(::a,::b);
    if(fill[fill_key]==1){
      fill[fill_key]=0;
    }
    int tie=loop_limit(fill);
    if(tie==0){
      cout<<"it is tie";
    }
  //footer 
  stop=loop_limit(fill);
  }
cout<<"----:Final game:----"<<endl;
display();
cout<<"thank you !bye";
}