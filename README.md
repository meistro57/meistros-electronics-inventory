# Meistro's Electronics Inventory

A bench catalogue of salvaged electronics, identified and cross-checked by Ohm.

**Live site:** https://meistro57.github.io/meistros-electronics-inventory/

## How this works

`data/items.json` is the single source of truth. `index.html` renders it client-side -
no build step, no framework, no dependencies.

### Status values

| Status | Meaning |
|---|---|
| `confirmed` | Markings read directly, part family verified against a datasheet or manufacturer page |
| `partial` | Part family plausible, but at least one key fact unverified (package, pinout, or function) |
| `TBD` | We know it is a component and almost nothing else |
| `vendor-only` | Only a vendor service part number survives; no public datasheet is likely to exist |
| `DO NOT POWER` | Physically damaged. Identified for the record only |

### Confidence

`high` / `medium` / `low` / `guess`. A `guess` confidence is a hypothesis, not an
identification, and is never treated as fact when planning a circuit.

## Adding an item

Append an object to `data/items.json`:

```json
{
  "id": "E013",
  "name": "Short descriptive name",
  "markings": "Verbatim text read off the part",
  "pkg": "Package type",
  "status": "confirmed",
  "conf": "high",
  "notes": "What the part is, its electrical character, and any hazard",
  "qs": ["Anything still unverified"]
}
```

## Rules this catalogue follows

1. A part number read off a photograph is evidence; a part number remembered is not.
2. Every unverified claim gets a question attached, not a guess.
3. Damaged parts are recorded and never powered.
4. Identity is confirmed by datasheet, not by plausibility.
