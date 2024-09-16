# Technická dokumentace

## Úvod

Na této stránce uploadován zápočtový program - piškvroky vytvořený k předmětu Programování 3 na MFF UK v ročníku 2023/24. Autor programu je Tadeáš Janků.

## Soubory a grafika

Celý kód je rozdělen do několika souborů (rozebrány níže), které se postupně importují do hlavního souboru game.cpp. Grafiku zajišťuje Win32 API pro tvorbu a práci s okny.

## Game.cpp

V této části kódu, ve které běží celý program dochází ke spuštění funkce winmain a importování důležitých souborů, se kterými jinak program pracuje.

## Window.h

Zde je definována třída window, ve které porbíhá obsluha celé grafické části programu a současně krokování jednotlivých akcí.

Celkově se v okně postupně využívá sedm tlačítek a sedm sliderů na obsluhu hry, dále sev okně objevují labely pro popisky a zobrazování vybraných hodnot. Důležitou součástí je ještě funkce DrawTable, která vykresluje aktuální stav hrací plochy. 

K postupnému hraní je nejvíce využívána hlavně trojice funkcí hraje_krizek, hraje_krouzek a dohrano.

## Board.h

V této části se nachází nejdůležitější třída celého programu hraci_plocha, ve které jsou udržovány údaje o polohách tvarů, rozměry, kdo je zrovna na tahu, zda někdo vyhrál, jakou úroveň má bot (a jestli bůbec nějaký je). Třída obsahuje metody na založení nové prázdné plochy, vypsaní plochy (nevyužívá se, jedná se o funkci pro případné použití v konzoli), dále pak pomocne metody nekdo_vyhral() a nove_policko().

Hlavní část tvoří funkce tah_bota(), která v případě hry s počítačem řeší tah bota v závislosti na jeho úrovni. Nejjednoduší bot táhne čistě náhodně. Další dva boti hledají potenciálně dobré tahy, ze kterých po té vybírají který zahrajou. Opět je zde daná nějaká míra náhody, kdy platí, že čím lepší tah, tím větší šanci má na to být zahrán (rozdíly v pravděpodobnosti mohou být až o několi řádů).

# Pole.h

Obsahuje třídu Policko, která uchovává informace u o jednotlivých polích. Je využíváno v rámci třídy board.

## Pboard.h

Funkce na vytvoření takzvané „pseudoplochy“, která je využívaná v tazích bota k hodnocení jednotlivých tahů.

## CheckW.h and WCheck.h

Funkce, které prochází po zadání nového políčka hrací plochu a kontrolují zda hráč nepoložil dostatečný počet symbolů vedle sebe. Používá se též pro hledání tahu pro boty.

## Tech.h

Několik jednoduších funkcí technického rázu, které zjednodušují fungování programu.

## TechWindow.h

Obdobně jako přechozí část, akorát funkce zjednodušují fungování okna.

## Const.h

Vypsání několika důležitých konstant, se kterými se v kódu pracuje.
