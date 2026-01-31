# Epaper partial update
This project shows how to update an epaper display partially, which is faster than a full update.
It writes a text on the panel, then a number. The number is then updated every minute, but the text remains untouched. Just the area where the number is printed is updated, a partial update of the screen.
The hardware used is a ESP32S3 and a ​​WeAct 2.13" Black&White Epaper Module. The connections for the screen is set in epaper.h, and you have to adjust the displat type in epaper.cpp if you use a different type. See https://github.com/ZinggJM/GxEPD2 for more info.