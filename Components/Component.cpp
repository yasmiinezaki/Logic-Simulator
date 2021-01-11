#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
	selected = false;
	result = false;
}

Component::Component()
{}

bool Component::getSelected()
{
	return selected;
}

void Component::setSelected(bool s)
{
	selected = s;
}
GraphicsInfo Component::GetGraphicsInfo()
{
	return m_GfxInfo;
}

Component::~Component()
{}

void Component::SetLabel(string Label)
{
	m_Label = Label;
}

string Component::GetLabel()
{
	return m_Label;
}

bool Component::getResult()
{
	return result;
}

void Component::setResult(bool r)
{
	result = r;
}

