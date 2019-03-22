#pragma once

class chainNode
{
    char value;
    char order;
    int xPosition;
    int yPosition;
    bool discovered;
    public:
    chainNode(void);
    chainNode(char v,char o,char x,char y);
    void setValue(char v);
    void setOrder(char o);
    void setDiscovered(bool d);
    char getValue(void);
    char getOrder(void);
    int  getX(void);
    int  getY(void);
    bool getDiscovered();
};