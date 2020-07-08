# Rear Parking Sensor em C/C++ 
Este projeto consiste no desenvolvimento de um sensor de ré (rear parking sensor) utilizando a linguagem C/C++ e o sistema embarcado Arduino Uno (Rev 3) junto com alguns componentes eletrônicos.

## Componentes Eletrônicos Utilizados
 - Arduino Uno (Rev 3)
 - HC-SR04
 - Buzzer +5V DC

## Ferramentas de Programação
- Arduino IDE 1.8.13
- C/C++

## Funcionamento
O dispositivo foi projetado para possuir 3 fases de detecção de distância (em **centímetros**), calculando essa distância utilizando a velocidade do som e a equação básica do Movimento Uniforme (MU) como representado na figura abaixo:

![equation](https://snipboard.io/3cFjbu.jpg?style=centerme "Equacionamento da onda sonora e captação do sensor")

As oscilações do acionamento do Buzzer ocorrem nas seguintes configurações de distância:
- Fora de Alcance (Distância > 18cm) - Sem Som
- Distância Segura (10cm <= Distância <= 18cm) - Intermitência de 200ms
- Distância Próxima (4cm <= Distância < 10cm) - Intermitência de 80ms
- Distância Muito Próxima (Distância < 4 cm) - Som contínuo 

## Esquemático

![esquematico](https://i.imgur.com/InSFuls.png "Esquemático de Implementação do Circuito")
O esquemático acima foi produzido no Fritzing e seguem as seguintes configurações de pinos:

#### HC-SR04
Pinos do Sensor:
- Trigger - Digital Pin 7
- Echo - Digital Pin 4
- VCC - 5V Output
- GND - GND Pin
#### Buzzer
- VCC - Digital (PWM) Pin 3 (O PWM foi usado para testar a variação de frequência com pulso modulado)
- GND - GND Pin

## Video - Funcionamento

<div align="center">
	<a  href="https://youtu.be/bdTQDP5m7C0" target="_blank"><img src="https://yt-embed.herokuapp.com/embed?v=bdTQDP5m7C0" 
alt="Functioning Video" width="720" height="480" border="10" /></a>
</div>
