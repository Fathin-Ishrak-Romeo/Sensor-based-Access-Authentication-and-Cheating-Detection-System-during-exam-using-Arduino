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



# How to 
## Module 1: Access Authentication System
1. Make sure the circuit below is built first before uploading the code. </br>

<img src="Module 1 Access Authentication System/Student Access Authentication System Circuit.PNG" alt="Student Access Authentication System Circuit Diagram" width="700"> </br>

2. Open Arduino IDE.
3. Go to: Tools > Manage Libraries > Search: "MFRC522 by Github Community" > Select Version: 1.4.10 > Install.
4. Connect the Arduino with the whole setup to the PC's USB port.
5. Go to: Tools > Board > Arduino AVR Boards > Select: Arduino UNO.
6. Go to: Tools > Port > Select the port to which the Arduino is connected (If multiple ports are shown, try connecting one by one to find out the actual port).
7. Now open the [RFID_UID_Program](Module 1 Access Authentication System/RFID_UID_Program/RFID_UID_Program.ino) file in Arduino IDE & upload it.
8. Open the serial monitor from the top right of the Arduino IDE.
9. It will ask to Scan your RFID card.
10. Scan any of the RFID tags that you want to make the key.
11. Copy the UID that appears in the serial monitor.
12. Now open the 


# License
This project is licensed under the MIT License.
