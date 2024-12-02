# Simulatoropgaven (A5, CompSys 2023)

Finn Schiermer Andersen, november-december 2023

Denne opgave stilles mandag den 2. december og skal afleveres kl 16 søndag den 15. december.



## Opgave

Der skal implementeres en disassembler og simulator for RISC-V, 32-bit base instruktionssæt og udvidelsen
for 32-bit multiplikation/division. Dog skal enkelte specielle instruktioner ikke indgå.
Derudover skal simulatoren håndtere nogle få systemkald. Detaljer gives nedenfor. 
Disassembleren og Simulatoren skal skrives i C. De skal skrives som *et* program, hvor en
kommandolinie option vælger mellem disassembly og simulation.

Til hjælp udleveres en ufærdig disassembler/simulator som skal færdiggøres. Den udleverede kode tager
hånd om simulation af lager og indlæsning af et program til dette lager. For at færdiggøre simulatoren 
skal I tilføje filen simulate.c og der implementere funktionen "simulate()", som allerede er 
erklæret i "simulate.h". Endvidere skal I tilføjen filen "disassemble.c" og der implementere
funktionen "disassemble()", som allerede er erklæret i "disassemble.h"

Der er tidligere udleveret nogle programmer (find dem i "resources/tiny_riscv" i kursets
offentlige repo). De fire af dem ("hello.c", "echo.c", "fib.c" og "erat.c") skal kunne 
disassembles og afvikles på den færdige simulator. Disse programmer er
skrevet i C og du kan bruge krydscompileren introduceret i forelæsningen 20/11 (se slides
i "lectures/24-11-20_tiny_riscv_setup/slides.pdf"), til at oversætte dem til et ELF-formatet
som den færdige disassembler/simulator kan læse.

Der skal opstilles og gennemføres en afprøvning af alle instruktionerne.


Besvarelsen skal indeholde:

* En kort rapport. Her bør I kort beskrive:
  * Jeres overordnede design/tilgang
  * Hvordan I afkoder instruktionerne (herunder genererer den korrekte "immediate" hvis relevant)
  * Hvordan I har afprøvet og hvad jeres afprøvning viser.
  * Hvis der er noget i ikke lykkedes med at implementere, hvorfor tror i så det var?
* Implementationen af disassembly-funktionen
* Implementationen af simulerings-funktionen
* Dokumentation for afprøvningen. For hver instruktion bør i anføre:
  * Hvad i afprøver
  * Hvordan i konkret afprøver det i form af et minimalt assembler program
* Dokumentation for at de nævnte 4 C programmer kan disassembles og afvikles af simulatoren

Hvis de udleverede programmer ikke kan disassembles eller bringes til at køre på simulatoren, skal det klart
fremgå af besvarelsen. Afprøvningen skal gøre et systematisk forsøg på at klarlægge hvilke
instruktioner der håndteres korrekt, og hvilke der ikke håndteres korrekt på afleveringstidspunktet.


## Udleverede filer

Der udleveres følgende filer som udgør den ufærdige simulator:

~~~
main.c: - hovedprogram
memory.c, memory.h: - simulering af computerens lager
read_elf.c, read_elf.h: - indlæsning af riscv .riscv fil
simulate.h: - header fil der erklærer funktionen simulate() som skal implementeres
disassemble.h: - header fil der erklærer funktionen disassemble() som skal implementeres
~~~

## Instruktioner
 
Den autoritative reference (herefter kaldet "riscv spec") for instruktionernes indkodning er her:

~~~
https://github.com/riscv/riscv-isa-manual/releases/download/20240411/unpriv-isa-asciidoc.pdf

~~~

Bemærk især beskrivelsen af indkodning af instruktioner og indlejrede konstanter (immediate),
som er i afsnit 2.2.

Simulatoren skal håndtere RISC-V 32 bit base instruktionssæt (RV32I) og udvidelsen
for 32 bit multiplikation (RV32M). Instruktionerne i base instruktionssættet er alle 
nævnt på "det grønne ark" som indgår i COD. Arket nævner også RV64M udvidelsen
(64 bit multiplikation), men det er altså 32-bit udvidelsen som skal 
implementeres. Denne udvidelse ligner meget men er ikke identisk. Find den beskrevet
i riscv spec.

Detaljer om hver instruktion findes i riscv spec.

Dog skal følgende instruktioner fra det grønne ark/RV32I IKKE implementeres: 

~~~
ebreak, fence, fence.i, CSRRW, CSRRS, CSRRC, CSRRWI, CSRRSI og CSRRCI.
~~~


