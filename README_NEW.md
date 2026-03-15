# Documentation Firmware Robzyl V6.7
## Pour Quansheng UV-K1 et UV-K5 (v3)

## 1. Introduction et avertissements

**Robzyl V6.7** est une évolution du firmware Robzyl pour UV-K5 v1 basée sur **F4HWN Fusion v5.2** permettant la portabilité  vers l'UV-K1. Robzyl apporte des modifications significatives notamment son analyseur de spectre ultra rapide, sous plusieurs modes et avec des fonctionnalités exclusives.

**Compatibilité** : 
- Quansheng UV-K1
- Quansheng UV-K5 (v3 uniquement, avec quelques limitation à précier)

### ⚠️ Avertissements importants
- **Risque de bricking** : veuillez respecter la compatibilité matérielle
- **Sauvegarde calibration** : impérative avant tout 1er flash de la radio
- **Législation** : Le domaine de la radio est réglementé, chacun est responsable de l’utilisation qu’il fait de sa radio.

## 2. Principaux apports

**Connectivité et Stockage en mémoires**
*   **Support USB natif** : En version USB, pour communiquer Chirp, il faut activer la communication avec le PC en **maintenant la touche SK1 enfoncée au démarrage** ; cela permet de réduire la consommation d'énergie le reste du temps.
*   **Capacité de mémoire** : Selon La version choisie, le firmware propose la gestion de 600 à 999 canaux en mémoire, **20 scanlists** et **48 mémoires** en radio FM.

**Analyseur de Spectre et Réception**
*   **Balayage entrelacé** : Utilise des pas (steps) de 0,5 kHz à 25 kHz pour améliorer la détection des signaux lors du scan du spectre.
*   **Vitesse de scan** : Capable d'analyser environ **200 canaux par seconde**.
*   **Filtre "Glitch"** : Un nouveau paramètre dans le menu permet d'améliorer la sélectivité en rejetant les parasites.
*   **Transmission depuis le spectre** : Possibilité d'émettre sur une fréquence détectée en appuyant sur PTT pendant le balayage, avec retour automatique au scan après l'émission.
*   **Squelch Dynamique** : Basé sur la détection de crête, il ignore les variations du bruit de fond pour plus de précision.
*   **Historique défilant** : Une liste d'historique enregistre les fréquences balayées, le nombre de détections et les noms des canaux.
*   **Gestion des modulations** : Sélection automatique de la modulation (FM/AM/SSB) en fonction des informations du canal ou de la bande lors du balayage.
*   **Fréquences à ignorer** : Possibilité de mettre en "blacklist" des fréquences bruyantes pour les sauter lors des prochains scans.

**Modes Spécifiques et Ergonomie**
*   **Affichage simplfié du spectre** : L'affichage par défaut est en histogrammes, mais il est également proposé un écran simplfié
*   **Personnalisation sonore** : Ajout d'une option **Soundboost** et de bips de fin de transmission variés (Mario, Pac-Man, R2D2).

**Retraits** : Pour libérer de l'espace et optimiser les performances, les fonctionnalités **Aircopy** et les **jeux** ont été retirés de cette version.


## 3. Versions disponibles

| Version | Canaux |  Communication PC | Particularités |
|---------|--------|--------------------|---------------|
| **ROBZYL.K1.USB.bin** | **600** | ✅ USB (ON+SK1) | Pas d'UART |
| **ROBZYL.K1.RS232.bin** | **800** | ✅ UART Kenwood | Pas d'USB |
| **ROBZYL.K1.NO_COM.bin** | **999** | ❌ Aucune | Chirp non utilisable *|

**Driver CHIRP inclus** : `Chirp_Robzyl_K1.py`

 \* Pour bénéficier des 999 canaux, il faut d'abord installer une version USB ou RS232, uploader les mémoires avec Chrip puis revenir en version NO_COM.

## 4. Installation et configuration initiale

