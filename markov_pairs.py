# written by john gauthier

import random

words = open('text_files/dream_speech.txt').read().split()


##### make 2d word frequency dict
l = len(words)
p = {}

for i in range(l-2):
	pair = (words[i], words[i+1])
	suffix = words[i+2]
	if pair not in p:
		p[pair] = {suffix: 1}
	elif suffix not in p[pair]:
		p[pair][suffix] = 1
	else:
		p[pair][suffix] += 1


##### Generate chain
pair = random.choice(list(p.keys()))
num_words = 40
markov_chain = pair[0] + " " + pair[1] + " "

population = list(p[pair].keys())
weights = list(p[pair].values())

for i in range(num_words):
	x = pair[0]
	y = pair[1]
	z = random.choices(population, weights=weights)[0]
	markov_chain += z + " "
	pair = (y, z)
	population = list(p[pair].keys())
	weights = list(p[pair].values())

print(markov_chain)