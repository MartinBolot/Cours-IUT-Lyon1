﻿Lien avec le matériel
------

GPIO (E/S TOR - Tout Ou Rien)
ADC = Analog Digital Converter
DAC = Digital Analog Converter

Linux embarqué
=======




Introduction
Cas d'utilisation de Linux en embarqué

    Traitements "lourds"

    traitement d'imlages
    Flux vidéos
    Génération de fichiers de logs et d'enregistrements haut débit sur stockage externe type disques durs.

    Affichage et IHM

    Écrans haute définition
    Écrans avec une fréquence de rafraîchissement élevée

    Communication haut débit

    Wifi
    Ethernet
    Multi-protocole

    Systèmes et programmes complexes

Limitations

    Mémoire disponible

    RAM >= 16Mo et ROM >= 4Mo (Routeur WRT54GL de Lynksys, toujours en vente !)

    Énergie disponible

    Consommation de l'ordre de quelques Watts (0.5W - 10W)

    Gestion temps réel
> temps réel = on sait quand on a la réponse de manière sûre (ça pourrait être une semaine c'est pareil)

    Asservissements
    Capteurs
    Acquisition de données
    Temps réel dur

Temps réel "dur"

    Linux-rt (patch officiel PREEMPT-RT sur le noyau Linux standard) par Ingo Molnar

    N'ajoute aucune "sous-couche" de virtualisation

    Solutions basées sur la couche de virtualisation Adeos : les projets RTAI et Xenomai.
    Solution RTLinux, si vous voulez jouer avec des brevets et des problèmes judiciaires plutôt qu'avec du code ...

Utilisation conjointe micro-processeur et micro-contrôleur

    Processeurs multi-core assymétriques

Historique

    GNU ...
    Linux ...

Licences

    Les licences FSF

    Copyleft
    FSF : 4 libertés : Exécution (sur toutes les machines), Étude (accès au code source), Modification, Redistribution
    La licence GPLv2 : Commercialisation - Mise à disposition des sources - Recompilation - Transmission des droits
    La licence GPLv3, évolution de la GPLv2 - Tivoı̈sation  
> plus de droit de mettre un verrou matériel

    LGPL (Lesser General Publc Licence)

    Parmi d’autres :

    Licences Creative Commons
    Licences BSD
> ~= CC-by (licence de logiciel libre, utilisateur a des droits s'il remplit les conditions)

    Licences de projets (Mozilla, Apache, ...)

 > Lien statique = tout est inclus, lien dynamique à l'exécution : seulement ce dont on a besoin

 > .so sous linux (shared object) ~= dll sous windows

Matériel

    Linux supporte 31 architectures
    Et de très nombreuses sous-architectures !
    Utilisation de SOC (System on Chip)
>	=> très peu de mémoire interne, plus de mémoire externe

Architecture des systèmes Linux
Empilement de couches

Le noyau Linux

    Fonction ?
>	=> faire l'Abstraction du matériel pour le système qui est au-dessus (on ne se soucie pas d'où est stocké un fichier ram, usb, ...)

    Abstraction du matériel
    Uniformisation des couches matérielles en interfaces simples (VFS, ALSA, ...)
    Fourni des services utilisables par les processus, et dédiés a des fonctionnalités "atomiques"

> Root ou autre => tout programme se lance dans l'espace utilisateur (!= noyau)

> Entre espace utilisateur et noyeau => appels systèmes

> 3 types de fonctions en C : appels systèmes, fonction utilitaire pour les données (strlen,...), allocations mémoires (malloc,...)

    Norme POSIX

    Portable Operating System Interface for UNIX
    Mais pas que ...
> le noyau linux ne respecte pas que la norme posix

    Noyau monolithique modulaire
    Un package de services fondamentaux

    Ordonnanceur
    Gestion de la mémoire
    IPC (Inter process communication)
    VFS (Virtual File System)
    Contrôle d'accès aux ressources
    Gestion des timers, locks et interruptions

    Des services additionnels à la carte

    Réseau
    Systèmes de fichiers
    Drivers (USB, Son, ...)

Syscalls et Libc

    Les appels système~: interface entre deux mondes

    Espace utilisateur et espace noyau
    Les appels système~: 346 dans le noyau 3.8-rc5
    Appel par la LibC
    Ne pas confondre~: L'utilisateur 'root' est en espace utilisateur~!

    La LibC~: La base de l'espace utilisateur

    Liée au noyau
    Liée au compilateur
    Différentes versions : glibc, eglibc, uClibc, Bionic libc +(android), ...

Fichiers et Systèmes de fichiers

    Tout est fichier

    Les droits des fichiers : une des bases des systèmes UNIX
    Les périphériques : des fichiers spéciaux appelés nœuds (device nodes)
    Des fichiers virtuels : /proc et /sys

    Systèmes de fichiers

    Grande variété : FAT, EXT*, REISERFS, UBIFS, NFS, XFS, ..., ZFS
    Journalisés

> trace des modifs récentes pour éviter la corruption si plantage

    Spécifiques : JFFS2, UBIFS, CRAMFS, ...
    Non persistants : tmpfs, procfs, sysfs
    Accès par les points de montage

> point de montage = dossier (point de l'architecture) à laquelle on donne accès à un morceau du système de fichier

> ~= lecteur C: sur windows par exemple ou une partition (on peut monter une partition a plusieurs endroits)

    Uniformisation des accès : le VFS

> (virtual file system)

    Organisation : FHS (Filesystem Hierarchy Standard)
    Système de fichiers racine (rootfs) et démarrage

> rootfs car relatif à la racine "/"

> user => libc => syscall => VFS => FS => USB Mass Storage => USB

> (c'est long mais il peut y avoir une mise en cache du fichier un fois le syscall appelé un 1ere fois)

Systèmes d'init

    init : PID 1
    Rôle : défini dans la norme POSIX
    Très nombreux

    BSD (pas de runlevel)
    SysV (inittab + runlevels)
    initng
    upstart
    runit
    busybox
    Home made ?

Shell ou coquille vide ?

    Interpréteur de commandes
    Fait partie de la norme POSIX
    Texte ou Graphique
    Obligatoire ?
    Ne pas confondre avec le terminal (un ensemble de périphériques qui permet d'interagir avec un ordinateur).

Chaîne de cross-compilation
Principe

    Architecture hôte != Architecture cible
    Hôte (host) = Poste de développement : Gros processeur et beaucoup d’espace de stockage et de RAM
    Cible (target) = Système embarqué : ressources limitées
    Génération de code binaire exécutable par la cible

Éléments constitutifs de la chaîne de (cross-)compilation

    Compilateurs (C, C++, Go, Fortran, ...)
    Binutils (Editeur de liens, ...)
    LibC (glibc, eglibc, uClibc) ?

    glibC : GNU - Licence LGPL - Performante - Complète - Taille importante: 1.7 Mo
    uClibc : Licence LGPL - 400 Ko
    klibc : "Kernel C library" - GPL - Non compatible avec Busybox . . .

    Noyau Linux

Mise en œuvre
Séquence de démarage

    Bootloader ?
    Noyau Linux
    Rootfs
    Init

Génération du noyau Linux

    Source ?

    Vanilla (kernel.org)
    Custom spécifique à la carte utilisée

    Configuration

    make oldconfig / myboard defconfig / menuconfig / xconfig
    Fichier ”.config”
    make ARCH=... CROSS_COMPILE=...
    make ... modules_install INSTALL_MOD_PATH=...

    Formats de sortie adaptés au bootloader

    bzImage
    zImage
    uImage
    ...

    Application de patches
    Fichier binaire du noyau:

    arch/.../boot/...

    Device tree ?

    arch/arm/boot/dts/....
    Génération du "device tree blob"
    Chargement par le bootloader

Génération du système de fichiers racine
> obligatoires à minima : /prog et /sys

    Type ?

    Initrd : noyau 2.4 - emulation block - filesystem - taille fixe

> « initial Ram Disk »

> emulation d'un disque dur on crée le fichier à la taille du DD (fixe)

> on se retrouve avec des doublons dans le cache, mauvaise chose

    initramfs : tmpfs - config initramfs du noyau : création et inclusion

> créé pour pallier le problème des doublons dans le cache

    Systèmes de fichier journalisés

> moments ou la table de correspondance des fichiers et fichies ne sont 	pas cohérente : systèmes pas journalisés

> Dans les sdf journalisés un historique est tenu donc si le périphérique 	est débranche on peut reprendre une opération en cours par ex

    UNIONFS : pour un mix de solutions diverses (squashfs, ubifs, tmpfs, . . . )
    Systèmes de fichiers spécifiques mémoire flash : jffs2, ubifs, cramfs, yaffs2, ...

        Flash : noatime + sync mount options

    Contenu ?

    arborescence ?
    init : mandatory !
    libs ?
    binaires ?
    config ?
    device nodes ?

Busybox

La plupart des commandes UNIX regroupées en un unique exécutable

    Taille pouvant être facilement inférieure à 1 Mo
    Système complet en moins de 4 Mo
    Menu de configuration (interface de configuration similaire à celle du noyau)
    Peu de besoins externes
    Quelques limites cependant ...
    Copie de busybox (exécutable et liens)

    rsync -a install/ dev_busybox/
    Création des fichiers spéciaux et de la configuration
    Copie des bibliothèques (lesquelles, ldd ? qemu ?)

Création d'un système autonome

    Choix du système d'init
    Suppression de la console ? (mémoire, sécurité, debug ?)
    Connexion à distance ? (telnet, SSH)
    Démarrage automatique (inittab, démon, remplacement de init)
    Démarrage sur évènements
    utilisation de cron (ou équivalent)

Mise en flash et démarrage

    Bootloader ?

    Configuration :

        Chargement des images
        Ligne de commande du noyau (root=? console=? ...)

    Mise en flash des images

    Boot sur Flash ou SD/uSD/USB

    Limiter les accès en écriture (option noatime)

    Boot sur NFS

> boote sur un fichier racine distant (poste de dev sur lequl on peut faire des modifs)

    Activer NFS dans le noyau
    Activer la configuration IP automatique
    Configuration sur l'hôte
    Développement simplifié
    Limitations ?

    Pivotroot

Outils et debug

    Chaîne de cross-compilation
    IDE ?
    Frameworks ... (Scratchbox, OpenEmbeded et dérivés)
    Outils indispensables :

    Terminal série
    Serveur DHCP (protocole BOOTP)
    Serveur TFTP
    Serveur NFS ?

    Debug ?

    GDB et GDB Server : démarrage du serveur gdb sur la cible, utilisation de gdb depuis l’hôte.
    Utilisation de gdb de façon native, sur la cible.
    Utilisation de sondes JTAG
    Linux Trace Toolkit
    Emulateurs :

        Qemu - Fabrice Bellard - x86, x86 64, ppc, arm, sparc, mips, m68k
        SkyEye : ARM

Interfaces graphiques

Un choix très vaste

    Qt (QtEmbedded)
    GTK+
    Nano-X / Microwindows
    MiniGUI
    FLTK
    SDL
    DirectFB
    ...
