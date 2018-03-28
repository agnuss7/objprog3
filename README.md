## V1.0 laiko skaičiavimas

# Trukmių lentelės
laikas skaiciuojamas milisekundėmis.
Mano skaičiavimo būdas buvo sumest visus "blogus" studentus į konteinerio galą.
Su list'u neišėjo, nes reikia konteinerio elementus pasiekinėti atsitiktinai.
Tai labai neefektyvu.

Kiekvieno main'o kažkur pradžioj yra konstanta žyminti studentų skaičių faile. Jį pakeist keičiant pateikiamą failą (1.txt, 2.txt...).

## Vektoriai

| Generuotų studentų skaičius faile | mano | 2 konteineriai | 3 konteineriai
|------------ | ------------- |-------------|--------
|10 | 15| 15 | 15
|100 | 93| 124 | 109
|1000 | 1297 | 656 | 578
|10000 | 74235 | 6188 | 6203
|100000 | per ilgai skaičiavo| 40053 | 38178

## Deque

| Generuotų studentų skaičius faile | mano | 2 konteineriai | 3 konteineriai
|------------ | ------------- |-------------|--------
|10 | 15| 15 | 15
|100 | 78| 125 | 93
|1000 | 1359 | 671 | 627
|10000 | 80537 | 6437 | 6469
|100000 | per ilgai skaičiavo| 40457 | 40379

## List

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 15 | 15
|100 | 93|  124
|1000 | 671 |  640
|10000 | 6766 |  7543
|100000 | 171036 | 411019


