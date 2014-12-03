//
//  main.cpp
//  Random_Prog
//
//  Created by Alex Hornford on 2014-10-24.
//  Copyright (c) 2014 Flaimion. All rights reserved.
//

//pinout
const int dataP = 2; 
const int clockP = 3;
const int latchP = 4;
const int dataN = 8; 
const int clockN = 9;
const int latchN = 10;
const int beat = 7;

bool beatDet = false;

const int DelayTime = 15;
//array size
const int Size =32;//size of grid

//array
bool Lights[Size][Size];

//print and reset for Lights array
void Print();
void resetLights();

//drawing functions

void Diamond();
void Square();
//void Rectangle();


void setup() {
  
    // initialize digital pin 13 as an output.
    pinMode(dataP, OUTPUT);
    pinMode(clockP, OUTPUT);  
    pinMode(latchP, OUTPUT);  
    pinMode(dataN, OUTPUT);
    pinMode(clockN, OUTPUT);  
    pinMode(latchN, OUTPUT);
    pinMode(beat, INPUT); 
    randomSeed(analogRead(5));
    resetLights();
    
    //Serial.begin(9600);
}

void loop(){    
        
       blue();       
        do{
        Print();
        }while(beatDet==false);
        resetLights();
       
        white();       
        do{
        Print();
        }while(beatDet==false);
        resetLights();
               
        /*green();  ******To Dim******     
        do{
        Print();
        }while(beatDet==false);
        resetLights();*/
               
        red();       
        do{
        Print();
        }while(beatDet==false);
        resetLights();
        
        yellow();       
        do{
        Print();
        }while(beatDet==false);
        resetLights();
        
        
}

/*void testPattern()
{
  
   for(int i=0;i<Size;i++)
{
  for(int j=0;j<Size;j++)
   {
       Serial.print(Lights[i][j]);
    }
    Serial.println("");
}  
  
}*/

void Print()
{
  	for(int i=0;i<Size;i++)
	{
		digitalWrite(latchP,LOW);
		digitalWrite(latchN,LOW);
		//set negative column
		for(int k=0;k<i+1;k++)
		{
			digitalWrite(dataN,HIGH);
			digitalWrite(clockN,HIGH);
			//delay(1);
			 digitalWrite(clockN,LOW);
		}
			digitalWrite(dataN,LOW);
			digitalWrite(clockN,HIGH);
			//delay(1);
			 digitalWrite(clockN,LOW);
                for(int k=i;k<Size;k++)
		{
			digitalWrite(dataN,HIGH);
			digitalWrite(clockN,HIGH);
			//delay(1);
			 digitalWrite(clockN,LOW);
		}
		//end of negative column set
		//set positive column
		for(int j=0;j<Size;j++)
		{
			if(Lights[i][j]==true)
			{
				digitalWrite(dataP,HIGH);
				digitalWrite(clockP,HIGH);
				//delay(1);
				 digitalWrite(clockP,LOW);
			}else{
				digitalWrite(dataP,LOW);
				digitalWrite(clockP,HIGH);
				//delay(1);
				digitalWrite(clockP,LOW);
			}
		}
		digitalWrite(latchP,HIGH);
		digitalWrite(latchN,HIGH);
                delay(DelayTime/2);
                if(digitalRead(beat)==HIGH)
                {
                 beatDet=true; 
                 return;
                }
                delay(DelayTime/2); 
	}
beatDet=false;
}

void resetLights()
{
  for(int i=0;i<Size;i++)
  {
    for(int j=0;j<Size;j++)
     {
       Lights[i][j]=false; 
      }
  }
  beatDet=false;
}


