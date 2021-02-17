#include <iostream>
#include <conio>
#include <process>
#include <string>
#include <ctype>
#include <graphics>
#include <stdlib>
#include <dos>
#include <time>
using namespace std;
union REGS in,out; //to manipulate register data
struct cell{
    int row;
    int col;
    int type; //type of cell: 0 not occupied, 1 occupied by player 1 soldier ,2 occupied by player 1 king, 3 occupied by player 2 soldier,4 occupied by player 2 king
};
struct game{
    int cells[8][8]; //contays the type of cell in the board
    char player1[80]; //Name of player 1
    char player2[80]; // name of player2
};
const int BOARD_WIDTH 	= 400;
const int BOARD_HEIGHT	= 400;
const int LEFT_CORNER	= 20;
const int TOP_CORNER	= 10;
const int NB_ROWS  	= 8;
const int NB_COLS  	= 8;
const int CELL_SIZE	= BOARD_HEIGHT/NB_ROWS;
const int STATUS_AREA_WIDTH  = 300;
const int STATUS_AREA_HEIGHT= 195;
const int STATUS_AREA_LEFT = LEFT_CORNER + BOARD_WIDTH + 10;
const int STATUS_AREA_TOP1 = TOP_CORNER;
const int STATUS_AREA_TOP2 = TOP_CORNER + 210;
const int INFO_AREA_WIDTH  = 710;
const int INFO_AREA_HEIGHT= 40;
const int INFO_AREA_LEFT = LEFT_CORNER;
const int INFO_AREA_TOP = TOP_CORNER+ + BOARD_HEIGHT + 10;
const int CELL1_COLOR =WHITE;
const int CELL2_COLOR =LIGHTGRAY;
const int PLAYER1_COLOR =BLUE;
const int PLAYER2_COLOR =RED;
const int INFO_COLOR =WHITE;
const int ESC =27;
const int NEW_GAME ='n';
// mouse handling functions
int StartMouse(void); //initialize the mouse driver
void showMousePointer(void);     // show mouse pointer arrow
void hideMousePointer(void);         // hide mouse pointer arrow
void restrictMouseArea(int ,int ,int , int ); // restrict the mouse area
void mouseBtnPosition(int *,int *,int *);    //returns which mouse button clicked and the pointer pixel position
//game functions
int getCellColor(cell c);    //returns cell back color
void putQuarki(cell, int &);  //put qorki on board
void makeKing(cell qurki);      //makes a given soilder king (not implemented}
void putQuarkis(cell quarkis[], int n, int c[][8]); //put several quarkis
void drawCell(cell c); //draw any type of cell empty, solider, and king
void drawBoard();   //draw board
void getPlayer(int playerId, char name[]); //get player  name
void displayInfo(char *msg);    //display message in the information area
void displayStatus1(char *msg); // display playe1 status
void displayStatus2(char *msg); // display player2 status
void  initialize(game & g, int & turn,int newGame); //initialize new or saved game
cell getCell(int x, int y, int cells[][8]);  // get cell from pixel position
void moveQuarki(cell startCell, cell destCell, int & c); //move quarki
int getCellColor(cell c){
    if(c.row%2 == 0 && c.col%2!=0 ||  c.row%2 != 0 && c.col%2==0){
        return CELL2_COLOR;
    }else{
        return CELL1_COLOR;
    }
}
void putQuarki(cell quarki, int & cell){
    int x, y, fcolor;
    x=LEFT_CORNER + quarki.col*CELL_SIZE;
    y=TOP_CORNER + quarki.row*CELL_SIZE;
    if(quarki.type==1)
      fcolor=PLAYER1_COLOR;
    else
      fcolor=PLAYER2_COLOR;
    setfillstyle(SOLID_FILL, fcolor);
    fillellipse(x+0.5*CELL_SIZE , y + 0.5*CELL_SIZE, CELL_SIZE/2.5,CELL_SIZE/2.5);
    fillellipse(x+0.5 * CELL_SIZE , y + 0.5 *CELL_SIZE, CELL_SIZE/2.8,CELL_SIZE/2.8);
    cell=quarki.type;
}
void makeKing(cell c){
    ;
}
void putQuarkis(cell quarkis[], int n, int c[][8]){
    for(int i=0; i< n; i++){
        putQuarki(quarkis[i], c[quarkis[i].row][quarkis[i].col]);
        if(quarkis[i].type==2 || quarkis[i].type==4)
	    makeKing(quarkis[i]);
    }
}
void drawCell(cell c){
    int fcolor;
    int x, y;
    x=LEFT_CORNER + c.col*CELL_SIZE;
    y=TOP_CORNER + c.row*CELL_SIZE;
    fcolor=getCellColor(c);
    setfillstyle(SOLID_FILL, fcolor);
    bar(x,y,x+CELL_SIZE,y+CELL_SIZE);
}

