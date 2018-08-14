
//Used to get ISS location and update map
//This runs about every 10 seconds - the delay can be changed if desired.

void decodeLocJson( void * parameter) {
  delay(1500);
  M5.Lcd.clearDisplay();
  M5.Lcd.fillScreen(0x0000);
  M5.Lcd.display();
  for(;;) {
    getJson(iss);
  StaticJsonBuffer<512> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(payload);
  if (!root.success()) {
    Serial.println("parseObject() failed");
    return;
  }
  isslat=root["iss_position"]["latitude"];
  isslon=root["iss_position"]["longitude"];
  ISSCoord = String(root["iss_position"]["latitude"].as<char*>()) + "," + String(root["iss_position"]["longitude"].as<char*>());
  Serial.println("ISSCoord = " + ISSCoord);
  getDistance();
  Serial.print("The ISS is currently at ");
  Serial.print(isslat, 4); Serial.print(","); Serial.println(isslon,4);
  Serial.print("The ISS is about "); Serial.print(distance); Serial.println(" miles from you now.\nAnd moving fast!");
  updateMap(zoom);
  delay(5000); //There has to be a better way.
 }
}

//updateMap function code by Giuliano Pisoni  
void updateMap(int zoom){

 if (mode == 0) {
  Serial.println("UPDATE MAP START");
  unsigned long currentMillis = millis();
  if (currentMillis - locpreviousMillis >= 10000 || zoom != zoomChange) {
  downloadFile("http://maps.googleapis.com/maps/api/staticmap?center=" + coordinate + "&zoom=" + String(zoom) + "&format=jpg-baseline&size=320x220&maptype=roadmap&markers=size:tiny%7C" + coordinate + "&markers=icon:https://images.srad.jp/topics/iss_64.png%7Cshadow:false%7C" + ISSCoord, "/staticmap.jpg");
  locpreviousMillis = currentMillis;
  zoomChange = zoom;
  }
        //M5.Lcd.clearDisplay();
        //M5.Lcd.setBrightness(200);
        M5.Lcd.setTextColor(0xFFFF);
        //M5.Lcd.fillScreen(0x0000);
        M5.Lcd.setFreeFont(FF18);
        M5.Lcd.drawJpgFile(SPIFFS, "/staticmap.jpg");
        M5.Lcd.drawString("ZOOM -     FUNC      ZOOM +", 10, 220,GFXFF);
        M5.Lcd.display();
   
        displayTime();
 }
}
