

// bolean loading_screen = false;

void thisDraw(String trash, int x, int y, int fontSize){
  tft.setTextColor(TFT_WHITE);          //sets the text colour to black
  tft.setTextSize(fontSize);                   //sets the size of text
  tft.drawString(trash, x, y);
}

void welcomeLogin(){
    clearDisplay(TFT_DARKGREEN);
    thisDraw("\t\t\tGroup 2", 10, 10, 3) ;
    thisDraw("--  Lazy Trashcan  --   ", 10, 40, 2);
    thisDraw("--------------------", 10, 60, 2) ;
    thisDraw("... Booting ...", 10, 100, 2);
    delay(1000);
    thisDraw("... Loading files...", 10, 120, 2);
    delay(1000);
    thisDraw("... Loading Servos...", 10, 140, 2) ;
    delay(3000);
    thisDraw("... Completed.", 10, 160, 2) ;
    delay(3000);
    finishLoadingScreen = true;
    idleStatus = true;
    clearDisplay(TFT_BLUE);
}

void clearDisplay(uint32_t color){
      tft.fillScreen(color);
}

void idleDisplay(){
    thisDraw("\t\t\tGroup 2", 10, 10, 3) ;
    thisDraw("--  Lazy Trashcan  --   ", 10, 40, 2);
    thisDraw("--------------------", 10, 60, 2) ;
    
    //thisDraw("- 19:31 hs ...", 10, 80, 2);
    getTime();
    
    // delay(1000);
    thisDraw("- Temperature: 24 Celsius", 10, 100, 2);
    // delay(1000);
    thisDraw("- Humidity: 62%", 10, 120, 2) ;
    // delay(3000);
    thisDraw("- Wifi Status: OK", 10, 140, 2) ;
    // delay(3000);
    thisDraw("- Light Mode: day", 10, 160, 2) ;
    // delay(3000);
    thisDraw("- Trash sensor: Nothing.", 10, 180, 2) ;
    // delay(3000);
    // finishLoadingScreen = true;
}
