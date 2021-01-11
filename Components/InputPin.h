#ifndef _INPUTPIN_H
#define _INPUTPIN_H

#include "Pin.h"
class Component; //Forward class declaration
class Connection;

class InputPin: public Pin	//inherited from class Pin
{
	Component* pComp; //Component at which this pin is associated
	bool isConnected; //true if a wire is connected to the pin 
	Connection* pConnection; //Connection connected to this input pin
public:
	InputPin();
	void setComponent(Component* pCm);//sets the component of this input pin
	Component* getComponent();	//returns the component of this input pin
	void setIsConnected(bool b);
	bool getIsConnected();

	void setConnection(Connection* pCn);
	Connection* getConnection();
};
#endif