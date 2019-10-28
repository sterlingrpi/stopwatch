/*****************************************************
 * RRproj1 - RRproj1.c - Ramon Rodriguez - 10/25/19
 * Stopwatch
 ****************************************************/
#include <hidef.h>      // common defines and macros
#include "derivative.h" // device spec. definitions

void delay (void);
void SysInit(void);
void main(void) {
// Local variables go here
volatile int m=0 ;
volatile int s=0 ;
volatile int d=0 ; 
int min=0 ;
int max=10 ;
int maxsec=6 ;
int last=0;
int button=0; //input 
int run=0
char a [10]={ 0x7E,0x30,0x6D,0x79,0x33,0x5B,0x5F,0x70,0x7F,0x7B};   // Array setup to save the values I will uses on my outputs to display numbers on the seven segment   
SysInit();    
while (1)  
{
      button=PORTA;
      if(button == 1 && last == 0)
            run != run;
      if (run == 1)
      button=last;
      {    // start running the counter. 
            for (d = min; d < maxsec; d++) 
            {
                  PORTB= a[d];
                  s=0;
                  for (s = min; s < max; s++) 
                  { 
                        PTT=a[s] ;
                        m=0;
                        for (m = min; m < max; m++) 
                        {
                              PTAD=a[m];
                              delay(); 
                        }
                   }
            }
      }
}

 if (button==2 || d==6){  // reset routine. 
    m=0;
    s=0;
    d=0;
  }
  }


  void delay ()
  {  //Delay subroutine with 1000milliseconds 
  int i;
  for (i=0;i<=10;i++) {  
  __asm {
          ldd #$C350
          nop
          nop 
          nop
          nop
          nop
          nop
          subd #$01   
           }
  }       
  }
  
void SysInit(void){
  COPCTL = 0x00;  // normally one-time writable 
    DDRA = 0;    //PORTA setup as an input
DDRB =0xFF;  //PORTB setup as an output utilize to display milliseconds
DDRT=0xFF;   //PORTT setup as an output utilize to display seconds
DDRAD=0xFF;  //PORTAD setup as an output utilize to display tenths of seconds.
PORTB = 0x7E;
PTAD = 0x7E;
PTT = 0x7E;
}
