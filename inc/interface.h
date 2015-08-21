int choix;
int menuScroll;

int menuScrollLevel()
  {
    if ( menuScroll == 1 ) { mainMenu(); }
    else if ( menuScroll == 2 ) { optMenu(); }
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
    int menuScroll = 1;
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

}
void optMenu()
{
  LcdString("optMenu works");
}
void steve()
{
  LcdString("steve");
}
void doCalibrate()
{
  LcdString("doCalibrate");
}