void blue()
{
  Lights[1][2]=true;Lights[1][3]=true;Lights[1][10]=true;Lights[1][11]=true;Lights[1][22]=true;Lights[1][23]=true;Lights[1][30]=true;Lights[1][31]=true;
  Lights[2][3]=true;Lights[2][4]=true;Lights[2][11]=true;Lights[2][12]=true;Lights[2][21]=true;Lights[2][22]=true;Lights[2][29]=true;Lights[2][30]=true;Lights[2][31]=true;
  Lights[3][3]=true;Lights[3][4]=true;Lights[3][11]=true;Lights[3][12]=true;Lights[3][21]=true;Lights[3][22]=true;Lights[3][29]=true;Lights[3][30]=true;
  Lights[4][5]=true;Lights[4][6]=true;Lights[4][13]=true;Lights[4][14]=true;Lights[4][19]=true;Lights[4][20]=true;Lights[4][27]=true;Lights[4][28]=true;
  Lights[5][5]=true;Lights[5][6]=true;Lights[5][13]=true;Lights[5][14]=true;Lights[5][19]=true;Lights[5][20]=true;Lights[5][27]=true;Lights[5][28]=true;
  Lights[6][7]=true;Lights[6][8]=true;Lights[6][17]=true;Lights[6][18]=true;Lights[6][25]=true;Lights[6][26]=true;
  Lights[7][0]=true;Lights[7][7]=true;Lights[7][8]=true;Lights[7][17]=true;Lights[7][18]=true;Lights[7][25]=true;Lights[7][26]=true;
  Lights[8][0]=true;Lights[8][1]=true;Lights[8][2]=true;Lights[8][9]=true;Lights[8][10]=true;Lights[8][23]=true;Lights[8][24]=true;
  Lights[9][1]=true;Lights[9][2]=true;Lights[9][9]=true;Lights[9][10]=true;Lights[9][23]=true;Lights[9][24]=true;Lights[9][31]=true;
  Lights[10][3]=true;Lights[10][4]=true;Lights[10][11]=true;Lights[10][12]=true;Lights[10][21]=true;Lights[10][22]=true;Lights[10][29]=true;Lights[10][30]=true;Lights[10][31]=true;
  Lights[11][3]=true;Lights[11][4]=true;Lights[11][11]=true;Lights[11][12]=true;Lights[11][21]=true;Lights[11][22]=true;Lights[11][29]=true;Lights[11][30]=true;
  Lights[12][5]=true;Lights[12][6]=true;Lights[12][13]=true;Lights[12][14]=true;Lights[12][19]=true;Lights[12][20]=true;Lights[12][27]=true;Lights[12][28]=true;
  Lights[13][5]=true;Lights[13][6]=true;Lights[13][13]=true;Lights[13][14]=true;Lights[13][19]=true;Lights[13][20]=true;Lights[13][27]=true;Lights[13][28]=true;
  Lights[14][7]=true;Lights[14][8]=true;Lights[14][17]=true;Lights[14][18]=true;Lights[14][25]=true;Lights[14][26]=true;
  Lights[15][7]=true;Lights[15][8]=true;Lights[15][17]=true;Lights[15][18]=true;Lights[15][25]=true;Lights[15][26]=true;
 
  Lights[18][5]=true;Lights[18][6]=true;Lights[18][13]=true;Lights[18][14]=true;Lights[18][19]=true;Lights[18][20]=true;Lights[18][27]=true;Lights[18][28]=true;
  Lights[19][5]=true;Lights[19][6]=true;Lights[19][13]=true;Lights[19][14]=true;Lights[19][19]=true;Lights[19][20]=true;Lights[19][27]=true;Lights[19][28]=true;
  Lights[20][3]=true;Lights[20][4]=true;Lights[20][11]=true;Lights[20][12]=true;Lights[20][21]=true;Lights[20][22]=true;Lights[20][29]=true;Lights[20][30]=true;
  Lights[21][3]=true;Lights[21][4]=true;Lights[21][11]=true;Lights[21][12]=true;Lights[21][21]=true;Lights[21][22]=true;Lights[21][29]=true;Lights[21][30]=true;Lights[21][31]=true;
  Lights[22][1]=true;Lights[22][2]=true;Lights[22][9]=true;Lights[22][10]=true;Lights[22][23]=true;Lights[22][24]=true;Lights[22][31]=true;
  Lights[23][0]=true;Lights[23][1]=true;Lights[23][2]=true;Lights[23][9]=true;Lights[23][10]=true;Lights[23][23]=true;Lights[23][24]=true;
  Lights[24][0]=true;Lights[24][7]=true;Lights[24][8]=true;Lights[24][17]=true;Lights[24][18]=true;Lights[24][25]=true;Lights[24][26]=true;
  Lights[25][0]=true;Lights[25][7]=true;Lights[25][8]=true;Lights[25][17]=true;Lights[25][18]=true;Lights[25][25]=true;Lights[25][26]=true;
  Lights[26][5]=true;Lights[26][6]=true;Lights[26][13]=true;Lights[26][14]=true;Lights[26][19]=true;Lights[26][20]=true;Lights[26][27]=true;Lights[26][28]=true;
  Lights[27][5]=true;Lights[27][6]=true;Lights[27][13]=true;Lights[27][14]=true;Lights[27][19]=true;Lights[27][20]=true;Lights[27][27]=true;Lights[27][28]=true;
  Lights[28][3]=true;Lights[28][4]=true;Lights[28][11]=true;Lights[28][12]=true;Lights[28][21]=true;Lights[28][22]=true;Lights[28][29]=true;Lights[28][30]=true;
  Lights[29][3]=true;Lights[29][4]=true;Lights[29][11]=true;Lights[29][12]=true;Lights[29][21]=true;Lights[29][22]=true;Lights[29][29]=true;Lights[29][30]=true;Lights[29][31]=true;
  Lights[30][1]=true;Lights[30][2]=true;Lights[30][9]=true;Lights[30][10]=true;Lights[30][23]=true;Lights[30][24]=true;Lights[30][31]=true;
  Lights[31][1]=true;Lights[31][2]=true;Lights[31][9]=true;Lights[31][10]=true;Lights[31][23]=true;Lights[31][24]=true;
}
void green()
{
  Lights[1][0]=true;Lights[1][1]=true;Lights[1][8]=true;Lights[1][9]=true;Lights[1][20]=true;Lights[1][21]=true;Lights[1][28]=true;Lights[1][29]=true;
  Lights[2][0]=true;Lights[2][1]=true;Lights[2][2]=true;Lights[2][9]=true;Lights[2][10]=true;Lights[2][19]=true;Lights[2][20]=true;Lights[1][27]=true;Lights[2][28]=true;
  Lights[3][1]=true;Lights[3][2]=true;Lights[3][8]=true;Lights[3][9]=true;Lights[3][10]=true;Lights[3][19]=true;Lights[2][20]=true;
  Lights[4][3]=true;Lights[4][4]=true;Lights[4][11]=true;Lights[4][12]=true;Lights[4][17]=true;Lights[4][18]=true;Lights[4][25]=true;Lights[4][26]=true;
  Lights[5][3]=true;Lights[5][4]=true;Lights[5][11]=true;Lights[5][12]=true;Lights[5][17]=true;Lights[5][18]=true;Lights[5][25]=true;Lights[5][26]=true;
  Lights[6][5]=true;Lights[6][6]=true;Lights[6][13]=true;Lights[6][14]=true;Lights[6][23]=true;Lights[6][24]=true;
  Lights[7][5]=true;Lights[7][6]=true;Lights[7][13]=true;Lights[7][14]=true;Lights[7][23]=true;Lights[7][24]=true;Lights[7][31]=true;
  Lights[8][7]=true;Lights[8][8]=true;Lights[8][21]=true;Lights[8][22]=true;Lights[8][29]=true;Lights[8][30]=true;Lights[8][31]=true;
  Lights[9][0]=true;Lights[9][7]=true;Lights[9][8]=true;Lights[9][21]=true;Lights[9][22]=true;Lights[9][29]=true;Lights[9][30]=true;
  Lights[10][0]=true;Lights[10][1]=true;Lights[10][2]=true;Lights[10][9]=true;Lights[10][10]=true;Lights[10][19]=true;Lights[10][20]=true;Lights[10][27]=true;Lights[10][28]=true;
  Lights[11][1]=true;Lights[11][2]=true;Lights[11][9]=true;Lights[11][10]=true;Lights[11][19]=true;Lights[11][20]=true;Lights[11][27]=true;Lights[11][28]=true;
  Lights[12][3]=true;Lights[12][4]=true;Lights[12][11]=true;Lights[12][12]=true;Lights[12][17]=true;Lights[12][18]=true;Lights[12][25]=true;Lights[12][26]=true;
  Lights[13][3]=true;Lights[13][4]=true;Lights[13][11]=true;Lights[13][12]=true;Lights[13][17]=true;Lights[13][18]=true;Lights[13][25]=true;Lights[13][26]=true;
  Lights[14][5]=true;Lights[14][6]=true;Lights[14][13]=true;Lights[14][14]=true;Lights[14][23]=true;Lights[14][24]=true;
  Lights[15][5]=true;Lights[15][6]=true;Lights[15][13]=true;Lights[15][14]=true;Lights[15][23]=true;Lights[15][24]=true;
  
  Lights[18][7]=true;Lights[18][8]=true;Lights[18][17]=true;Lights[18][18]=true;Lights[18][25]=true;Lights[18][26]=true;
  Lights[19][7]=true;Lights[19][8]=true;Lights[19][17]=true;Lights[19][18]=true;Lights[19][25]=true;Lights[19][26]=true;
  Lights[20][5]=true;Lights[20][6]=true;Lights[20][13]=true;Lights[20][14]=true;Lights[20][19]=true;Lights[20][20]=true;Lights[20][27]=true;Lights[20][28]=true;
  Lights[21][5]=true;Lights[21][6]=true;Lights[21][13]=true;Lights[21][14]=true;Lights[21][19]=true;Lights[21][20]=true;Lights[21][27]=true;Lights[21][28]=true;
  Lights[22][3]=true;Lights[22][4]=true;Lights[22][11]=true;Lights[22][12]=true;Lights[22][21]=true;Lights[22][22]=true;Lights[22][29]=true;Lights[22][30]=true;
  Lights[23][3]=true;Lights[23][4]=true;Lights[23][11]=true;Lights[23][12]=true;Lights[23][21]=true;Lights[23][22]=true;Lights[23][29]=true;Lights[23][30]=true;Lights[23][31]=true;
  Lights[24][1]=true;Lights[24][2]=true;Lights[24][9]=true;Lights[24][10]=true;Lights[24][23]=true;Lights[24][24]=true;Lights[24][31]=true;
  Lights[25][0]=true;Lights[25][1]=true;Lights[25][2]=true;Lights[25][9]=true;Lights[25][10]=true;Lights[25][23]=true;Lights[25][24]=true;
  Lights[26][0]=true;Lights[26][7]=true;Lights[26][8]=true;Lights[26][17]=true;Lights[26][18]=true;Lights[26][25]=true;Lights[26][26]=true;
  Lights[27][7]=true;Lights[27][8]=true;Lights[27][17]=true;Lights[27][18]=true;Lights[27][19]=true;Lights[27][25]=true;Lights[27][26]=true;
  Lights[28][5]=true;Lights[28][6]=true;Lights[28][19]=true;Lights[28][20]=true;Lights[28][27]=true;Lights[28][28]=true;
  Lights[29][5]=true;Lights[29][6]=true;Lights[29][19]=true;Lights[29][20]=true;Lights[29][27]=true;Lights[29][28]=true;
  Lights[30][3]=true;Lights[30][4]=true;Lights[30][21]=true;Lights[30][22]=true;Lights[30][29]=true;Lights[30][30]=true;
  Lights[31][3]=true;Lights[31][4]=true;Lights[31][21]=true;Lights[31][22]=true;Lights[31][29]=true;Lights[31][30]=true;Lights[31][31]=true;
}
void white()
{
  Lights[1][14]=true;Lights[1][15]=true;Lights[1][16]=true;Lights[1][17]=true;
  Lights[2][15]=true;Lights[2][16]=true;
  Lights[3][15]=true;Lights[3][16]=true;
  Lights[4][15]=true;Lights[4][16]=true;
  Lights[5][15]=true;Lights[5][16]=true;
  Lights[6][15]=true;Lights[6][16]=true;
  Lights[7][15]=true;Lights[7][16]=true;
  Lights[8][15]=true;Lights[8][16]=true;
  Lights[9][15]=true;Lights[9][16]=true;
  Lights[10][15]=true;Lights[10][16]=true;
  Lights[11][15]=true;Lights[11][16]=true;
  Lights[12][15]=true;Lights[12][16]=true;
  Lights[13][15]=true;Lights[13][16]=true;
  Lights[14][15]=true;Lights[14][16]=true;
  Lights[15][0]=true;Lights[15][15]=true;Lights[15][16]=true;Lights[15][31]=true;
 
 Lights[16][0]=true;Lights[16][1]=true;Lights[16][2]=true;Lights[16][3]=true;Lights[16][4]=true;Lights[16][5]=true;Lights[16][6]=true;Lights[16][7]=true;
 Lights[16][8]=true;Lights[16][9]=true;Lights[16][10]=true;Lights[16][11]=true;Lights[16][12]=true;Lights[16][13]=true;Lights[16][14]=true;Lights[16][15]=true;
 Lights[16][16]=true;Lights[16][17]=true;Lights[16][18]=true;Lights[16][19]=true;Lights[16][20]=true;Lights[16][21]=true;Lights[16][22]=true;Lights[16][23]=true;
 Lights[16][24]=true;Lights[16][25]=true;Lights[16][26]=true;Lights[16][27]=true;Lights[16][28]=true;Lights[16][29]=true;Lights[16][30]=true;Lights[16][31]=true;
 
  Lights[17][0]=true;Lights[17][1]=true;Lights[17][2]=true;Lights[17][3]=true;Lights[17][4]=true;Lights[17][5]=true;Lights[17][6]=true;Lights[17][7]=true;
 Lights[17][8]=true;Lights[17][9]=true;Lights[17][10]=true;Lights[17][11]=true;Lights[17][12]=true;Lights[17][13]=true;Lights[17][14]=true;Lights[17][15]=true;
 Lights[17][16]=true;Lights[17][17]=true;Lights[17][18]=true;Lights[17][19]=true;Lights[17][20]=true;Lights[17][21]=true;Lights[17][22]=true;Lights[17][23]=true;
 Lights[17][24]=true;Lights[17][25]=true;Lights[17][26]=true;Lights[17][27]=true;Lights[17][28]=true;Lights[17][29]=true;Lights[17][30]=true;Lights[17][31]=true;
 
 Lights[18][0]=true; Lights[18][15]=true;Lights[18][16]=true;Lights[18][31]=true;
  Lights[19][15]=true;Lights[19][16]=true;
  Lights[20][15]=true;Lights[20][16]=true;
  Lights[21][15]=true;Lights[21][16]=true;
  Lights[22][15]=true;Lights[22][16]=true;
  Lights[23][15]=true;Lights[23][16]=true;
  Lights[24][15]=true;Lights[24][16]=true;
  Lights[25][15]=true;Lights[25][16]=true;
  Lights[26][15]=true;Lights[26][16]=true;
  Lights[27][15]=true;Lights[27][16]=true;
  Lights[28][15]=true;Lights[28][16]=true;
  Lights[29][15]=true;Lights[29][16]=true;
  Lights[30][15]=true;Lights[30][16]=true;
  Lights[31][14]=true;Lights[31][15]=true;Lights[31][16]=true;Lights[31][17]=true;

}

