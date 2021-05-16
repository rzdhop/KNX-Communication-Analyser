# KNX-Communication-Analyser

> *Par KNX Workers Inc.* (ceci est un projet étudiant)

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
![APM](https://img.shields.io/apm/l/vim-mode)

## A propos

**KNX-Communication-Analyser est un analyseur de trame de réseau de type Wireshark pour les objets KNX**, comme les stores, l'éclairage, le chauffage, la climatisation, et même les appareils connectés à la communication de porte utilisant le réseau KNX. Le programme est écrit en C++.

## Caractéristiques

* Voir en temps réel les trames KNX brutes en transition dans le réseau.
* Voir la traduction de l'action. Par exemple "Le boîtier n°1 transmet l'ordre d'allumer la lumière n°04".
* Mode log : exporter dans un fichier .md ou .txt les trames et leur traduction transmises pendant l'exécution du programme.
* Mode logs minimisés : le programme s'exécute en arrière plan et écrit dans un fichier les trames transmises pendant l'exécution du programme.
* (dans le projet) Imprimer les trames KNX sélectionnées directement depuis l'application.

## Démarrage

Pour exécuter ce programme, vous aurez besoin d'une carte PCB (le lien de la nôtre est ci-dessous) sur laquelle vous placerez un câble de votre bus KNX, et que vous connecterez à votre ordinateur.  
  
Après avoir téléchargé et installé le paquet [ici sur fosshub] (<https://www.fosshub.com/> "KNX-Communication-Analyser download"), et le KNX-Communication-Analyser lancé, il reconnaîtra si vous devez installer un (ou plusieurs) pilotes sur votre PC.
Le logiciel détectera les trames KNX et commencera à lire après avoir appuyé sur le bouton ▶️ ou sur Ctrl+B.

## Comment utiliser l'analyseur de communication KNX ?

|Raccourcis clavier|Information|
|-----|----|
|▶️ ou Ctrl+B|Lancer la capture de paquets|
|⏺️ ou Ctrl+R|Record the packets into one .md or one .txt file with their description|
|↘️ ou Ctrl+M|Minimiser le programme (toujours en cours d'exécution en arrière-plan) |
|⏸️ ou Ctrl+Pause|Pause de la capture|
|⏏️ ou Ctrl+Del|Restaurer la capture en cours (effacer toutes les données en cours)|
|🔚 ou Ctrl+S|Sauvegarder et quitter|.

[//] : <> (Capture d'écran intégrée. Veuillez supprimer cette ligne UNIQUEMENT lorsque la capture d'écran sera ajoutée).

## Compatibilité

Ce programme est toujours en développement. La version actuelle est alpha 0.0.1.
Ce programme a été conçu pour être utilisé sous Windows.

## Feedbacks

Si vous trouvez un bug, n'hésitez pas à créer un nouveau [issue] (<https://github.com/rzdhop/KNX-Communication-Analyser/issues> "issue's section"). Merci !

## Contributeurs

Ce programme génial a été écrit par [IchInose_0x3b](https://github.com/rzdhop "IchInose_0x3b GitHub profile"), [VictorFS78](https://github.com/VictorFS78 "VictorFS78 GitHub profile") et [Soajoh](https://github.com/Soajoh "Soajoh GitHub profile").

## Licence

Licence MIT.

# Utilisation du logiciel 

## Avec une trame déjà existante

Vous pouvez utiliser KNX-Communication-Analyzer pour analyser une trame que vous avez déjà enregistrée sur vôtre ordinateur. Pour cela, ajoutez l'argument -f. 
```.\<nom du programme> -f```

![Utilisation avec une trame déjà existante](https://raw.githubusercontent.com/rzdhop/KNX-Communication-Analyser/gh-pages/assets/knx-manualframe.gif)

chouette
