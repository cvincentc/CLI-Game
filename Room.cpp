#include "Room.h"
#include <iostream>
using namespace std;
/*******************************************************
 *Room class implementation file for a CLI game.       *
 *Even though "rooms" maps string(s) and pointer(s)    *
 *to Floor, it is meant to map all Room(s) on a Floor  *
 *For the eaiser understanding of the implementation   *
 *file, Floor will be addressed as Room.               *
 *******************************************************/

Room::Room():Lobby(0){}

Room::Room(const Room& R):Lobby(R.Lobby){}

Room::Room(string name ,const Floor& F)
{
    //Set class value with given input.
    this->SetName(name);
    this->SetLvl(F.GetLvl());
}

void Room::SetLobby()
{
    //Set start point
    this->Lobby=true;
}

PtrToFloor Room::Go(const PtrToFloor StartPlace,int Win,int Lose)
{
    //Variables declaration to read input commands.
    string cmd1,cmd2;
    //Display info of current Room.
    Show();
    //Read input commands with instruction given from Show().
    cin>>cmd1>>cmd2;
    cout<<endl;
    //Check commands validity.
    while(cmd1!="go"||rooms.find(cmd2)==rooms.end())
    {
        //If command is not valid, ignore whatever is after. 
        cin.ignore();
        //Give out new instructions.
        cout<<"Input invalid! Enter \"end game\" if you want to end the game."<<endl;
        cout<<"To continue, input \"go+[direction]\". Eg.\"go south\""<<endl;
        cin>>cmd1>>cmd2;
        if(cmd1=="end")
        {
            //Change game state, will terminate program.
            cin.ignore();
            EndGame();
            return this;
        }
        cout<<endl;
    }
    //Set ptr Point to the next Room to go to.
    PtrToFloor ptr=rooms.find(cmd2)->second;
    //Pointer of NPC in next room.
    PtrToChar CharPtr=ptr->GetNPC();
    //Check for lose condiction.
    if(ptr->FoundLose(Lose))
    {
        //Bring terminator NPC to StartPlace.
        StartPlace->SetNPC(CharPtr);
        //Remove NPC from current Room.
        ptr->RemoveNPC();
        //Go to StartPlace.
        return StartPlace;
    } 
    //Check for win condiction.
    if(ptr->FoundWin(Win))
    {
        //Print found winning condiction and prompt.
        PrintStars();
        cout<<"You have found \""<<ptr->GetNPC()->GetName();
        cout<<"\"! Now go back to the start point to win the game!"<<endl;
        PrintStars();
    }
    //Bring NPC to the next Room if current Room contains
    //winning condiction NPC.
    this->CarryOver(ptr,this->GetNPC());
    //Return the next Room to go to.
    return ptr;
}


void Room::Show()
{
    //Display current Room info.
    cout<<"You are in the \""<<GetName()<<"\" on "<<GetLvl()<<"."<<endl;
    if(rooms.empty()) cout<<"No exit!"<<endl;
    else
    {
        //Display exits to other Rooms.
        if(GetNPC()) cout<<"You found:"<<GetNPC()->GetName()<<endl;
        cout<<"In this room you can go: ";
        //Set iterator to iterate through every exit in map.
        map<string,PtrToFloor>::iterator it;
        //Show exit Room(s) detail(s).
        for(it=rooms.begin();it!=rooms.end();it++)
        {
            if(it!=rooms.begin()) cout<<", ";
            cout<<"\""<<it->first<<"\""<<" to "<<it->second->GetName();
        }
        cout<<endl<<"Enter the direction you want to go to. Eg. \"go east\""<<endl;
    }
    
}

void Room::connect(const PtrToRoom up,const PtrToRoom down,const PtrToRoom N,const PtrToRoom S,const PtrToRoom W,const PtrToRoom E)
{
    //Bi-connection of two Rooms.
    //For example, Rooms are located on east and west sides.
    //EastRoom exits west to WestRoom, WestRoom exits east to East Room.
    if(up)
    {
        this->rooms["up"]=up;
        up->rooms["down"]=this;
    }
    //For the follow if statements, similar instructions as above.
    if(down)
    {
        this->rooms["down"]=down;
        down->rooms["up"]=this;
    }
    if(N)
    {
        this->rooms["north"]=N;
        N->rooms["south"]=this;
    }
    if(S)
    {
        this->rooms["south"]=S;
        S->rooms["north"]=this;
    }
    if(E)
    {
        this->rooms["east"]=E;
        E->rooms["west"]=this;
    }
    if(W)
    {
        this->rooms["west"]=W;
        W->rooms["east"]=this;
    }
}

//Destructor that does nothing.
Room::~Room(){}

