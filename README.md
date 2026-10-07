# Servo Motor Control with LED Indicators

An Arduino demonstration that maps a potentiometer position to a hobby servo angle and uses three push buttons to select red, green, or off LED states.

## Repository contents

- `Servo Motor Control with LED Indicators.cpp` - Arduino-style source code.
- `Grand Jaiks.pdf` - one-page circuit schematic/reference for the prototype.

## Hardware and software

- Arduino-compatible board with a 10-bit analog input, such as an Arduino Uno
- Standard hobby servo
- Potentiometer (the supplied schematic labels it 250 kOhm)
- Red and green LEDs with current-limiting resistors
- Three normally open push buttons
- Arduino IDE and the standard `Servo` library

## Pin map

| Component | Arduino pin |
| --- | --- |
| Potentiometer wiper | A0 |
| Servo signal | D9 |
| Red LED | D2 |
| Green LED | D3 |
| Red-select button | D4 |
| Green-select button | D5 |
| LEDs-off button | D6 |

The buttons use `INPUT_PULLUP`: connect each button between its input pin and ground. A pressed button therefore reads `LOW`.

## Build and run

1. Review the circuit in `Grand Jaiks.pdf` and assemble the components using the pin map above.
2. Create an Arduino sketch and copy `Servo Motor Control with LED Indicators.cpp` into its `.ino` file.
3. Select the correct board and port, compile, and upload.
4. Rotate the potentiometer to command approximately 0 to 180 degrees.
5. Press the red or green button to select that LED; press the off button to switch both LEDs off.

The sketch reads A0 in the 0-1023 range and maps it linearly to a 0-180 degree servo command. The potentiometer's total resistance does not appear in the calculation, but its end terminals must be connected across the board's reference supply and ground, with the wiper connected to A0. LED state remains unchanged when no button is pressed.

## Behavior notes

- The three button conditions are separate `if` statements. If multiple buttons are pressed in one loop, the later checks take precedence: green overrides red, and the off button overrides both.
- There is no button debouncing, servo calibration, angle limiting, or stored startup LED state beyond the GPIO reset state.
- A real servo can draw far more current than an Arduino regulator or GPIO can provide. Use a suitable external servo supply and connect its ground to the Arduino ground. Never power the motor through a GPIO pin.
- Fit current-limiting resistors to both LEDs. Confirm that the servo's travel does not force the mechanism against a hard stop.
