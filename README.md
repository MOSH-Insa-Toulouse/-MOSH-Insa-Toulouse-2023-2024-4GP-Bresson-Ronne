# -MOSH-Insa-Toulouse-2023-2024-4GP-Bresson-Ronne

Projet 4GP du capteur au banc de test en open source hardware
---
## Sommaire
  - [1) Contexte](#1-contexte)
  - [2) L'électronique Analogique](#2-L'électroniqueAnalogique)
  - [3) Kicad](#3-kicad)
  - [4) Le code Arduino](#4-lecodeArduino)
  - [5) L'application Bluetooth ](#5-l'appli)
  - [6) La DataSheet ](#6-data)
---


## 1) Contexte
Dans le cadre de l'UE "Du capteur au banc de test en Open Source Hardware", nous avons été amenés à réaliser un capteur de déformation low-tech à base de graphite. Le fonctionnement de ce capteur repose sur la variation de résistance engendrée par la déformation du matériau. La physique sous-jacente à cette variation de résistance provient du déplacement des électrons par effet tunnel entre les nanoparticules de graphite. Lorsqu'une contrainte mécanique est appliquée, la distance entre les nanoparticules varie, ce qui modifie la conductivité du graphite. Cette modification entraîne ainsi une variation de la résistance du capteur.<br>
Ce capteur est ensuite connnecté à un arduino. Divers élements sont ajoutés à l'Arduino, un capeteur flex sensor industriel que l'on comparera à notre capteur LowTech maison, un écran Oled pour pouvoir afficher nos résultats et un encodeur rotatoire qui permet de se déplacer sur les menus de l'écran Oled. Un module bluetooth est aussi implémenté en vue de créer une application android pour visualiser nos données. 

<p align="center">
  <img src="https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-Bresson-Ronne/blob/main/Photos%20et%20images/Capture.jpg" alt="Photo de l'installation">
  <br>
  <i>Photo de l'installation</i>
</p>


## 2) L'électronique Analogique

## 3) Kicad

## 4) Le code Arduino

Un code Arduino est implémenté sur un ArduinoUno. Ce code permet d'afficher les valeurs des résistances des capteurs en fonction de l'angle du capteur. 

## 5) Lapplication 

## 6) La DataSheet 
