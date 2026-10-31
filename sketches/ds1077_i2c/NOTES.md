# ds1077_i2c - NOTES

## Board
Arduino Micro (ATmega32U4). **5 V logic.** Hardware I2C:
- SCL = D2
- SDA = D3

Check the clone has pull-ups fitted; add 4.7 k to 5 V on both lines if not.

## Purpose
Breadboard the DS1077, set a divider over I2C, watch OUT0 on the scope.
If the scope does not move, the register contents are irrelevant. That is the test.

## Verified
- DS1077 is a dual-output programmable oscillator with a 2-wire (I2C) interface,
  frequency changeable on the fly, outputs are submultiples of the master
  frequency via programmable prescalers and a divider.
- 7-bit I2C address = `1011` hardwired + 3 strap bits = **0x58..0x5F**.

## NOT verified - check before trusting
- Exact register-select bytes (`REG_MUX` = 0x01, `REG_DIV` = 0x02).
  Could not extract the register map from a primary source this session.
- The 10-bit divider split (MSB = n >> 2, LSB = n & 0x03) is my reading.
- Whether the EEPROM store is automatic after each write on your part.

## Bring-up order
1. Confirm the exact part number (DS1077 vs DS1077L) and its supply range.
2. Pull-ups on SDA/SCL to the logic rail.
3. Flash, open serial at 115200, read the bus scan. Device must appear in
   0x58-0x5F. If it does not, stop and fix wiring.
4. Probe OUT0 before any write. Record the starting frequency.
5. One divider write, watch OUT0 change, confirm readback matches.
6. Cycle power, confirm the setting persisted.

## Scope settings
- Probe OUT0, ground to board ground, DC coupling
- Square wave at master frequency divided by N
- 1 V/div to start, timebase set after the frequency is known

## Gaps
- No MUX/output-enable handling.
- No second-output divider handling.
- Divider is hard-coded to 2 on purpose for the first test - fewer moving parts.
