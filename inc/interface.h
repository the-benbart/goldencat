int choix;
int menuScroll;

int menuScrollLevel()
  {
    if ( menuScroll == 1 ) { mainMenu(); }
    //else if ( menuScroll == 2 ) { optMenu(); }
    else { /*screen(ErrmenuScrollLevel)*/; delay(1000); mainMenu(); }
  }
int menuTicket(int cursor)
  {
    if (cursor == choix) { LcdString ("->");  }
    else { LcdString ("- "); }
  }
int menuBehavor()
{
  switch (keypad())
  {
    case 1:
    menuScroll--;
    break;
    case 2:
    choix--;
    break;
    case 3:
    choix++;
    break;
    case 4:
    menuScroll++;
    break;
  }
}
int mainMenu()
  {
    menuScroll = 1;
    menuBehavor();
    if ( choix == NULL ) { choix = 1; }
    else if ( choix >= 3 ) { choix = 3; }
    else if ( choix <= 1 ) { choix = 1; }
    if ( menuScroll == 2 )
     {
       switch (choix)
       {
         case 1:
         steve();
         break;
         case 2:
         optMenu();
         break;
         case 3:
         doCalibrate();
         break;
       }
     }
  gotoXY(25,0);
  LcdString (" Menu");
  gotoXY(0,2);
  menuTicket(1);
  LcdString (" Lancer");
  gotoXY(0,3);
  menuTicket(2);
  LcdString (" Options");
  gotoXY(0,4);
  menuTicket(3);
  LcdString (" Calibrer");
  delay(100);
  LcdClear();

}
void optMenu()
{
  menuScroll = 2;
  menuBehavor();
  if ( choix == NULL ) { choix = 1; }
  else if ( choix >= 4 ) { choix = 4; }
  else if ( choix <= 1 ) { choix = 1; }
  if ( menuScroll == 3 )
   {
     switch (choix)
     {
       case 1:
       optSpeedUp();
       break;
       case 2:
       optSpeedDown();
       break;
       case 3:
       optIncubTime();
       break;
       case 4:
       optAlertType();
       break;
     }
   }
LcdClear();
gotoXY(5,0);
LcdString (" Menu/options");
gotoXY(0,2);
menuTicket(1);
LcdString (" Vitesse Monté");
gotoXY(0,3);
menuTicket(2);
LcdString (" Vitesse Descente");
gotoXY(0,4);
menuTicket(3);
LcdString (" Temps incubation");
gotoXY(0,5);
menuTicket(4);
LcdString (" Type d'alerte");
delay(100);
}
void steve()
{
  LcdClear();
  LcdString("steve");
  delay(1000);
  LcdClear();
}
void doCalibrate()
{
  LcdClear();
  LcdString("doCalibrate");
  delay(1000);
  LcdClear();
}
void optSpeedUp()
{
  LcdClear();
  LcdString("optSpeedUp");
  delay(1000);
  LcdClear();
}
void optSpeedDown()
{
  LcdClear();
  LcdString("optSpeedDown");
  delay(1000);
  LcdClear();
}
void optIncubTime()
{
  LcdClear();
  LcdString("optIncubTime");
  delay(1000);
  LcdClear();
}
void optAlertType()
{
  LcdClear();
  LcdString("optAlertType");
  delay(1000);
  LcdClear();
}
