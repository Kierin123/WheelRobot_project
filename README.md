# ZUT_wheel_robot

Wheel robot based on Raspberry Pi providing travelling along the pre seattled truck. Robot consists 2 wheels drived by DC motors and coupled with encoders. The control panel for the robot is provided by desktop application designed in QT framework. 

Project agenda: 

1. Build the robot 
    - Robot constructed with dedicated parts. 
        Romi Chassis Kit - https://botland.com.pl/podwozia-robotow/7347-romi-chassis-kit-2-kolowe-podwozie-robota-czerwone-pololu-3502-5904422310196.html

        Romi Pololu 3541, power distribution board - https://botland.com.pl/podwozia-robotow/7349-romi-modul-zasilania-do-podwozia-romi-chassis-pololu-3541-5904422310219.html

        Romi Pololu 3542 encoder boards - https://botland.com.pl/podwozia-robotow/7350-romi-zestaw-enkoderow-magnetycznych-do-podwozia-romi-chassis-2szt-pololu-3542.html

        Raspberry pi Zero - https://kamami.pl/raspberry-pi-zero-2/587851-raspberry-pi-zero-2-w-z-512mb-ram-4x1ghz-wifi-bluetooth.html?search_query=r+pi+zero&results=164

        MaX14870 - https://botland.com.pl/raspberry-pi-hat-kontrolery-silnikow-i-serw/11844-max14870-dwukanalowy-sterownik-silnikow-28v17a-rozszerzenie-dla-raspberry-pi-4332b-zmontowany-pololu-3759-5904422318086.html

        GPIO Expander - https://kamami.pl/prototypowanie-raspberry-pi/574628-ekspander-portow-gpio-dla-raspberry-pi.html

2. Develope the application controlled the robot
    - Develope the motor controlle layer by use the WiringPi.h - http://wiringpi.com/
    - Develope the communication layer between socket and motro controller. 
    - Develope TCP/IP socket function by use the POSIX library. - https://www.man7.org/linux/man-pages/man2/socket.2.html#NAME

3. Develoep the desktop application for robot control. 