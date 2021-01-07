/******************************************************
 *Floor class implementation file for a CLI game.     *
 *Even though "rooms" map mainly points to Rooms, for *
 *the purpose of this implementation file, we will    *
 *address Room as Floor.                              *
 ******************************************************/

#include "Floor.h"
#include <iostream>
#include <string>
using namespace std;

//Following three function are constructors.
Floor::Floor(){}

Floor::Floor(const Floor& f):rooms(f.rooms),NPC(f.NPC){}

Floor::Floor(const string& name,const string& lvl)
{
    this->SetName(name);
    this->SetLvl(lvl);
}

void Floor::Insert(const PtrToFloor R,const string& direction)
{
    this->rooms[R->GetName()]=R;    //Insert pointer to Floor R to "rooms".
    R->rooms[direction]=this;       //Set exit direction in respect to R.
}

void Floor::Show()
{
    //Display this Floor's Plane info.
    cout<<"You are on: "<<GetLvl()<<", "<<GetName()<<endl; 
    if(this->rooms.empty()) 
        cout<<"No Rooms on this floor!"<<endl;      
    else
    {
        int count;
        map<string,PtrToFloor>::iterator it;
        //Display Rooms on this Floor.
        cout<<"On this floor, you can find: ";   
        //Iterating through "rooms" map, outing Floors.                       
        for(it=rooms.begin(),count=1;it!=rooms.end();it++,count++)      
        {

            //Display first of a map item, which is "Name" of Floor.
            if(it!=rooms.begin()) cout<<", ";     
            //Also display the access number of each item in the map.                          
            cout<<it->first<<"["<<count<<"]";                           
        }                                                               
    }
}

void Floor::SetNPC(const PtrToChar C)
{
    NPC=C;
}

PtrToChar Floor::GetNPC()const
{
    return NPC;
}

void Floor::RemoveNPC()
{
    NPC=0;
}

//Destructor that does nothing else.
Floor::~Floor(){}                               

bool Floor::FoundWin(int Win)const
{
    //Return true if win condiction is satisified from this Floor's "NPC". 
    if(NPC)return NPC->GetValue()==Win;    
    //False otherwise.     
    else return false;                          
}

bool Floor::FoundLose(int Lose)const
{
    //Return true if aquired lose condiction from this Floor's "NPC".
    if(NPC)return NPC->GetValue()==Lose;        
    //False otherwise.
    else return false;                          
}

void Floor::PrintStars()const
{
    cout<<endl;
    cout<<"**********************************************************************"<<endl;
    cout<<"**********************************************************************"<<endl;
}

void Floor::CarryOver(const PtrToFloor F,const PtrToChar C)
{
    if(C)
    {
        F->SetNPC(C);
        this->RemoveNPC();
    }
}

PtrToFloor Floor::Go(const PtrToFloor StartPlace,int Win,int Lose)
{
    //Variables declaration to collect different command types.
    string cmd1,cmd2;
    //show Floor info.                                                                 
    Show();
    //Output instruction.
    cout<<endl<<"Enter the room number you want to go to, eg.\"go 1\" "<<endl;   
    cin>>cmd1>>cmd2;
    cout<<endl;
    int n=cmd2[0]-'0';
    //Determine validity of input command.
    while(n<1||n>rooms.size()||cmd1.substr(0,2)!="go")                                 
    {
        cout<<"Input invalid! Enter \"end game\" to end"; 
        cout<<"the game, else enter go+room number"<<endl;
        cin>>cmd1>>cmd2;                                                          
        if(cmd1=="end"&&cmd2=="game")
        {
            //Set the static variable of Plane and
            EndGame();  
            //end game right on this Floor.                                                         
            return this;                                                         
        }
        
    }
    //Iterator set up for "rooms" map.
    map<string,PtrToFloor>::iterator it; 
    //Count variable for return of Floor number.         
    int i=0;
    //Iterate through "rooms" map.                                      
    for(it=rooms.begin();;it++)                   
    {
        i++;
        //Break after Floor position reached.
        if(i==n)break;                         
    }
    //Ptr points to next Floor to go to.
    PtrToFloor ptr= it->second;   
    //This char points to "NPC" on next Floor.                
    PtrToChar Char = ptr->GetNPC();
    //Check if "NPC" next Floor terminates game.               
    if(ptr->FoundLose(Lose))                      
    {
        //Bring game terminator to start point.
        StartPlace->SetNPC(Char);
        //Return pointer to start point.                 
        return StartPlace;                        
    } 
    //Check if we found win condiction
    if(ptr->FoundWin(Win))                        
    {
        //Prompt when condition is found 
        PrintStars();                             
        cout<<"You have found \""<<ptr->GetNPC()->GetName();
        cout<<"\"! Now go back to the start point to win the game!"<<endl;
        PrintStars();
        cout<<endl;
    }
    //Bring "NPC" to next Floor, do nothing if no "NPC" is with player.
    this->CarryOver(ptr,this->GetNPC());  
    //Return pointer to next Floor.            
    return ptr;                                   
}