## Systemkald

Systemkald udføres med "ecall" instruktionen. Værdien i A7 angiver hvilket systemkald der
er tale om. Der skal implementeres følgende fire systemkald.

~~~
Kald:           Effekt:
1               returner "getchar()" i A0
2               udfør "putchar(c)", hvor c tages fra A0
3 og 93         afslut simulationen
~~~

## Simulation

Den udleverede (ufærdige) disassembler/simulator tager en ELF (extension: ".riscv") fil som første argument.
Som andet argument kan angives logning. Eventuelle argumenter til det simulerede
program kan gives efter "--" som illustreret nedenfor

~~~
./sim myprog.riscv -d                # disassembler ELF fil til standard output
./sim myprog.riscv                   # simulering og ingen logning
./sim myprog.riscv -l log            # simulering for hver eneste instruktion
./sim myprog.riscv -s log            # simulering og derpå logning af afsluttende opsamling (antal instruktioner, simulationstid)
./sim fib.riscv -l log -- 5          # simuler fib.riscv med input 5, log udførelsen til "log"
~~~

Det er også muligt at overføre argumenter til main() via argc/argv i det simulerede
C program. Det gøres ved at placere argumenterne efter "--", f.eks.:

~~~
./sim fib.riscv -- 7                  # fib(7), ingen logning
./sim fib.riscv -l log -- 7           # fib(7), logning for indlæsning af dis-fil og for hver eneste instruktion
./sim fib.riscv -s log -- 7           # fib(7), logning af afsluttende opsamling (antal instruktioner, simulationstid)
~~~

Argumenterne SKAL angives i rækkefølgen brugt ovenfor.

Den udleverede kode forventer at det simulerede program erklærer symbolet "_start" og vil
starte simulationen ved addressen på dette symbol. Programmer lavet som beskrevet
nedenfor vil automatisk opfylde dette krav.

## Output format

Som minimum skal for hver instruktion udskrives:

Ved disassemblering og ved logning under simulation:

 - Instruktionens adresse.
 - Instruktionen som tal i hexadecimal notation
 - Disassemblering af instruktionen (dvs symbolsk assembler for instruktionen)
 - For hop og kald skal den indlejrede konstant vises som absolut adresse.

Ved logning under simulation skal tillige for hver instruktion udskrives:

 - Instruktionens nummer siden start af simulationen
 - For betingede hop: om hoppet tages eller ej
 - For instruktioner der skriver til et register: register nummer og registerets nye indhold
 - For instruktioner der skriver til lageret: lager adresse og nyt indhold

Til inspiration er her et eksempel på muligt output format fra logning af simulation:

~~~
   144 =>  10098 : 00044503     lbu      a0,0(s0)                R[10] <- 6e
   145     1009c : fe051ae3     bnez     a0,10090            {T}
   146 =>  10090 : 00140413     addi     s0,s0,1                 R[ 8] <- 119a2
   147     10094 : 4d8000ef     jal      ra,1056c                R[ 1] <- 10098
   148 =>  1056c : 00200893     li       a7,2                    R[17] <- 2
   149     10570 : 00a00833     add      a6,zero,a0              R[16] <- 6e
~~~

Symbolet "=>" indikerer at der er hoppet til denne instruktion.
Symbolet "{T}" indikerer et taget betinget hop.
Resten skulle gerne være selvforklarende.


## Fra "C" til ".riscv" filer

Vi bruger en krydsoversætter til at frembringe ".riscv" filer fra 'C' eller fra
håndskrevet riscv assembler. 

Installation og brug af krydsoversætteren er beskrevet i slides fra forelæsningen 20/11
og de tilhørende øvelser. 

### Fra riscv assembler til .riscv fil

Dette gøres ved at bruge krydsoversætteren. Selvom den primært er en C compiler vil den
gladeligt medtage ".s" filer som input. Sådanne .s filer kan man skrive i en almindelig
tekst editor.

Til brug ved afprøvning kan det betale sig at lave små riscv assembler filer der hver tester
en enkelt eller ganske få instruktioner. I dette scenarie skal det minimale bibliotek (lib.c)
ikke indgå i oversættelsen. Makefilen kan håndtere dette.

Simulatoren forventer at symbolet "_start" er erklæret og vil starte simulation ved 
første instruktion efter "_start".

Her er et meget lille assembler program der illustrerer det:

~~~
        .globl _start
_start:
	ori	a7,x0,3
	ecall
~~~

Det eneste dette lille program gør er at stoppe simulationen (se tidligere afsnit om systemkald).

