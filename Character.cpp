#include "Character.h"
#include <iostream>

/*****************************************************
 *Character class implementation file for a CLI game.*
 *                                                   *
 *Functions are simple instructions.                 *
 *****************************************************/

#define DEFAULT 0 //Default value for Character "Value".

//Default construtor with values to let user know Character created by default.
Character::Character():Name("NoName"),Description("Nothing"),Value(DEFAULT){}                     

Character::Character(const string& s1,const string& s2):Name(s1),Description(s2),Value(DEFAULT){}

Character::Character(const Character& c):Name(c.Name),Description(c.Description),Value(c.Value){}

string Character::GetName() const
{
  return Name;
}

int Character::GetValue()const
{
  return Value;
}

void Character::Show() const
{
  cout<<"Character name:"<<Name<<endl;
  cout<<"Description: "<<Description<<endl;
  return;
}

void Character::SetValue(int i)
{
  this->Value=i;
  return;
}

//Destructor that does nothing else.
Character::~Character(){}

