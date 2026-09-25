# Pico Macropad

Bluetooth-Macropad mit Raspberry Pi Pico 2W, 6 Tasten und 2 Drehencodern.

## Build

```bash
arduino-cli compile --fqbn rp2040:rp2040:rpipico2w:ipbtstack=ipv4btcble .
```

## Upload

```bash
arduino-cli upload --fqbn rp2040:rp2040:rpipico2w:ipbtstack=ipv4btcble --port <PORT> .
```
