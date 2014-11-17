#!/bin/bash

./db destroy
./db create
./db set 1 gaurav gmail@gauravchande.com
./db set 2 g2 g2@gaurav.com
./db set 5 g3 g3@gaurav.com
./db set 25 g4 g4@gaurav.com
./db set 50 reallyreallyreallyreallyreallyreallyreallyreallyreallylongname g5@gaurav.com
./db list
./db get 2
./db del 5
./db get 5
./db destroy
