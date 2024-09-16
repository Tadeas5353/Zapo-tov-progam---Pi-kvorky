# Uživatelská příručka

## Úvod

Piškvorky jsou jednoduchá desková hra dva hráče, kteří se postupně střídají v pokládání symbolů (kroužky a křížky) na hrací desku. Zvítězí hráč, kterému se podaří spojit (předem určený) počet znaků buďto ve sloupci, řadě nebo diagonále.

## Úvodní menu

Po spuštění hry hráč uvidí možnost hrát buďto s kamarádem, který sedí vedle něj nebo s počítačem. Pokračovat může zvolením jedné nebo druhé možnosti.

Po té, co si vybere s kým chce hrát, tak může nastavit rozměry hrací plochy (od 3×3 po 26×10) a počet políček potřebných k vítězství, který může být od tří do pěti. V příapdě, že zvolil hru s počítačem, tak ještě nastaví úroveň bota a kdo bude začínat.

Pokud chce hráč hrát s počítačem, tak má na výběr tři boty. První je bot simulujíhráče, který přišel k hrací ploše po mohutné oslavě v baru a pod vlivem alkoholu už v postatě nevnímá, co dělá. Tomu odpovídají i jeho tahy. Druhý bot simuluje hráče, který je plně při smyslech, nicméně s hrou samotnou má minimální zkušenosti. Třetí a nejsilnější bot funguje jako hráč, který už má nějaké partie za sebou.

## Hra

Po zvolení parametrů se uprostřed obrazovky vykrelsí hrací plocha a v ní se ukazují pole zabraná jednotlivými symboly. Jako první začínají vždy kroužky. Hráč, který je na tahu má v dolní části obrazovky možnost nastavit souřadnice políčka, na které chce umístit svůj symbol. Po té co si svou volbu důkladně promyslí ji ještě musí potvrdit tlačítkem vlevo dole.

## Boti

Jak bylo řečeno, ve hře jsou tři boti. První z nich, „opilec“ hraje své tahy čistě náhodně. Boti „začátečník“ a „opilec“ pak fungují oba dva na stejném principu. Procházejí hrací plochu a zjišťují si výhodnost jednotlivých políček. Berou při tom v potaz počet obsazených sousedních políček, možnost vytvořit dvojice, trojice či čtveice stejných symbolů v jedné řadě nebo naopak zabránit v tomhle soupeři. Ani jeden bot nehledá jedno optimální políčko, nicméně políčkům nastavuje pravděpodobnost, se kterou se zahrají (lepší políčka můžou mít až desetitisíckrát větší pravděpodobnost na zahrání než horší). Jedinou výjimkou je, pokud pokročilý bot vidí možnost sestrojit řadu o požadovaném počtu znaků nebo naopak soupeři zabránit v sestrojení této řady. Boti se od sebe liší pravděpodobnostími hodnotami (začátečník spíše vybere horší políčko než pokročilý bot) a mírou podrobnosti zkoumání jednotlivých políček (políčko, které pokročilý bot vybere jako nějak zajímavé může bot začátečník vyhodnotit jako zbytečné).
Během hry se také zvýrazňuje poslední zahraný symbol. Toto slouží k většímu přehledu o hře.

## Konec hry

V případě, že se jednomu hráči podaří spojit požadovaný počet symbolů, hra končí a daný hráč vyhrává. V případě, žese symboly zaplní celá hrací plocha, tak hra končí remízou.
