word = input('Enter a word to find: ')

with open('../test.txt', 'r') as file:
	counter = 1
	for line in file:
		if word in line:
			print(counter)
		counter += 1