void drawBoard(){
 cell c;
 for(int i=0;i< 8;i++)
 {
     for(int j=0; j<8; j++){
        c.row=i;
        c.col=j;
        c.type=0;
        drawCell(c);
     }
 }
}
void getPlayer(int playerId, char name[]){
    cout << "Enter Player"  << playerId << " name: ";
    cin.getline(name, 79);
}
void displayInfo(char *msg){
  setcolor(BLACK);
  setfillstyle(SOLID_FILL, INFO_COLOR);
  bar(INFO_AREA_LEFT,INFO_AREA_TOP,INFO_AREA_LEFT+INFO_AREA_WIDTH,INFO_AREA_TOP+INFO_AREA_HEIGHT);
  settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
  outtextxy(INFO_AREA_LEFT+5,INFO_AREA_TOP+5,msg);
}
void displayStatus1(char *msg){
  setcolor(WHITE);
  setfillstyle(SOLID_FILL, PLAYER1_COLOR);
  bar(STATUS_AREA_LEFT,STATUS_AREA_TOP1,STATUS_AREA_LEFT+STATUS_AREA_WIDTH,
	STATUS_AREA_TOP1+STATUS_AREA_HEIGHT);
  settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
  outtextxy(STATUS_AREA_LEFT+10,STATUS_AREA_TOP1+10,msg);
}
void displayStatus2(char *msg){
  setcolor(WHITE);
  setfillstyle(SOLID_FILL, PLAYER2_COLOR);
  bar(STATUS_AREA_LEFT,STATUS_AREA_TOP2,STATUS_AREA_LEFT+STATUS_AREA_WIDTH,
	STATUS_AREA_TOP2+STATUS_AREA_HEIGHT);
  settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
  outtextxy(STATUS_AREA_LEFT+10,STATUS_AREA_TOP2+10,msg);
}
void  initialize(game & g, int & turn,int newGame){
    cell quarkis[]={{0,1,1}, {0,3,1}, {0,5,1}, {0,7,1}, {1,0,1},{1,2,1},{1,4,1},{1,6,1}, {2,1,1},{2,3,1}, {2,5,1}, {2,7,1}, {5,0,3}, {5,2,3}, {5,4,3}, {5,6,3}, {6,1,3},{6,3,3}, {6,5,3}, {6,7,3}, {7,0,3}, {7,2,3}, {7,4,3}, {7,6,3}};
    int n=24;
    if(newGame==1){        //new game
       ;

    }else{               //saved game
	;
    }
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "c:\\tc\\BGI");
    int errorcode=graphresult();
    if(errorcode!=grOk){
        cout << grapherrormsg(errorcode);
        getch();
        exit(1);
    }
    if(StartMouse()==0){
    closegraph();
    restorecrtmode();
    cout << "Mouse Driver not found";
    exit(1);
    }
    drawBoard();
    displayStatus1(g.player1);
    displayStatus2(g.player2);
    displayInfo("Select(R Click). Move (L Click). New Game(n). Quit(ESC).");
    putQuarkis(quarkis, n, g.cells);
    turn=rand()%2 + 1;
    restrictMouseArea(LEFT_CORNER,TOP_CORNER,BOARD_WIDTH + LEFT_CORNER ,BOARD_HEIGHT + TOP_CORNER);
    showMousePointer();
}
cell getCell(int x, int y, int cells[][8]){
    cell c;
    if(x<=LEFT_CORNER || x>= LEFT_CORNER + BOARD_WIDTH || y<=TOP_CORNER || y>= TOP_CORNER + BOARD_HEIGHT ){
        c.row=-1;
        c.col=-1;
    }else{
        c.row=(y-TOP_CORNER)/CELL_SIZE;
        c.col=(x-LEFT_CORNER)/CELL_SIZE;
    }
    c.type=cells[c.row][c.col];
    return c;
}

void moveQuarki(cell startCell, cell destCell, int & c){
    drawCell(startCell);
    destCell.type=startCell.type;
    putQuarki(destCell, c);
}
int main(){
    int button,x,y, turn;
    char key,ans;

    cell selectedCell={-1,-1,0};
    cell destCell=selectedCell;
    char msg[200];
    game g={{0}, "", ""};
    getPlayer(1, g.player1);
    getPlayer(2, g.player2);
    initialize(g,turn,1);
     do{
       if(kbhit()){
	key=getche();
	switch (key){
	case ESC:
            displayInfo ("Are you sure you want to end the game? (Y/y) to end any other key to return to game.");
            hideMousePointer();
           do{
                if(kbhit()){
                     ans=getche();
                    if(ans=='y' || ans=='Y'){
                            displayInfo ("Come Again ... ");
                            delay(1000);
                            restorecrtmode();
                            return 0;
                    }else
                       break;
               }
	    }while(1);
	    displayInfo("Select(R Click). Move (L Click). New Game(n). Quit(ESC).");
	    showMousePointer();
            break;
	case NEW_GAME:
	    initialize(g,turn,1);
	    break;
       }

    }
    mouseBtnPosition(&button, &x, &y);
    if(button==2){
	    selectedCell=getCell(x,y,g.cells);
	    button=-1;
    }else if(button==1){
       destCell=getCell(x,y,g.cells);
       if(selectedCell.row != -1) {
	   hideMousePointer();
	   moveQuarki(selectedCell, destCell,g.cells[destCell.row][destCell.col]);
           showMousePointer();
           selectedCell.row =-1;
           selectedCell.col=-1;
           selectedCell.type=0;
       }
           button=-1;
    }
  }while(1);

//return 0;
}
int StartMouse(){
    in.x.ax=0;
    int86(0x33,&in,&out);
    return(out.x.ax) ;
}
void showMousePointer(){
    in.x.ax=1;
    int86(0x33,&in,&out);
}
void restrictMouseArea(int x1, int y1, int x2, int y2){
    in.x.ax=7;
    in.x.cx=x1;
    in.x.dx=x2;
    int86(0x33,&in,&out);
    in.x.ax=8;
    in.x.cx=y1;
    in.x.dx=y2;
    int86(0x33,&in,&out);
}
void hideMousePointer(){
	in.x.ax=2;
	int86(0x33,&in,&out);
}
void mouseBtnPosition(int *button, int *x, int *y){
   in.x.ax=3;
   int86(0x33,&in,&out);
   *button=out.x.bx;
   *x=out.x.cx;
   *y=out.x.dx;
}
