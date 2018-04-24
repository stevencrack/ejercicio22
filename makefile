gauss.png : datosgauss.txt gauss.py
	python gauss.py

datosgauss.txt : gauss
	./gauss > datosgauss.txt

advec_nolineal.x : ejercicio22.cpp
c++ ejercicio22.cpp -o gauss
