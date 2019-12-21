#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>
#include <iostream>

using namespace std;
int y=4;

char Map[1600][1600]=
{

    "                                                                                   #    ##                         #    #   #                                                                          # #                     #####                      ############                                                                                                                           #",
    "                                                              #######                                  ####        #    #                                                                              # #                                    #####                    #####                                                                                                                     #",
    "                                                             ###############                      ############     ######   #                                                                          # #               ####                                                                                     ###############                                  Made by Raadwan Masum in C++  #",
    "                                                     ##                       ## ####      ####                    #    #   #        #                                  #####     #                      #                             ###                         ##########                            ###                                #                                                    #",
    "                                  ##########              ################################################         #    #   #       ##                         #######################         ###############           #####                 ###          ###                                                ###################       #######    ##############                               #",
    "                                             ###        #######################################################                   ###         #   ###                                #                            #############        ######             ###########         #  ######               ############################################################# #####        #####           #",
    "##################################################################################################################################################################################################################################################################################################################################################################################################"};


bool endgame=true;

void gotoXY(int x,int y)
{
    COORD coord = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}//this will set our console cursor where we want to...

void showmap (int u)
{
    for (int i=0; i<=6; i++)
    {
        for (int j=u; j<=u+20; j++)
        {
            cout<<Map[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    string i;
    cout << "Press enter to start and up arrow to jump." << endl;
    cin .get();

    while(true)
    {
        endgame=true;
        y=4;
        PlaySound("Ali-a", NULL, SND_ASYNC);

        int n=0;
        int jump=0;
        while (endgame)
        {
            gotoXY(0,0);
            showmap(n);
            n++;
            if (jump==0 && GetAsyncKeyState(VK_UP) && Map[y+1][n+3]=='#')jump=3;
            if (jump>0)
            {
                y--;
                jump--;
            }
            else if (Map[y+1][n+3]!='#')
            {
                y++;

            }
            gotoXY(4,y);
            cout<<"C";
            //printf("%c",248);
            if (Map[y][n+3]=='#')endgame=false;
            Sleep(50);

        }
    }

}
