#include "Room.h"
#include <iostream>
#include <map>
#include <cstdlib>
#include <windows.h>
#include "time.h"
using namespace std;

#define LOSEGAME -1   //Lose game value.
#define WINGAME 1     //Win game value.
#define RANDOMMAX 9   //Number limit to set random number.
//------------------------------------------------------------------------------------------
//|Game object definitions.                                                                |
//------------------------------------------------------------------------------------------

//Character 1 description.
string s1 ="Game over if you encounter this Character!";

//Character 2 description.
string s2 ="Find Character and take her to the Lobby, then you will win the game";

//Construct Characters with s1 and s2.
Character C1("Monster",s1),C2("Princess",s2);

//Construct a castle with four Floors
Floor F1("Gound floor","1F"),F2("Second floor","2F");
Floor B1("Underground Pool floor","1B"),F3("Rooftop floor","3F");

//Construct ten different Rooms for the game.
Room R1("Change Room",B1),R2("Sauna Room",B1),R3("Theater Room",F1),Lobby("Lobby",F1);
Room R5("Fitness Room",F1),R6("Rest Room",F1),R7("Suite 2046",F2),R8("Luxury Suite",F2);
Room R9("Supreme Plus Suite1",F3),R10("Supreme Plus Suite2",F3);

//------------------------------------------------------------------------------------------
//|end of object definitions.                                                              |
//------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
//|function declarations.                                                                  |
//------------------------------------------------------------------------------------------

//Initialize castle,connect Rooms and Floors,
//and put Characters in seperate Rooms randomly.
void Initialize();

//Start the CLI game. Function ends either when 
//encounter "Monster",with "Princess" at "Lobby",
//,or termination by inputing "end game" command.
void StartGame();

//------------------------------------------------------------------------------------------
//|end of function declarations.                                                           |
//------------------------------------------------------------------------------------------

/*******************************************************************************************
 * main function.                                                                          *
 *******************************************************************************************/

int main() {
    Initialize();
    cout<<"Welcome to the game!"<<endl;
    cout<<"To win this game, you must find \"Princess\"";
    cout<<" and bring her to the Lobby."<<endl;
    cout<<"Look out for \"Monster\", game will be over whenever ";
    cout<<"you encounter it."<<endl;
    cout<<"Btw,....they are in two separate rooms in this castle."<<endl;
    cout<<"Instructions are \"go + where to go\". For example, \"go east\"";
    cout<<" in rooms, and \"go 1\" on floors."<<endl;
    cout<<"Now go find your princess, Good luck buddy!"<<endl<<endl; 

    StartGame();

    system("pause");
    return 0;
}

/*******************************************************************************************
 * end of main                                                                             *
 *******************************************************************************************/

//------------------------------------------------------------------------------------------
//|function definitions.                                                                   |
//------------------------------------------------------------------------------------------
void StartGame()
{
    PtrToFloor StartPoint=&Lobby;
    PtrToFloor player=&Lobby;
    while(player->GameState())
    {
        player=player->Go(StartPoint,WINGAME,LOSEGAME);
        if(Lobby.GetNPC())break;
    }
    if(StartPoint->GetNPC())
    {
        if(StartPoint->GetNPC()->GetValue()==LOSEGAME) 
            cout<<"You have encountered Monster, GAMEOVER!"<<endl;
        else cout<<"Congrats! you win!"<<endl;
    }
    else cout<<"Aww......this fun adventure has ended TT"<<endl;
    
}
void Initialize()
{
    //Set "Monster" to be game terminator
    C1.SetValue(LOSEGAME);
    //Set "Princess" to be game winning condiction.     
    C2.SetValue(WINGAME);
    //Set Lobby Room to be start point.      
    Lobby.SetLobby();
    B1.Insert(&R2,"north");
    B1.Insert(&R1,"north");
    F1.Insert(&R3,"north");
    F1.Insert(&Lobby,"north");
    F1.Insert(&R5,"north");
    F1.Insert(&R6,"south");
    F2.Insert(&R7,"east");
    F2.Insert(&R8,"west");
    F3.Insert(&R9,"east");
    F3.Insert(&R9,"north");
    F3.Insert(&R9,"south");
    F3.Insert(&R10,"west");
    F3.Insert(&R10,"north");
    F3.Insert(&R10,"south");
    //Connect rooms.
    //related directions are below:
    //up,down,north,south,west,east;
    R1.connect(&R3,NULL,NULL,NULL,NULL,&R2); 
    R2.connect(&R9,NULL,NULL,NULL,NULL,NULL);
    Lobby.connect(&R7,NULL,NULL,NULL,&R3,&R5);
    R8.connect(NULL,&R6,NULL,&R7,NULL,NULL);
    R5.connect(&R10,NULL,NULL,NULL,NULL,NULL);
    //Set up random number RanNum1 and RanNum2.
    //Random numbers are from 1-9 inclusively.
    //Ten Rooms are in this game.
    //Room number from 1-9, excluded Lobby Room.
    srand((int)time(0));
    int RanNum1 = rand()%RANDOMMAX+1;
    int RanNum2 = rand()%RANDOMMAX+1;
    //Make sure random numbers are not same.
    while(RanNum2==RanNum1)
    {
        RanNum2 = rand()%RANDOMMAX+1;
    }
    //Map Rooms with integers 1-9.
    //To set NPCs in separete Rooms.
    map<int,PtrToRoom> RoomList;
    RoomList[1]=&R1;
    RoomList[2]=&R2;
    RoomList[3]=&R3;
    RoomList[4]=&R5;
    RoomList[5]=&R6;
    RoomList[6]=&R7;
    RoomList[7]=&R8;
    RoomList[8]=&R9;
    RoomList[9]=&R10;
    RoomList[RanNum1]->SetNPC(&C1);
    RoomList[RanNum2]->SetNPC(&C2);
    //commented out display of random rooms with "Momster" and "Princess".
    //Uncomment only when checking program correctness.
    //cout<<RanNum1<<" "<<"Monster"<<RoomList[RanNum1]->GetName()<<endl;
    //cout<<RanNum2<<" "<<"Princess"<<RoomList[RanNum2]->GetName()<<endl;
    return;
}

//------------------------------------------------------------------------------------------
//|end of function definitions.                                                            |
//------------------------------------------------------------------------------------------


//to run program, make sure to complie the following cpp files.
//g++ main.cpp Character.cpp Plane.cpp Floor.cpp Room.cpp -o main
//.\main
//------------------------------------------------------------------------------------------
//|end of program.                                                                         |
//------------------------------------------------------------------------------------------