### 4.1 Prérequis
1. Identifier votre radio : UV-K5 v3 ou UV-K1
2. Télécharger le fichier ROBZYL.K1.xxx.bin
3. Accéder à un flasher web type [Multi-UVTools](https://spm81.github.io/Multi-UVTools/) ou [UVTools2](https://armel.github.io/uvtools2/)


### 4.2 Sauvegarde initiale obligatoire !!
Avant toute installation d'un nouveau firmware sur une radio, il est **important** de sauvegarder les données de calibration (Dump calibration sur [Multi-UVTools](https://spm81.github.io/Multi-UVTools/) ou [UVTools2](https://armel.github.io/uvtools2/))


### 4.2 Procédure de flashage
1. Brancher la radio au PC, idéalement en USB pour plus de rapidité.
2. Accéder au flasher web
3. Démarrer en pressant PTT, la radio passe en mode DFU (led blanche allumée fixe)
4. Flasher la radio qui redemarrera en fin de mise à jour.

### 4.3 Configuration CHIRP
1. Télécharger le driver Chirp_Robzyl_K1.py
2. Brancher la radio au PC
3. Exécuter Chrip à l'aide d'un raccourci du type : "C:\Program Files\CHIRP\chirp.exe" --module C:\CHIRPpy\Chirp_Robzyl_K1.py
4. Télécharger depuis la radio → Modifier les mémoires → Uploader vers la radio

## 5. Guide de référence et menu général

**Guide de base** : Pour les focntionanlités de base du firmware, veuillez vous reporter au [Guide F4HWN Fusion v5.2.0 disponible en PDF](https://www.dropbox.com/scl/fi/tuv1j8r4ct0503lw9qhtb/MENU-ARMEL-F4HWN-K1-Fusion-v5.2.0.pdf?e=3&fbclid=IwY2xjawQav_pleHRuA2FlbQIxMQBicmlkETFSc0VnSTB4OVpOYzlqQWRPc3J0YwZhcHBfaWQQMjIyMDM5MTc4ODIwMDg5MgABHqWft_sOj1NWqHCrYDFH7kIVyxdctXuEwqtkX4SFV2P76sXNUKluA8hkVy20_aem_yY7q7BrxxU69xQ7l3bGSrw&rlkey=ua3qqsvqarnozp5be0ul9i2f3&dl=0)

**Menu principal**  accessible en mode MR/VFO :

| Pas de menu | Fonction | 
|-------------|----------|
| **1-18** | Paramètres par canal |
| **19-74** | Paramètres système | 

Se référer au guide pour les détaisl concernant chaque pas de menu.

## 6. Raccourcis clavier

| Touche | Court | Long | F+ |
|--------|-------|------|----|
| **MENU** | Menu | - | - |
| **EXIT** | Quitte | - | - |
| **< >** |Touches ↑↓ | - |Squelch ↑↓|
| **1** | - | Plan de bande | Plan de bande |
| **2** | - | VFO A/B | - |
| **3** | - | VFO/MR | - |
| **4** | - | Copie de fréquence | Copie de fréquence |
| **5** | - | **Spectre Robzyl** | - |
| **6** | - | Puissance ↑↓ | Puissance ↑↓ |
| **7** | - | VOX N/A | - |
| **8** | Freq inverse | Rétroéclairage BLMax / BLMin | - |
| **9** | -  | Canal favori | Rétroéclairage BLMax / BLMin |
| **\*** | - | Scan VFO/MR * |  Scan CTCSS/DCS  |
| **F** | Fonction | Verrou clavier | - |

 \* Bien que le scan ici soit conservéi, il est **beaucoup plus interessant** de scanner avec l'analyseur de spectre Robzyl (Fn+5) qui est ultra performant.
 
## 7. Spectre / Bandscope Robzyl

### 7.1 Avantages vs F4HWN
✅ Remplacement COMPLET du spectre F4HWN
✅ Multiples modes avancés : BANDE, SCAN-LISTE, RANGE, FREQUENCE 
✅ Bandes MONDIALES (tous pays en 1 firmware)
✅ Précis, rapide et fluide

| Mode | Description |
|---------|-------------|
| **BANDE** | 50 bandes mondiales prédéfinies (HAM, AIR, SATCOM, etc.)|
| **SCAN-LIST** | 20 scan-listes basées sur vos canaux mémoire |
| **RANGE** | Spectre sur bornes de fréquence début / fin |
| **FREQUENCE** | Spectre centrée sur la fréquence en VFO |

### 7.2 Utilisation pratique

**Lancement du spectre** : Fn+5 depuis le VFO.

[*IMAGE ECRAN PRINCIPAL*]

* Ligne supérieure : DSxx valeur de DynamicSquel, Modulation, largeur de bande d'écoute, step de canalisation (ou A+XXXX en écoute, valeur AFC)
* Ligne 2-2 : Affichage fréquence en cours et selon le mode la scan-list ou la bande 
* Ligne basse : Étendue en cours et pic de fréquence au centre.

**Affectation des touches :**

|Touche | Fonction | 
|---------------------|---------------|
| **1** | Passer une fréquence à l’écoute (« skip »)
| **2** | Accès à l’écran simplifié (scanner)
| **3** | Sélection de la largeur de bande d’écoute
| **4** | Menu de séléction mono ou multiple SL ou BD
| **5** | Accès aux Paramètres, puis 1/4 pour naviguer, </> pour changer les valeurs
| **6** | Navigation dans les modes BANDE, SCAN-LISTE, RANGE, FREQUENCE
| **7** | Sauvegarde des principaux paramètres.
| **8** | Options d'affichage fréquence BIG/CLASSQIUE
| **9** | Séléction de la modulation
| **0** | Accès à l'historique des récéptions
| **M** | Passage en Still mode (monitoring et accès registres)
| **SIDE KEY 1** | Passer du mode Normal à FL (verrouillage de fréquence), puis à M (Monitor = écoute ouverte).
| **SIDE KEY 2** | Blacklister une fréquence à l’écoute.
| ***/F** | Réglage squelch dynamqiue Uxx
| **< >** | Naviguation dans les SL, les bandes, ou en fréquence.

**Menu des paramètres :**

[*IMAGE ECRAN PARAM*]

* RSSI Delay : temps de capture du RSSI en ms. 
* SpectrumDelay : Permet de définir le temps d’attente sur un signal à l’écoute ayant chuté sous le squelch. Si la valeur est à l’infini : pressez la touche Exit pour quitter l’écran d’écoute.
* Max Listen Time : temps maximum d'écoute d'une fréquence reçue.
* Fstart/Fstop : paramétrage des fréquences ^/v (mode RG).
* Step : paramétrage de la canalisation des fréquences.
* ListenBW : paramétrage de la largeur de la bande d’écoute.
* Modulation : FM/AM/USB.
* RX_Backlight_ON : permet d'activer le rétroéclairage en réception spectre.
* PowerSave : permet d'augmenter le délai de réactualisation du spectre sur l'écran LCD.
* Noislvl_OFF : permet d'ajuster le niveau de bruit à prendre en compte pour éviter des déclenchements d'écoutes intempestifs.
* Popups : règle le délai d'affichage des messages en surimpression.
* Record  Trig : pour enregistrer l'historique non stop.
* Key Unlocked : verouillage automatique du clavier.
* GlitchMax : niveau de rejet du bruit.
* SoundBoostON : augmente le niveau sonore mais également le risque de distortion.
* Clear History : efface l'historique de l'EEPROM.
* Reset Default : réinitialise les paramètres du spectre ainsi que les registres.

**Vue simplifiée :**

[*IMAGE ECRAN SIMPLIFIE*]

Cet écran offre une vue synthétique du scan en cours.

**Still mode (monitoring de fréquence) :**

[*IMAGE ECRAN STILL*]

Le monitor se lance avec la touche M sur une fréquence en écoute. Sur cet écran, certains registres sont modifiables pour les utilisateurs avancés.

**Historique des fréquences :**

[*IMAGE ECRAN HISTO*]

L'historique évolue dynamiquement au gré des fréquences reçues. Il est possible de naviguer dans la liste, la radio passe en Frequency Lock (FL) et on peut écouter directement les fréquences stockées (comme une radio FM qui balaie et enregistre des fréquences).

* Touche M : passer en Frequency Lock puis monitoring sur la fréquence. Touche PTT pour copier la fréquence vers le mode VFO.
* Touche 2 : sauvegarder l'entrée d'historique sélectionnée dans la première mémoire disponible.
* Touche 3 : effacer l'entrée de l'historique.
* Touche 5 : scanner les entrées de l'historique.
* Touche 7 : sauvegarder l'historique en EEPROM (version 512k).
* Touche 8 : effacer l'historique en mémoire, mais pas en EEPROM.

Il existe un mode spécial de scan en valeur U00 (juste avant la valeur U0). Ce mode permet de collecter très rapidement un historique sans s'arrêter en écoute ; c'est le paramètre U00_trigger du menu du spectre qui permet d'ajuster un niveau seuil de déclenchement des signaux à historiser.

## Spectre sur les ScanLists (mode SL)

* Fonction : Permet de charger dans le spectre les mémoires affectées à des scanlists.
* Lancement : Depuis le mode VFO/MR, touche F+4.
* Utilisation et conseils :
* Préalablement, les fréquences en mémoires doivent avoir été affectées à une scanlist (ex. SL1 = PMR, SL2 = Répéteurs, SL3 = Aéro, etc.).
* À la première utilisation, vous pouvez naviguer dans chaque SL (^/v) pour ajuster les paramètres de squelch U, puis mémoriser vos valeurs avec la touche 7.
* Enfin, chargez vos SL dans le spectre via le menu de sélection en touche 4.

[*IMAGE ECRAN SEL SL*]

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
* Il est possible de paramétrer 32 bandes.

Ensuite, le menu touche 4 permet de choisir les bandes à analyser de la même manière que le menu en mode SL :

[*IMAGE ECRAN SEL BD*]

## 8. Procédure de restauration (en particulier retour de FAGCI, IJV et KARINA)

* Utiliser l'archive `Rollback.zip`.
* Commencez par flasher le fichier (`ROLLBACK.bin`) en mode simple.
* Après le flashage, éteignez la radio, maintenez le bouton 7 enfoncé, puis rallumez-la.
* Attendez que la mémoire soit effacée.
* Flashez ensuite le firmware d'origine (`K6 v3.00.19_publish.bin`).
* Après le flashage, effectuez une réinitialisation complète via le menu.
* Enfin, flashez le fichier de calibration (`my_calibration.bin`) (allumez la radio en mode simple).
* Utilisez k5prog.


## 9. 📱 Code et discussions

- **GitHub** : https://github.com/Robby69400/Robzyl_K1
- **Telegram** : [Telegram Robzyl](https://t.me/k5robby69)
