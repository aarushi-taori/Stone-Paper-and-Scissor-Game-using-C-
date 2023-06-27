#include <cstdlib> 
#include <ctime> 
#include <iostream>
using namespace std;

class game 
{
    public :
    char user_ch;
    char comp_ch;
    int count_user=0;
    int count_comp=0;
    int result;

    char User_Option();
    char Computer_choice();
    void decision(char user_ch, char comp_ch);
};

char game ::Computer_choice()
{
    int random =0;
	random = 1+ (rand() % 30);
    if (random<=10)
    {
        comp_ch = 'r';
    }
 
    else if(random>=11 && random<20)
    {
        comp_ch = 'p';
    }
    else if (random>=21 && random<=30)
    {
        comp_ch = 's';
    } 
    return(comp_ch);
}


char game :: User_Option()
{
    char user_ch;
    cout << "\nEnter r for Rock \nEnter p for paper \nEnter s for scissors\n "<<endl;;
    cin >> user_ch;
    while (user_ch != 'r' && user_ch != 'p' && user_ch != 's')
    {
        cout<<"Wrong Input !!";
        cout << "Please enter one of the following options only !!\n" << endl;
        cout << "\nEnter r for Rock \nEnter p for paper \nEnter s for scissors\n" << endl;
        cin >> user_ch;
    }

    if (user_ch=='r')
    {
        cout<<"You Entered ROCK"<<endl;
    }
    else if (user_ch=='p')
    {
        cout<<"You Entered PAPER"<<endl;
    }
    else
    {
        cout<<"You Entered SCISSORS"<<endl;
    }
    return (user_ch);
}

void game :: decision(char user_ch, char comp_ch)
{
    if (user_ch == comp_ch)
        {result = -1;}
 
    else if (user_ch == 'r' && comp_ch == 'p')
        {result = 0;}
 
    else if (user_ch == 'p' && comp_ch == 'r') 
        {result =1;}
 
   
    else if (user_ch == 'r' && comp_ch == 's')
        {result= 1;}
 
  
    else if (user_ch == 's' && comp_ch == 'r')
        {result= 0;}
 

    else if (user_ch == 'p' && comp_ch == 's')
        {result= 0;}
 
    
    else if (user_ch == 's' && comp_ch == 'p')
        {result = 1;}
        
        
    if (result == -1)
    {
        cout<<"Game Draw!!"<<endl;
    }
    else if (result == 1)
    {
        cout<<"YOU WIN !!"<<endl;
        count_user+=1;
    }
    else
    {
        cout<<"COMPUTER WINS !!"<<endl;
        count_comp+=1;
    }
    cout<<"You chose : "<<user_ch<<" and Computer chose : "<<comp_ch<<endl;
}

int main()
{   
    game g;
    int best,i=1;
    cout << "\n\t\t\t ROCK, PAPER & SCISSORS GAME !!!" << endl;
    cout<<"\nEnter 3 to play best of three & 5 to play best of five : ";
    cin>> best;
    while (i<=best)
   {    
        cout<<"ROUND "<<i;
        g.decision(g.User_Option(),g.Computer_choice());
        cout<<"COMPUTER SCORE : "<<g.count_comp<<endl;
        cout<<"USER SCORE : "<<g.count_user<<endl;
        cout<<"---------------------------------------"<<endl;
        i++;
   }
   cout<<"---------------------------------------"<<endl;
   cout<<"Your Total Score is :"<<g.count_user<<endl;
   cout<<"Computer's Total Score is :"<<g.count_comp<<endl;
   if (g.count_comp>g.count_user)
   {
    cout<<"BETTER LUCK NEXT TIME !!!";
   }
   else if (g.count_user>g.count_comp)
   {
    cout<<"CONGRATULATIONS !!! YOU WIN !!";
   }
   else 
   {
    cout<<"DRAW !!";
   }
    return 0;
}