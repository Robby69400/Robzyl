># [**Translate 🌐**](https://translate.google.com/translate?sl=auto&tl=en&u=https://github.com/Robby69400/Robzyl_K5/)
# Firmware Quansheng UV-K5 (V1) et K1 - Robzyl

## Le logiciel est en anglais, les versions disponibles correspondent aux pays cibles pour les bandes : International, France, Pologne, Roumanie, Turquie, Russie, Tchéquie, Brésil. Ces bandes peuvent être personnalisées, me contacter sur Telegram.

### 🙏 Many thanks to Zylka, Kolyan, Iggy, Toni, Yves and Francois

<h2><a href="[https://www.youtube.com/@robby_69400](https://www.youtube.com/@robby_69400)" rel="nofollow">🗲 Youtube</a></h2>
<h2><a href="[https://t.me/k5robby69](https://t.me/k5robby69)">🗲 Telegram </a></h2>
Désormais le code source sera accessible sur demande. Contactez-moi sur Telegram.

# **Manuel Robzyl - Firmware Quansheng UV-K5**

## Introduction

Ce firmware, fork de NUNU de NTOIVOLA, est caractérisé par ses multiples fonctions de réception mettant en œuvre l’analyseur de spectre capable de traiter jusqu’à 160 canaux par seconde.
Actuellement, il ne fonctionne que pour les K5/K6 en V1.

## ⚠️ En cas de problème, vous pouvez utiliser la procédure de restauration en bas.

## ⚠️ Avertissements et responsabilités

**Le domaine de la radio est réglementé, chacun est responsable de l’utilisation qu’il fait de sa radio.**

## Firmware Robzyl – Principales fonctionnalités pour le Quansheng K5 !

🔥 Support des extensions EEPROM : permet de gérer 1000 canaux (nécessite le driver Chirp "512k").

## ⚠️ Attention : n'utiliser la version 512k que si vous avez plus de 8 Ko de mémoire EEPROM !

🔍 Modes de balayage multiples
Basculez entre les modes de balayage de fréquence, de plage, de bande et de liste – ultra-flexible pour toutes les situations !

🎚️ Sélection automatique de la modulation
Lors du balayage des bandes ou des listes, la modulation est automatiquement définie (FM/AM/SSB) en fonction des informations du canal ou de la bande enregistrée. Plus besoin de commutation manuelle !

📊 Squelch dynamique
Le squelch est basé sur la détection de crête et ignore les variations du bruit de fond.

⛔ Fréquences à ignorer
Évitez les fréquences gênantes ou bruyantes lors des balayages futurs d'une simple pression.

📜 Liste d'historique défilante
Consultez toutes les fréquences récemment balayées, y compris le nombre de détections ou la durée et les noms des mémoires correspondantes. Revenez facilement à n'importe quelle fréquence !
Enregistrement en EEPROM si l'extension est disponible.
Affiche le nom du canal dans l'historique si la fréquence correspond à une mémoire enregistrée.

✅ 15 listes de balayage et 32 bandes – Activez/désactivez visuellement vos bandes/listes, avec des indicateurs en forme d'étoile. Des listes de bandes sont disponibles pour plusieurs pays, mais peuvent être personnalisées sur demande.

📡 Transmission depuis le spectre – Appuyez sur PTT pendant le balayage pour émettre sur la fréquence sélectionnée, puis retour automatique au balayage.

🕒 Réglage DelayRssi – Ajustez la vitesse de balayage en réglant le délai avant la mesure du RSSI.
Réglage SpectrumDelay – Ajustez le délai avant relance du balayage.
Réglage MaxListenTime – Ajustez le temps maximum d'écoute avant relance du balayage.

💾 Sauvegarde/Chargement EEPROM – Paramètres de balayage, bandes, niveaux de squelch – tout est sauvegardé et chargé au démarrage.

😎 Mode Ninja : saut de fréquence sur votre K5.
😜 Bips Mario, Pac-Man, R2D2 et Roger.

## 🔥 Nouveautés V6_TURBO

<img width="120" height="120" alt="0-logo v6_turbo" src="https://github.com/user-attachments/assets/1f3a87fc-46a8-4132-a874-d56aa87eb5e7" />

