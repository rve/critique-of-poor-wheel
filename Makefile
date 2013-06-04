.PHONY : clean count
count:
	find . -name '*' | xargs wc -l
count_cpp:
	find . -name '*.[h|c|cpp|cc]' | xargs wc -l
clean:
	find . -perm +100 -type f -delete
	-rm -r ./*.in 
	

