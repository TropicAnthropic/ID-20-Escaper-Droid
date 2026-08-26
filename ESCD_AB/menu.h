#ifndef MENU_H
#define MENU_H

#include "globals.h"
#include "room.h"

void drawTitleScreen()
{
  sprites.drawSelfMasked(0, 0, titleScreen, 0);
  sprites.drawSelfMasked(17, 56, mainMenus, gameState);
  
}

void moveSelectors()
{
if (arduboy.everyXFrames(2))
  {
    selectorX++;
    selectorX2--;
  }
  if (selectorX > 31)selectorX = 20;
  if (selectorX2 < 21)selectorX2 = 32;
}

void stateMenuIntro()
{
  if (arduboy.everyXFrames(120))
  { 
    ATM.stop();
    ATM.play(menuSong);
    gameState = STATE_MENU_MAIN;
  }
  sprites.drawSelfMasked(49, 20, T_arg, 0);

}

void stateMenuMain()
{
  // show the titleScreen art
  drawTitleScreen();
  moveSelectors();
  sprites.drawPlusMask(selectorX + (menuSelection * 24), 56, selector_plus_mask, 0);
  sprites.drawPlusMask(selectorX2 + (menuSelection * 24), 56, selector_plus_mask, 0);
  if (arduboy.justPressed(RIGHT_BUTTON) && (menuSelection < 3)) menuSelection++;
  if (arduboy.justPressed(LEFT_BUTTON) && (menuSelection > 0)) menuSelection--;
  if (arduboy.justPressed(A_BUTTON | B_BUTTON)) gameState = menuSelection+1;
}

void stateMenuConf()
{
  byte offSet = 65 + (12 * (((player.assets & 0B10000000) == 0) ? FALSE : TRUE));
  drawTitleScreen();
  moveSelectors();
  sprites.drawPlusMask(selectorX + offSet, 56, selector_plus_mask, 0);
  sprites.drawPlusMask(selectorX2 + offSet, 56, selector_plus_mask, 0);
  if (arduboy.justPressed(RIGHT_BUTTON)) 
  {
    bitSet(player.assets,7);
    //Serial.println((bitRead(player.assets,7)));
  }
  if (arduboy.justPressed(LEFT_BUTTON)) 
  {
    bitClear(player.assets,7);
    //Serial.println((bitRead(player.assets,7)));
  }
  if (arduboy.justPressed(A_BUTTON | B_BUTTON))
  {
    gameState = STATE_MENU_MAIN;
  }
}

void stateMenuInfo()
{
  sprites.drawSelfMasked(16, 20, infoScreen, 0);
  if (arduboy.justPressed(A_BUTTON | B_BUTTON)) gameState = STATE_MENU_MAIN;
}

void stateMenuSdfx()
{
  byte offSet = 44 + (arduboy.audio.enabled() * 18);
  drawTitleScreen();
  moveSelectors();
  sprites.drawPlusMask(selectorX + offSet, 56, selector_plus_mask, 0);
  sprites.drawPlusMask(selectorX2 + offSet, 56, selector_plus_mask, 0);
  if (arduboy.justPressed(RIGHT_BUTTON)) arduboy.audio.on();
  if (arduboy.justPressed(LEFT_BUTTON)) arduboy.audio.off();
  if (arduboy.justPressed(A_BUTTON | B_BUTTON))
  {
    arduboy.audio.saveOnOff();
    gameState = STATE_MENU_MAIN;
  }
}

#endif
