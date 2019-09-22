# Garbage Disposal
**Capacitative push-button switch for kitchen garbage disposal**

Most continuous-operation garbage disposals are activated by either an
air-switch or a wall-switch. Neither option really appealed to my design sense,
and I wanted to use an unobtrusive capacitative push-button switch instead.
While there are beautiful options these days, none of them can switch a
high-powered inductive load. A relay and some supporting hardware was in order.
As 1 HP motors have some pretty high in-rush currents, suitable protective
devices had to be installed. Also, only some relays can handle inductive loads,
so that limited our choice of parts.

[![PCB Photo](https://raw.githubusercontent.com/gutschke/garbagedisposal/master/easyeda/photo.png)](easyeda)

The circuit board is densely packed and sufficiently compact to fit into a
regular junction box. It is even possible to mount an outlet on top of the
junction box. I recommend using the powercord from a garbage disposal wiring
kit to connect the junction box to an existing under-sink outlet. This way, it
can easily be disconnected for servicing.

Nylon stand-off bolts should be used to securely mount the circuit board
inside the junction box.

# Schematics

[![Schematics](https://raw.githubusercontent.com/gutschke/garbagedisposal/master/easyeda/schematics.svg?sanitize=true)](easyeda)

# Bill of Material

| Part | Description |
| ---- | ----------- |
| ACDC1 | [Recom 5V 4W AC/DC power supply](https://www.digikey.com/product-detail/en/recom-power/RAC04-05SC-277/945-2100-5-ND/3906310) |
| D1 | [TVS Diode 5.8V 10.5V 1.5KE6.8CA](https://www.digikey.com/product-detail/en/1.5KE6.8CA/1.5KE6.8CALFCT-ND/285845) |
| D2 | [TVS Diode 185V 328V 1V5KE220CA](https://www.digikey.com/product-detail/en/micro-commercial-co/1.5KE220CA-TP/1.5KE220CA-TPMSCT-ND/1960072) |
| D3 | [1N4004](https://www.digikey.com/product-detail/en/micro-commercial-co/1N4004-TP/1N4004-TPMSCT-ND/773691) |
| F1 | [Fuse Holder](https://www.digikey.com/product-detail/en/wurth-electronics-inc/696103201002/732-11372-ND/7244556) |
|    | [Fuse 250V 15A slow](https://www.digikey.com/product-detail/en/littelfuse-inc/0215015.MXP/F3251-ND/2023367) |
| Q1 | [HUF76423 N-Channel Logic Level UltraFET](https://www.digikey.com/products/en?keywords=huf76423p3) |
| R1 | [MOV 470V Varistor 14D471KR](https://www.digikey.com/product-detail/en/bourns-inc/MOV-14D471KTR/MOV-14D471KTRCT-ND/5775039) |
| R2 | [10kOhm 1/4W](https://www.digikey.com/product-detail/en/yageo/CFR-25JB-52-10K/10KQBK-ND/338) |
| R3 | [10kOhm 1/4W](https://www.digikey.com/product-detail/en/yageo/CFR-25JB-52-10K/10KQBK-ND/338) |
| R4 | [10kOhm 1/4W](https://www.digikey.com/product-detail/en/yageo/CFR-25JB-52-10K/10KQBK-ND/338) |
| C1 | [1uF 50V](https://www.digikey.com/products/en?keywords=478-1836-nd) |
| RELAY1 | [30A 5A SPST T9GS1L14-5](https://www.digikey.com/product-detail/en/te-connectivity-potter-brumfield-relays/T9GS1L14-5/PB2389-ND/8345149) |
| U1 | [Atmel ATTiny45](https://www.digikey.com/product-detail/en/microchip-technology/ATTINY45-20PU/ATTINY45-20PU-ND/735465) |
|    | [IC Socket AR 08 HZL-TT](https://www.digikey.com/product-detail/en/assmann-wsw-components/AR-08-HZL-TT/AE10011-ND/821765) |
| BUTTON | [Schurter push button 3-101-414](https://www.digikey.com/product-detail/en/3-101-414/486-3357-ND/7104553) |
| | [Wiring Kit](https://www.amazon.com/ClearMax-Universal-Garbage-Disposal-Assembly/dp/B01N7KAQIL) |
| | [Nylon Spacers](https://www.amazon.com/gp/product/B071DF6ST4) |
| | [Junction Box](https://www.homedepot.com/p/RACO-4-in-Raised-Ground-Welded-Square-Electrical-Box-8232/100578083) |
| | [Extension Ring](https://www.homedepot.com/p/4-in-Square-Drawn-Extension-Ring-1-1-2-in-Deep-with-1-2-and-3-4-in-KO-s-8203/100002268) |
| | [Cover Plate](https://www.homedepot.com/p/RACO-4-in-Square-Exposed-Work-Cover-Single-Device-3-in-1-Universal-Cover-808U/204486935) |
| | [Outlet](https://www.homedepot.com/p/Leviton-Decora-15-Amp-Residential-Grade-Self-Grounding-Duplex-Outlet-White-R52-05325-0WS/100357024) |
| | [Thermostat Wire](https://www.homedepot.com/p/Southwire-By-the-Foot-18-5-Brown-Solid-CU-CL2Thermostat-Wire-64169699/204725214) |
| | [Copper Wire](https://www.homedepot.com/p/Gardner-Bender-14-AWG-18-ft-Primary-Wire-Spool-Black-AMW-314/300689786) |
| | [Heat Shrink Tubing](https://www.amazon.com/Vktech-150pcs-Shrink-Tubing-Sleeving/dp/B00EXLPLTW) |
| PCB | [Order from easyeda.com / jlcpcb.com](https://easyeda.com/zodiac_7307/garbage-disposal-relay) |

# Source Code

The circuit uses a microcontroller to add a couple of convenience features. A
maximum duty cycle of 30 seconds  is enforced. After a power-failure, the
device stays off. Holding the button turns on the device until the button is
released. On the other hand, briefly touching the button turns on the device
until the button is touched a second time. The motor cannot be switched faster
than every 2 seconds in order to avoid overloading the relay.

[Source code](garbagedisposal.ino)

# Estimated Cost

Total cost for the project is between $90 and $120, depending on shipping costs
and depending on how many of the common supplies are already on hand. The most
expensive individual line item is the capacitative push-button, which by itself
costs more than $30. It is really pretty though; and it can safely be handled
with wet hands. The next item is probably the cost of the PCB. Shipping is a
big factor here. Also, unless you use by-pass wires for the high-current paths,
it should be made from 2oz copper board. That drives the cost up. Finally, I
picked a high-quality power supply. Some cost could be shaved off by selecting
a cheaper part.

# Notes On Connecting The Push Button

The button has a lot of pig tail wires; but we really only need to make four
connections. Both black wires get connected to GND. The brown and one of the
white wires get connected to 5V. The red, green, and blue wires get connected
to LED. And the remaining white wire gets connected to BUTTON.

Use heat shrink tubing and thermostat wire to make the connections. Don't
forget to ensure proper strain relief.

I wired the status LED to shine white. If you prefer a different color, don't
connect all of the R/G/B wires. The LED lights up, when the R/G/B wires are
connected to ground (i.e. black wires). The microcontroller lets the signal
float, whenever the LED is supposed to be off.

The push button (two white wires) makes a connection to 5V (brown wire). The
microcontroller detects this signal.
