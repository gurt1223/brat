# BRAT Framework

The **Baseline Robust Aircraft Testing (BRAT)** framework is a lightweight, Simulink starter project with **PX4 Input/Output blocks** pre-configured so that you can bring your own custom MATLAB/Simulink algorithms (model identification, guidance, control, etc.) to **bench (Connected IO)** and **flight (Build, Deploy, & Start)** testing with minimal setup.

> If you’re brand-new to the PX4 ↔ MATLAB/Simulink toolchain, start with the companion **[UAV Toolbox Setup Guide](https://github.com/gurt1223/UAV-Toolbox-Setup-Guide)**, then come back here to bench test or deploy custom algorithms to PX4.

---

## Features
- **Ready-to-run FCS diagram** (`FCS_Hardware.slx`) with PX4 I/O pre-wired for rapid startup.
- **One setup script** (`setupHardware.m`) to launch the environment and choose your workflow:
  - **Connected IO (logging disabled):** fast bench testing against a live PX4.
  - **Build, Deploy, & Start (logging enabled):** compiles and runs on-target with ULOG data capture.
- **Clean extension points** for dropping in your own controllers (`Experimental_Control.slx`), estimators (`Read_PX4_Sensors.slx`), model identification (`OL_PTI.slx`), or experimental logic.
- **[Baseline Robust Aircraft Testing (BRAT) Framework Tutorial Video](https://youtu.be/mS8hB7pjNKs)** <br>

---

## Quick Start

1. **Requirements**
- QGroundControl (v4.4.2)
- MATLAB - R2025a
- Simulink
- MATLAB/Simulink Add-Ons
  - UAV Toolbox
  - UAV Toolbox Support Package for PX4 Autopilots
  - MATLAB Coder
  - Simulink Coder
  - Embedded Coder 
- A PX4-based flight controller (e.g., Pixhawk family) and QGroundControl for firmware/QGC setup

3. **Clone or Download The Latest Release**

## Disclaimer

> **THIS SOFTWARE ENVIRONMENT IS PROVIDED “AS IS” AND IS INTENDED SOLELY AS A REFERENCE FOR DEVELOPING AND DEPLOYING CUSTOM ALGORITHMS TO PX4 AUTOPILOTS WITHIN SIMULINK.**  
> NO GUARANTEES ARE MADE, EITHER EXPRESS OR IMPLIED, REGARDING FUNCTIONALITY, PERFORMANCE, RELIABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR FREEDOM FROM ERRORS. USE OF THIS SOFTWARE IS AT YOUR OWN RISK.
>
> IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, LOSS OF FLIGHT VEHICLES, LOSS OF DATA, OR PERSONAL INJURY) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT, ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE. 
>
> BY USING THIS ENVIRONMENT, YOU ACKNOWLEDGE THAT IT IS A REFERENCE IMPLEMENTATION ONLY, AND THAT FLIGHT TESTING WITH PX4 AUTOPILOTS REQUIRES APPROPRIATE SAFETY MEASURES, ENGINEERING JUDGMENT, AND VERIFICATION BEYOND WHAT IS PROVIDED HERE.