Refonte graphique complète des écrans principaux !

Réallocation des touches dans les écrans VFO/MR :

* Appui long 4/5/6/0 pour régler BANDWIDTH/STEP/POWER/MODULATION.
* F + 7/8/9 pour lancer le spectre en mode SCANLIST/BANDLIST/FREQUENCE.
Passage du spectre vers VFO (touche PTT), les valeurs de LNA sont récupérées.
1000 entrées d'historique pour la version EEPROM 8k.
Tuning et correctifs divers.
* Scan des fréquences de l'historique
* U00 pour enregistrer l'historique non stop

## Nouveautés V5.5.0

Gestion de 1000 canaux avec la version 512k, nécessite un changement d'EEPROM.
Correction touches.
La LED verte ne s'allume plus si backlight < 6.
Affichage AFC (Automatic Frequency Control), permet de vérifier le réglage fin de fréquence.
Spectrum delay sauvegardé et le son coupé sans signal.
100 valeurs d'historique / blacklist stockables en EEPROM sur version 512k.

Nouveaux paramètres dans le menu [5] :

* Max Listen Time : temps maximum d'écoute d'une fréquence reçue.
* RX_Backlight_ON : permet d'activer le rétroéclairage en réception spectre.
* CLEAR HISTORY : efface l'historique de l'EEPROM (version 512k).
* FREE RAM : indique la mémoire disponible.

## Démarrage

* **Installation du firmware :**
* Télécharger la dernière version sur le GitHub (lien en fin de doc). Attention aux versions 8k et 512k selon votre EEPROM.
* Munissez-vous du câble de programmation USB compatible avec le poste.
* Brancher le poste à l’ordinateur puis démarrer le K5 tout en appuyant sur le bouton PTT.
* Puis, LED allumée fixe, transférer le firmware vers le K5 via le Flasher en ligne ou K5prog-win (lien en fin de doc).
* Si vous vous apprêtez à remplacer le firmware d’usine, il est recommandé de sauvegarder préalablement votre configuration et votre calibration à l’aide de K5prog (voir par exemple la vidéo de F5SVP).
* À chaque montée de version du FW, les paramètres du spectre sont réinitialisés.


* **Prise en main rapide :**
* Les menus cachés : les menus peu utilisés ont été cachés dans une optique de simplification. Pour afficher le menu complet, il suffit de démarrer le poste en pressant 0.
* La programmation avec Chirp : le driver à utiliser pour dialoguer avec le poste sous Robzyl est à télécharger (lien en fin de doc). Attention à ne pas être en mode spectre pour pouvoir communiquer avec le PC. Attention aux versions 8k et 512k selon votre EEPROM.
* Restauration du dernier état : suite à l’arrêt du K5, son redémarrage reprend dans le mode actif à son extinction en tenant compte de vos derniers paramètres de spectre sauvegardés.
* Les principales fonctionnalités propres au firmware Robzyl sont décrites dans la suite de ce document. Pour les fonctions de base du K5, veuillez vous reporter à sa documentation.



## Les modes VFO et Mémoire

Ces modes sont accessibles alternativement par un appui long sur la touche 3. Sur ces écrans, les touches 4/5/6/0 en appui long permettent de régler BANDWIDTH/STEP/POWER/MODULATION. Le menu en touche M donne également accès à tous ces paramètres. En réception, il apparaît un minuteur de temps d'écoute.

### VFO MODE

<img width="512" height="320" alt="2-VFO" src="https://github.com/user-attachments/assets/b22aa54a-6bd5-4d00-9600-564f20f88325" />

Le mode simple VFO permet de saisir librement une fréquence. En réception, il apparaît à l'écran la valeur d'AFC (info de décalage de fréquence), la valeur du S-mètre et la puissance du signal en dBm.

### MR MODE (Mémoires)

<img width="512" height="320" alt="1-MR" src="https://github.com/user-attachments/assets/069a11e4-e81d-4670-9d12-cf08a2ac43df" />

