# CitizenWatt-ArduinoBase

Sketch for Arduino, that connects the nRF24 transceiver and the PINE64+ board    

`CitizenWatt Sensor (((              ))) nRF24---Arduino Nano---PINE64+`

## Prerequisites
TMRh20's RF24 Library : https://github.com/TMRh20/RF24    

## Connexion between Arduino and Transceiver

| nFR24L01+ | Arduino Uno | 
| --------- |:-----------:|
| GND       | GND         |
| VCC       | 3.3V        |
| CE        | 7           |
| CSN       | 8           |
| SCK       | 13          |
| MOSI      | 11          |
| MISO      | 12          |
| IRQ       | -           |
