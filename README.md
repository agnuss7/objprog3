## V0.1

Objektinio programavimo pradmenys. Perdaryta 2-os užduoties paskutinė versija, tik su klasėm.

# Trukmių lentelės
laikas skaiciuojamas milisekundėmis.


## Vektoriai (2 užduotis, procedūrinis)

| Generuotų studentų skaičius faile | mano | 2 konteineriai | 3 konteineriai
|------------ | ------------- |-------------|--------
|10 | 15| 15 | 15
|100 | 93| 124 | 109
|1000 | 1297 | 656 | 578
|10000 | 74235 | 6188 | 6203
|100000 | per ilgai skaičiavo| 40053 | 38178

## Vektoriai (3 užduotis, OOP)

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 2 | 3
|100 | 93| 146
|1000 | 753 |  1328
|10000 | 11797 |  7648
|100000 | 631283 | 70333

## Deque (2 užduotis, procedūrinis)

| Generuotų studentų skaičius faile | mano | 2 konteineriai | 3 konteineriai
|------------ | ------------- |-------------|--------
|10 | 15| 15 | 15
|100 | 78| 125 | 93
|1000 | 1359 | 671 | 627
|10000 | 80537 | 6437 | 6469
|100000 | per ilgai skaičiavo| 40457 | 40379

## Deque (3 užduotis, OOP)

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 15 | 15
|100 | 62|  125
|1000 | 756 |  721
|10000 | 13815 | 11039
|100000 | 171360 | 56342

## List (2 užduotis, procedūrinis)

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 15 | 15
|100 | 93|  124
|1000 | 671 |  640
|10000 | 6766 |  7543
|100000 | 171036 | 411019

## List (3 užduotis, OOP)

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 15 | 15
|100 | 125| 62
|1000 | 1296 | 750
|10000 | 7596 | 7758
|100000 | 158106 | 317164

Užtrunka ilgiau, bet daug patogiau.
Kad pagreitinti viską, pabandykim optimizuoti kompiliatorių.

# -01 flag'ai

## Vektoriai

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 15 | 15
|100 | 93| 125
|1000 | 750 | 750
|10000 | 8205 | 9443
|100000 | 234539 | 48034

## Deque

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 17 | 15
|100 | 125|  109
|1000 | 750 |  1236
|10000 | 9425 | 7431
|100000 | 101444 | 82695

## List

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 15 | 15
|100 | 132| 93
|1000 | 703 | 734
|10000 | 11286 | 7431
|100000 | 134205 | 299489

# -02 flag'ai

## Vektoriai

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 15 | 16
|100 | 140| 62
|1000 | 718 |  755
|10000 | 8877 | 10758
|100000 | 281798 | 92640

## Deque

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 17 | 15
|100 | 109|  62
|1000 | 1281 |  703
|10000 | 9617 | 10277
|100000 | 126270 | 48243

## List

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 1 | 1
|100 | 62| 62
|1000 | 724 | 687
|10000 | 7205 | 7478
|100000 | 97506 | 266916

# -03 flag'ai

## Vektoriai

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 15 | 17
|100 | 62| 78
|1000 | 734 |  734
|10000 | 8288 |  7067
|100000 | 234074 | 48513

## Deque

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 15 | 15
|100 | 78| 62
|1000 | 718 | 687
|10000 | 7336 | 6691
|100000 | 76113 | 47100

## List

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 15 | 15
|100 | 62| 62
|1000 | 736 | 718
|10000 | 7020 | 7445
|100000 | 95234 | 265041

Nematau aiškių pagreitinimų, kartais net užtrukdavo ilgiau. Tik list'o veikimo greitis visada trumpėdavo.

## V0.2

Operatorių realizacija ir Doxygen dokumentacija. Taip pat patobulinau skirstimą į gerus/blogus studentus.

# Operatoriai

Vienintelis operatorius, kuris šiuo atveju buvo naudingas buvo "<<" spausdinant tam tikrą info apie studentą (print metodas vis dar liko ir spausdina kitokią info).

# Doxygen

Prirašinėjau komentarų, kurie bus matomi Doxygen dokumentacijoj.

# std::partition

whoa, kartais daugiau nei per pusę sumažina laiko sąnaudas.

## V1.0

Unit testai. Bandžiau Catch.

I concede defeat. Cmake failų neišėjo padaryt. Atsižvelkit...

# Vartojimo instrukcija

main.cpp paleiskit su kažkokiu IDE. Headeriai turi būti tam pačiam foldery. 
Jums iškris "meniu" su pasirinkimais, kokią operaciją atlikti. Kitos instrukcijos bus pateiktos tenai.