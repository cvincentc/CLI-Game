#ifndef _PLANE_H
#define _PLANE_H
#include <string>
using namespace std;

/************************************************************************
 * This is a Plane class header file for a CLI game.                    *
 *                                                                      *
 * Plane class can be used as a structrue for further inheritance.      *
 *                                                                      *
 * Plane could be thought of as a two-dimentional base for "physical"   *
 * structures. Eg.A piece of land is a Plane, soccer field and farm land*
 * are Floors, and they can build on any Plane(piece of land).          *
 *                                                                      *
 * Plane class contains commom elements when "building" structures like *
 * "Floors" and "Rooms", such elements are: "Name","Level",and "state". *
 ************************************************************************/

class Plane
{
public:
    //Default constructor.
    Plane();         

    //Copy constructor.                       
    Plane(const Plane&);      

    //To set member "Level".              
    virtual void SetLvl(const string&);  

    //To set member "Name".   
    virtual void SetName(const string&);  

    //To change member "state".  
    virtual void EndGame();     

    //To return memeber "Level".           
    virtual string GetLvl()const;   

    //To return member "Name".        
    virtual string GetName()const; 

    //To return static member "state".         
    static int GameState();   

    //Destructor.              
    virtual ~Plane();

private:
    string Name;         //Object identification
    string Level;        //Object height
    static int state;    //Class state
};

//Declaration of pointer to Plance for convenient use later.
typedef Plane *PtrToPlane;  

#endif