Cet autre mode permet de naviguer dans la banque des 200 mémoires nommées du K5 8K (ou 999 pour le K5 512K). Cette banque est à préparer et à injecter dans la radio depuis Chirp (driver 8k ou 512k). En réception, il apparaît à l'écran la valeur du S-mètre et la puissance du signal en dBm.

## Le mode spectre

### Fonctionnalités communes du mode spectre

Écran principal :

<img width="512" height="320" alt="3-spectre vue 1" src="https://github.com/user-attachments/assets/f7f1c0d7-538a-4fbd-8bb2-68a64e8bea8a" />

* Ligne haute :
* Type de spectre : SL (Scan Lists), FQ (Fréquences avoisinantes au VFO), BD (Bandes => le code bande pays apparaît en 1er), RG (Plage si définie via le menu).
* Valeur trigger UP Uxx du squelch (valeur de déclenchement sur signal montant).
* Délai de capture du RSSI d’un signal allant de 0 à 12 ms. Permet d’accélérer la vitesse de scan, mais cela réduit le rapport signal sur bruit.
* Modulation courante FM/AM/USB.
* Niveau de la batterie.


* Cadre 1 : 2 affichages possibles des informations liées à la fréquence en cours en pressant 8.
* Cadre 2 : Représentation graphique et dynamique des canaux analysés avec leur niveau de signal.
* Ligne basse : Étendue en cours et pic de fréquence au centre.

### Affectation des touches

* Touche 1 : Passer une fréquence à l’écoute (« skip »).
* Touche 2 : Accès à l’écran simplifié façon scanner simple.
* Touche 3 : Sélection de la largeur de bande d’écoute.
* Touche 4 : Menu de choix mono ou multiple SL/BD.
* Touche 5 : Accès aux Paramètres, puis ^/v pour naviguer, 1/3 pour changer les valeurs, 1/M pour saisir Fstart/Fstop (RG mode).
* Touche 6 : Navigation dans les modes SL/BD/FQ.
* Touche 7 : Sauvegarde des principaux paramètres.
* Touche 8 : 2 options d'affichage :
* Fréquence seule grande taille + info canal.
* Fréquence + info canal + timer d'écoute (petite taille).
* Touche 9 : Choix de la modulation.
* Touche 0 : Accès à l’écran d'historique.
* Touche M : Passage en Still mode (monitoring et accès registres).
* SIDE KEY 1 : Passer du mode Normal à FL (verrouillage de fréquence puis Monitor) et à M (écoute ouverte).
* SIDE KEY 2 : Blacklister une fréquence à l’écoute.
* Touche */F : Réglage squelch paramètre Uxx. 
  Si Uoo, enregistrment de l'historique sans s'arrêter
* Touche ^/v : Naviguer dans les SL ou les bandes.

### Menu des paramètres

<img width="512" height="320" alt="4-Menu" src="https://github.com/user-attachments/assets/752c4f6d-6626-4798-9886-c95ca67700de" />

* RSSI Delay : temps de capture du RSSI en ms. Une valeur trop faible peut faire rater des signaux.
* SpectrumDelay : Permet de définir le temps d’attente sur un signal à l’écoute ayant chuté sous le squelch. Si la valeur est à l’infini : pressez la touche Exit pour quitter l’écran d’écoute.
* Max Listen Time : temps maximum d'écoute d'une fréquence reçue.
* PTT (Option de passage en émission) : LAST RECEIVED = dernière fréquence entendue, LAST VFO FREQ = fréquence en VFO, NINJA MODE : Mode de communication expérimental par saut de fréquence à chaque PTT entre deux K5 utilisant le spectre en mode Ninja sur une Scanlist commune. Voir vidéo sur YouTube.
* Fstart/Fstop : paramétrage des fréquences ^/v (mode RG).
* Step : paramétrage de la canalisation des fréquences.
* ListenBW : paramétrage de la largeur de la bande d’écoute.
* Modulation : FM/AM/USB.
* DEFAUT PARAMS et touche 3 pour réinitialiser les paramètres du spectre ainsi que les registres.
* RX_Backlight_ON : permet d'activer le rétroéclairage en réception spectre.
* Freq counting : l'historique compte le nombre de réceptions d'une fréquence, Time counting compte le temps écoulé en réception de la fréquence.
* CLEAR HISTORY : efface l'historique de l'EEPROM (version 512k).
* FREE RAM : indique la mémoire disponible.
* PowerSave : permet d'augmenter le délai de réactualisation du spectre sur l'écran LCD.
* Noislvl_OFF : permet d'ajuster le niveau de bruit à prendre en compte pour éviter des déclenchements d'écoutes intempestifs.
* POPUPS : règle le délai d'affichage des messages en surimpression.
* U00_trigger : voir ci-dessous Historique.

