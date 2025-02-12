import numpy as np
import random

def counting_sort(*array):
    #generate frequency array
    k = max(array)+1
    freq_array = np.zeros((k))
    for item in array:
        freq_array[item] += 1

    #turn into cumulative frequency arry
    cum_freq = np.cumsum(freq_array)

    #sort items in reverse order
    sorted_array = np.zeros((len(array)))
    for item in reversed(array):
        index = int(cum_freq[item])
        sorted_array[index-1] = item
        cum_freq[item] -= 1
    return list(sorted_array)

#generate test data
random_list = np.random.randint(1, 101, size=random.randint(5,20))
sorted_list = counting_sort(*random_list)
print(sorted_list)
