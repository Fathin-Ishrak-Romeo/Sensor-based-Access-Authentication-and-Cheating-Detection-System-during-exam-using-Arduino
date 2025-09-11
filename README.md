# Components List
1. Arduino UNO x2
2. RFID MFRC522
3. RFID Tags x2(at least)
4. 16x2 LCD Display
5. I2C Module for LCD Display
6. SG90 Servo
7. Buzzer x2
8. Different Color LED x9 ()
9. Resistor (220 Ohm) x3
10. Breadboard: Large 1x OR Medium 2x
11. Jumper Wire (Male to Male, Male to Female)
12. Electric Wire



# Full Setup & Installation Guidelines:
## Module 1: Access Authentication System
1. Ensure the circuit below is built before uploading the code. </br>

<img src="Module 1 Access Authentication System/Student Access Authentication System Circuit.PNG" alt="Student Access Authentication System Circuit Diagram" width="700"> </br>

2. Open Arduino IDE.
3. Go to: Tools > Manage Libraries > Search: "MFRC522 by Github Community" > Select Version: 1.4.10 > Install.
4. Go to: Tools > Manage Libraries > Search: "LiquidCrystal_I2C by Martin Kobuvvcik, Frank de Brabander" > Select Version: 2.0.0 > Install.
5. Connect the Arduino to the PC's USB port with the whole circuit setup.
6. Go to: Tools > Board > Arduino AVR Boards > Select: Arduino UNO.
7. Go to: Tools > Port > Select the port to which the Arduino is connected (If multiple ports are shown, try connecting one by one to find out the actual port).
8. Now open the [RFID_UID_Program.ino](https://github.com/Fathin-Ishrak-Romeo/Sensor-based-Smart-Desk-with-Student-Access-Authentication-System-during-exam-using-Arduino/blob/main/Module%201%20Access%20Authentication%20System/RFID_UID_Program/RFID_UID_Program.ino) file in Arduino IDE & upload it.
9. Open the serial monitor from the top right of the Arduino IDE.
10. It will ask to Scan your RFID card.
11. Scan any of the RFID tags that you want to make the key.
12. Copy the UID that appears in the serial monitor.
13. Now open the [Student_Access_Authentication_Program.ino](https://github.com/Fathin-Ishrak-Romeo/Sensor-based-Smart-Desk-with-Student-Access-Authentication-System-during-exam-using-Arduino/blob/main/Module%201%20Access%20Authentication%20System/Student_Access_Authentication_Program/Student_Access_Authentication_Program.ino) file.
14. Look for the variable named "String MasterTag" and replace the value in the variable with the previously copied UID.
15. Save the program.
16. Upload it.
17. Open the [I2C_Scanner_Program_for_LCD_Display.ino](https://github.com/Fathin-Ishrak-Romeo/Sensor-based-Smart-Desk-with-Student-Access-Authentication-System-during-exam-using-Arduino/blob/main/Module%201%20Access%20Authentication%20System/I2C_Scanner_Program_for_LCD_Display/I2C_Scanner_Program_for_LCD_Display.ino) file & upload it.
18. Open the serial monitor from the top right of the Arduino IDE.
19. Copy the I2C address of the display (e.g. 0x27, 0x38, 0x39, 0x42, etc.)
20. Now open the [Student_Access_Authentication_Program.ino](https://github.com/Fathin-Ishrak-Romeo/Sensor-based-Smart-Desk-with-Student-Access-Authentication-System-during-exam-using-Arduino/blob/main/Module%201%20Access%20Authentication%20System/Student_Access_Authentication_Program/Student_Access_Authentication_Program.ino) file.
21. Look for the function named "LiquidCrystal_I2C lcd" and replace the first parameter with the previously copied I2C address.
22. Save the program.
23. Upload it.
24. Now, power the whole setup by connecting the Arduino cable to a 5V power source or PC, or by connecting the "Vin" pin of the Arduino UNO to the +ve terminal of a 5V power source and any of the "GND" pins to the -ve terminal of the power source.


# License
This project is licensed under the MIT License.