### Vue simplifiée

<img width="512" height="320" alt="5-spectre simplifé" src="https://github.com/user-attachments/assets/cf74343c-cc15-4a25-95e4-eca36844a643" />

Cet écran offre une vue plus synthétique du scan en cours tout en permettant le réglage aisé des paramètres de squelch.

### Still mode (monitoring de fréquence)

<img width="512" height="320" alt="6-Mode still" src="https://github.com/user-attachments/assets/6c8e06e8-dabb-450f-b95a-aeac241ed38a" />

Le monitor se lance avec la touche M sur une fréquence en écoute. Sur cet écran, certains registres sont modifiables pour les utilisateurs avancés.

### Historique des fréquences

<img width="512" height="320" alt="7-Historique" src="https://github.com/user-attachments/assets/f9090de3-a594-4e61-a2d6-7b41627531e8" />

L'historique évolue dynamiquement au gré des fréquences reçues. Il est possible de naviguer dans la liste, la radio passe en Frequency Lock (FL) et on peut écouter directement les fréquences stockées (comme une radio FM qui balaie et enregistre des fréquences).

* Touche M : passer en Frequency Lock puis monitoring sur la fréquence. Touche PTT pour copier la fréquence vers le mode VFO.
* Touche 2 : sauvegarder l'entrée d'historique sélectionnée dans la première mémoire disponible.
* Touche 3 : effacer l'entrée de l'historique.
* Touche 5 : scanner les entrées de l'historique.
* Touche 7 : sauvegarder l'historique en EEPROM (version 512k).
* Touche 8 : effacer l'historique en mémoire, mais pas en EEPROM.

Il existe un mode spécial de scan en valeur U00 (juste avant la valeur U0). Ce mode permet de collecter très rapidement un historique sans s'arrêter en écoute ; c'est le paramètre U00_trigger du menu du spectre qui permet d'ajuster un niveau seuil de déclenchement des signaux à historiser.

### Conseils

* La valeur de réglage du squelch dépend de votre environnement, de votre antenne et de votre choix de délai RSSI.
* RSSI Delay : commencer par exemple à 3 ms et ajuster jusqu'à obtenir un bon compromis entre vitesse et réception.
* Trigger Up Uxxx : commencer par exemple à 5 et ajuster jusqu’à ne plus recevoir de bruits.
* Noise level (Noislvl) : commencer par exemple à 60 et ajuster pour limiter les faux signaux.

## Spectre sur les ScanLists (mode SL)

* Fonction : Permet de charger dans le spectre les mémoires affectées à des scanlists.
* Lancement : Depuis le mode VFO/MR, touche F+4.
* Utilisation et conseils :
* Préalablement, les fréquences en mémoires doivent avoir été affectées à une scanlist (ex. SL1 = PMR, SL2 = Répéteurs, SL3 = Aéro, etc.).
* À la première utilisation, vous pouvez naviguer dans chaque SL (^/v) pour ajuster les paramètres de squelch U, puis mémoriser vos valeurs avec la touche 7.
* Enfin, chargez vos SL dans le spectre via le menu de sélection en touche 4.



<img width="512" height="320" alt="8-SL sel menu" src="https://github.com/user-attachments/assets/1f7e690b-b5b3-4cdd-a84d-899616d78f8e" />

On navigue dans ce menu avec les touches ^/v.

* Touche 5 : choisir une SL en excluant les autres.
* Touche 4 : choisir/invalider une ou plusieurs SL.
* Touche * : affichage des mémoires affectées à la SL sélectionnée.

Les SL choisies apparaissent avec un symbole *. Puis faire Exit pour lancer le spectre. Touche 7 pour enregistrer sa configuration.

