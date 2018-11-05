# Garbage Disposal
**Capacitative push-button switch for kitchen garbage disposal**

Most continuous-operation garbage disposals are activated by either an air-switch or a
wall-switch. Neither option really appealed to my design sense, and I wanted to 
use a unobtrusive capacitative push-button switch instead. While there are beautiful
options these days, none of them can switch a high-powered inductive load. A relay
and some supporting hardware was in order.

[![PCB Photo](https://raw.githubusercontent.com/gutschke/garbagedisposal/master/easyeda/photo.png)](easyeda)

The circuit board is densely packed and sufficiently compact to fit into a regular
junction box. It is even possible to mount an outlet on top of the junction box.
I recommend using the powercord from a garbage disposal wiring kit to connect the
junction box to an existing under-sink outlet. This way, it can easily be disconnected
for servicing.

Nylon stand-off bolts should be used to securely mount the circuit board inside the
junction box.

# Schematics

[![Schematics](https://raw.githubusercontent.com/gutschke/garbagedisposal/master/easyeda/schematics.svg?sanitize=true)](easyeda)

# Bill of Material

| Part | Description |
| ---- | ----------- |
| ACDC1 | [Recom 5V 4W AC/DC power supply](https://www.digikey.com/product-detail/en/3-101-414/486-3357-ND/7104553) |
| D1 | [TVS Diode 5.8V 10.5V 1.5KE6.8CA](https://www.digikey.com/product-detail/en/1.5KE6.8CA/1.5KE6.8CALFCT-ND/285845) |
| D2 | [TVS Diode 185V 328V 1V5KE220CA](https://www.digikey.com/product-detail/en/1V5KE220CA/1V5KE220CACT-ND/3907941) |
| D3 | [1N4004](https://www.digikey.com/product-detail/en/micro-commercial-co/1N4004-TP/1N4004-TPMSCT-ND/773691) |
| F1 | [Fuse Holder](https://www.digikey.com/product-detail/en/keystone-electronics/3576/36-3576-ND/3465426) |
|    | [Fuse 125V 15A slow](https://www.digikey.com/product-detail/en/bel-fuse-inc/3SB-15-R/507-1537-ND/1009761) |
| Q1 | [HUF76423 N-Channel Logic Level UltraFET](https://www.digikey.com/products/en?keywords=huf76423p3) |
| R1 | [MOV 350 Varistor TMOV20RP275M](https://www.digikey.com/product-detail/en/littelfuse-inc/TMOV20RP275M/F4043-ND/1154461) |
| R2 | [10kOhm 1/4W](https://www.digikey.com/product-detail/en/yageo/CFR-25JB-52-10K/10KQBK-ND/338) |
| R3 | [10kOhm 1/4W](https://www.digikey.com/product-detail/en/yageo/CFR-25JB-52-10K/10KQBK-ND/338) |
| RELAY1 | [30A 5A SPST T9AS1D12-5](https://www.digikey.com/product-detail/en/T9AS1D12-5/PB1014-ND/1095335) |
| U1 | [Atmel ATTiny45](https://www.digikey.com/product-detail/en/microchip-technology/ATTINY45-20PU/ATTINY45-20PU-ND/735465) |
|    | [IC Socket AR 08 HZL-TT](https://www.digikey.com/product-detail/en/microchip-technology/ATTINY45-20PU/ATTINY45-20PU-ND/735465) |
| BUTTON | [Schurter push button 3-101-414](https://www.digikey.com/product-detail/en/3-101-414/486-3357-ND/7104553) |
| PCB | [Order from easydata.com](https://easyeda.com/zodiac_7307/garbage-disposal-relay) |

# Source Code

The circuit uses a microcontroler to add a couple of convenience features. A maximum
duty cycle of one minute is enforced. After a power-failure, the device stays off.
Holding the button turns on the device until the button is released. On the other hand,
briefly touching the button turns on the device until the button is touched a second
time.

[Source code](garbagedisposal.ino)

