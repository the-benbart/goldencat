////////////////////////////////////////////////////////////////////////////////
//                          INIT variables                                    //
////////////////////////////////////////////////////////////////////////////////

int token = 1;
struct config // Core configuration, PLEASE DON'T TOUCH
{
  int calibrageSpeed[3]; // 0-2 speed to Calibrate, DO NOT TOUCH
  int downSpeed[3]; // 0-2 speed to DOWN, DO NOT TOUCH
  int holdSleep[3]; // Time to incubate, DO NOT TOUCH
  int upSpeed[3]; // 0-2 speed to UP, DO NOT TOUCH
  int alertMod[3]; // 0=No Alert / 1 = Few 3 bip alert / 2 = One bip every 5 seconds
}
////////////////////////////////////////////////////////////////////////////////
//                           calibrage stage                                  //
////////////////////////////////////////////////////////////////////////////////
int doCalibrate()
  {
    screen(calibrageStart);
    while ( captorUP != 1 || token == 1 ) //
    {
      screen(calibrageRUN);
      gearsUp(struct config(calibrageSpeed));
      token = token++;
    }
    screen(calibrageStop);
    if ( token != 2 )
    {
      screen(tokenError);
      break;
    }
  }
////////////////////////////////////////////////////////////////////////////////
//                            gearsDown stage                                 //
////////////////////////////////////////////////////////////////////////////////
int doDown()
  {
    screen(downStart);
    while ( captorDown != 1 || token == 2 )
    {
      screen(downRUN);
      gearsDown(struct config(downSpeed));
      token = token++;
    }
    screen(downStop);
    if ( token != 3 )
    {
      screen(tokenError);
      break;
    }
  }
////////////////////////////////////////////////////////////////////////////////
//                            Peigne gearsHold stage                          //
////////////////////////////////////////////////////////////////////////////////
int doHold()
    {
      screen(holdStart);
      while (captorDown == 1 || token == 3)
      {
        screen(holdRUN);
        sleep(struct config(holdSleep));
        token = token++;
      }
      screen(holdStop);
      if ( token != 4 )
      {
        screen(tokenError);
        break;
      }
    }
////////////////////////////////////////////////////////////////////////////////
//                              Peigne gearsUp stage                          //
////////////////////////////////////////////////////////////////////////////////
int doUp()
      {
        screen(upStart);
        while ( captorUp != 1 || token == 4 )
        {
          screen(upRUN);
          gearsUp(struct config(upSpeed));
          token = token++;
        }
        screen(upStop);
        if ( token != 5 )
        {
          screen(tokenError);
          break;
        }
      }
////////////////////////////////////////////////////////////////////////////////
//                                Peigne Alert stage                          //
////////////////////////////////////////////////////////////////////////////////
int doAlert()
      {
        screen(alertStart);
        while ( captorDown == 1 || token == 5 )
        {
          screen(alertRUN);
          bipAlert(struct config(alertMod));
          token = token++;
          interface(any);
        }
        screen(alertStop);
        if ( token != 6 )
        {
          screen(tokenError);
          break;
        }
      }
////////////////////////////////////////////////////////////////////////////////
//                                Steve loop                                  //
////////////////////////////////////////////////////////////////////////////////


  int steve(void)
  {
    doCalibrate();
    doDown();
    doHold();
    doUp();
    doAlert();
  }