# Spectre sur plage de fréquences (mode FQ) :

* Fonction : Permet d’analyser une gamme de fréquences à partir d’une fréquence centrale ou bien à partir d’une étendue définie.
* Lancement : Depuis le mode VFO/MR, touche F+5.
* Utilisation et conseils :
* La fréquence issue du VFO/MR est portée au spectre en tant que fréquence centrale. Ensuite, vous pouvez agir sur le paramétrage de votre spectre selon vos besoins en step, modulation, etc. (Réglages touche 5).
* L’étendue des fréquences basse/haute peut être ajustée dans le menu via les paramètres FStart/FStop. Sur ces paramètres, faire 1 pour accéder à la saisie et M pour valider (touche * pour la virgule).
* Ajuster votre squelch.



## Spectre sur les bandes prédéfinies (mode BD)

* Fonction : Permet d’analyser en spectre des bandes prédéfinies (ex. PMR, CB, AERO, HAM, etc.).
* Lancement : Depuis le mode VFO/MR, touche F+6.
* Utilisation et conseils :
* Les bandes sont stockées dans un fichier `bands.h` personnalisable avec recompilation du firmware ; il faut me contacter pour cela.
* Il est possible de paramétrer 32 bandes.



### Exemple de fichier de configuration

Les fréquences sont définies en 10 Hz (144 MHz s'écrit 14400000).
Il y a 32 bandes max et le nom fait maximum 12 caractères.
Les steps sont à choisir parmi : S_STEP_0_01kHz, S_STEP_0_1kHz, S_STEP_0_5kHz, S_STEP_1_0kHz, S_STEP_2_5kHz, S_STEP_5_0kHz, S_STEP_6_25kHz, S_STEP_8_33kHz, S_STEP_10_0kHz, S_STEP_12_5kHz, S_STEP_25_0kHz, S_STEP_100kHz, S_STEP_500kHz.
Les modulations parmi : MODULATION_FM, MODULATION_AM, MODULATION_SSB.

<img width="741" height="130" alt="bands h" src="https://github.com/user-attachments/assets/dc352144-cb45-4a49-b9cb-8a8375f98935" />

De la même manière qu’en mode SL, il est possible à la 1ère utilisation de paramétrer et sauvegarder la valeur du squelch sur les bandes qui vous intéressent. Touches ^/v pour naviguer dans les bandes.

Ensuite, le menu touche 4 permet de choisir les bandes à analyser de la même manière que le menu en mode SL :

<img width="512" height="320" alt="9-BD sel menu" src="https://github.com/user-attachments/assets/c81a3d8b-eddf-49a7-a8ac-2adae633c6cc" />

## Procédure de restauration (en particulier retour de FAGCI, IJV et KARINA)

* Utiliser l'archive `Rollback.zip`.
* Commencez par flasher le fichier (`ROLLBACK.bin`) en mode simple.
* Après le flashage, éteignez la radio, maintenez le bouton 7 enfoncé, puis rallumez-la.
* Attendez que la mémoire soit effacée.
* Flashez ensuite le firmware d'origine (`K6 v3.00.19_publish.bin`).
* Après le flashage, effectuez une réinitialisation complète via le menu.
* Enfin, flashez le fichier de calibration (`my_calibration.bin`) (allumez la radio en mode simple).
* Utilisez k5prog.

## Puissances

* Low : puissances situées auour de 1W selon les bandes VHF ou UHF.
* Low VERSION DEV:puissance de quelques milliwatts, convient pour faire des tests de proximité entre radios.
* Mid : puissances situées entre 2 et 3W selon les bandes VHF ou UHF.
* High : puissance maximale proposée par le matériel, soit en moyenne 5W.

## FAQ

* Est-il possible de verrouiller son K5 en bande PMR uniquement ? : Oui, affichage menus cachés, menu n°48, valeur PMR446 ONLY.
* Le firmware est-il compatible avec les mods SI4732 ? : Oui, une version est en cours de développement
* Le firmware est-il compatible avec les mods EEPROM ? : Oui, 2 versions existent : 8k et 512k pour les K5 modifiés.