void red()
{
  Lights[1][4]=true;Lights[1][5]=true;Lights[1][12]=true;Lights[1][13]=true;Lights[1][24]=true;Lights[1][25]=true;
  Lights[2][5]=true;Lights[2][6]=true;Lights[2][13]=true;Lights[2][14]=true;Lights[2][23]=true;Lights[2][24]=true;
  Lights[3][5]=true;Lights[3][6]=true;Lights[3][13]=true;Lights[3][14]=true;Lights[3][23]=true;Lights[3][24]=true;Lights[2][31]=true;
  Lights[4][7]=true;Lights[4][8]=true;Lights[4][21]=true;Lights[4][22]=true;Lights[4][29]=true;Lights[4][30]=true;Lights[4][31]=true;
  Lights[5][0]=true;Lights[5][7]=true;Lights[5][8]=true;Lights[5][21]=true;Lights[5][22]=true;Lights[5][29]=true;Lights[5][30]=true;
  Lights[6][0]=true;Lights[6][1]=true;Lights[6][2]=true;Lights[6][9]=true;Lights[6][10]=true;Lights[6][19]=true;Lights[6][20]=true;Lights[6][27]=true;Lights[6][28]=true;
  Lights[7][1]=true;Lights[7][2]=true;Lights[7][9]=true;Lights[7][10]=true;Lights[7][19]=true;Lights[7][20]=true;Lights[7][27]=true;Lights[7][28]=true;
  Lights[8][3]=true;Lights[8][4]=true;Lights[8][11]=true;Lights[8][12]=true;Lights[8][17]=true;Lights[8][18]=true;Lights[8][25]=true;Lights[8][26]=true;
  Lights[9][3]=true;Lights[9][4]=true;Lights[9][11]=true;Lights[9][12]=true;Lights[9][17]=true;Lights[9][18]=true;Lights[9][25]=true;Lights[9][26]=true;
  Lights[10][5]=true;Lights[10][6]=true;Lights[10][13]=true;Lights[10][14]=true;Lights[10][23]=true;Lights[10][24]=true;
  Lights[11][5]=true;Lights[11][6]=true;Lights[11][13]=true;Lights[11][14]=true;Lights[11][23]=true;Lights[11][24]=true;Lights[11][31]=true;
  Lights[12][7]=true;Lights[12][8]=true;Lights[12][21]=true;Lights[12][22]=true;Lights[12][29]=true;Lights[12][30]=true;Lights[12][31]=true;
  Lights[13][0]=true;Lights[13][7]=true;Lights[13][8]=true;Lights[13][21]=true;Lights[13][22]=true;Lights[13][29]=true;Lights[13][30]=true;
  Lights[14][0]=true;Lights[14][1]=true;Lights[14][2]=true;Lights[14][9]=true;Lights[14][10]=true;Lights[14][19]=true;Lights[14][20]=true;Lights[14][27]=true;Lights[14][28]=true;
  Lights[15][1]=true;Lights[15][2]=true;Lights[15][9]=true;Lights[15][10]=true;Lights[15][19]=true;Lights[15][20]=true;Lights[15][27]=true;Lights[15][28]=true;
  
  Lights[18][3]=true;Lights[18][4]=true;Lights[18][11]=true;Lights[18][12]=true;Lights[18][21]=true;Lights[18][22]=true;Lights[18][29]=true;Lights[18][30]=true;
  Lights[19][3]=true;Lights[19][4]=true;Lights[19][11]=true;Lights[19][12]=true;Lights[19][21]=true;Lights[19][22]=true;Lights[19][29]=true;Lights[19][30]=true;Lights[19][31]=true;
  Lights[20][1]=true;Lights[20][2]=true;Lights[20][9]=true;Lights[20][10]=true;Lights[20][23]=true;Lights[20][24]=true;Lights[20][31]=true;
  Lights[21][0]=true;Lights[21][1]=true;Lights[21][2]=true;Lights[21][9]=true;Lights[21][23]=true;Lights[21][24]=true;
  Lights[22][0]=true;Lights[22][7]=true;Lights[22][8]=true;Lights[22][17]=true;Lights[22][18]=true;Lights[22][25]=true;Lights[22][26]=true;
  Lights[23][7]=true;Lights[23][8]=true;Lights[23][17]=true;Lights[23][18]=true;Lights[23][25]=true;Lights[23][26]=true;
  Lights[24][5]=true;Lights[24][6]=true;Lights[24][13]=true;Lights[24][14]=true;Lights[24][19]=true;Lights[24][20]=true;Lights[24][27]=true;Lights[24][28]=true;
  Lights[25][5]=true;Lights[25][6]=true;Lights[25][13]=true;Lights[25][14]=true;Lights[25][19]=true;Lights[25][20]=true;Lights[25][27]=true;Lights[25][28]=true;
  Lights[26][3]=true;Lights[26][4]=true;Lights[26][11]=true;Lights[26][12]=true;Lights[26][21]=true;Lights[26][22]=true;Lights[26][29]=true;Lights[26][30]=true;
  Lights[27][3]=true;Lights[27][4]=true;Lights[27][11]=true;Lights[27][12]=true;Lights[27][21]=true;Lights[27][22]=true;Lights[27][29]=true;Lights[27][30]=true;Lights[27][31]=true;
  Lights[28][1]=true;Lights[28][2]=true;Lights[28][9]=true;Lights[28][10]=true;Lights[28][13]=true;Lights[28][23]=true;Lights[14][24]=true;Lights[14][31]=true;
  Lights[29][0]=true;Lights[29][1]=true;Lights[29][2]=true;Lights[29][9]=true;Lights[29][10]=true;Lights[29][13]=true;Lights[29][14]=true;Lights[29][23]=true;Lights[29][24]=true;
  Lights[30][0]=true;Lights[30][7]=true;Lights[30][8]=true;Lights[30][11]=true;Lights[30][13]=true;Lights[30][14]=true;Lights[30][17]=true;Lights[30][18]=true;Lights[30][25]=true;Lights[30][26]=true;
  Lights[31][7]=true;Lights[31][8]=true;Lights[31][11]=true;Lights[31][13]=true;Lights[31][14]=true;Lights[31][17]=true;Lights[31][18]=true;Lights[31][25]=true;Lights[31][26]=true;
}

