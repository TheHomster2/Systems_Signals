ahsignals: ahsignals.c
	gcc ahsignals.c -o ahsignals

run: ahsignals
		./ahsignals

clean: rm *~