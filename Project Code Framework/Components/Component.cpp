#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
	selected = false;
}
bool Component::getSelected()
{
	return  selected;
}
void Component::setSelected(bool s)
{
	selected = s;
}
GraphicsInfo Component::GetGraphicsInfo()
{
	return m_GfxInfo;
}

Component::Component()
{}

Component::~Component()
{}

