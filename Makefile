build:
	@g++ -o fact FactReader.cpp

run:
	@./fact
	@swipl facts.pl

clean:
	@rm -f fact facts.pl