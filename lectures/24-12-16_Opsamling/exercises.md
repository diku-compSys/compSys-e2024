# Øvelser til 16. december

1. Øvelser fra sidste uge som ikke blev løst, eller hvor der er stor usikkerhed om deres løsning.

2. Brug tid på at sikre forståelse af A6


## Opgave 1

Spg 1:

Oversæt dette C-fragment til RISC-V assembler

~~~
while (a < limit) { *a++ = *b++; }
~~~ 

hvor de tre variable a,b og limit alle er af typen pointer to int.


Spg 2:

Konstruer et afviklingsplot der viser afvikling af
to iterationer af løkken i dit program på en simpel 
5-trins pipeline med fuld forwarding.

Spg 3:

Konstruer et afviklingsplot der viser afvikling af to iterationer af
løkken i dit program på en 2-vejs superskalar in-order maskine med
realistisk cache tilgang.

Gør eventuelt antagelser om branch prediction

Spg 4:

Konstruer er afviklingsplot der viser afvikling af to iterationer
af løkken i dit program på en out-of-order maskine som
beskrevet i slides for onsdag 11/12.

Se specifikt slide 28 fra onsdag 11/12 for oversigt over forkortelser til brug
i afviklingsplot for out-of-order maskiner

Husk at angive antagelser du må gøre for at præcisere opgaven.

