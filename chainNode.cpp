#include "chainNode.h"

chainNode::chainNode(void)
{
    order = 0;
    value = ' ';
    xPosition = 0;
    yPosition = 0;
    discovered = false;
}

chainNode::chainNode(char v,char o,char x,char y)
{
    value = v;
    order = o;
    xPosition = x;
    yPosition = y;
    discovered = false;
}

void chainNode::setValue(char v)
{
    value = v;
}

void chainNode::setOrder(char o)
{
    order = o;
}

void chainNode::setDiscovered(bool d)
{
    discovered = d;
}

char chainNode::getValue(void)
{
    return value;
}

char chainNode::getOrder(void)
{
    return order;
}

int  chainNode::getX(void)
{
    return xPosition;
}

int  chainNode::getY(void)
{
    return yPosition;
}

bool chainNode::getDiscovered()
{
    return discovered;
}