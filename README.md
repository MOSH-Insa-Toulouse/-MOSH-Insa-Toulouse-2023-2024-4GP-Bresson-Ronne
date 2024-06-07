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
Une partie importante de la chaîne d’acquisition pour notre capteur réside dans le
conditionnement du signal délivré par le capteur, c’est-à-dire l’amplifier et le filtrer
pour pouvoir l’exploiter. Afin d’utiliser les capacités de la carte Arduino au maximum
(en pleine échelle), le gain du circuit d’amplification est variable grâce à la résistance
R2, ajustée par un potentiomètre digital.<br>
Le filtrage est effectué à plusieurs niveaux (avant et après amplification). Il y a donc 3
étages, chacun avec une fréquence de coupure différente, pour limiter le bruit au
maximum. Le circuit est modélisé dans LTSpice, afin d’effectuer des simulations. Il
faut noter qu’ici on peut se permettre d’avoir un filtrage fort à des fréquences très
faibles car à priori notre capteur ne sera pas utilisé à plus qu’environ 1Hz. Les
résultats obtenus par les simulations et un exemple de simulation (Diagramme de
Bode pour un étage sont présentés sur les figures suivantes. Le circuit LTSpice est à
trouver dans le dossier « électronique analogique ».

<p align="center">
  <img src="https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-Bresson-Ronne/blob/main/Photos%20et%20images/BodeAOP.png" alt="Caractéristiques de l'AOP">
  <br>
  <i>Caractéristiques de l'AOP</i>
</p>

<p align="center">
  <img src="https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-Bresson-Ronne/blob/main/Photos%20et%20images/BodeAOPSch%C3%A9ma.png" alt="Diagramme de Bode du premier étage de l'AOP">
  <br>
  <i>Diagramme de Bode du premier étage de l'AOP</i>
</p>

## 3) Kicad
Afin de réaliser en pratique le circuit modélisé dans LTSpice, ainsi qu’ajouter tous les
composants liés à notre chaîne d’acquisition et aux capteurs, le logiciel KiCad est
utilisé. Il permet à partir d’un schéma électrique, créé dans un premier temps, et de
l’ajout des empreintes et modèles 3D des différents composants, de modéliser le
PCB et ses pistes électroniques, et d’en obtenir un modèle 3D. Ces documents sont
disponibles dans le dossier « KiCad ». Avec l’aide de Catherine Crouzet, nous avons
ensuite pu fabriquer notre PCB y souder les composants pour tester toute notre
chaîne d’acquisition, qui s’est avérée fonctionnelle directement.

<p align="center">
  <img src="https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-Bresson-Ronne/blob/main/Photos%20et%20images/Sch%C3%A9maKiCad.png" alt="Schéma du PCB réalisé sur KiCad">
  <br>
  <i>Schéma du PCB réalisé sur KiCad</i>
</p>


## 4) Le code Arduino

Un code Arduino est implémenté sur un ArduinoUno. Le code permet d'afficher les valeurs de résistance sur l'écran oled et de choisir quel capteur est affiché via un encodeur rotatoire. Les valeurs de résitances sont aussi disponibles sur le serialmonitor ainsi que sur le téléphone. 

## 5) Lapplication 
L’application Android, créée avec le MIT App Inventor, permet de dialoguer via Bluetooth
(bouton de connexion à activer) avec la carte Arduino pour obtenir les valeurs de
résistance/angle fournies par le capteur. L’utilisateur peut choisir un nombre de mesures à
effectuer, le moment pour les lancer, puis ces mesures sont affichées en live sur un
indicateur numérique, un graphique, et exportées dans un tableur afin de les exploiter au
mieux. Un fichier APK est téléchargeable dans le dossier « Application Android »


<p align="center">
  <img src="https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-Bresson-Ronne/blob/main/Photos%20et%20images/CodeAppli.png" alt="Schéma de l'application Android">
  <br>
  <i>Schéma de l'application Android</i>
</p>

## 6) La DataSheet 
La data sheet du capteur est disponible  [ici](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-Bresson-Ronne/blob/main/DataSheet/datasheetCapteurBressonRonne.pdf).
