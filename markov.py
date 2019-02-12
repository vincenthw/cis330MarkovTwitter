# written by john gauthier

import random

words = open('text_files/dream_speech.txt').read().split()


##### make 2d word frequency dict
l = len(words)
p = {}
for index, word in enumerate(words):
    if index <= l-2:
        word2 = words[index+1]
    if word not in p:
        p[word] = {word2: 1}
    elif word2 not in p[word]:
        p[word][word2] = 1
    else:
        p[word][word2] += 1


##### Generate chain
word = random.choice(words)
num_words = 30
markov_chain = ""
population = list(p[word].keys())
weights = list(p[word].values())

for i in range(num_words):
    markov_chain += word + " "
    word = random.choices(population, weights=weights)[0] #python function to make a random choice based on relative weights (word frequency)
    population = list(p[word].keys())
    weights = list(p[word].values())

print(markov_chain)