#include <iostream>
#include "chainNode.h"
#include <fstream>
#include <list>
#include <string>
#include <iterator>
#include <sstream>
 
using namespace std;
int no_rows = 0,no_cols;
chainNode **arr_nodes; 
void discover(int i,int j,int &max,list<chainNode> &current_chain);
int main()
{
    ifstream file;
    file.open("input.txt");
    string input;
    list<string> l_input;
   
    while(getline(file,input))
    {
        l_input.push_back(input);
        no_rows++;
    }
    file.close();
    no_cols = l_input.front().length();
    arr_nodes = new chainNode*[no_rows]; 
    int count = 0;
    list <string> :: iterator it;
    for (it = l_input.begin(); it != l_input.end(); ++it)
    {
        arr_nodes[count] = new chainNode[no_cols];
        string input = *it;
        for(int j=0;j<no_cols;j++)
        {

            arr_nodes[count][j] = chainNode(input.substr(j,1)[0],0,count,j);
        }   
        count++;
    }
    int maxLength = 0;
    list <chainNode> chain;
    for(int i=0;i<no_rows;i++)
    {
        for(int j=0;j<no_cols;j++)
        {
            if(arr_nodes[i][j].getValue()=='.'&&!arr_nodes[i][j].getDiscovered())
            {
                int max = 0;
                list<chainNode> current_chain;
                discover(i,j,max,current_chain);
                if(max > maxLength)
                {
                    maxLength = max;
                    chain = current_chain;
                }
            }
        }
    }
    list <chainNode> :: iterator itr;
    for(itr = chain.begin();itr != chain.end();++itr)
    {
        chainNode temp = *itr;
        arr_nodes[temp.getX()][temp.getY()].setValue(temp.getOrder()+48); 
    }
    stringstream ss;
    ss << maxLength;
    string output = ss.str() + "\n";
    for(int i=0;i<no_rows;i++)
    {
        for(int j=0;j<no_cols;j++)
        {
            output += string(1,arr_nodes[i][j].getValue());
        }
        output+="\n";
    }
    ofstream out("output.txt");
    out << output;
    out.close();
    return 0;
}

void discover(int i,int j,int &max,list<chainNode> &current_chain)
{
    arr_nodes[i][j].setDiscovered(true);
    arr_nodes[i][j].setOrder(max);
    max++;
    current_chain.push_back(arr_nodes[i][j]);
    bool case1=false,case2=false;
    int max1,max2;
    list<chainNode> chain1,chain2;
    if(j+1 < no_cols&&arr_nodes[i][j+1].getValue()=='.'&&!arr_nodes[i][j+1].getDiscovered())
    {
        max1 = max;
        chain1 = current_chain;
        discover(i,j+1,max1,chain1);
        case1 = true;
    }
    if(j-1 >= 0&&arr_nodes[i][j-1].getValue()=='.'&&!arr_nodes[i][j-1].getDiscovered())
    {
        max2 = max;
        chain2 = current_chain;
        discover(i,j-1,max2,chain2);
        case2 = true;
    }

    if(case1&&!case2)
    {
        max = max1;
        current_chain = chain1;
    }
    else if(!case1&&case2)
    {
        max = max2;
        current_chain = chain2;
    }
    else if(case1&&case2)
    {
        if(max1 > max2)
        {
            max = max1;
            current_chain = chain1;
        }
        else
        {
            max = max2;
            current_chain = chain2;
        }
    }else
    {
        if(i+1 < no_rows&&arr_nodes[i+1][j].getValue()=='.'&&!arr_nodes[i+1][j].getDiscovered())
        {
            discover(i+1,j,max,current_chain);
        }
    }    
}