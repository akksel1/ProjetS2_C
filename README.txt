==================================== Bienvenue dans notre code! ====================================

Notre programme est un jeu de Takuzu. Le Takuzu est un jeu de réflexion consistant à remplir une grille avec les chiffres 0 et 1 par déduction logique.
Pour remplir la grille différentes conditions sont à prendre en compte:
- Il doit avoir le même nombre de 1 et de 0 dans les lignes et dans les colonnes
- Il ne doit pas y avoir une ligne ou une colonne identique dans la grille
- Il ne doit pas avoir 3 fois de suite un 0 ou un 1 en colonne et en ligne


Si vous avez bien saisi toutes les subtilités du TAKUZU a vous de jouez !!!




==================================== EXPLICATION DU PROGRAMME ============================================================================================================
Le programme est composé de 4 fichiers :

Vérifier que vous avez bien tous les fichiers avant de lancer le programme!!


-	main.c                                            (Dans ce fichier vous trouverez l'interface utilisateur)
-	fonction.c                                        (Dans ce fichier nous retrouvons la caverne Ali Baba tout le code de nos fonctions)
-	fonction.h                                        (Dans ce fichier vous trouverez l'entièreté de nos fonctions pour vous offrir une excellente expérience)
-	README.txt                                        (Et enfin celui-ci où je vous parler actuellement, le fichier est sensé vous expliquez comment jouer simplement)

====================================================================================================================================================================================




Notre code est structuré sur 3 menus principaux : PARTIE I (l.1194), PARTIE II, PARTIE III (l.1754)


================================================================================================================================================
VOICI LES DIFFERENTES FONCTIONNALITES QUE COMPOSE LA PARTIE I:

- Pour commencer vous devez choisir la dimension de la grille
    1 - GRILLE 4x4
    2 - GRILLE 8x8
    3 - GRILLE 16x16


Ensuite un menu s'ouvrira avec 3 possibilités, composé chacun de sous-menu:

>> 1 - SAISIR MANUELEMENT UN MASQUE\n");
         Sous-menu
	     -------------------------
	     1- Saisir/Modifier le masque
         2- Afficher le masque & la grille jeu
         3- Reinitialiser le masque & la grille jeu
         -------------------------

>> 2 - GENERER UN MASQUE
           Sous-menu
           -------------------------
           Vous devais choisir une difficulté
           1 - DEBUTANT
           2 - MOYEN
           3 - EXPERT (veuillez prevoir 5min)
           -------------------------



>> 3 - JOUER AVEC UNE GRILLE SOLUTION EN DUR
           Sous-menu
           -------------------------
           Vous devez choisir une difficulté
           1 - DEBUTANT
           2 - MOYEN
           3 - EXPERT
           -------------------------

Explication en detail de l'option 3 -> JOUER
---------------------------------------------------------------------------
Il vous reste plus qu'à remplir la grille de la facon suivante : ligne/colonne


/!\ ATTENTION à chaque mauvais coup vous perdez une vie, au début de la partie vous avez 3 vies  [NE LES PERD PAS ELLES SONT PRECIEUSES !!!]



Messages pouvant apparaitre:
-----------------------------

Exemple d'indice susceptible d'avoir :  INDICE : ATTENTION IL Y A 3x 1 DE SUITE -> Le message vous demande d'être plus vigilant pour ne pas perdre la partie

Exemple erreur susceptible d'avoir:  -1 PT : LA COLONNE A CONTIENT TROIS 1 DE SUITE ! -> Vous venez de réaliser un mauvais coup vous perdez donc une vie attention

Coup valide mais incorrect... -> cela signifie que votre coup respecte toutes les règles sauf que la grille solution n'est pas composée d'un 1 ou 0 a cet endroit
----------------------------------------------------------------------------------------------------




====================================================================================================================================================================================

VOICI LES DIFFERENTES FONCTIONNALITES QUE COMPOSE LA PARTIE II:

Pour commencer vous devez choisir la dimension de la grille
-------------------------
     1 - GRILLE 4x4
     2 - GRILLE 8x8
     3 - GRILLE 16x16
-------------------------

Vous devez choisir une difficulté
-------------------------
1 - DEBUTANT
2 - MOYEN
3 - EXPERT
-------------------------



Autour de SPARTACUS ( l'ordinateur) de résoudre une grille tous seul

Chaque coup est affiché au-dessus de la matrice :
----------------------------------------------------

Quand un indice est affiché en VIOLET dans la matrice ->  cela signifie que Spartacus a choisi la bonne valeur au bon endroit en respectant toutes les règles
Quand un indice est affiché en ROUGE dans la matrice -> cela signifie que Spartacus a fait un coup qui respecte toutes les règles sauf que la grille solution n'est pas composée à cet endroit de la valeur saisi donc il l'inverse ( Cela correspond "Coup valide mais incorrect...")
=============================================================================================================



=============================================================================================================
VOICI LES DEUX FONCTIONNALITE QUE COMPOSE LA PARTIE III:
            Pour commencer vous devez choisir la dimension de la grille
            -------------------------
            1 - GRILLE 4x4
            2 - GRILLE 8x8
            3 - GRILLE 16x16
            -------------------------

>> 1 - GENERER UNE GRILLE SOLUTION -> l'ordinateur va générer une grille solution

>> 2 - JOUER MANUELEMENT AVEC GRILLE SOLUTION GENERER -> l'ordinateur va générer une grille solution pour que vous puissiez jouer dessus
          sous-menu
           -------------------------
           Vous devez choisir une difficulté
           1 - DEBUTANT
           2 - MOYEN
           3 - EXPERT
           -------------------------
---------------------------------------------------------------------------
Il vous reste plus qu'à remplir la grille de la facon suivante : ligne/colonne


/!\ ATTENTION à chaque mauvais coup vous perdez une vie, au début de la partie vous avez 3 vies  [NE LES PERD PAS ELLES SONT PRECIEUSES !!!]



Messages pouvant apparaitre:
-----------------------------

Exemple d'indice susceptible d'avoir :  INDICE : ATTENTION IL Y A 3x 1 DE SUITE -> Le message vous demande d'être plus vigilant pour ne pas perdre la partie

Exemple erreur susceptible d'avoir:  -1 PT : LA COLONNE A CONTIENT TROIS 1 DE SUITE ! -> Vous venez de réaliser un mauvais coup vous perdez donc une vie attention

Coup valide mais incorrect... -> cela signifie que votre coup respecte toutes les règles sauf que la grille solution n'est pas composée d'un 1 ou 0 a cet endroit
----------------------------------------------------------------------------------------------------



=============================================================================================================



*************************************************************************
/!\ ASTUCE
Si vous voulez modifier en dur une matrice solution 4x4 ou 8x8 ou 16x16 rendez-vous dans le fichier fonction.c dans la fonction Game_gridd (ligne 658)

Vous retrouverez dans celle-ci une partie pour la dim=4 (4x4), dim=8 (8x8) et dim=16 (16x16)
il vous reste plus qu'à remplacer la matrice bonne chance <3

*************************************************************************


===========================-- FONCTIONALITES DU PROGRAMME --==================================================================================


    > Saisie d'un masque manuellement par l'utilisateur

    > Génération d'un masque avec 3 niveaux de difficulté (Débutant 25% d'indices cachés, Moyens 50% indices cachés, Experts 75% indices cachés)

    > Afficher une grille jeu (en appliquant un masque manuel)

    > Afficher une grille jeu (en générant un masque)

    > Résoudre automatiquement une grille

    > Générer automatiquement une grille jeu aléatoire


=============================================================================================================


********************************************
Programme créé Alex Stoltz et Louka Milan




