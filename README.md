# BRAT Framework

The **Baseline Robust Aircraft Testing (BRAT)** framework is a lightweight, Simulink starter project with **PX4 Input/Output blocks** pre-configured so that you can bring your own custom MATLAB/Simulink algorithms (model identification, guidance, control, etc.) to **bench (Connected IO)** and **flight (Build, Deploy, & Start)** testing with minimal setup.

> If you’re brand-new to the PX4 ↔ MATLAB/Simulink toolchain, start with the companion **[UAV Toolbox Setup Guide](https://github.com/gurt1223/UAV-Toolbox-Setup-Guide)**, then come back here to bench test or deploy custom algorithms to PX4.

---

## Table of Contents
- **[File Guide](#file-guide)**
- **[Features](#features)**
- **[How to Use](#how-to-use)**
- **[Required Software](#required-software)**
- **[Related Resources](#related-resources)**
- **[Related Publications](#related-publications)**
- **[Acknowledgments](#acknowledgments)**
- **[Citing This Resource](#citing-this-resource)**
- **[Disclaimer](#disclaimer)**

---

## File Guide
- **FCS_Hardware.slx**  
  The main Simulink flight control system diagram with PX4 I/O blocks pre-wired for rapid testing and deployment.

- **setupHardware.m**  
  A single setup script that initializes MATLAB paths, loads parameters, and launches the environment for either bench testing or on-target execution.

- **Experimental_Control.slx**  
  Drop-in subsystem for your custom control algorithms.

- **Read_PX4_Sensors.slx**  
  Example sensor input block demonstrating PX4-to-Simulink data flow.

- **OL_PTI.slx**  
  Example open-loop Propulsion Test Interface (PTI) for experimental or model identification purposes.

---

## Features
- **Ready-to-run FCS diagram** (`FCS_Hardware.slx`) with PX4 I/O pre-wired for rapid startup.
- **One setup script** (`setupHardware.m`) to launch the environment and choose your workflow:
  - **Connected IO (logging disabled):** fast bench testing against a live PX4.
  - **Build, Deploy, & Start (logging enabled):** compiles and runs on-target with ULOG data capture.
- **Clean extension points** for dropping in your own controllers (`Experimental_Control.slx`), estimators (`Read_PX4_Sensors.slx`), model identification (`OL_PTI.slx`), or experimental logic.
- **[Baseline Robust Aircraft Testing (BRAT) Framework Tutorial Video](https://youtu.be/mS8hB7pjNKs)** <br>
  A walkthrough video showing both Connected IO and Build/Deploy testing.

---

## How to Use
1. Clone or download the BRAT Framework repository.  
2. Run `setupHardware.m` to configure the environment.  
3. Select your workflow mode (Connected IO or Build, Deploy, & Start).  
4. Modify or replace subsystems with your own algorithms.  
5. Use QGroundControl to verify successful firmware deployment.  

---

## Required Software
- QGroundControl (v4.4.2)
- MATLAB - R2025a
- Simulink
- MATLAB/Simulink Add-Ons
  - UAV Toolbox
  - UAV Toolbox Support Package for PX4 Autopilots
  - MATLAB Coder
  - Simulink Coder
  - Embedded Coder 
- PX4-compatible flight controller (e.g., CubeOrange, Pixhawk series)

---

## Related Resources
- **[UAV Toolbox Setup Guide](https://github.com/gurt1223/UAV-Toolbox-Setup-Guide)**  
  Step-by-step written and video tutorials for setting up the MATLAB–PX4 toolchain.

- **[PX4-Modification-Example-Files](https://github.com/gurt1223/PX4-Modification-Example-Files)**  
  Example PX4 source code modifications for adding parameters, telemetry streams, or custom logging.

---

## Related Publications
<details>
<summary>Click to expand</summary>

[1]	Asper, G. D. and Simmons, B. M., “Rapid Flight Control Law Deployment and Testing Framework for Subscale VTOL Aircraft,” NASA/TM−20220011570, Sept. 2022. 

[2]	Asper, G. D., Simmons, B. M., Ackerman, K. A., Axten, R. M., and Corrigan, P. E., “Inexpensive Multirotor Platform for Advanced Controls Testing (IMPACT): Development, Integration, and Experimentation,” NASA/TM-20240000223, March 2024. 

[3]	Simmons, B.M., Ackerman, K.A., and Asper, G.D. “Aero-Propulsive Damping Characterization for eVTOL Aircraft Using Free Motion Wind-Tunnel Testing,” AIAA SciTech 2025 Forum, AIAA Paper 2025-0006, Jan. 2025.

[4]	Corrigan, P.E., Matt, J.J., and Asper, G.D. “Design and Testing of an Octocopter for Aerodynamic and Power Consumption Modeling,” NASA/TM-20240013453, March 2025. 

[5]	Asper, G.D. and Woolsey, C.A., “Toward a Fault-Tolerant Control Allocation Evaluation Framework for eVTOL Aircraft,” VSGC Student Research Conference, Virginia Space Grant Consortium, April 2025.

[6]	Simmons, B.M., Ackerman, K.A., Asper, G.D., Gray, M.N., Snyder, S.M., Axten, R.M., Geuther, S.C., and Chan, R. “Subscale Tiltrotor eVTOL Aircraft Dynamic Modeling and Flight Control Software Development,” Vertical Flight Society Annual Forum & Technology Display, May 2025. 
Awarded Best Paper Submitted to the Modeling & Simulation Technical Committee.

[7]	Comer, A.M., Simmons, B.M., and Asper, G.D. “Design, Simulation, and Flight Testing of a Multi-Purpose VTOL Flight Control System,” NASA/TM—20250000954, September 2025. 

[8]	Simmons, B.M., Ackerman, K.A., and Asper, G.D. “Aero-Propulsive Damping Characterization for eVTOL Aircraft Using Free Motion Wind-Tunnel Testing,” Journal of Aircraft, In review.

[9]	Corrigan, P.E., Asper, G.D., Simmons, B.M., and Woolsey, C.A., “Aircraft System Identification Approach for Control Surface Fault Diagnosis,” AIAA SciTech 2026 Forum, Submitted for consideration, 2026. 

[10]	Asper, G.D., Corrigan, P.E., Simmons, B.M., and Woolsey, C.A., “An Evaluation of Fault-Tolerant Control Allocation Strategies for eVTOL Aircraft,” AIAA SciTech 2026 Forum, Submitted for consideration, 2026.

</details>

---

## Acknowledgments
Thank you to Patrick Corrigan, Benjamin Simmons, and Anthony Comer for your support in learning the ins and outs of this toolchain.<br>
Thank you to the developers at MathWorks, particularly Arun Mathamkode and Ankur Bose, for your insight and openness to feedback on problems and improvements.

---

## Citing This Resource
If you use the steps or framework in this repository for your research, please cite Garrett Asper's Master's Thesis:<br>  
Asper, G. D., “An Evaluation of Fault-Tolerant Control Allocation Strategies for eVTOL Aircraft,” M.S. Thesis, Virginia Tech, Blacksburg, VA, To be published Spring 2026.<br>
_Please check back in January to ensure there are no updates to the citation. Citing the above thesis is the most effective way to acknowledge these resources._

---

## Disclaimer
> **THIS SOFTWARE ENVIRONMENT IS PROVIDED “AS IS” AND IS INTENDED SOLELY AS A REFERENCE FOR DEVELOPING AND DEPLOYING CUSTOM ALGORITHMS TO PX4 AUTOPILOTS WITHIN SIMULINK.**  
> NO GUARANTEES ARE MADE, EITHER EXPRESS OR IMPLIED, REGARDING FUNCTIONALITY, PERFORMANCE, RELIABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR FREEDOM FROM ERRORS. USE OF THIS SOFTWARE IS AT YOUR OWN RISK.
>
> IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, LOSS OF FLIGHT VEHICLES, LOSS OF DATA, OR PERSONAL INJURY) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT, ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE. 
>
> BY USING THIS ENVIRONMENT, YOU ACKNOWLEDGE THAT IT IS A REFERENCE IMPLEMENTATION ONLY, AND THAT FLIGHT TESTING WITH PX4 AUTOPILOTS REQUIRES APPROPRIATE SAFETY MEASURES, ENGINEERING JUDGMENT, AND VERIFICATION BEYOND WHAT IS PROVIDED HERE.
