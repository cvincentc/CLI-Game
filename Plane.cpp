/*****************************************************
 *Plance class implementation file for a CLI game.   *
 *                                                   *
 *Functions are simple instructions.                 *
 *****************************************************/


#include "Plane.h"    //Base class include.
#define End 0         //Varibles for Plane member "state".
#define GameOn 1      

//Definition of base class static member.
int Plane::state=GameOn;    

//Default constructor with values reflecting defautly created.
Plane::Plane():Name("UnKnown"),Level("UnKnown"){}  

Plane::Plane(const Plane& P):Name(P.Name),Level(P.Level){}  

void Plane::SetLvl(const string& s)
{
    Level=s;
}

void Plane::SetName(const string& s)
{
    Name=s;
}

string Plane::GetLvl()const
{
    return Level;
}

string Plane::GetName()const
{
    return Name;
}

void Plane::EndGame()
{
    state=End;
}

int Plane::GameState()
{
    return state;
}

//Destructor that does nothing else.
Plane::~Plane(){} 

