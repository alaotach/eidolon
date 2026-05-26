# Euphoria

## Project Overview
Euphoria is a 3d holographic display for your setup and you can display whatever you want on it from anywhere in the world using the WiFi.

<img width="1748" height="2480" alt="EUPHORIA-zine" src="https://github.com/user-attachments/assets/f05f8a8d-315b-4047-aa72-dea24bb75f8c" />

## What's Inside This Folder
**PCB & Hardware Files:**
- `hardware/gerbers/` - All Gerber files for PCB manufacturing (e.g., `hologram-F_Cu.gbr`, `hologram-B_Cu.gbr`, etc.)
- `hardware/pcbs/hologram.kicad_pcb` - The main PCB layout file.
<img width="609" height="410" alt="Screenshot_2026-05-20_085501-removebg-preview" src="https://github.com/user-attachments/assets/b305e620-0bab-475a-b587-4fe5544053e7" />

- `hardware/pcbs/hologram.kicad_sch` - The main schematic.
- `hardware/pcbs/hologram.kicad_pro` - KiCad project file for editing.
- `hardware/fab/outputs/3d/updated-pcb.stl` - 3D model of the PCB.
<img width="538" height="463" alt="PCB-F" src="https://github.com/user-attachments/assets/108bb022-80ad-492b-a923-848fdec5e9d9" />
<img width="531" height="470" alt="PCB-B" src="https://github.com/user-attachments/assets/05126014-2837-459e-9841-ffd8787f69bf" />


**Firmware:**
  - `firmware/eidolon/` - All firmware source code.
	- `include/` - Header files.
**3D Case Files:**
- `hardware/fab/outputs/3d/updated-pcb.f3d` - 3D models for the PCB.
- `hardware/fab/outputs/3d/eldolon-case.stl` - 3D model of the case.
<img width="483" height="581" alt="case" src="https://github.com/user-attachments/assets/bbd5197f-c930-495e-837b-438879e4c6fb" />
<img width="496" height="566" alt="case1" src="https://github.com/user-attachments/assets/f0a0961a-760f-437f-81cb-b77476ee4032" />


**Misc Files:**
- `hardware/fab/outputs/bom/BOM.csv` - BOM.

## The Files You Actually Need
**To Manufacture the PCB:**
1. `hardware/pcbs/hologram.kicad_pcb`.
2. `hardware/gerbers/` - for PCB fabrication.
3. `hardware/pcbs/hologram.kicad_sch` - main schematic.

---

## Build Guide

### Step 1 - Export Gerbers from KiCad
Open `hologram.kicad_pcb` in KiCad, then generate gerbers and drill files. Zip all outputs together.

---

### Step 2 - Order the PCB
Upload your gerber zip to jlcpcb and place your order.

---

### Step 3 - Solder the leftover parts

- Battery connector
- Speaker connector
- Microphone connector
- Oled connector

---

### Step 4 - Connect the Battery
Use a flat LiPo battery with a 2-pin JST PH2.0 connector.

---

### Step 5 - Connect the Display
Connect the 1.3 inch 4 pin Oled display module.
---

### Step 6 - Flash the Firmware
- Use PlatformIO to flash the firmware in the ESP32-C3-WROOM-02

---

### Step 7 - 3D Print
- **Material:** PLA works.
---

### Step 9 - Assemble the Pyramid
Cut your transparent acrylic sheet into 4 identical trapezoid pieces and place them accordingly.
---

### Modifying the Firmware
- All main configs are in `include/Config.h`.
- Each feature is in its own file.
---
