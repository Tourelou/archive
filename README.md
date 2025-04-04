# archive

I needed a software, not complicated, to do the collection of files that I kept in archive.

Every 4 gigabytes, I would burn a DVD and then a Blu-Ray. But you can imagine the amount of files that it represents ...

The project to create this small software had just been born.

### How does it work?

Very simply, once we are convinced that we have enough files to make a backup on DVD, Blu-Ray or a NAS, we launch this little program as follows:

```bash

archive -s < volume to be scanned >

```

`archive` will collect all files in this tree and create a file from it. txt on behalf of this volume that it will deposit in your folder: ‘$HOME/Documents/Archives/Volumes/`

This directory does not exist, no problem `archive` will create it automatically.

And here, no more complicated than that.

### find: more...

Now that we have scanned our entire collection, we are able to query the program, namely: On what volume is this or that file. To do this:

```bash

archive -f < regex pattern to be found >

```

In the following example, I am searching for Davinci Resolve. Here is the result:

```bash
archive -f resolve

--------------------------------------------------------------------
The pattern "resolve" in/.../..../Documents/Archives/Volumes/*. txt
--------------------------------------------------------------------
2019-10-06.txt <=== . /Images/DaVinci Resolve/DaVinci_Resolve_11.3.1.zip
2019-10-06.txt <=== . /Images/DaVinci Resolve/DaVinci_Resolve_11_Manual_2015-03-24.pdf
2019-10-06.txt <=== . /Images/DaVinci Resolve/DaVinci_Resolve_12.5.1.zip
2019-10-06.txt <=== . /Images/DaVinci Resolve/DaVinci_Resolve_14.3.zip
--------------------------------------------------------------------
2023-07-21.txt <=== . /Images/DaVinci_Resolve_18.1.4.dmg
--------------------------------------------------------------------
2023-10-02.txt <=== . /Images/DaVinci_Resolve_18.5.dmg
2023-10-02.txt <=== . /Images/DaVinci_Resolve_18.6.dmg
--------------------------------------------------------------------
2023-12-01.txt <=== . /Images/DaVinci_Resolve_18.6.1.dmg
2023-12-01.txt <=== . /Images/DaVinci_Resolve_18.6.2.dmg
2023-12-01.txt <=== . /Images/DaVinci_Resolve_18.6.3.zip
--------------------------------------------------------------------
2024-07-05.txt <=== . /Images/DaVinci_Resolve_18.6.6.zip
--------------------------------------------------------------------
2025-03-01.txt <=== . /Images/DaVinci_Resolve_19.1.3.zip
--------------------------------------------------------------------
```

There you go, simple and efficient.

So if a particular version of DaVinci Resolve crashes repeatedly on my system, I can re-install a previous version.


# archive

J'avais besoin d'un logiciel, pas compliqué, pour faire la collecte de fichiers que je gardais en archive.

À chaque 4 Giga octets, je me gravais un DVD, puis par la suite, un Blu-ray. Mais vous imaginez la quantité de fichiers que ça représente ...

Le projet de créer ce petit logiciel venait de voir le jour.

### Comment ça marche ?

Très simplement, une fois convaincu que nous avons assez de fichiers pour faire une sauvegarde sur DVD, Blu-Ray ou un NAS, on lance ce petit programme comme suit:

```bash

archive -s < volume à scanner >

```

`archive` va rammasser tout les fichiers de cette arborescence et en créer un fichier .txt au nom de ce volume qu'il déposera dans votre dossier: `$HOME/Documents/Archives/Volumes/`.

Ce répertoire n'existe pas, pas de problème `archive` va le créer automatiquement.

Et voilà, pas plus compliqué que ça.

### find: la suite ...

Maintenant que nous avons scanner toute notre collection, nous sommes en mesure d'interroger le programme, à savoir: Sur quelle volume se trouve tel ou tel fichier. Pour ce faire:

```bash

archive -f < motif regex à trouver >

```

Dans l'exemple qui suit, je fais une recherche pour Davinci Resolve. Voici le résultat:

```bash
archive -f resolve

--------------------------------------------------------------------
Le motif «resolve» dans /.../..../Documents/Archives/Volumes/*.txt
--------------------------------------------------------------------
2019-10-06.txt <=== ./Images/DaVinci Resolve/DaVinci_Resolve_11.3.1.zip
2019-10-06.txt <=== ./Images/DaVinci Resolve/DaVinci_Resolve_11_Manual_2015-03-24.pdf
2019-10-06.txt <=== ./Images/DaVinci Resolve/DaVinci_Resolve_12.5.1.zip
2019-10-06.txt <=== ./Images/DaVinci Resolve/DaVinci_Resolve_14.3.zip
--------------------------------------------------------------------
2023-07-21.txt <=== ./Images/DaVinci_Resolve_18.1.4.dmg
--------------------------------------------------------------------
2023-10-02.txt <=== ./Images/DaVinci_Resolve_18.5.dmg
2023-10-02.txt <=== ./Images/DaVinci_Resolve_18.6.dmg
--------------------------------------------------------------------
2023-12-01.txt <=== ./Images/DaVinci_Resolve_18.6.1.dmg
2023-12-01.txt <=== ./Images/DaVinci_Resolve_18.6.2.dmg
2023-12-01.txt <=== ./Images/DaVinci_Resolve_18.6.3.zip
--------------------------------------------------------------------
2024-07-05.txt <=== ./Images/DaVinci_Resolve_18.6.6.zip
--------------------------------------------------------------------
2025-03-01.txt <=== ./Images/DaVinci_Resolve_19.1.3.zip
--------------------------------------------------------------------
```

Et voilà, Simple et efficasse.

Ainsi, si une version en particulier de DaVinci Resolve crash à répétition sur mon système, je peux ré-installer une version précédante.