void yellow()
{
   Lights[1][6]=true;Lights[1][7]=true;Lights[1][18]=true;Lights[1][19]=true;Lights[1][26]=true;Lights[1][27]=true;
  Lights[2][7]=true;Lights[2][8]=true;Lights[2][17]=true;Lights[2][18]=true;Lights[2][25]=true;Lights[2][26]=true;
  Lights[3][0]=true;Lights[3][7]=true;Lights[3][8]=true;Lights[3][17]=true;Lights[3][18]=true;Lights[3][25]=true;Lights[2][25]=true;
  Lights[4][0]=true;Lights[4][1]=true;Lights[4][2]=true;Lights[4][9]=true;Lights[4][10]=true;Lights[4][23]=true;Lights[4][24]=true;
  Lights[5][1]=true;Lights[5][2]=true;Lights[5][9]=true;Lights[5][10]=true;Lights[5][23]=true;Lights[5][24]=true;Lights[5][31]=true;
  Lights[6][3]=true;Lights[6][4]=true;Lights[6][11]=true;Lights[6][12]=true;Lights[6][21]=true;Lights[6][22]=true;Lights[6][29]=true;Lights[6][30]=true;Lights[6][31]=true;
  Lights[7][3]=true;Lights[7][4]=true;Lights[7][11]=true;Lights[7][12]=true;Lights[7][21]=true;Lights[7][22]=true;Lights[7][29]=true;Lights[7][30]=true;
  Lights[8][5]=true;Lights[8][6]=true;Lights[8][13]=true;Lights[8][14]=true;Lights[8][19]=true;Lights[8][20]=true;Lights[8][27]=true;Lights[8][28]=true;
  Lights[9][5]=true;Lights[9][6]=true;Lights[9][13]=true;Lights[9][14]=true;Lights[9][19]=true;Lights[9][20]=true;Lights[9][27]=true;Lights[9][28]=true;
  Lights[10][7]=true;Lights[10][8]=true;Lights[10][17]=true;Lights[10][18]=true;Lights[10][25]=true;Lights[10][26]=true;
  Lights[11][0]=true;Lights[11][7]=true;Lights[11][8]=true;Lights[11][17]=true;Lights[11][18]=true;Lights[11][25]=true;Lights[11][26]=true;
  Lights[12][0]=true;Lights[12][1]=true;Lights[12][2]=true;Lights[12][9]=true;Lights[12][10]=true;Lights[12][23]=true;Lights[12][24]=true;
  Lights[13][1]=true;Lights[13][2]=true;Lights[13][9]=true;Lights[13][10]=true;Lights[13][23]=true;Lights[13][24]=true;Lights[13][31]=true;
  Lights[14][3]=true;Lights[14][4]=true;Lights[14][11]=true;Lights[14][12]=true;Lights[14][21]=true;Lights[14][22]=true;Lights[14][29]=true;Lights[14][30]=true;Lights[14][31]=true;
  Lights[15][3]=true;Lights[15][4]=true;Lights[15][11]=true;Lights[15][12]=true;Lights[15][21]=true;Lights[15][22]=true;Lights[15][29]=true;Lights[15][30]=true;
  
  Lights[18][1]=true;Lights[18][2]=true;Lights[18][9]=true;Lights[18][10]=true;Lights[18][19]=true;Lights[18][20]=true;Lights[18][27]=true;Lights[18][28]=true;
  Lights[19][0]=true;Lights[19][1]=true;Lights[19][2]=true;Lights[19][9]=true;Lights[19][10]=true;Lights[19][19]=true;Lights[19][20]=true;Lights[19][27]=true;Lights[19][28]=true;
  Lights[20][0]=true;Lights[20][7]=true;Lights[20][8]=true;Lights[20][21]=true;Lights[20][22]=true;Lights[20][29]=true;Lights[20][30]=true;
  Lights[21][7]=true;Lights[21][8]=true;Lights[21][21]=true;Lights[21][22]=true;Lights[21][29]=true;Lights[21][30]=true;Lights[21][31]=true;
  Lights[22][5]=true;Lights[22][6]=true;Lights[22][13]=true;Lights[22][14]=true;Lights[22][23]=true;Lights[22][24]=true;Lights[22][31]=true;
  Lights[23][5]=true;Lights[23][6]=true;Lights[23][13]=true;Lights[23][14]=true;Lights[23][23]=true;Lights[23][24]=true;
  Lights[24][3]=true;Lights[24][4]=true;Lights[24][11]=true;Lights[24][12]=true;Lights[24][17]=true;Lights[24][18]=true;Lights[24][25]=true;Lights[24][26]=true;
  Lights[25][3]=true;Lights[25][4]=true;Lights[25][11]=true;Lights[25][12]=true;Lights[25][17]=true;Lights[25][18]=true;Lights[25][25]=true;Lights[25][26]=true;
  Lights[26][1]=true;Lights[26][2]=true;Lights[26][9]=true;Lights[26][10]=true;Lights[26][19]=true;Lights[26][20]=true;Lights[26][27]=true;Lights[26][28]=true;
  Lights[27][0]=true;Lights[27][1]=true;Lights[27][2]=true;Lights[27][9]=true;Lights[27][10]=true;Lights[27][19]=true;Lights[27][20]=true;Lights[27][27]=true;Lights[27][28]=true;
  Lights[28][0]=true;Lights[28][7]=true;Lights[28][8]=true;Lights[28][21]=true;Lights[28][22]=true;Lights[28][29]=true;Lights[28][30]=true;
  Lights[29][7]=true;Lights[29][8]=true;Lights[29][21]=true;Lights[29][22]=true;Lights[29][29]=true;Lights[29][30]=true;Lights[29][31]=true;
  Lights[30][5]=true;Lights[30][6]=true;Lights[30][13]=true;Lights[30][14]=true;Lights[30][23]=true;Lights[30][24]=true;Lights[30][31]=true;
  Lights[31][5]=true;Lights[31][6]=true;Lights[31][13]=true;Lights[31][14]=true;Lights[31][23]=true;Lights[31][24]=true;Lights[31][31]=true;
}
