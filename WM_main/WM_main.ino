#include "ControlPanel.h"
#include "LED.h"
#include "TwinDos.h";

#define TWIN_DOS_PIN 32

static uint8_t lastButtonPressed_8;
static uint8_t R_pin_u8 = 25;
static uint8_t G_pin_u8 = 26;
static uint8_t B_pin_u8 = 27;

LED led(R_pin_u8, G_pin_u8, B_pin_u8);
TwinDos twinDos_o;
ControlPanel controlPanel_o;

bool doorButtonPressed_b = false;
bool startButtonPressed_b = false;


void setup()
{
    // put your setup code here, to run once:

    Serial.begin(9600);                 // serial init for test messages
    delay(1500);                        // give time to Wemos Lolin32 to finish setup
    controlPanel_o.Initialise_e();      //be sure to initialise "s_pinLocation_au8[]" with propper pins
    led.setColor_v(0, 0, 0);

    twinDos_o.Initialise_e(TWIN_DOS_PIN); //setup TwinDos pin number    
}

void loop()
{ 


    // SCENARIO 2
    lastButtonPressed_8 = controlPanel_o.poolButtonsStateChanges_u8(); // constantly check if a button was pressed
  
    //
    switch(lastButtonPressed_8)
    {
    case BUTTON_POWER_ID:
        Serial.println("Power button pressed");
        break;

        break;
    default:        
        break;
    }
                

    
}
