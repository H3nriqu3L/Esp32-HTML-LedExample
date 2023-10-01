# Esp32-HTML-LedExample

Requirements for this project:

This project was developed for the Esp32-Pico Atom.

Follow the instructions on this GitHub page to ensure that Arduino IDE recognizes the Esp32 board:
https://github.com/espressif/arduino-esp32/tree/master

In the Arduino IDE, make sure to select "M5Stack-Atom" as your target board.

Additionally, you'll need to install the "WiFi.h" library if it's not already installed.

Using the Example:

After uploading your code to the Esp32-Pico Atom, it will print an IP address to the serial monitor. You should paste this IP address into your web browser while connected to the same Wi-Fi network as the Esp32.

This action will open an HTML page where you can control the color of the Esp32.

Note:
Please be aware that the connection can sometimes be unstable, and there might be cases where the server doesn't seem to recognize the connection.
