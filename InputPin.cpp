#include "InputPin.h"

InputPin::InputPin()
{
	isConnected = false;
	pConnection = NULL;
	pComp = NULL;
}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

void InputPin::setIsConnected(bool b)
{
	isConnected = b;
}

bool InputPin::getIsConnected()
{
	return isConnected;
}

void InputPin::setConnection(Connection* pConn)
{
	pConnection = pConn;
}

Connection* InputPin::getConnection()
{
	return pConnection;
}