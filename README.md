









# Controlando motores com o rádio FlySky utilizando Arduino UNO ou o MH-ET LIVE Attiny88 

Desenvolvimento:
_____________________________________________________________________________

Este projeto consiste na utilização da interface programável **MH-ET LIVE Attiny88** ou **Arduino UNO**, para construir um circuito capaz de controlar dois motores, que será utilizado em um hover esteirado.

_____________________________________________________________________________

A seguir o desenho de como fica o circuito na prática:

![Desenho do Circuito](https://github.com/eversonvansoski/FlySky-Arduino---Motor-speed-and-direction-controller/blob/master/circuito-esquema.png)



O esquema acima está representado com a utilização do Arduino, mas o código e o circuito servem também para o MH-ET LIVE Attiny88.

Abaixo estão os componentes utilizados no projeto:

* Rádio FlySky FS-i6 + Receptor
* Arduino UNO ou MH-ET LIVE Attiny88
* Ponte H L298N
* Motores DC com redução e tensão entre 3v e 10v
* Fios, jumpers, baterias, fontes, protoboard e demais itens que podem variar de acordo com a montagem



![Componentes Principais](https://raw.githubusercontent.com/eversonvansoski/FlySky-Arduino---Motor-speed-and-direction-controller/master/componentes_principais.png)

A seguir o circuito montado:

> [!WARNING]
> OBS: As portas (pins) foram alteradas, apenas para um melhor encaixe dos componentes. 

![Circuito Montado](https://raw.githubusercontent.com/eversonvansoski/FlySky-Arduino---Motor-speed-and-direction-controller/master/circuito.png)



