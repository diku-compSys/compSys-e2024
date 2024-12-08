# Øvelser til 9. december

## Opsamling

Overskydende øvelser fra forrige uge.


## Opgave 1

Opstil et diagram for afvikling af to iterationer af følgende programstump på en simpel 5-trins pipeline som beskrevet i COD:

~~~
Loop:
    addi x4,x4,1
    slli x11,x4,5
    add  x11,x16,x11
    lw	 x11,8(x11)
    slli x12,x4,2
    add	 x12,x17,x12
    sw   x11,0(x12)
    bge  x9,x4,Loop
~~~

Placer instruktionerne nedad og aktiviteten i pipelinen til højre for hver instruktion, således
at placering angiver tidspunktet (clock periode) for aktiviteten. Se følgende koder for de
enkelte aktiviteter:

~~~
  FE = fetch, instruktions hentning
  DE = decode, afkodning, læsning af registre
  EX = execute
  ME = memory, tilgang til data lageret
  WR = skriv resultat til registre
~~~


## Opgave 2

Opstil et tilsvarende diagram for udførelse af koden på en 5-trins 2-vejs superskalar pipeline.

Brug de samme forkortelser.

Hvis der er tvivlspørgsmål undervejs vælges en mulig fortolkning - gå ikke i stå.
Anfør eventuelle antagelser om mikroarkitekturen.

## Opgave 3

Opstil et diagram der illustrerer udførelsen af samme program (opfattet som en række dataflow operationer)
på en dataflow maskine svarende til beskrivelsen i dagens slides (den hvor STORE instruktioner splittes i to, en til adresse og
en til data håndtering)

## Overskydende tid:

Brug tid til at afklare spørgsmål vedrørende A5.

