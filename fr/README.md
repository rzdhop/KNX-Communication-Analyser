# KNX-Communication-Analyser

> *Par KNX Workers Inc.* (ceci est un projet étudiant)

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
![APM](https://img.shields.io/apm/l/vim-mode)

## A propos

**KNX-Communication-Analyser est un analyseur de trame de réseau de type Wireshark pour les objets KNX**, comme les stores, l'éclairage, le chauffage, la climatisation, et même les appareils connectés à la communication de porte utilisant le réseau KNX. Le programme est écrit en C++.

## Caractéristiques

* Voir en temps réel les trames KNX brutes en transition dans le réseau.
* Mode log : exporter dans un fichier .txt les trames transmises pendant l'exécution du programme.

## Démarrage

Pour exécuter ce programme, vous aurez besoin d'une carte PCB (le lien de la nôtre est ci-dessous) sur laquelle vous placerez un câble de votre bus KNX, et que vous connecterez à votre ordinateur.  
  
Après avoir téléchargé et installé le paquet disponible dans les Releases du Git du projet (<https://github.com/rzdhop/KNX-Communication-Analyser> "KNX-Communication-Analyser download"), et le KNX-Communication-Analyser lancé, il reconnaîtra si vous devez installer un (ou plusieurs) pilotes sur votre PC.
Le logiciel détectera les trames KNX et commencera à lire après avoir appuyé sur le bouton ▶️.

## Comment utiliser la version graphique l'analyseur de télégrammes KNX ?

|▶️|Lancer la capture de paquets|
|➕|Restaurer la capture en cours (effacer toutes les données en cours)|
|🔚|Sauvegarder et quitter|.

Retrouvez plus d'informations sur le fonctionnement des deux logiciels au sein de cette documentation

## Compatibilité

La version actuelle est alpha 0.0.1.
Ce programme a été conçu pour être utilisé sous Windows 10. Les outils Qt et Visual Studio peuvent-être demandés, mais seront installés automatiquement si nécessaire.

## Feedbacks

Si vous trouvez un bug, n'hésitez pas à créer un nouveau [issue] (<https://github.com/rzdhop/KNX-Communication-Analyser/issues> "issue's section"). Merci !

## Contributeurs

Ce programme génial a été écrit par [IchInose_0x3b](https://github.com/rzdhop "IchInose_0x3b GitHub profile"), [VictorFS78](https://github.com/VictorFS78 "VictorFS78 GitHub profile") et [Soajoh](https://github.com/Soajoh "Soajoh GitHub profile").

## Licence

Licence MIT.

# Utilisation du logiciel

## Avec le logiciel graphique

La première méthode est d'utiliser le logiciel graphique, le plus simple d'utilisation, dont une version excécutable est disponible sur GitHub, dans la partie Releases.

Démarrez le logiciel. Il est probable que vous deviez l'ouvrir avec les droits administrateurs afin de pouvoir détecter les différents ports COM.
![KNX-CA Windows Logo](https://raw.githubusercontent.com/rzdhop/KNX-Communication-Analyser/gh-pages/assets/KNXCA_desktop.jpg)

Une fois le logiciel démarré, appuyez sur ▶️ pour commencer la lecture des trames.

![KNX-CA Windows Logo](https://raw.githubusercontent.com/rzdhop/KNX-Communication-Analyser/gh-pages/assets/Inkedscreen_qt_withoutdetails_LI.jpg)

Les trames s'affichant, vous pouvez voir le détail de celle-ci en cliquant sur l'icône ➕.

![KNX-CA Windows Logo](https://raw.githubusercontent.com/rzdhop/KNX-Communication-Analyser/gh-pages/assets/Inkedscreen_qt_LI.jpg)

## Avec le logiciel en ligne de commande

La version en ligne de commande est plus compliquée d'utilisation, mais plus complète.

Exécuté sans aucun argument, celui-ci ne vous retournera rien. Voici la liste des différents arguments disponibles.

|-h|-help|Affiche l’aide rapide ainsi qu’un lien vers la documentation en ligne.|
|-ad|--autodetect|Détecte automatiquement le port COM et l’écoute à la recherche de trames KNX.|
|-p|--manualport|Demande à l’utilisateur de spécifier le port COM qu’il souhaite utiliser pour l’analyseur de trames.|
|-f|--frame|Permet d’avoir les informations d’une trame hexadécimale déjà en possession de l’utilisateur.|

Une des fonctionnalités les plus intéressantes est le décopage d'une trame existante, comme vu prédédemment. Excécutez-le selon ce schéma: ```.\<nom du programme> -f```

Un GIF vous montre l'excécution de cette option ci dessous.

![Utilisation avec une trame déjà existante](https://raw.githubusercontent.com/rzdhop/KNX-Communication-Analyser/gh-pages/assets/knx-manualframe.gif)

## Fichier logs

Après chaque excécution du logiciel, un fichier ```logs.txt``` est généré dans le dossier contenant le logiciel.
Attention. Celui-ci n'est pas purgé à chaque excécution afin d'éviter la perte de données importantes. Vous devez donc le supprimer ou supprimer son contenu si vous souhaitez avoir un fichier nouveau.
