
#ifndef _CHARACTER_H
#define _CHARACTER_H
#include <string>
using namespace std;

/***************************************************************************************
 *This is a Character class header file for a CLI game.                                *
 *                                                                                     *
 *Each Character has three private members, they are "Name" ,"Value",and "Description".*
 *                                                                                     *
 *Functions to access and to change there private members are listed below.            *
 ***************************************************************************************/

#define Danger 1;
typedef class Character *PtrToChar;
class Character
{
public:
  //Default constructor. 
  Character();   

  //Constructor to construct with Character Name and Description.
  Character(const string&,const string&);    

  //Copy constructor.
  Character(const Character&);   

  //To return Character member "Name".            
  virtual string GetName() const;  

  //To return CHaracter member "Value"          
  virtual int GetValue()const;  

  //To display Character "Name" and "Description".         
  virtual void Show() const;      

  //To set Character member "Value"           
  virtual void SetValue(int);    

  //Destructor            
  virtual ~Character();     

private:
  string Name;          //Character identification.              
  string Description;   //Character detail.              
  int Value;            //Meaningful variable to remark Character                     
};
#endif


