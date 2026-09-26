# Nächste Schritte

- [ ] **1. Hardware-Grundtest**
  - Pico 2W anschließen.
  - Einen einzelnen Taster an `GP2` gegen GND verdrahten.
  - Prüfen, ob der Taster zuverlässig erkannt wird.

- [ ] **2. Alle 6 Taster anschließen**
  - Taster an `GP2` bis `GP7`.
  - Jeden Eingang einzeln testen.
  - Entprellung prüfen.

- [ ] **3. Ersten Encoder anschließen**
  - `A -> GP8`
  - `B -> GP9`
  - `C -> GND`
  - Encoder-Taster an `GP10 -> GND`.
  - Links, rechts und Druck separat testen.

- [ ] **4. Zweiten Encoder anschließen**
  - `A -> GP11`
  - `B -> GP12`
  - `C -> GND`
  - Encoder-Taster an `GP13 -> GND`.
  - Drehrichtung prüfen und bei Bedarf `ENCODER_DIRECTION` ändern.

- [ ] **5. Bluetooth-HID testen**
  - Firmware flashen.
  - Pico mit dem Mac koppeln.
  - Prüfen, ob das Gerät als Bluetooth-Tastatur erkannt wird.

- [ ] **6. Tastenaktionen testen**
  - F13–F18 senden.
  - Prüfen, ob jede Taste genau einmal auslöst.
  - Danach erste echte Shortcuts konfigurieren.

- [ ] **7. Consumer-Keys testen**
  - Encoder 1: Lautstärke hoch/runter.
  - Encoder 1 drücken: Mute.
  - Encoder 2: Vorheriger/Nächster Titel.
  - Encoder 2 drücken: Play/Pause.

- [ ] **8. Debug-Ausgaben ergänzen**
  - Über `Serial` Button- und Encoder-Events ausgeben.
  - Debug-Ausgaben optional per Compile-Flag abschaltbar machen.

- [ ] **9. Action-System erweitern**
  - Shortcuts mit mehreren Modifiern.
  - `None`-Aktion.
  - Optional Text-/Makro-Aktionen vorbereiten.

- [ ] **10. Konfiguration aus dem Code lösen**
  - Aktuelle Belegung nicht mehr fest in `config.cpp` halten.
  - Konfigurationsstruktur für Flash-Speicherung vorbereiten.

- [ ] **11. Konfiguration persistent speichern**
  - Einstellungen im Flash/LittleFS speichern.
  - Default-Konfiguration laden, falls noch keine gespeichert ist.
  - Reset auf Werkseinstellungen vorsehen.

- [ ] **12. Profile einbauen**
  - Mehrere Profile unterstützen.
  - Aktives Profil speichern.
  - Profilwechsel über langen Druck eines Encoder-Tasters.

- [ ] **13. Long Press / Double Click**
  - Tasten-Events um langen Druck erweitern.
  - Optional Doppelklick unterstützen.
  - Aktionen getrennt konfigurierbar machen.

- [ ] **14. WLAN-Konfigurationsmodus**
  - Beim Start mit gedrückter Taste einen Access Point öffnen.
  - Einfachen Webserver starten.
  - Config-Modus klar vom normalen Keyboard-Betrieb trennen.

- [ ] **15. Weboberfläche bauen**
  - Belegung der 6 Tasten ändern.
  - Encoder links/rechts/drücken konfigurieren.
  - Profile auswählen und speichern.

- [ ] **16. USB-HID als Fallback**
  - Neben Bluetooth auch USB-HID unterstützen.
  - Gleiche Actions für USB und Bluetooth verwenden.

- [ ] **17. Stromversorgung planen**
  - Entscheiden: dauerhaft USB oder Akku.
  - Bei Akku Ladeelektronik und Ein/Aus-Schalter ergänzen.
  - Stromverbrauch im Idle prüfen.

- [ ] **18. Gehäuse bauen**
  - Layout von Tasten und Encodern festlegen.
  - Prototyp auf Lochraster fertigstellen.
  - Danach Gehäuse oder eigene PCB entwerfen.

- [ ] **19. Tests und Robustheit**
  - Reconnect nach Bluetooth-Abbruch testen.
  - Verhalten nach Neustart prüfen.
  - Mehrfachbetätigung und schnelles Encoder-Drehen testen.
  - Lint + Build vor jedem Flash laufen lassen.
