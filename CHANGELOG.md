# Changelog — Meistro's Electronics Inventory

Versioning scheme: `inventory-vMAJOR.MINOR`
- MAJOR: schema change (new required field, structural change to items.json)
- MINOR: new items added, or corrections to existing items

---

## inventory-v1.0 — 2026-11-14
First tagged release. 43 items catalogued.

**Baseline:** the 12 items that existed before 2026-11-14 (E001–E012), all
previously committed.

**Added this session (E013–E044):**
- E013 MAX7219 CNG — 8-digit LED driver
- E014 MAX7221 CNG — same die, true SPI
- E015 ADC0804 LCJ — 8-bit SAR ADC
- E016 TDA7052 — 1.2 W BTL audio amp
- E017 74HCT154N — 4-to-16 decoder (qty 3)
- E018 DM74150N — 16-input mux
- E019 74LS153 — dual 4-input mux
- E020 7406 — hex open-collector buffer
- E021 74LS161 — 4-bit counter
- E022 Z80A — 8-bit CPU, 4 MHz
- E023 LM324N — quad op-amp
- E024 7812 — +12 V regulator
- E025 74LS139 — dual 2-to-4 decoder
- E026 74S157 — quad 2-input mux
- E027 SN7448N — BCD to 7-segment
- E028 NTE2021 — 7406-class buffer (confirmed by Mark)
- E029 NTE1904 — confirmed by Mark
- E030 741 op-amp
- E031 NTE74LS175 — quad D flip-flop
- E032 TL082 — dual BiFET op-amp
- E033 5 W 0.33 ohm wirewound (qty 20)
- E034 ADI DAC-10Z-3 — 10-bit DAC (qty 2, pinout unverified)
- E035 Beken BK3231Q — wireless module, salvage
- E036 TI TFP410 — DVI transmitter on carrier
- E037 Lattice ispLSI 2032 — CPLD
- E038 HP HCTL-1100 — single-axis motion controller
- E039 TI TMS320F28069F — C2000 Piccolo MCU (qty 2)
- E040 — merged into E039 (same chip, OCR misread; removed)
- E041 Unidentified PLCC on PCB
- E042 nRF24-style 13.56 MHz RFID/NFC modules
- E043 Lantronix XPort Direct+ — ethernet-serial bridge
- E044 Seeed Music Shield v1.2 — VS1053b codec

**Corrections made in-session:**
- E039/E040 suspected DRL-344 provenance — removed, unverified
- E038 DRL-344 speculation — removed
- E042 name — kept as Mark's trade name, band clarification separated
- E028/E029 — promoted to confirmed on Mark's identification

**Comment:** `bc61599` (last commit before tagging).
