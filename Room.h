#ifndef ROOM_H
#define ROOM_H
/***************************************************************************************
 *This is a Room class header file for a CLI game.                                     *
 *Room has one private member "Lobby" indicating if Room is main Lobby.                * 
 *Room has Plane as Ancestor ,and Floor as Parent.                                     *
 *Even though Room inherits protected member map of string and pointer to Floor, for   *
 *for the purpose of this implementation file, Floor will be addressed as Room.        *
 ***************************************************************************************/
#include "Floor.h"


typedef class Room *PtrToRoom;
class Room:public Floor
{
public:
    //Default constructor.
    Room();    

    //Constructor takes in string and Floor refference,   
    //share Floor input with Room's Floor.                                   
    Room(string,const Floor&);            

    //Copy constructor.                                                   
    Room(const Room&);                                 
    
    //Following function connects() this Room with input Rooms, 
    //NULL for input when connect to specific direcion is not needed;
    //connect() is bi-connecting instruction, which this Room and input
    //rooms point to each other with direction.
    //Direction is related to input order, the order is "Up","Down","North","South","West",and "East".
    //Sets opposition for input Rooms.   
    virtual void connect(const PtrToRoom,const PtrToRoom,const PtrToRoom,const PtrToRoom,const PtrToRoom,const PtrToRoom);

    //Displays info of Room, and shows available exit(s)
    virtual void Show();   

    //Set Room member "Lobby"               
    virtual void SetLobby();                            

    //Show current Room info and exit(s) by calling Show(),
    //then go to the next input direction. If encounters given 
    //variables changes the game state accordingly. Returns a pointer
    //to Room, which points to the next Room to go to.
    virtual PtrToFloor Go(const PtrToFloor,int,int);  

    //Destructor.  
    virtual ~Room();

private:
    bool Lobby;  //special property of start point; 
};

#endif


