#ifndef _Floor_H
#define _Floor_H
#include "Plane.h"
#include "Character.h"
#include <map>

/*************************************************************************
 * This is a Floor class header file for a CLI game.                     *
 *                                                                       *
 * Floor class is a derived class from "Plane.h".                        *
 *                                                                       *
 * Floor "builds" on Plane class. Floor represent level floors in the    *
 * CLI game castle. Eg. Gound floor, second floor...etc.                 *
 *                                                                       *
 * Floor has a map that maps all the "rooms" (pointer to other Floor     *
 * object(s)) on the specific floor object. And an "NPC", Character      *
 * pointer.                                                              *
 *                                                                       *
 * In the CLI game, Floor and Room will share the "rooms" and the "NPC"  *
 * protected members, and "rooms" will mainly containing Rooms           *
 *                                                                       *
 * For example, in a swimming pool Floor. A swimming pool Floor has      *
 * changing Room and sauna Room, very less likely has a soccer field     *
 * Floor on swimming pool Floor                                          *
 *************************************************************************/

//Declaration of pointer to floor
typedef class Floor *PtrToFloor;                     

class Floor:public Plane                        
{
public:
    //Default constructor.
    Floor();                             

    //Constructor with string variables.            
    Floor(const string&,const string&);     

    //Copy constructor.         
    Floor(const Floor&);  

    //To insert a Floor object A to this Floor's map, and 
    //set exit on the A in respect to A. 
    virtual void Insert(const PtrToFloor,const string&); 

    //To show exit(s) in object, and some this Floor's info             
    virtual void Show();    

    //To return "NPC"(Character) pointer                         
    virtual PtrToChar GetNPC()const;      

    //Put an "NPC" in this Floor            
    virtual void SetNPC(const PtrToChar);  

    //Remove the "NPC" in this Floor          
    virtual void RemoveNPC();      

    //Show current Floor info and exits by calling Show(),
    //then go to the next input. If encounters given variables
    //changes the game state accordingly. Returns a pointer
    //to Floor, which points to the next room to go to.
    virtual PtrToFloor Go(const PtrToFloor,int,int); 
                                                                                                 
    //Check win game status                                                 
    virtual bool FoundWin(int)const; 

    //Check lose game status                
    virtual bool FoundLose(int)const; 

    //Carries "NPC" from this Floor to next Floor,   
    //Removes "NPC" from this Floor after.            
    virtual void CarryOver(const PtrToFloor,const PtrToChar);   

    //Print stars.                                                            
    virtual void PrintStars()const;   

    //Destructor.               
    virtual ~Floor();                                
    
protected:
    map<string,PtrToFloor> rooms;   //map of Floors and their Names .
    PtrToChar NPC;                  //pointer to an NPC.
};              

#endif