# Sketches

Arduino sketches for Meistro's bench. Pull the repo and you always have the latest version.

Each subfolder is a complete sketch folder — open it directly in the Arduino IDE
(`File → Open`, select the `.ino`).

`manifest.json` lists what appears on the site's Sketches tab:

```json
[
  {
    "name": "dac_sweep",
    "board": "Arduino Due (ATSAM3X8E)",
    "description": "Sweeps an external 10-bit DAC -10V to +10V via the parallel port.",
    "path": "sketches/dac_sweep/dac_sweep.ino",
    "updated": "2026-10-30"
  }
]
```

Rules:

1. One folder per sketch, folder name matches the `.ino` name — the IDE requires it.
2. Every sketch folder gets a `NOTES.md` recording board, wiring assumptions, and known faults.
3. A sketch that has not been compiled or run on the target board is not "working".
4. Changes get a line in the commit message saying what was fixed.
